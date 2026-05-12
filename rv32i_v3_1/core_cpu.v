`timescale 1ns / 1ns
module core_cpu (
    input           cpu_rst,
    input           cpu_clk,
    output [31:0]   irom_addr,
    input  [31:0]   irom_data,
    output [31:0]   perip_addr,
    output          perip_wen,
    output [2:0]    perip_mask,
    output [31:0]   perip_wdata,
    input  [31:0]   perip_rdata,
    input           hit,
    input  [31:0]   cache_rdata
);
    //外部接口
    wire rst_n = ~cpu_rst;
    wire clk = cpu_clk;
    //寄存器组
    reg [31:0] rs [31:0];


endmodule