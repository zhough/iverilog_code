
module STORE(
    input [2:0] store_op,
    input [31:0] rs_data,
    output [31:0] ram_din,
    output [1:0] mask
    );

assign ram_din = rs_data;
assign mask = mask_reg;

endmodule
