module dram4 (
    input  [31:0] a,
    input [31:0] d,
    input clk,
    input we,
    input [2:0] mask,
    output [31:0] spo
);

reg [31:0] mem [0:65535];
reg [31:0] din;
wire [15:0] addr;
wire [1:0] offset;
wire [31:0] tmp_output;
reg [31:0] spo_reg;
// 仿真时自动加载 hex 文件
initial begin
    $readmemh("../rv32i_v3/hex/dram.hex", mem); // 你的机器码文件
end
// initial begin: init_ram
//     integer i;
//     for(i=0; i<65536; i=i+1) begin
//         mem[i] = 32'hefefefef;  // 全部初始化为0
//     end
// end

// 0 延迟，组合逻辑读出
//读
assign addr = a[17:2];
assign offset = a[1:0];
assign tmp_output = mem[addr];
assign spo = spo_reg;

always @(*) begin
    case ({mask[1:0],offset})
        //单字节
        4'b0000: din <= {tmp_output[31:8], d[7:0]};
        4'b0001: din <= {tmp_output[31:16], d[7:0], tmp_output[7:0]};
        4'b0010: din <= {tmp_output[31:24], d[7:0], tmp_output[15:0]};
        4'b0011: din <= {d[7:0], tmp_output[23:0]};
        //双字节
        4'b0100: din <= {tmp_output[31:16], d[15:0]};
        4'b0101: din <= {tmp_output[31:24], d[15:0], tmp_output[7:0]};
        4'b0110: din <= {d[15:0], tmp_output[15:0]};
        //4字节
        4'b1000: din <= d;
        default: din <= d;
    endcase
end
//写
always @(posedge clk) begin
    if (we) begin
        mem[addr] <= din;
    end
end 

always @(*) begin
    case ({mask, offset}) 
        //无符号单字节
        5'b10000: spo_reg <= {24'b0, tmp_output[7:0]};
        5'b10001: spo_reg <= {24'b0, tmp_output[15:8]};
        5'b10010: spo_reg <= {24'b0, tmp_output[23:16]};
        5'b10011: spo_reg <= {24'b0, tmp_output[31:24]};
        //无符号双字节
        5'b10100: spo_reg <= {16'b0, tmp_output[15:0]};
        5'b10101: spo_reg <= {16'b0, tmp_output[23:8]};
        5'b10110: spo_reg <= {16'b0, tmp_output[31:16]};
        //四字节
        5'b01000: spo_reg <= tmp_output;
        //有符号单字节
        5'b00000: spo_reg <= {{24{tmp_output[7]}}, tmp_output[7:0]};
        5'b00001: spo_reg <= {{24{tmp_output[15]}}, tmp_output[15:8]};
        5'b00010: spo_reg <= {{24{tmp_output[23]}}, tmp_output[23:16]};
        5'b00011: spo_reg <= {{24{tmp_output[31]}}, tmp_output[31:24]};
        //有符号双字节
        5'b00100: spo_reg <= {{16{tmp_output[15]}}, tmp_output[15:0]};
        5'b00101: spo_reg <= {{16{tmp_output[23]}}, tmp_output[23:8]};
        5'b00110: spo_reg <= {{16{tmp_output[31]}}, tmp_output[31:16]};
        default: spo_reg <= 32'b0;
    endcase 
end
endmodule