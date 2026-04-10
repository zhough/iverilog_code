module counter4 (
    input           clk,
    input           rst,
    input   [31:0]  perip_wdata,
    input           cnt_wen,
    output  [31:0]  perip_rdata
);

    reg start;
    reg [15:0]  cnt_1ms;
    reg [31:0]  cnt_ms;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            start <= 1'b0;
        end else if (cnt_wen & perip_wdata == 32'h8000_0000) begin
            start <= 1'b1;
        end else if (cnt_wen & perip_wdata == 32'hFFFF_FFFF) begin
            start <= 1'b0;
        end
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            cnt_1ms <= 0;
        end else if (start) begin
            if (cnt_1ms == 49999) begin
                cnt_1ms <= 0;
            end else begin
                cnt_1ms <= cnt_1ms + 1;
            end
        end else begin
            cnt_1ms <= 0;
        end            
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            cnt_ms <= 0;
        end else if (start && cnt_1ms == 49999) begin
            cnt_ms <= cnt_ms + 1;
        end
    end

    assign perip_rdata = cnt_ms;

endmodule