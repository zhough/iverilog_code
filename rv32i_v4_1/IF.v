`timescale 1ns / 1ns
module IF (
    input           rst_n,
    input           clk,
    input           redirect_en,
    input   [31:0]  redirect_target,
    input           stall,
    output  [31:0]  irom_addr,
    input           pred_hit,
    input   [31:0]  pred_target
);

    wire    [31:0]  next_pc;
    reg     [31:0]  curr_pc;

    assign irom_addr = curr_pc;
    assign next_pc = redirect_en ? redirect_target:
                     stall ? curr_pc :
                     pred_hit ? pred_target:
                     curr_pc + 4;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            curr_pc <= 32'h80000000;
        end else begin
            curr_pc <= next_pc;
        end
    end
endmodule
