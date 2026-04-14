`timescale 1ns / 1ns
module perip_bridge (
    input           clk,
    input           rst,
    input   [31:0]  perip_addr,
    input   [31:0]  perip_wdata,
    input           perip_wen,
    input   [2:0]   perip_mask,
    output  [31:0]  perip_rdata
);
    localparam DRAM_ADDR_START = 32'h8010_0000;
    localparam DRAM_ADDR_END   = 32'h8013_FFFF;
    localparam DRAM_ADDR_START1 = 32'h8010_0000;
    localparam DRAM_ADDR_END1   = 32'h8013_FFFF;
    localparam SW0_ADDR  = 32'h8020_0000;  // sw[31:0]
    localparam SW1_ADDR  = 32'h8020_0004;  // sw[63:32]
    localparam KEY_ADDR  = 32'h8020_0010;  // key[7:0]
    localparam SEG_ADDR  = 32'h8020_0020;  // seg
    localparam LED_ADDR  = 32'h8020_0040;  // led[31:0]
    localparam CNT_ADDR  = 32'h8020_0050;  // counter


    wire [31:0] dram_rdata;
    wire [31:0] cnt_rdata;

    reg [31:0] perip_addr_reg;
    reg [31:0] perip_addr_reg2;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            perip_addr_reg <= 32'b0;
            perip_addr_reg2 <= 32'b0;
        end else
            perip_addr_reg <= perip_addr;
            perip_addr_reg2 <= perip_addr_reg;
    end

    dram_driver dram_driver_inst (
        .clk            (clk),
        .rst            (rst),
        .addr           (perip_addr),
        .din            (perip_wdata),
        .mask           (perip_mask),
        .wen            (perip_wen & (perip_addr >= DRAM_ADDR_START && perip_addr < DRAM_ADDR_END)),
        // .wen            (perip_wen),
        .dout           (dram_rdata)
    );

    counter u_counter(
        .clk (clk),
        .rst (rst),
        .perip_wdata (perip_wdata),
        .cnt_wen (perip_wen & (perip_addr == CNT_ADDR)),
        .perip_rdata (cnt_rdata)    
    );

    //模拟seg
    reg [31:0] sim_seg;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            sim_seg <= 32'b0;
        end else begin
            if(perip_addr == SEG_ADDR && perip_wen) begin
                sim_seg <= perip_wdata;
            end
        end
    end

    assign perip_rdata = (perip_addr_reg2 == CNT_ADDR) ? cnt_rdata :
                        (perip_addr_reg2 >= DRAM_ADDR_START && perip_addr_reg2 < DRAM_ADDR_END) ? dram_rdata :
                        (perip_addr_reg2 == SEG_ADDR) ? sim_seg :
                        32'b0;
    // assign perip_rdata =  (perip_addr == CNT_ADDR) ? cnt_rdata : dram_rdata;
endmodule