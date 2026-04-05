module dram (
    input  [31:0] a,
    input [31:0] d,
    input clk,
    input we,
    input [1:0] mask,
    output [31:0] spo
);

reg [31:0] mem [0:65535];
reg [31:0] din;
wire [15:0] addr;
wire [1:0] mask_addr;
// 仿真时自动加载 hex 文件
initial begin
    $readmemh("./hex/dram.hex", mem); // 你的机器码文件
end

// 0 延迟，组合逻辑读出
//读
assign addr = a[17:2];
assign mask_addr = a[1:0];
assign spo = mem[addr];    //外部逻辑控制读写的位数和符号扩展

always @(*) begin
    case ({mask,mask_addr})
        //单字节
        4'b0000: din <= {spo[31:8], d[7:0]};
        4'b0001: din <= {spo[31:16], d[7:0], spo[7:0]};
        4'b0010: din <= {spo[31:24], d[7:0], spo[15:0]};
        4'b0011: din <= {d[7:0], spo[23:0]};
        //双字节
        4'b0100: din <= {spo[31:16], d[15:0]};
        4'b0101: din <= {spo[31:24], d[15:0], spo[7:0]};
        4'b0110: din <= {d[15:0], spo[15:0]};
        //4字节
        4'b1000: din <= d;
        default: din <= d;
    endcase
end

always @(posedge clk) begin
    if (we == 1'b1) begin
        mem[addr] <= din;
    end
    else begin
        mem[addr] <= mem[addr];
    end
end 

endmodule