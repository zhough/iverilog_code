`timescale 1ns / 1ns
module IF (
    input           rst_n,
    input   [31:0]  curr_pc,
    input           jump_taken,
    input   [31:0]  jump_target,
    input           branch_taken,
    input   [31:0]  branch_target,
    input           stall,
    output  [31:0]  next_pc,
    output  [31:0]  irom_addr
);

    assign irom_addr = (rst_n) ? curr_pc : 32'h8000_0000;
    assign next_pc = stall ? curr_pc :
                     jump_taken ? jump_target :
                     branch_taken ? branch_target :
                     curr_pc + 4;
endmodule
