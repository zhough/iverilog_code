`timescale 1ns / 1ns
module top_tb ;

    reg rst, clk;

    initial begin
        rst = 0;
        #5;
        rst = 1;
        #5;
        rst = 0;
    end

    initial begin
        clk = 1'b0;
        forever begin
            #5 clk = ~clk;
        end
    end

    wire    [31:0]  perip_addr, perip_wdata, perip_rdata;
    wire    [2:0]   perip_mask;
    wire            peirp_wen;
    wire    [31:0]  cnt;

    top u_top (
        .clk            (clk),
        .rst            (rst),
        .perip_addr     (perip_addr),
        .perip_wdata    (perip_wdata),
        .perip_rdata    (perip_rdata),
        .perip_mask     (perip_mask),
        .perip_wen      (peirp_wen),
        .cnt            (cnt)
    );


    /*iverilog */
    initial
    begin            
        $dumpfile("wave.vcd");        //生成的vcd文件名称
        $dumpvars(0, top_tb);    //tb模块名称
    end
    /*iverilog */

    initial begin
        # 100000;  //
        $stop;   // 仿真停止
    end


endmodule