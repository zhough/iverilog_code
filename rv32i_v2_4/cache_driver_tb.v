`timescale 1ns / 1ns
module cache_driver_tb;
    
    reg                 clk;
    reg                 rst;
    reg     [31:0]      perip_addr;
    reg     [31:0]      perip_wdata;
    reg                 perip_wen;
    reg     [2:0]       perip_mask;
    wire    [31:0]      perip_rdata;
    wire                hit;
    wire    [31:0]      cache_rdata;

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

    perip_bridge perip_bridge_inst(
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

    reg     [15:0]  count;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            perip_addr <= 32'b0;
            perip_wdata <= 32'b0;
            perip_wen <= 1'b0;
            perip_mask <= 3'b111;
            count <= 16'b0;
        end else begin
            count <= count + 1;
            case (count)
                32'd1: begin
                    perip_addr <= 32'h8010_0000 + 32'd12;
                    perip_wdata <= 32'b1;
                    perip_wen <= 1'b0;
                    perip_mask <= 3'b000;
                end
                32'd2: begin
                    perip_addr <= 32'b0;
                    perip_wdata <= 32'b0;
                    perip_wen <= 1'b0;
                    perip_mask <= 3'b111;
                end
                32'd3: begin
                    perip_addr <= 32'b0;
                    perip_wdata <= 32'b0;
                    perip_wen <= 1'b0;
                    perip_mask <= 3'b111;
                end
                32'd4: begin
                    perip_addr <= 32'b0;
                    perip_wdata <= 32'b0;
                    perip_wen <= 1'b0;
                    perip_mask <= 3'b111;
                end
                32'd5: begin
                    perip_addr <= 32'h8010_0000;
                    perip_wdata <= 32'h13141413;
                    perip_wen <= 1'b1;
                    perip_mask <= 3'b010;
                end
                32'd6: begin
                    perip_addr <= 32'h8010_0000;
                    perip_wdata <= 32'b0;
                    perip_wen <= 1'b0;
                    perip_mask <= 3'b010;
                end
                32'd7: begin
                    perip_addr <= 32'h8010_0000 + 32'd12;
                    perip_wdata <= 32'b0;
                    perip_wen <= 1'b0;
                    perip_mask <= 3'b000;
                end
                default: begin
                    perip_addr <= 32'b0;
                    perip_wdata <= 32'b0;
                    perip_wen <= 1'b0;
                    perip_mask <= 3'b111;
                end
            endcase 
        end
    end

    /*iverilog */
    initial
    begin            
        $dumpfile("wave.vcd");        //生成的vcd文件名称
        $dumpvars(0, cache_driver_tb);    //tb模块名称
    end
    /*iverilog */

    initial begin
        # 10000;  //
        $stop;   // 仿真停止
    end
endmodule