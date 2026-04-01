module core_cpu1(
    input cpu_rst,
    input cpu_clk,
    output [31:0] irom_addr,
    input [31:0] irom_data,
    output [31:0] perip_addr,
    output perip_en,
    output [3:0] perip_mask,
    output [31:0] perip_wdata,
    input [31:0] perip_rdata,
    
    output [31:0] rs3,
    output [31:0] rs17,
    output [31:0] rs10,
    output [31:0] rs2,
    output [31:0] rs1,
    output [31:0] rs6
    );
wire clk;
wire rst_n;
assign clk = cpu_clk;
assign rst_n = ~cpu_rst;

//irom
wire [12:0] pc_irom;
wire [31:0] dout_irom;
//IF
wire jump_taken_if;
wire [31:0] jump_target_if;
wire branch_taken_if;
wire [31:0] branch_target_if;
reg [31:0] curr_pc_if;
wire [31:0] next_pc_if;
wire [31:0] irom_addr_if;
wire is_LAR_if;
//ID
reg [31:0] ins;
wire alu_src_id;
wire [3:0] alu_op_id;
wire [31:0] imm_id;
wire jump_en_id, branch_en_id, is_lui_id, is_auipc_id, is_jalr_id, not_wb_id;
wire [2:0] load_op_id, store_op_id;
wire [4:0] rs1_id, rs2_id, rd_id;
//EX
reg [3:0] alu_op_ex;
reg alu_src_ex;
reg [31:0] a_ex, b_ex, imm_ex;
reg jump_en_ex, branch_en_ex, is_jalr_ex;
reg [31:0] pc_ex;
wire jump_taken_ex, branch_taken_ex;
wire [31:0] jump_target_ex, branch_target_ex, alu_result_ex;
wire [31:0] j_rd_ex;
//寄存器组定义
reg [31:0] rs [31:0];
//传给后续端口的信号
reg not_wb_ex, not_wb_mem;
reg [2:0] load_op_ex, store_op_ex, load_op_mem;
reg [4:0] rd_ex, rs2_ex, rd_mem;
reg [31:0] curr_pc_id;
reg is_lui_ex, is_auipc_ex;
//
wire is_WAR1, is_WAR2; //write after read标志位
wire is_WAR1_last, is_WAR2_last; //上上条指令的写和当前读为同一寄存器
wire is_LAR;   //load after read标志位
wire is_load_id, is_store_id;
wire is_load, is_store;
reg is_load_mem, is_store_mem;
//译码
reg [31:0] curr_pc_id_reg, curr_pc_id_reg2;
reg is_LAR_reg;
reg jump_taken_reg, branch_taken_reg;
wire [31:0] ins_if;
reg [31:0] dout_irom_reg;
//执行
wire [31:0] rs_result;
//写回
wire [2:0] wb_op;
wire [31:0] wb_result;
//mem
wire [3:0] we, we_store;
wire [31:0] ram_dout, load_data_in;
wire [31:0] load_data_out;
wire [31:0] dram_addr;
reg [31:0] last_dram_addr;
reg [1:0] alu_result_mem_low2;
reg [31:0] last_store_data;
reg [31:0] rs_result_mem;
reg is_WAR2_reg;
wire [1:0] alu_result_ex_low2;
wire [31:0] ram_din;
wire [31:0] store_data_in;
wire is_SAL;    //store after laod标志位


