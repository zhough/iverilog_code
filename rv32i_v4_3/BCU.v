module BCU(
    input                   clk,
    input                   rst_n,
    input                   bcu_en,
    input       [3:0]       bcu_op,
    input       [31:0]      pc,
    input       [31:0]      src1,
    input       [31:0]      src2,
    input       [31:0]      imm,
    input       [4:0]       dest_regid_in,

    input                   pred_hit,
    input       [31:0]      pred_target,

    output  reg             bcu_done,
    output  reg [4:0]       dest_regid_out,
    output  reg [31:0]      wb_result,
    output  reg             wb_en,
    output  reg             pred_correct, 
    output  reg [31:0]      update_pc,
    output  reg [31:0]      update_target,
    output  reg             update_en,
    output  reg             btb_clear_en
);
//对于分支语句，广播给快照队列，IF，ID
//对于跳转语句，广播给快照队列，IF，ID同时写buffer
    reg branch_en;
    reg [31:0]  branch_target;
    reg wb_en_reg;
    reg [31:0]  wb_result_reg;
    always @(*) begin
        case (bcu_op)
            4'b0001: begin
                branch_en = (src1 == src2);
                wb_en_reg = 1'b0;
                wb_result_reg = pc + 4;
                branch_target = pc + imm;
            end
            4'b0010: begin
                branch_en = (src1 != src2);
                wb_en_reg = 1'b0;
                wb_result_reg = pc + 4;
                branch_target = pc + imm;
            end
            4'b0011: begin
                branch_en = ($signed(src1) < $signed(src2));
                wb_en_reg = 1'b0;
                wb_result_reg = pc + 4;
                branch_target = pc + imm;
            end
            4'b0100: begin
                branch_en = ($signed(src1) >= $signed(src2));
                wb_en_reg = 1'b0;
                wb_result_reg = pc + 4;
                branch_target = pc + imm;
            end
            4'b0101: begin
                branch_en = (src1 < src2);
                wb_en_reg = 1'b0;
                wb_result_reg = pc + 4;
                branch_target = pc + imm;
            end
            4'b0110: begin
                branch_en = (src1 >= src2);
                wb_en_reg = 1'b0;
                wb_result_reg = pc + 4;
                branch_target = pc + imm;
            end
            4'b1000: begin
                branch_en = 1'b1;
                wb_en_reg = 1'b1;
                wb_result_reg = pc + 4;
                branch_target = pc + imm;
            end
            4'b1001: begin
                branch_en = 1'b1;
                wb_en_reg = 1'b1;
                wb_result_reg = pc + 4;
                branch_target = (src1 + imm) & 32'hFFFFFFFE;
            end
            default: begin
                branch_en = 1'b0;
                wb_en_reg = 1'b0;
                wb_result_reg = pc + 4;
                branch_target = pc + imm;
            end
        endcase
    end

    
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            bcu_done <= 1'b0;
            dest_regid_out <= 5'b0;
            wb_result <= 32'b0;
            wb_en <= 1'b0;
            pred_correct <= 1'b0;
            update_pc <= 32'b0;
            update_target <= 32'b0;
            update_en <= 1'b0;
            btb_clear_en <= 1'b0;
        end else begin
            bcu_done <= bcu_en;
            dest_regid_out <= dest_regid_in;
            wb_result <= wb_result_reg;
            wb_en <= wb_en_reg && bcu_en;
            //预测正确需要检查两种，一种是预测跳实际跳并且预测正确
            //另一种是没有预测同时也没跳
            pred_correct <= bcu_en && (branch_en && pred_hit && (branch_target == pred_target)) || (!pred_hit && !branch_en);
            update_pc <= pc;
            update_target <= (pred_hit && !branch_en) ? pc + 4: branch_target;
            update_en <= bcu_en && (branch_en && pred_hit && (branch_target != pred_target)) || (!pred_hit && branch_en);
            btb_clear_en <= bcu_en && pred_hit && !branch_en;
        end
    end

    // always @(*) begin
    //         // bcu_done = bcu_en;
    //         // dest_regid_out = dest_regid_in;
    //         // wb_result = wb_result_reg;
    //         // wb_en = wb_en_reg && bcu_en;
    //         // //预测正确需要检查两种，一种是预测跳实际跳并且预测正确
    //         // //另一种是没有预测同时也没跳
    //         pred_correct = bcu_en && (branch_en && pred_hit && (branch_target == pred_target)) || (!pred_hit && !branch_en);
    //         update_pc = pc;
    //         update_target = (pred_hit && !branch_en) ? pc + 4: branch_target;
    //         update_en = bcu_en && (branch_en && pred_hit && (branch_target != pred_target)) || (!pred_hit && branch_en);
    //         btb_clear_en = bcu_en && pred_hit && !branch_en;
    // end
    
endmodule