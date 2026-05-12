module cache_driver (
    input                   clk,
    input                   rst,
    input       [31:0]      addr,
    input       [31:0]      dram_rdata,
    input       [31:0]      wdata,
    input                   ren,
    input                   wen,
    input       [2:0]       mask,
    output  reg             hit,
    output  reg [31:0]      cache_rdata
);

    // reg     [7:0]   cache_tag       [0:255];
    reg             cache_valid     [0:255];
    wire    [7:0]   tag;
    wire            tag_we;
    wire    [7:0]   tag_in;
    wire    [7:0]   tag_a;

    assign tag_we = wen | cnt[0];
    assign tag_in = wen ? addr_tag:
                    cnt[0] ? addr_tag_reg: addr_tag;
    assign tag_a = wen ? addr_idx: 
                    cnt[0] ? addr_idx_reg: addr_idx; 

    reg             refill_wen;
    reg     [2:0]   cnt;
    wire    [7:0]   addr_tag   = addr[17:10];
    wire    [7:0]   addr_idx   = addr[9:2];
    wire    [1:0]   offset     = addr[1:0];

    reg     [7:0]   addr_tag_reg, addr_tag_reg2, addr_tag_reg3;
    reg     [7:0]   addr_idx_reg, addr_idx_reg2, addr_idx_reg3;    

    wire cache_hit = cache_valid[addr_idx] & (tag == addr_tag) & ren;
    
    always @(posedge clk or posedge rst) begin
        if (rst) begin: init_cache
            integer i;
            refill_wen <= 1'b0;
            for(i=0; i<256; i=i+1) begin
                cache_valid[i] <= 1'b0;
            end 
        end else begin
            refill_wen <= 1'b0;
            if (wen) begin
                if (~refill_wen) begin
                    cache_valid[addr_idx] <= 1'b1;
                    // cache_tag[addr_idx] <= addr_tag;
                end else begin
                    cache_valid[addr_idx] <= 1'b0;
                    // cache_tag[addr_idx] <= 8'b0;
                end
            end else if (cnt[0]) begin
                cache_valid[addr_idx_reg] <= 1'b1;
                // cache_tag[addr_idx_reg2] <= addr_tag_reg2;
                refill_wen <= 1'b1;
            end
        end
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            cnt <= 3'b0;
        end else begin
            cnt[1] <= cnt[0];
            cnt[2] <= cnt[1];
            if (ren & (~cache_hit) & (~wen)) begin
                cnt[0] <= 1'b1;
            end else begin
                cnt [0] <= 1'b0;
            end
        end
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            addr_tag_reg <= 8'b0;
            addr_tag_reg2 <= 8'b0;
            addr_tag_reg3 <= 8'b0;
            addr_idx_reg <= 8'b0;
            addr_idx_reg2 <= 8'b0;
            addr_idx_reg3 <= 8'b0;
        end else begin
            addr_tag_reg <= addr_tag;
            addr_tag_reg2 <= addr_tag_reg;
            addr_tag_reg3 <= addr_tag_reg2;
            addr_idx_reg <= addr_idx;
            addr_idx_reg2 <= addr_idx_reg;
            addr_idx_reg3 <= addr_idx_reg2;
        end
    end

    wire [7:0] cache_addr = refill_wen ? addr_idx_reg2 : addr_idx;
    reg [31:0] din;
    wire [31:0] cache_din = refill_wen ? dram_rdata : din;
    wire [31:0] cache_dout;
    reg [31:0] cache_rdata_reg;


    cache cache_inst(
        .clk            (clk),
        .a              (cache_addr),
        .d              (cache_din),
        .we             (refill_wen | wen),
        .dpra           (addr_idx),
        .dpo            (cache_dout)
    );

    cache_tag cache_tag_inst(
        .clk            (clk),
        .a              (tag_a),
        .d              (tag_in),
        .we             (tag_we),
        .dpra           (addr_idx),
        .dpo            (tag)
    );

    always @(*) begin
        case({offset, mask})
            5'b00000: din <= {cache_dout[31:8], wdata[7:0]};
            5'b01000: din <= {cache_dout[31:16], wdata[7:0], cache_dout[7:0]};
            5'b10000: din <= {cache_dout[31:24], wdata[7:0], cache_dout[15:0]};
            5'b11000: din <= {wdata[7:0], cache_dout[23:0]};

            5'b00001: din <= {cache_dout[31:16], wdata[15:0]};
            5'b10001: din <= {wdata[15:0], cache_dout[15:0]};

            5'b00010: din <= wdata;
            default: din <= wdata;
        endcase 
    end

    always @(*) begin
        case({offset, mask}) 
            5'b00000: cache_rdata_reg <= {{24{cache_dout[7]}},cache_dout[7:0]};
            5'b01000: cache_rdata_reg <= {{24{cache_dout[15]}}, cache_dout[15:8]};
            5'b10000: cache_rdata_reg <= {{24{cache_dout[23]}}, cache_dout[23:16]};
            5'b11000: cache_rdata_reg <= {{24{cache_dout[31]}}, cache_dout[31:24]};

            5'b00100: cache_rdata_reg <= {24'b0, cache_dout[7:0]};
            5'b01100: cache_rdata_reg <= {24'b0, cache_dout[15:8]};
            5'b10100: cache_rdata_reg <= {24'b0, cache_dout[23:16]};
            5'b11100: cache_rdata_reg <= {24'b0, cache_dout[31:24]};

            5'b00001: cache_rdata_reg <= {{16{cache_dout[15]}}, cache_dout[15:0]};
            5'b10001: cache_rdata_reg <= {{16{cache_dout[31]}}, cache_dout[31:16]};

            5'b00101: cache_rdata_reg <= {16'b0, cache_dout[15:0]};
            5'b10101: cache_rdata_reg <= {16'b0, cache_dout[31:16]};

            5'b00010: cache_rdata_reg <= cache_dout;
            default: cache_rdata_reg <= cache_dout;
        endcase
    end

    // always @(posedge clk or posedge rst) begin
    //     if (rst) begin
    //         cache_rdata <= 32'b0;
    //         hit  <= 1'b0;
    //     end else begin
    //         cache_rdata <= cache_rdata_reg;
    //         hit <= cache_hit;
    //     end
    // end
    
    always @(*) begin
        cache_rdata = cache_rdata_reg;
        hit = cache_hit;
    end
endmodule