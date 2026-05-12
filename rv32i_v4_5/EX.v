module EX(
    input               clk,
    input               rst_n,
    input       [15:0]  ex_unit,                           
    input       [3:0]   ex_op,
    input       [31:0]  src1,
    input       [31:0]  src2,
    input       [31:0]  imm,
    input       [31:0]  pc,
    input       [4:0]   dest_regid_in,

    input               pred_hit,
    input       [31:0]  pred_target,
    output      [31:0]  update_pc,
    output      [31:0]  update_target,
    output              update_en,
    output              btb_clear_en,
    output              pred_correct,
    output              bcu_done,
    output              update_branch_en,
    output              update_branch_not_en,
           
    output      [4:0]   wb_id,
    output              wb_en,
    output      [31:0]  wb_result,
    
    input       [31:0]  perip_rdata,
    input               cache_hit,
    input       [31:0]  cache_rdata,
    output      [31:0]  addr,
    output      [31:0]  wdata,
    output              wen,
    output      [2:0]   mask,
    output              lsu_busy,
    
    output      [4:0]   CCB_id,
    output              CCB_en,
    output      [31:0]  CCB_data
);

    wire    alu_en = ex_unit[0];
    wire    lsu_en = ex_unit[4];
    wire    bcu_en = ex_unit[8];

    wire                alu_done;
    wire    [31:0]      alu_result;
    wire    [4:0]       dest_regid_out_alu;

    ALU alu_inst(
        .clk            (clk),
        .rst_n          (rst_n),
        .alu_op         (ex_op),
        .src1           (src1),
        .src2           (src2),
        .alu_en         (alu_en),
        .dest_regid_in  (dest_regid_in),

        .alu_done       (alu_done),
        .alu_result     (alu_result),
        .dest_regid_out (dest_regid_out_alu)
    );

    wire    [4:0]       dest_regid_out_bcu;
    wire    [31:0]      bcu_result;
    wire                bcu_wb_en;
    
    BCU bcu_inst(
        .clk            (clk),
        .rst_n          (rst_n),
        .bcu_en         (bcu_en),
        .bcu_op         (ex_op),
        .pc             (pc),
        .src1           (src1),
        .src2           (src2),
        .imm            (imm),
        .dest_regid_in  (dest_regid_in),
        .pred_hit       (pred_hit),
        .pred_target    (pred_target),
        .bcu_done       (bcu_done),
        .dest_regid_out (dest_regid_out_bcu),
        .wb_result      (bcu_result),
        .wb_en          (bcu_wb_en),
        .pred_correct   (pred_correct),
        .update_pc      (update_pc),
        .update_target  (update_target),
        .update_en      (update_en),
        .btb_clear_en   (btb_clear_en),
        .update_branch_en   (update_branch_en),
        .update_branch_not_en (update_branch_not_en)
    );
    
    wire    [4:0]       dest_regid_out_lsu;
    wire                lsu_done;
    wire                lsu_wb_en;
    wire    [31:0]      lsu_wb_result;
    
    LSU lsu_inst(
        .clk            (clk),
        .rst_n          (rst_n),
        .lsu_en         (lsu_en),
        .lsu_op         (ex_op),
        .src1           (src1),
        .src2           (src2),
        .imm            (imm),
        .dest_regid_in  (dest_regid_in),
        .perip_rdata    (perip_rdata),
        .cache_hit      (cache_hit),
        .cache_rdata    (cache_rdata),
        .addr           (addr),
        .wdata          (wdata),
        .wen            (wen),
        .mask           (mask),
        .dest_regid_out (dest_regid_out_lsu),
        .lsu_done       (lsu_done),
        .wb_en          (lsu_wb_en),
        .wb_result      (lsu_wb_result),
        .lsu_busy       (lsu_busy),
        .CCB_id         (CCB_id),
        .CCB_en         (CCB_en),
        .CCB_data       (CCB_data)
    );

    
    reg [31:0]  wb_result_buffer    [0:15];
    reg [4:0]   wbid_buffer         [0:15];
    wire    [31:0]  buffer_data_in;
    wire    [4:0]   buffer_id_in;
    wire    [31:0]  buffer_data_out;
    wire    [4:0]   buffer_id_out;
    reg [3:0]   buffer_head;
    reg [3:0]   buffer_tail;
    wire    push_en, pop_en;
    wire    buffer_full, buffer_empty;
    assign buffer_empty = (buffer_head == buffer_tail);
    assign buffer_full = (buffer_head == buffer_tail + 3);
    assign buffer_data_out = wb_result_buffer[buffer_head];
    assign buffer_id_out = wbid_buffer[buffer_head];

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin: init_buffer
            integer i;
            for (i=0;i<16;i=i+1) begin
                wb_result_buffer[i] <= 32'b0;
                wbid_buffer[i] <= 5'b0;
            end
            buffer_head <= 4'b0;
            buffer_tail <= 4'b0;
        end else begin
            if (push_en) begin
                buffer_tail <= buffer_tail + 4'b1;
                wb_result_buffer[buffer_tail] <= buffer_data_in;
                wbid_buffer[buffer_tail] <= buffer_id_in;
            end
            if (pop_en) buffer_head  <= buffer_head + 4'b1;
        end
    end

    assign push_en = (alu_done || bcu_wb_en) && lsu_wb_en;
    assign buffer_data_in = alu_done ? alu_result: bcu_result;
    assign buffer_id_in = alu_done ? dest_regid_out_alu: dest_regid_out_bcu;
    
    assign wb_en = alu_done || bcu_wb_en || lsu_wb_en || !buffer_empty;
    assign wb_result =  lsu_wb_en ? lsu_wb_result:
                        alu_done ? alu_result:
                        bcu_wb_en ? bcu_result:
                        (!buffer_empty) ? buffer_data_out: 32'b0;
    assign wb_id =  lsu_wb_en ? dest_regid_out_lsu:
                    alu_done ? dest_regid_out_alu:
                    bcu_wb_en ? dest_regid_out_bcu:
                    (!buffer_empty) ? buffer_id_out: 5'b0;
                         
    assign pop_en = !alu_done && !bcu_wb_en && !lsu_wb_en && !buffer_empty;

endmodule
