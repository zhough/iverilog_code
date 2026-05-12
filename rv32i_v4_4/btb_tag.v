module btb_tag(
    input               clk,
    input       [6:0]   a,
    input       [4:0]   d,
    input               we,
    input       [6:0]   dpra,
    output      [4:0]   dpo
);
    reg [4:0]  mem [0:128];
    
    always @(posedge clk) begin
        if (we) begin 
            mem[a] <= d;
        end
    end
    initial begin: init_cache
        integer i;
        for(i=0; i<128; i=i+1) begin
            mem[i] = 5'b0;
        end
    end
    assign dpo = mem[dpra];
endmodule
