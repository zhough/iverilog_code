module LOAD(
    input [2:0] load_op,
    input [31:0] load_data_in,
    input [1:0] addr_low2, 
    output [31:0] load_data_out
);
reg [31:0] load_data_out_reg;
assign load_data_out = load_data_out_reg;
always @(*) begin
    // case(load_op)
    //     3'b000: load_data_out_reg = {{24{load_data_in[7]}}, load_data_in[7:0]};
    //     3'b001: load_data_out_reg = {{16{load_data_in[15]}}, load_data_in[15:0]};
    //     3'b010: load_data_out_reg = load_data_in;
    //     3'b100: load_data_out_reg = {24'b0, load_data_in[7:0]};
    //     3'b101: load_data_out_reg = {16'b0, load_data_in[15:0]};
    //     default: load_data_out_reg = 32'b0;
    // endcase 
    case({addr_low2,load_op})
        //对齐4字节
        5'b00000: load_data_out_reg = {{24{load_data_in[7]}}, load_data_in[7:0]};
        5'b00001: load_data_out_reg = {{16{load_data_in[15]}}, load_data_in[15:0]};
        5'b00010: load_data_out_reg = load_data_in;
        5'b00100: load_data_out_reg = {24'b0, load_data_in[7:0]};
        5'b00101: load_data_out_reg = {16'b0, load_data_in[15:0]};
        //32位内1字节
        5'b01000: load_data_out_reg = {{24{load_data_in[15]}}, load_data_in[15:8]};
        5'b01001: load_data_out_reg = {{16{load_data_in[24]}}, load_data_in[23:8]};
        5'b01100: load_data_out_reg = {24'b0, load_data_in[15:8]};
        5'b01101: load_data_out_reg = {16'b0, load_data_in[23:8]};
        //32位2字节
        5'b10000: load_data_out_reg = {{24{load_data_in[23]}}, load_data_in[23:16]};
        5'b10001: load_data_out_reg = {{16{load_data_in[31]}}, load_data_in[31:16]};
        5'b10100: load_data_out_reg = {24'b0, load_data_in[23:16]};
        5'b10101: load_data_out_reg = {16'b0, load_data_in[31:16]};
        //32位3字节
        5'b11000: load_data_out_reg = {{24{load_data_in[31]}}, load_data_in[31:24]};
        5'b11100: load_data_out_reg = {24'b0, load_data_in[31:24]};
        default: load_data_out_reg = 32'b0;
    endcase 
end

endmodule