module  BCB(
    input           bcu_done,
    output          bcb_en,
    input           pred_correct_ex,
    input   [31:0]  update_pc_ex,
    input   [31:0]  update_target_ex,
    input           update_en_ex,
    input           clear_en_ex,
    output          bcb_pred_correct,
    output  [31:0]  bcb_update_pc,
    output  [31:0]  bcb_update_target,
    output          bcb_update_en,
    output          bcb_clear_en,

    input           lsu_busy_ex,
    output          bcb_lsu_busy
);

    // EX输出
    assign  bcb_pred_correct = pred_correct_ex;
    assign  bcb_update_pc   = update_pc_ex;
    assign  bcb_update_target = update_target_ex;
    assign  bcb_update_en   = update_en_ex;
    assign  bcb_clear_en    = clear_en_ex;
    assign  bcb_lsu_busy = lsu_busy_ex;
    assign  bcb_en      = bcu_done;

endmodule