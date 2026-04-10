module IF4(
    input           rst_n,
    input   [31:0]  curr_pc,
    input           jump_taken,
    input   [31:0]  jump_target,
    input           branch_taken,
    input   [31:0]  branch_target,
    input           nop,
    output  [31:0]  next_pc,
    output  [31:0]  irom_addr
);

    assign irom_addr = (rst_n) ? curr_pc : 32'h0000_0000;
    assign next_pc = nop ? curr_pc :
                    jump_taken ? jump_target :
                    branch_taken ? branch_target :
                    curr_pc + 4;
endmodule