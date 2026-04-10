module perip_bridge4 (
    input           clk,
    input           rst,
    input   [31:0]  perip_addr,
    input   [31:0]  perip_wdata,
    input           perip_wen,
    input   [2:0]   perip_mask,
    output  [31:0]  perip_rdata
);
    localparam DRAM_ADDR_START = 32'h0010_0000;
    localparam DRAM_ADDR_END   = 32'h8013_FFFF;
    localparam DRAM_ADDR_START1 = 32'h8010_0000;
    localparam DRAM_ADDR_END1   = 32'h8013_FFFF;
    localparam SW0_ADDR  = 32'h8020_0000;  // sw[31:0]
    localparam SW1_ADDR  = 32'h8020_0004;  // sw[63:32]
    localparam KEY_ADDR  = 32'h8020_0010;  // key[7:0]
    localparam SEG_ADDR  = 32'h8020_0020;  // seg
    localparam LED_ADDR  = 32'h8020_0040;  // led[31:0]
    localparam CNT_ADDR  = 32'h8020_0050;  // counter

    reg [31:0] LED; //模拟LED
    reg [31:0] SEG; //模拟SEG
    wire [31:0] dram_rdata;
    wire [31:0] cnt_rdata;

    dram4 u_dram(
        .a (perip_addr),
        .d (perip_wdata),
        .clk (clk),
        // .we (perip_wen & (perip_addr >= DRAM_ADDR_START && perip_addr < DRAM_ADDR_END)),
        .we (perip_wen),
        .mask (perip_mask),
        .spo (dram_rdata)
    );

    counter4 u_counter(
        .clk (clk),
        .rst (rst),
        .perip_wdata (perip_wdata),
        .cnt_wen (perip_wen & (perip_addr == CNT_ADDR)),
        .perip_rdata (cnt_rdata)    
    );

    // assign perip_rdata = (perip_addr == CNT_ADDR) ? cnt_rdata :
    //                     (perip_addr >= DRAM_ADDR_START && perip_addr < DRAM_ADDR_END) ? dram_rdata :
    //                     32'b0;
    assign perip_rdata = dram_rdata;
endmodule