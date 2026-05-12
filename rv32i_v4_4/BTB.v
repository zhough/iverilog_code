module BTB(
    input               clk,
    input               rst_n,
    input   [31:0]      pc,
    input               update_en,
    input               clear_en,
    input   [31:0]      update_pc,
    input   [31:0]      update_target,
    output              pred_hit,
    output  [31:0]      pred_target,
    input               update_branch_en,
    input               update_branch_not_en

);

    parameter ENTRIES = 128;

    reg  [1:0] BHT [0:ENTRIES-1];

    reg         valid [0:ENTRIES-1];
    wire    [31:0]  target;
    wire    [4:0]   tag;

    wire [6:0]  idx_if = pc[8:2];
    wire [4:0]  tag_if = pc[13:9];

    wire    BHT_en = BHT[idx_if] == 2'b11 || BHT[idx_if] == 2'b10;
    assign pred_hit = (tag_if == tag) && valid[idx_if] && BHT_en;
    assign pred_target = target;
    
    //更新
    wire [6:0] update_idx = update_pc[8:2];

    always @(posedge clk or negedge rst_n) begin
        if (~rst_n) begin: rst_btb
            integer i;
            for (i=0; i<ENTRIES; i=i+1) begin
                valid[i] <= 1'b0;
                BHT[i] <= 2'b01;
            end
        end else begin
             if (update_branch_en) begin
                valid[update_idx] <= 1'b1;
                case(BHT[update_idx])
                    2'b00: BHT[update_idx] <= 2'b01;
                    2'b01: BHT[update_idx] <= 2'b10;
                    2'b10: BHT[update_idx] <= 2'b11;
                    2'b11: BHT[update_idx] <= 2'b11;
                endcase
            end else if (update_branch_not_en) begin
                case(BHT[update_idx]) 
                    2'b00: BHT[update_idx] <= 2'b00;
                    2'b01: BHT[update_idx] <= 2'b00;
                    2'b10: BHT[update_idx] <= 2'b01;
                    2'b11: BHT[update_idx] <= 2'b10;
                endcase
            end
        end    
    end

    btb_target btb_target_inst(
        .clk        (clk),
        .a          (update_idx),
        .d          (update_target),
        .we         (update_en),
        .dpra       (idx_if),
        .dpo        (target)
    );
    
    btb_tag btb_tag_inst(
        .clk        (clk),
        .a          (update_idx),
        .d          (update_pc[13:9]),
        .we         (update_en),
        .dpra       (idx_if),
        .dpo        (tag)
    );
endmodule
