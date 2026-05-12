`timescale 1ns / 1ns
module IF (
    input           rst_n,
    input   [31:0]  curr_pc,
    input           jump_taken,
    input   [31:0]  jump_target,
    input           branch_taken,
    input   [31:0]  branch_target,
    input           nop,
    output  [31:0]  next_pc,
    output  [31:0]  irom_addr,
    input           pred_hit,
    input   [31:0]  pred_target
);
    assign irom_addr = (rst_n) ? curr_pc : 32'h8000_0000;
    assign next_pc = jump_taken ? jump_target :
                     branch_taken ? branch_target :
                     nop ? curr_pc :
                     pred_hit ? pred_target:
                     curr_pc + 4;
endmodule
