module ID2(
    input   [31:0]  ins,
    output          jb_en
);

    wire [6:0]  opcode = ins[6:0];
    assign jb_en = (opcode == 7'b1101111) | (opcode == 7'b1100111) | (opcode == 7'b1100011);

endmodule