`timescale 1ns / 1ps
module core_cpu4_tb;
reg cpu_rst, cpu_clk;
initial begin 
    cpu_clk = 1'b0;
    forever begin
        #5 cpu_clk = ~cpu_clk;
    end
end
initial begin
    cpu_rst = 1;
    #6;
    cpu_rst = 0;
end

wire [12:0] pc_irom;
wire [31:0] irom_data, irom_addr, perip_addr, perip_wdata, perip_rdata;
wire [2:0] perip_mask;
wire perip_wen;
assign pc_irom = irom_addr[14:2];

irom4 u_irom(
    .a (pc_irom),
    .spo (irom_data)
);

core_cpu4 Core_CPU(
    .cpu_clk        (cpu_clk),
    .cpu_rst        (cpu_rst),
    .irom_addr      (irom_addr),
    .irom_data      (irom_data),
    .perip_addr     (perip_addr),
    .perip_wdata    (perip_wdata),
    .perip_wen      (perip_wen),
    .perip_mask     (perip_mask),
    .perip_rdata    (perip_rdata)
);

perip_bridge4 u_perip(
    .clk (cpu_clk),
    .rst (cpu_rst),
    .perip_addr (perip_addr),
    .perip_wdata (perip_wdata),
    .perip_wen (perip_wen),
    .perip_mask (perip_mask),
    .perip_rdata (perip_rdata)
);
    /*iverilog */
    initial
    begin            
        $dumpfile("wave.vcd");        //生成的vcd文件名称
        $dumpvars(0, core_cpu4_tb);    //tb模块名称
    end
    /*iverilog */

    initial begin
        # 1000000;  //
        $stop;   // 仿真停止
    end
endmodule