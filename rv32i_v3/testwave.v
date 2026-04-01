`timescale 1ns/100ps
module testwave;

/*iverilog */
initial
begin            
    $dumpfile("wave.vcd");        //生成的vcd文件名称
    $dumpvars(0, testwave);    //tb模块名称
end
/*iverilog */

initial begin
    # 10000;  // 跑 10000 个时间单位后停止
    $stop;   // 仿真停止
end

parameter SYSCLK_PERIOD = 10;

reg [12:0] addr;
wire [31:0] ins;
reg clk;

irom uirom(
    .a (addr),
    .spo (ins)
);

initial begin
    clk = 1'b0;  // 初始值
    addr = 13'b0;
    forever begin  // 永久循环
        #(SYSCLK_PERIOD/2) clk = ~clk;
    end
end

always @(posedge clk) begin
    addr <= addr + 1;
end

endmodule