module core_cpu(
    input           cpu_rst,
    input           cpu_clk,
    output [31:0]   irom_addr,
    input  [31:0]   irom_data,
    output [31:0]   perip_addr,
    output          perip_wen,
    output [2:0]    perip_mask,
    output [31:0]   perip_wdata,
    input  [31:0]   perip_rdata,
    input           hit,
    input  [31:0]   cache_rdata
);
    reg             SAT         [0:31];
    reg     [31:0]  regfiles    [0:31];

    wire    rst_n = !cpu_rst;
    wire    clk   = cpu_clk;
    wire    stall;
    wire    flush;


    //CDB总线
    wire            wb_en_ex;
    wire    [31:0]  wb_result_ex;
    wire    [4:0]   wb_id_ex;
    wire            cdb_en;
    wire    [31:0]  cdb_result;
    wire    [4:0]   cdb_id;

    CDB u_cdb(
        .wb_en_ex       (wb_en_ex),
        .wb_result_ex   (wb_result_ex),
        .wb_id_ex       (wb_id_ex),
        .cdb_en         (cdb_en),
        .cdb_result     (cdb_result),
        .cdb_id         (cdb_id)
    );

    //BCB总线
    wire            bcu_done;
    wire            pred_correct_ex;
    wire    [31:0]  update_pc_ex;
    wire    [31:0]  update_target_ex;
    wire            update_en_ex;
    wire            clear_en_ex;
    wire            lsu_busy_ex;
    wire            bcb_en;
    wire            bcb_pred_correct;
    wire    [31:0]  bcb_update_pc;
    wire    [31:0]  bcb_update_target;
    wire            bcb_update_en;
    wire            bcb_clear_en;
    wire            bcb_lsu_busy;
    BCB u_bcb(
        .bcu_done           (bcu_done),
        .pred_correct_ex    (pred_correct_ex),
        .update_pc_ex       (update_pc_ex),
        .update_target_ex   (update_target_ex),
        .update_en_ex       (update_en_ex),
        .clear_en_ex        (clear_en_ex),
        .lsu_busy_ex        (lsu_busy_ex),
        .bcb_en             (bcb_en),
        .bcb_pred_correct   (bcb_pred_correct),
        .bcb_update_pc      (bcb_update_pc),
        .bcb_update_target  (bcb_update_target),
        .bcb_update_en      (bcb_update_en),
        .bcb_clear_en       (bcb_clear_en),
        .bcb_lsu_busy       (bcb_lsu_busy)
    );

    // BTB
    wire    [31:0]  pc;
    wire            pred_hit_btb;
    wire    [31:0]  pred_target_btb;
    wire    btb_update_en = bcb_update_en && bcb_en;
    wire    btb_clear_en = bcb_clear_en && bcb_en;
    BTB u_btb(
        .clk            (clk),
        .rst_n          (rst_n),
        .pc             (pc),
        .update_en      (btb_update_en),
        .clear_en       (btb_clear_en),
        .update_pc      (bcb_update_pc),
        .update_target  (bcb_update_target),
        .pred_hit       (pred_hit_btb),
        .pred_target    (pred_target_btb)
    );

    // IF
    wire    redirect_en = bcb_en && !bcb_pred_correct;
    IF u_IF(
        .rst_n              (rst_n),
        .clk                (clk),
        .redirect_en        (redirect_en),
        .redirect_target    (bcb_update_target),
        .stall              (stall),
        .irom_addr          (pc),
        .pred_hit           (pred_hit_btb),
        .pred_target        (pred_target_btb)
    );

    parameter NOP_inst  = 32'h00000013;
    assign  irom_addr   = pc;
    reg     [31:0]  inst_if;
    reg             pred_hit_if;
    reg     [31:0]  pred_target_if;
    reg     [31:0]  pc_if;
    always  @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            inst_if <= 32'b0;
            pred_hit_if <= 1'b0;
            pred_target_if <= 32'b0;
            pc_if <= 32'b0;
        end else begin
            if (!stall || flush) begin
                inst_if <= flush ? NOP_inst: irom_data;
                pred_hit_if <= pred_hit_btb;
                pred_target_if <= pred_target_btb;
                pc_if <= pc;
            end
        end
    end

    wire    [3:0]   ex_tag;
    wire    [4:0]   rs1_addr;
    wire    [4:0]   rs2_addr;
    wire    [4:0]   rd_addr;
    wire            alu_src1_ispc;
    wire            alu_src2_isimm;
    wire    [31:0]  imm;
    wire    [3:0]   op;

    ID u_ID(
        .inst           (flush ? NOP_inst: inst_if),
        .ex_tag         (ex_tag),
        .rs1_addr       (rs1_addr),
        .rs2_addr       (rs2_addr),
        .rd_addr        (rd_addr),
        .alu_src1_ispc  (alu_src1_ispc),
        .alu_src2_isimm (alu_src2_isimm),
        .imm            (imm),
        .op             (op)
    );

    reg     [31:0]  pc_id;
    reg             pred_hit_id;
    reg     [31:0]  pred_target_id;
    reg     [3:0]   ex_tag_id;
    reg     [4:0]   rs1_addr_id;
    reg     [4:0]   rs2_addr_id;
    reg     [4:0]   rd_addr_id;
    reg             alu_src1_ispc_id;
    reg             alu_src2_isimm_id;
    reg     [31:0]  imm_id;
    reg     [3:0]   op_id;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pc_id <= 32'b0;
            pred_hit_id <= 1'b0;
            pred_target_id <= 32'b0;
            ex_tag_id <= 4'b0;
            rs1_addr_id <= 5'b0;
            rs2_addr_id <= 5'b0;
            rd_addr_id  <= 5'b0;
            alu_src1_ispc_id <= 1'b0;
            alu_src2_isimm_id <= 1'b0;
            imm_id <= 32'b0;
            op_id <= 4'b0;
        end else begin
            if (!stall || flush) begin
                pc_id <= pc_if;
                pred_hit_id <= pred_hit_if;
                pred_target_id <= pred_target_if;
                ex_tag_id <= ex_tag;
                rs1_addr_id <= rs1_addr;
                rs2_addr_id <= rs2_addr;
                rd_addr_id <= rd_addr;
                alu_src1_ispc_id <= alu_src1_ispc;
                alu_src2_isimm_id <= alu_src2_isimm;
                imm_id <= imm;
                op_id <= op;
            end
        end
    end

    wire    rs1_states, rs2_states, rd_states;
    wire    [31:0]  regsrc1, regsrc2;
    wire    [15:0]  ex_unit;
    wire            update_SAT_en;
    wire    [31:0]  src1;
    wire    [31:0]  src2;

    assign rs1_states = SAT[rs1_addr_id];
    assign rs2_states = SAT[rs2_addr_id];
    assign rd_states  = SAT[rd_addr_id];
    assign regsrc1 = regfiles[rs1_addr_id];
    assign regsrc2 = regfiles[rs2_addr_id];

    Issue u_issue(
        .ex_tag         (ex_tag_id),
        .rs1_states     (rs1_states),
        .rs2_states     (rs2_states),
        .rd_states      (rd_states),
        .alu_src1_ispc  (alu_src1_ispc_id),
        .alu_src2_isimm (alu_src2_isimm_id),
        .src1_addr      (rs1_addr_id),
        .src2_addr      (rs2_addr_id),
        .rd_addr        (rd_addr_id),
        .regsrc1        (regsrc1),
        .regsrc2        (regsrc2),
        .imm            (imm_id),
        .pc             (pc_id),
        .ex_unit        (ex_unit),
        .update_SAT_en  (update_SAT_en),
        .src1           (src1),
        .src2           (src2),
        .stall          (stall),
        .flush          (flush),
        .bcb_en         (bcb_en),
        .pred_correct   (bcb_pred_correct),
        .lsu_busy       (bcb_lsu_busy),
        .cdb_en         (cdb_en),
        .cdb_result     (cdb_result),
        .cdb_id         (cdb_id)
    );


    EX u_EX(
        .clk            (clk),
        .rst_n          (rst_n),
        .ex_unit        (ex_unit),
        .ex_op          (op_id),
        .src1           (src1),
        .src2           (src2),
        .imm            (imm_id),
        .pc             (pc_id),
        .dest_regid_in  (rd_addr_id),
        .pred_hit       (pred_hit_id),
        .pred_target    (pred_target_id),
        .update_pc      (update_pc_ex),
        .update_target  (update_target_ex),
        .update_en      (update_en_ex),
        .btb_clear_en   (clear_en_ex),
        .pred_correct   (pred_correct_ex),
        .bcu_done       (bcu_done),
        .wb_id          (wb_id_ex),
        .wb_en          (wb_en_ex),
        .wb_result      (wb_result_ex),
        .perip_rdata    (perip_rdata),
        .cache_hit      (hit),
        .cache_rdata    (cache_rdata),
        .addr           (perip_addr),
        .wdata          (perip_wdata),
        .wen            (perip_wen),
        .mask           (perip_mask),
        .lsu_busy       (lsu_busy_ex)
    );

    //SAT更新
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin: init_SAT
            integer i;
            for (i=0;i<32;i=i+1) begin
                SAT[i] <= 1'b0;
            end
        end else begin
            if (cdb_en) begin
                SAT[cdb_id] <= 1'b0;
            end
            if (update_SAT_en && (rd_addr_id != 5'b0)) begin
                SAT[rd_addr_id] <= 1'b1;
            end
        end
    end

    //提交到regfiles
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin: init_regfiles
            integer i;
            for (i=0;i<32;i=i+1) begin
                regfiles[i] <= 32'b0;
            end
        end else begin
            if (cdb_en && (cdb_id != 5'b0)) begin
                regfiles[cdb_id] <= cdb_result;
            end
        end
    end
        
    wire    [31:0]  gp = regfiles[3];
endmodule