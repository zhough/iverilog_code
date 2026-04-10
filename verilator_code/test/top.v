module top(
    input               clk,
    input               rst,
    output  [31:0]      perip_addr,
    output  [31:0]      perip_wdata,
    output  [31:0]      perip_rdata,
    output  [2:0]       perip_mask,
    output              perip_wen
);

    wire    [12:0]  pc_irom;
    wire    [31:0]  irom_addr, irom_data;
    // wire    [31:0]  perip_addr, perip_wdata, perip_rdata;
    // wire    [2:0]   perip_mask;
    // wire            perip_wen;

    assign  pc_irom     = irom_addr[14:2];

    irom4 u_irom (
        .a              (pc_irom),
        .spo            (irom_data)
    );

    core_cpu4 Core_CPU (
        .cpu_clk        (clk),
        .cpu_rst        (rst),
        .irom_addr      (irom_addr),
        .irom_data      (irom_data),
        .perip_addr     (perip_addr),
        .perip_wdata    (perip_wdata),
        .perip_wen      (perip_wen),
        .perip_mask     (perip_mask),
        .perip_rdata    (perip_rdata)
    );

    perip_bridge4 u_perip (
        .clk            (clk),
        .rst            (rst),
        .perip_addr     (perip_addr),
        .perip_wdata    (perip_wdata),
        .perip_wen      (perip_wen),
        .perip_mask     (perip_mask),
        .perip_rdata     (perip_rdata)
    );

endmodule
