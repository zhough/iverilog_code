`timescale 1ns/100ps
module dram_tb;

/*iverilog */
initial
begin            
    $dumpfile("wave.vcd");        //生成的vcd文件名称
    $dumpvars(0, dram_tb);    //tb模块名称
end
/*iverilog */

initial begin
    # 10000;  // 跑 10000 个时间单位后停止
    $stop;   // 仿真停止
end


parameter SYSCLK_PERIOD = 10;
reg clk;
reg [31:0] a, d;
reg we;
reg [1:0] mask;
wire [31:0] spo;

initial begin
    clk = 1'b0;  // 初始值
    a = 32'b0;
    d = 32'b0;
    we = 1'b0;
    mask = 2'b0;
    count = 32'b0;
    forever begin  // 永久循环
        #(SYSCLK_PERIOD/2) clk = ~clk;
    end
end

dram u_dram(
    .a (a),
    .d (d),
    .clk (clk),
    .we (we),
    .mask (mask),
    .spo (spo)
);

reg [31:0] count;
always @(posedge clk) begin
    count <= count + 1;
    if (count == 32'd1) begin
        a <= 32'd12;
        we <= 1'b0;
        d <= 32'b0;
        mask <= 2'b01;
    end
    else if (count == 32'd2) begin
        a <= 32'd16;
        we <= 1'b1;
        d <= 32'h1234567;
        mask <= 2'b01;
    end
    else if (count == 32'd3) begin
        a <= 32'd16;
        we <= 1'b0;
        d <= 32'b0;
        mask <= 2'b0;
    end
    else begin
        a <= a + 1;
    end
end

endmodule