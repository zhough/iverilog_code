`timescale 1ns / 1ps

module top1_tb;

/*iverilog */
initial
begin            
    $dumpfile("wave.vcd");        //生成的vcd文件名称
    $dumpvars(0, top1_tb);    //tb模块名称
end
/*iverilog */

reg clk, rst_n;
initial begin
    clk = 1'b0;  // 初始值
    forever begin  // 永久循环
        #5 clk = ~clk;
    end
end
initial begin
    rst_n = 0;
    #2;
    rst_n = 1;
end

//==================== irom_test instance start ================
wire [12:0] pc_irom;
wire [31:0] dout_irom;

dist_irom u_irom(
    .a (pc_irom),
    .spo (dout_irom)
);

//==================== IF module instance start ================

wire jump_taken_if;
wire [31:0] jump_target_if;
wire branch_taken_if;
wire [31:0] branch_target_if;
reg [31:0] curr_pc_if;
wire [31:0] next_pc_if;
wire [31:0] irom_addr_if;
wire is_LAR_if;

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
//===================== IF module instance end ==================

//===================== ID module instance start ================
reg [31:0] ins;
wire alu_src_id;
wire [3:0] alu_op_id;
wire [31:0] imm_id;
wire jump_en_id, branch_en_id, is_lui_id, is_auipc_id, is_jalr_id, not_wb_id;
wire [2:0] load_op_id, store_op_id;
wire [4:0] rs1_id, rs2_id, rd_id;

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
//=================== ID module instance end =====================

//=================== EX module instance start ===================
reg [3:0] alu_op_ex;
reg alu_src_ex;
reg [31:0] a_ex, b_ex, imm_ex;
reg jump_en_ex, branch_en_ex, is_jalr_ex;
reg [31:0] pc_ex;
wire jump_taken_ex, branch_taken_ex;
wire [31:0] jump_target_ex, branch_target_ex, alu_result_ex;
wire [31:0] j_rd_ex;

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
//================= EX module instance end =====================


//寄存器组定义
reg [31:0] rs [31:0];

//传给后续端口的信号
reg not_wb_ex, not_wb_mem;
reg [2:0] load_op_ex, store_op_ex, load_op_mem;
reg [4:0] rd_ex, rs2_ex, rd_mem;
reg [31:0] curr_pc_id;
reg is_lui_ex, is_auipc_ex;
//==================================================

//检测写寄存器下一条指令读同一寄存器    (标志位会在译码的下一个周期，即执行周期开始生效)
wire is_WAR1, is_WAR2; //write after read标志位
wire is_WAR1_last, is_WAR2_last; //上上条指令的写和当前读为同一寄存器
wire is_LAR;   //load after read标志位
wire is_load_id, is_store_id;
wire is_load, is_store;
assign is_load_id = ~(&load_op_id);
assign is_store_id = ~(&store_op_id);
assign is_load = ~(&load_op_ex);
assign is_store = ~(&store_op_ex);
reg is_load_mem, is_store_mem;
assign is_WAR1 = ((rd_ex == rs1_id) & (rd_ex != 5'b0) & (~is_load) & (~not_wb_ex)) ? 1'b1 : 1'b0;
assign is_WAR2 = ((rd_ex == rs2_id) & (rd_ex != 5'b0) & (~is_load) & (~not_wb_ex)) ? 1'b1 : 1'b0;
assign is_WAR1_last = ((rd_mem == rs1_id) & (rd_mem != 5'b0) & (~not_wb_mem)) ? 1'b1 : 1'b0;    //包含了load-x-read类型
assign is_WAR2_last = ((rd_mem == rs2_id) & (rd_mem != 5'b0) & (~not_wb_mem)) ? 1'b1 : 1'b0;
assign is_LAR_if = is_LAR;
assign is_LAR = ((rd_ex == rs1_id) & (rd_ex != 5'b0) & is_load & (~not_wb_ex)) ? 1'b1 : 1'b0;
//取指
assign pc_irom = irom_addr_if [14:2];
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
//==============================

//译码
reg [31:0] curr_pc_id_reg;
reg is_LAR_reg;
//reg jump_taken_reg, branch_taken_reg;
wire [31:0] ins_if;
reg [31:0] dout_irom_reg;
assign ins_if = (is_LAR_reg) ? dout_irom_reg : 
                (jump_taken_if | branch_taken_if) ? 32'b0 : dout_irom;
always @(posedge clk or negedge rst_n)
begin
    if (!rst_n) begin
        ins <= 32'b0;
        curr_pc_id <= 32'b0;
        curr_pc_id_reg <= 32'b0;
        is_LAR_reg <= 1'b0;
        //jump_taken_reg <= 1'b0;
        //branch_taken_reg <= 1'b0;
        dout_irom_reg <= 32'b0;
    end
    else begin
        is_LAR_reg <= is_LAR_if;
        dout_irom_reg <= dout_irom;
        //jump_taken_reg <= jump_taken_if;
        //branch_taken_reg <= branch_taken_if;
        curr_pc_id_reg <= curr_pc_if;
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
//================================

//执行
wire [31:0] rs_result;
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
//写回
wire [2:0] wb_op;
assign wb_op = {is_lui_ex, is_auipc_ex, jump_taken_ex};

WB u_wb(
    .wb_op (wb_op),
    .imm (imm_ex),
    .branch_target (branch_target_ex),
    .j_rd (j_rd_ex),
    .alu_result (alu_result_ex),
    .rs_result (rs_result)
);

wire [31:0] wb_result;
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

//分支跳转
assign branch_taken_if = branch_taken_ex;
assign branch_target_if = branch_target_ex;
assign jump_taken_if = jump_taken_ex;
assign jump_target_if = jump_target_ex;


//mem
wire [3:0] we, we_store;
wire [31:0] ram_dout, load_data_in;
wire [31:0] load_data_out;
wire [15:0] dram_addr;
reg [15:0] last_dram_addr;
reg [1:0] alu_result_mem_low2;
reg [31:0] last_store_data;
reg [31:0] rs_result_mem;
reg is_WAR2_reg;
wire [1:0] alu_result_ex_low2;
wire [31:0] ram_din;
wire [31:0] store_data_in;
wire is_SAL;    //store after laod标志位
//地址偏移
assign dram_addr = alu_result_ex[17:2];
assign is_SAL = (is_store_mem & is_load & (dram_addr == last_dram_addr));   //load和上一条store指令操作同一地址
assign load_data_in = is_SAL ? last_store_data : ram_dout;
assign alu_result_ex_low2 = alu_result_ex[1:0];
assign we = is_store ? we_store : 4'b0;
assign store_data_in = is_WAR2_reg ? rs_result_mem : rs[rs2_ex];

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

dram u_dram(
    .clka (clk),
    .ena (1'b1),
    .wea (we),
    .addra (dram_addr),
    .dina (ram_din),
    .douta (ram_dout)
);

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
        last_dram_addr <= 12'b0;
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
assign wb_result = is_load_mem ? load_data_out : rs_result_mem;

//output 
wire [31:0] rs1 = rs[1];
wire [31:0] rs2 = rs[2];
wire [31:0] rs3 = rs[3];
wire [31:0] rs17 = rs[17];
wire [31:0] rs10 = rs[10];
wire [31:0] rs4 = rs[4];
wire [31:0] rs5 = rs[5];

endmodule
