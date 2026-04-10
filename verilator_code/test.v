module test(
    input               clk,
    input               rst_n,
    output  reg [3:0]   cnt
);
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            cnt <= 4'b0;
        end else begin
            cnt <= cnt + 1;
        end
    end

endmodule
