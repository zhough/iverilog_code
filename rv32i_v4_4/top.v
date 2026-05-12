`timescale 1ns / 1ns
module top(
    input               clk,
    input               rst,
    output  [31:0]      perip_addr,
    output  [31:0]      perip_wdata,
    output  [31:0]      perip_rdata,
    output  [2:0]       perip_mask,
    output              perip_wen,
    output  reg [31:0]  cnt,
    output      [63:0]  branch_count,
    output      [63:0]  pred_count
);

    wire    [12:0]  pc_irom;
    wire    [31:0]  irom_addr, irom_data;
    wire            hit;
    wire    [31:0]  cache_rdata;

    assign  pc_irom     = irom_addr[14:2];

    irom u_irom (
        .a              (pc_irom),
        .spo            (irom_data)
    );

    core_cpu Core_CPU (
        .cpu_clk        (clk),
        .cpu_rst        (rst),
        .irom_addr      (irom_addr),
        .irom_data      (irom_data),
        .perip_addr     (perip_addr),
        .perip_wdata    (perip_wdata),
        .perip_wen      (perip_wen),
        .perip_mask     (perip_mask),
        .perip_rdata    (perip_rdata),
        .hit            (hit),
        .cache_rdata    (cache_rdata),
        .branch_count   (branch_count),
        .pred_count     (pred_count)
    );

    perip_bridge u_perip (
        .clk            (clk),
        .rst            (rst),
        .perip_addr     (perip_addr),
        .perip_wdata    (perip_wdata),
        .perip_wen      (perip_wen),
        .perip_mask     (perip_mask),
        .perip_rdata    (perip_rdata),
        .hit            (hit),
        .cache_rdata    (cache_rdata) 
    );

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            cnt <= 32'b0;
        end else begin
            cnt <= cnt + 1;
        end
    end

endmodule
