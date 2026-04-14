`timescale 1ns / 1ns
module core_cpu (
    input cpu_rst,
    input cpu_clk,
    output [31:0] irom_addr,
    input [31:0] irom_data,
    output [31:0] perip_addr,
    output perip_wen,
    output [2:0] perip_mask,
    output [31:0] perip_wdata,
    input [31:0] perip_rdata
);
    //外部接口
    wire rst_n = ~cpu_rst;
    wire clk = cpu_clk;
    reg [31:0] rs [31:0];


    //IF
    reg     [31:0]      curr_pc_if;
    reg                 jump_taken_if;
    reg     [31:0]      jump_target_if;
    reg                 branch_taken_if;
    reg     [31:0]      branch_target_if;
    reg                 nop_if;
    wire    [31:0]      next_pc_if;
    wire    [31:0]      irom_addr_if;

    IF u_IF(
        .rst_n          (rst_n),
        .curr_pc        (curr_pc_if),
        .jump_taken     (jump_taken_if),
        .jump_target    (jump_target_if),
        .branch_taken   (branch_taken_if),
        .branch_target  (branch_target_if),
        .nop            (nop_if),
        .next_pc        (next_pc_if),
        .irom_addr      (irom_addr_if)
    );

    always @(negedge rst_n or posedge clk) begin
        if (!rst_n) begin
            curr_pc_if <= 32'h8000_0000;
        end else begin
            curr_pc_if <= next_pc_if;
        end
    end

    //外部端口
    assign irom_addr = irom_addr_if;
    wire     [31:0]     ins_if;
    assign ins_if = irom_data;



    reg     [31:0]      ins_id;
    wire                alu_src_id;
    wire    [3:0]       alu_op_id;
    wire    [31:0]      imm_id;
    wire                jump_en_id;
    wire                branch_en_id;
    wire                is_lui_id;
    wire                is_auipc_id;
    wire                is_jalr_id;
    wire                rd_en_id;
    wire                rs2_en_id;
    wire    [2:0]       load_op_id;
    wire    [2:0]       store_op_id;
    wire    [4:0]       rs1_id;
    wire    [4:0]       rs2_id;
    wire    [4:0]       rd_id;

    ID u_ID(
        .ins        (ins_id),
        .alu_src    (alu_src_id),
        .alu_op     (alu_op_id),
        .imm        (imm_id),
        .jump_en    (jump_en_id),
        .branch_en  (branch_en_id),
        .is_lui     (is_lui_id),
        .is_auipc   (is_auipc_id),
        .is_jalr     (is_jalr_id),
        .rd_en      (rd_en_id),
        .load_op    (load_op_id),
        .store_op   (store_op_id),
        .rs1        (rs1_id),
        .rs2        (rs2_id),
        .rd         (rd_id),
        .rs2_en     (rs2_en_id)
    );

    reg     [31:0]      pc_id;
    always @(negedge rst_n or posedge clk) begin
        if (!rst_n) begin
            ins_id <= 32'b0;
            pc_id <= 32'b0;
        end else begin
            //pc_id <= irom_addr_if;
            if (id_clear) begin
                pc_id <= 32'b0;
                ins_id <= 32'b0;
            end else if (id_nop) begin
                ins_id <= ins_id;
                pc_id <= pc_id;
            end else begin
                ins_id <= ins_if;
                pc_id <= irom_addr_if;
            end
        end
    end


    reg     [3:0]       alu_op_ex;
    reg                 alu_src_ex;
    reg     [31:0]      a_ex;
    reg     [31:0]      b_ex;
    reg     [31:0]      imm_ex;
    reg                 jump_en_ex;
    reg                 branch_en_ex;
    reg                 is_jalr_ex;
    reg     [31:0]      pc_ex;
    wire                jump_taken_ex;
    wire                branch_taken_ex;
    wire    [31:0]      jump_target_ex;
    wire    [31:0]      branch_target_ex;
    wire    [31:0]      alu_result_ex;
    wire    [31:0]      j_rd_ex;
    reg     [2:0]       store_op_ex;
    reg     [2:0]       load_op_ex;

    wire                is_load_ex;
    wire                is_store_ex;
    assign is_load_ex = ~(&load_op_ex);
    assign is_store_ex = ~(&store_op_ex);


    EX u_EX(
        .alu_op         (alu_op_ex),
        .alu_src        (alu_src_ex),
        .a              (a_ex),
        .b              (b_ex),
        .imm            (imm_ex),
        .jump_en        (jump_en_ex),
        .branch_en      (branch_en_ex),
        .is_jalr        (is_jalr_ex),
        .pc             (pc_ex),
        .jump_taken     (jump_taken_ex),
        .branch_taken   (branch_taken_ex),
        .jump_target    (jump_target_ex),
        .branch_target  (branch_target_ex),
        .alu_result     (alu_result_ex),
        .j_rd           (j_rd_ex)
    );

    always @(negedge rst_n or posedge clk) begin
        if (!rst_n) begin
            pc_ex <= 32'b0;
            alu_op_ex <= 4'b0;
            alu_src_ex <= 1'b0;
            a_ex <= 32'b0;
            b_ex <= 32'b0;
            imm_ex <= 32'b0;
            jump_en_ex <= 1'b0;
            branch_en_ex <= 1'b0;
            is_jalr_ex <= 1'b0;
            store_op_ex <= 3'b111;
            load_op_ex <= 3'b111;
        end else begin
            if (ex_clear) begin
                pc_ex <= 32'b0;
                alu_op_ex <= 4'b0;
                alu_src_ex <= 1'b0;
                a_ex <= 32'b0;
                b_ex <= 32'b0;
                imm_ex <= 32'b0;
                jump_en_ex <= 1'b0;
                branch_en_ex <= 1'b0;
                is_jalr_ex <= 1'b0;
                store_op_ex <= 3'b111;
                load_op_ex <= 3'b111;
            end else begin
                pc_ex <= pc_id;
                alu_op_ex <= alu_op_id;
                alu_src_ex <= alu_src_id;
                //加入旁路
                a_ex <= WAR1_ex     ? bypass_ex     :
                        WAR1_mem    ? bypass_mem    :
                        rs[rs1_id];
                b_ex <= WAR2_ex     ? bypass_ex     :
                        WAR2_mem    ? bypass_mem    :
                        rs[rs2_id];

                imm_ex <= imm_id;
                jump_en_ex <= jump_en_id;
                branch_en_ex <= branch_en_id;
                is_jalr_ex <= is_jalr_id;
                store_op_ex <= store_op_id;
                load_op_ex <= load_op_id;
            end
        end
    end

    reg     id_clear;
    reg     ex_clear;
    reg     id_nop;
    always @(*) begin
        // if (!rst_n) begin
        //     nop_if = 1'b0;
        //     jump_taken_if = 1'b0;
        //     jump_target_if = 32'b0;
        //     branch_taken_if = 1'b0;
        //     branch_target_if = 32'b0;
        //     id_clear = 1'b0;
        //     ex_clear = 1'b0;
        //     id_nop = 1'b0;
        // end else begin
            jump_taken_if = jump_taken_ex;
            jump_target_if = jump_target_ex;
            branch_taken_if = branch_taken_ex;
            branch_target_if = branch_target_ex;
            id_clear = jump_taken_ex | branch_taken_ex;
            ex_clear = jump_taken_ex | branch_taken_ex | LAR;
            id_nop = LAR;
            nop_if = LAR;
        // end
    end

    //数据旁路
    reg     [4:0]       rd_ex;
    reg                 rd_en_ex;
    reg     [4:0]       rd_mem;
    reg                 rd_en_mem;
    reg     [4:0]       rs2_ex;
    reg     [4:0]       rs2_mem;
    reg                 is_lui_ex;
    reg                 is_auipc_ex;
    wire                WAR1_ex;
    wire                WAR2_ex;
    wire                WAR1_mem;
    wire                WAR2_mem;
    wire                LAR;
    wire    [31:0]      bypass_ex;
    wire    [31:0]      bypass_mem;
    wire    [31:0]     wb_result_ex;
    assign  WAR1_ex = (rd_ex == rs1_id) & rd_en_ex & (~is_load_ex) & (rs1_id != 5'b0);
    assign  WAR2_ex = (rd_ex == rs2_id) & rd_en_ex & (~is_load_ex) & (rs2_id != 5'b0);
    assign WAR1_mem = (rd_mem == rs1_id) & rd_en_mem & (rs1_id != 5'b0);
    assign WAR2_mem = (rd_mem == rs2_id) & rd_en_mem & (rs2_id != 5'b0);
    assign LAR = ((rd_ex == rs1_id & rs1_id != 5'b0) | (rd_ex == rs2_id & rs2_id != 5'b0)) & is_load_ex;
    assign bypass_ex = wb_result_ex;
    assign bypass_mem = wb_result_mem;
    
    //ex阶段要写寄存器的数
    assign wb_result_ex =   is_lui_ex ? imm_ex :
                            is_auipc_ex ? branch_target_ex :
                            jump_taken_ex ? j_rd_ex :
                            alu_result_ex;

    always @(negedge rst_n or posedge clk) begin
        if (!rst_n) begin
            rd_ex <= 5'b0;
            rd_en_ex <= 1'b0;
            rd_mem <= 5'b0;
            rd_en_mem <= 1'b0;
            rs2_ex <= 5'b0;
            rs2_mem <= 5'b0;
            is_lui_ex <= 1'b0;
            is_auipc_ex <= 1'b0;
        end else begin
            rd_mem <= rd_ex;
            rd_en_mem <= rd_en_ex;
            rs2_mem <= rs2_ex;
            if (ex_clear) begin
                rd_ex <= 5'b0;
                rd_en_ex <= 1'b0;
                rs2_ex <= 5'b0;
                is_lui_ex <= 1'b0;
                is_auipc_ex <= 1'b0;
            end else begin
                rd_ex <= rd_id;
                rd_en_ex <= rd_en_id;
                rs2_ex <= rs2_id;
                is_lui_ex <= is_lui_id;
                is_auipc_ex <= is_auipc_id;
            end
        end
    end


    reg                 is_load_mem;
    reg                 is_store_mem;
    reg     [31:0]      wb_result_mem;

    //MEM2阶段
    reg                 is_load_mem2;
    reg     [31:0]      wb_result_mem_reg;
    wire    [31:0]      wb_result_mem2;
    wire    [31:0]      load_data_mem2;

    //store的数据也要旁路
    wire     [31:0]      store_data_ex;
    //判断是否为写寄存器后下一条指令为将该寄存器写入内存
    wire                is_WAS; //write after store
    assign is_WAS = (rs2_ex == rd_mem) & (is_store_ex) & rd_en_mem & (rs2_ex != 5'b0);
    assign  store_data_ex  = is_WAS ? bypass_mem : rs[rs2_ex];

    assign  load_data_mem2 = perip_rdata;
    assign  perip_addr  =   alu_result_ex;
    assign  perip_wen   =   is_store_ex;
    assign  perip_wdata =   store_data_ex;
    assign  perip_mask  =   is_store_ex ? store_op_ex : load_op_ex;
    assign  wb_result_mem2 = is_load_mem2 ? load_data_mem2 : wb_result_mem_reg;

    always @(negedge rst_n or posedge clk) begin
        if (!rst_n) begin
            is_load_mem <= 1'b0;
            is_store_mem <= 1'b0;
            wb_result_mem <= 32'b0;
            wb_result_mem_reg <= 32'b0;
            is_load_mem2 <= 1'b0;
        end else begin
            is_load_mem <= is_load_ex;
            is_store_mem <= is_store_ex; 
            wb_result_mem <= wb_result_ex;
            wb_result_mem_reg <= wb_result_mem;
            is_load_mem2 <= is_load_mem;
        end
    end

    always @(negedge rst_n or posedge clk) begin
        if (!rst_n) begin: rs_init
            integer i;
            for (i = 0; i < 32; i = i + 1) begin
                rs[i] <= 32'd0; 
            end
        end else begin
            if (rd_en_mem & (rd_mem != 5'b0)) begin
                rs[rd_mem] <= wb_result_mem2;
            end
        end
    end

    wire [31:0] rs1    = rs[1];
    wire [31:0] rs2    = rs[2];
    wire [31:0] rs3    = rs[3];

    // 注意改组合逻辑和时序逻辑的位置
endmodule