//赋值
assign is_load_id = ~(&load_op_id);
assign is_store_id = ~(&store_op_id);
assign is_load = ~(&load_op_ex);
assign is_store = ~(&store_op_ex);
assign is_WAR1 = ((rd_ex == rs1_id) & (rd_ex != 5'b0) & (~is_load) & (~not_wb_ex)) ? 1'b1 : 1'b0;
assign is_WAR2 = ((rd_ex == rs2_id) & (rd_ex != 5'b0) & (~is_load) & (~not_wb_ex)) ? 1'b1 : 1'b0;
assign is_WAR1_last = ((rd_mem == rs1_id) & (rd_mem != 5'b0) & (~not_wb_mem)) ? 1'b1 : 1'b0;    //包含了load-x-read类型
assign is_WAR2_last = ((rd_mem == rs2_id) & (rd_mem != 5'b0) & (~not_wb_mem)) ? 1'b1 : 1'b0;
assign is_LAR_if = is_LAR;
assign is_LAR = ((rd_ex == rs1_id) & (rd_ex != 5'b0) & is_load & (~not_wb_ex)) ? 1'b1 : 1'b0;
assign ins_if = (is_LAR_reg) ? dout_irom_reg : 
                (jump_taken_reg | branch_taken_reg) ? 32'b0 : dout_irom;
assign wb_op = {is_lui_ex, is_auipc_ex, jump_taken_ex};
//分支跳转
assign branch_taken_if = branch_taken_ex;
assign branch_target_if = branch_target_ex;
assign jump_taken_if = jump_taken_ex;
assign jump_target_if = jump_target_ex;

assign is_SAL = (is_store_mem & is_load & (dram_addr == last_dram_addr));   //load和上一条store指令操作同一地址
assign load_data_in = is_SAL ? last_store_data : ram_dout;
assign alu_result_ex_low2 = alu_result_ex[1:0];
assign we = is_store ? we_store : 4'b0;
assign store_data_in = is_WAR2_reg ? rs_result_mem : rs[rs2_ex];
assign wb_result = is_load_mem ? load_data_out : rs_result_mem;
//接口
//调试
assign rs3 = rs[3];
assign rs17 = rs[17];
assign rs10 = rs[10];
assign rs2 = rs[2];
assign rs1 = rs[1];
assign rs6 = rs[6];
assign irom_addr = irom_addr_if;
assign dout_irom = irom_data;
//具体情况再改
assign perip_addr = alu_result_ex;
assign perip_en = 1'b1;
assign perip_wdata = ram_din;
assign ram_dout = perip_rdata;
assign perip_mask = we;

assign dram_addr = perip_addr;
IF u_IF(
    .rst_n (rst_n),
    .curr_pc (curr_pc_if),
    .jump_taken (jump_taken_if),
    .jump_target (jump_target_if),
    .branch_taken (branch_taken_if),
    .branch_target (branch_target_if),
    .is_LAR (is_LAR_if),
    .next_pc (next_pc_if),
    .irom_addr (irom_addr_if)
);

ID u_ID(
    .ins        (ins),
    .alu_src    (alu_src_id),
    .alu_op     (alu_op_id),
    .imm        (imm_id),
    .jump_en    (jump_en_id),
    .branch_en  (branch_en_id),
    .is_lui     (is_lui_id),
    .is_auipc   (is_auipc_id),
    .is_jalr    (is_jalr_id),
    .not_wb     (not_wb_id),
    .load_op    (load_op_id),
    .store_op   (store_op_id),
    .rs1        (rs1_id),
    .rs2        (rs2_id),
    .rd         (rd_id)
);

EX u_EX(
    .alu_op (alu_op_ex),
    .alu_src (alu_src_ex),
    .a (a_ex),
    .b (b_ex),
    .imm (imm_ex),
    .jump_en (jump_en_ex),
    .branch_en (branch_en_ex),
    .is_jalr (is_jalr_ex),
    .pc (pc_ex),
    .jump_taken (jump_taken_ex),
    .branch_taken (branch_taken_ex),
    .jump_target (jump_target_ex),
    .branch_target (branch_target_ex),
    .alu_result (alu_result_ex),
    .j_rd (j_rd_ex)
);

WB u_wb(
    .wb_op (wb_op),
    .imm (imm_ex),
    .branch_target (branch_target_ex),
    .j_rd (j_rd_ex),
    .alu_result (alu_result_ex),
    .rs_result (rs_result)
);

LOAD u_load(
    .load_op (load_op_mem),
    .load_data_in (load_data_in),
    .addr_low2 (alu_result_mem_low2),
    .load_data_out (load_data_out)
);

STORE u_store(
    .store_op (store_op_ex),
    .addr_low2 (alu_result_ex_low2),
    .rs_data (store_data_in),
    .ram_din (ram_din),
    .we (we_store)
);

always @(posedge clk or negedge rst_n)
begin
    if (!rst_n) begin
        curr_pc_if <= 32'b0;
    end
    else begin
        //curr_pc_if <= next_pc_if;
        if (is_LAR_if) curr_pc_if = curr_pc_if;
        else begin
            curr_pc_if = next_pc_if;
        end 
    end
end

always @(posedge clk or negedge rst_n)
begin
    if (!rst_n) begin
        ins <= 32'b0;
        curr_pc_id <= 32'b0;
        curr_pc_id_reg <= 32'b0;
        curr_pc_id_reg2 <= 32'b0;
        is_LAR_reg <= 1'b0;
        jump_taken_reg <= 1'b0;
        branch_taken_reg <= 1'b0;
        dout_irom_reg <= 32'b0;
    end
    else begin
        is_LAR_reg <= is_LAR_if;
        dout_irom_reg <= dout_irom;
        jump_taken_reg <= jump_taken_if;
        branch_taken_reg <= branch_taken_if;
        curr_pc_id_reg2 <= curr_pc_if;
        curr_pc_id_reg <= curr_pc_id_reg2;
        curr_pc_id <= curr_pc_id_reg;
        if(~is_LAR_if) begin
            if(jump_taken_if | branch_taken_if) begin
                ins <= 32'b0;
            end
            else begin
                ins <= ins_if;
            end
        end
        else begin
            ins <= ins;
        end
    end
end

always @(posedge clk or negedge rst_n)
begin
    if (!rst_n) begin
        alu_op_ex <= 4'b0;
        alu_src_ex <= 1'b0;
        a_ex <= 32'b0;
        b_ex <= 32'b0;
        imm_ex <= 32'b0;
        jump_en_ex <= 1'b0;
        branch_en_ex <= 1'b0;
        is_jalr_ex <= 1'b0;
        pc_ex <= 32'b0;
        not_wb_ex <= 1'b1;
        load_op_ex <= 3'b111;
        store_op_ex <= 3'b111;
        rd_ex <= 5'b0;
        rs2_ex <= 5'b0;
        is_lui_ex <= 1'b0;
        is_auipc_ex <= 1'b0;
    end
    else begin
        if (~is_LAR & ~(jump_taken_if | branch_taken_if)) begin
            alu_op_ex <= alu_op_id;
            alu_src_ex <= alu_src_id;
            //数据旁路选择分支
            a_ex <= (is_WAR1) ? rs_result :
                    (is_WAR1_last) ? wb_result : rs [rs1_id];   //这种情况包含load-x-read
            b_ex <= (is_WAR2) ? rs_result :
                    (is_WAR2_last) ? wb_result : rs [rs2_id];
            rs2_ex <= rs2_id;
            imm_ex <= imm_id;
            jump_en_ex <= jump_en_id;
            branch_en_ex <= branch_en_id;
            is_jalr_ex <= is_jalr_id;
            pc_ex <= curr_pc_id;
            not_wb_ex <= not_wb_id;
            load_op_ex <= load_op_id;
            store_op_ex <= store_op_id;
            rd_ex <= rd_id;
            is_lui_ex <= is_lui_id;
            is_auipc_ex <= is_auipc_id;
        end
        else begin
            alu_op_ex <= 4'b0;
            alu_src_ex <= 1'b0;
            a_ex <= 32'b0;
            b_ex <= 32'b0;
            imm_ex <= 32'b0;
            jump_en_ex <= 1'b0;
            branch_en_ex <= 1'b0;
            is_jalr_ex <= 1'b0;
            pc_ex <= 32'b0;
            not_wb_ex <= 1'b1;
            load_op_ex <= 3'b111;
            store_op_ex <= 3'b111;
            rd_ex <= 5'b0;
            rs2_ex <= 5'b0;
            is_lui_ex <= 1'b0;
            is_auipc_ex <= 1'b0;
        end
    end
end

always @(posedge clk or negedge rst_n)
begin
    if (!rst_n) begin : init_rs
        integer i;
        for (i = 0; i < 32; i = i + 1) begin
            rs[i] <= 32'd0; 
        end
    end
    else begin
        if ((not_wb_mem != 1'b1) & (rd_mem != 5'b0)) begin
            rs [rd_mem] <= wb_result;
        end
    end
end

always @(posedge clk or negedge rst_n)
begin
    if (!rst_n) begin
        load_op_mem <= 3'b111;
        rs_result_mem <= 32'b0;
        not_wb_mem <= 1'b0;
        rd_mem <= 5'b0;
        is_load_mem <= 1'b0;
        is_store_mem <= 1'b0;
        alu_result_mem_low2 <= 2'b0;
        last_dram_addr <= 32'b0;
        last_store_data <= 32'b0;
        is_WAR2_reg <= 1'b0;
    end
    else begin
        load_op_mem <= load_op_ex;
        rs_result_mem <= rs_result;
        not_wb_mem <= not_wb_ex;
        rd_mem <= rd_ex;
        is_load_mem <= is_load;
        is_store_mem <= is_store;
        alu_result_mem_low2 <= alu_result_ex_low2;
        last_dram_addr <= dram_addr;
        last_store_data <= ram_din;
        is_WAR2_reg <= is_WAR2;
    end
end

endmodule
