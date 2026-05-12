module btb_target(
    input               clk,
    input       [5:0]   a,
    input       [31:0]  d,
    input               we,
    input       [5:0]   dpra,
    output      [31:0]  dpo
);
    reg [31:0]  mem [0:63];
    
    always @(posedge clk) begin
        if (we) begin 
            mem[a] <= d;
        end
    end
    initial begin: init_cache
        integer i;
        for(i=0; i<64; i=i+1) begin
            mem[i] = 32'b0;
        end
    end
    assign dpo = mem[dpra];
endmodule