module core_cpu4(
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

    IF4 u_IF(
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
            curr_pc_if <= 32'b0;
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

    ID4 u_ID(
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
        .rs2_en     (rs2_en_id)
    );

    reg     [31:0]      pc_id;
    always @(negedge rst_n or posedge clk) begin
        if (!rst_n) begin
            ins_id <= 32'b0;
            pc_id <= 32'b0;
        end else begin
            ins_id <= ins_if;
            pc_id <= irom_addr_if;
        end
    end


    reg     [31:0]      pc_ex;
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
    wire    [31:0]      j_rd;
    reg     [2:0]       store_op_ex;
    reg     [2:0]       load_op_ex;

    always @(negedge rst_n or posedge clk) begin
        if (!rst_n) begin
            pc_ex <= 32'b0;
            alu_op_ex <= 4'b0;
            alu_src_ex <= 4'b0;
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
            //暂定无旁路
            a_ex <= rs[rs1_id];
            b_ex <= rs[rs2_id];
            imm_ex <= imm_id;
            jump_en_ex <= jump_en_id;
            branch_en_ex <= branch_en_id;
            is_jalr_ex <= is_jalr_id;
            store_op_ex <= store_op_id;
            load_op_ex <= load_op_id;
        end
    end

    reg     clear_id;
    reg     clear_ex;
    always @(*) begin
        if (!rst_n) begin
            nop_if <= 1'b0;
            jump_taken_if <= 1'b0;
            jump_target_if <= 32'b0;
            branch_taken_if <= 1'b0;
            branch_target_if <= 32'b0;
            id_clear <= 1'b0;
            ex_clear <= 1'b0;
        end else begin
            jump_taken_if <= jump_taken_ex;
            jump_target_if <= jump_target_ex;
            branch_taken_if <= branch_taken_ex;
            branch_target_if <= branch_target_ex;
            nop_if <= 1'b0; //改为LAR
            end
    end


endmodule