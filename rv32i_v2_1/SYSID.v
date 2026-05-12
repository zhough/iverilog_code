module SYSID(
    input       [31:0]  ins,
    output              is_ecall
);

    wire opcode = ins[6:0];
    wire is_sys_inst = (ins == 7'b1110011);
    wire is_ecall = is_sys_inst && (ins[31:7] == 25'b0);
    wire is_mret = is_sys_inst && (ins[31:25] == 7'b0110000) && (ins[24:7] == 18'b0);


endmodule