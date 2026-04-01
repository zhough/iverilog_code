
module STORE(
    input [2:0] store_op,
    input [1:0] addr_low2,
    input [31:0] rs_data,
    output [31:0] ram_din,
    output [3:0] we
    );

reg [3:0] we_reg;
reg [31:0] ram_din_reg;
assign ram_din = ram_din_reg;
assign we = we_reg;
always @(*) begin
    case(addr_low2)
        2'b00: begin
            ram_din_reg = rs_data;
            case(store_op)
                3'b000: we_reg = 4'b0001;
                3'b001: we_reg = 4'b0011;
                3'b010: we_reg = 4'b1111;
                default: we_reg = 4'b0000;
            endcase 
        end
        2'b01: begin 
            ram_din_reg = {rs_data[23:0], 8'b0};
            case(store_op)
                3'b000: we_reg = 4'b0010;
                3'b001: we_reg = 4'b0110;
                default: we_reg = 4'b0000;
            endcase
        end 
        2'b10: begin
            ram_din_reg = {rs_data[15:0], 16'b0};
            case(store_op)
                3'b000: we_reg = 4'b0100;
                3'b001: we_reg = 4'b1100;
                default: we_reg = 4'b0000;
            endcase
        end
        2'b11: begin
            ram_din_reg = {rs_data[7:0], 24'b0};
            case(store_op)
                3'b000: we_reg = 4'b1000;
                default: we_reg = 4'b0000;
            endcase
        end
    endcase
end
endmodule
