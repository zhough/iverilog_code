module BTB(
    input               clk,
    input               rst_n,
    input   [31:0]      pc_if,
    input               update_en,
    input               clear_en,
    input   [31:0]      update_pc,
    input   [31:0]      update_target,
    output              pred_hit,
    output  [31:0]      pred_target

);

    parameter ENTRIES = 64;

    reg         valid [0:ENTRIES-1];
    wire    [31:0]  target;
    wire    [5:0]   tag;

    wire [5:0]  idx_if = pc_if[7:2];
    wire [5:0]  tag_if = pc_if[13:8];

    assign pred_hit = (tag_if == tag) && valid[idx_if];
    assign pred_target = target;
    
    //更新
    wire [5:0] update_idx = update_pc[7:2];

    always @(posedge clk or negedge rst_n) begin
        if (~rst_n) begin: rst_btb
            integer i;
            for (i=0; i<ENTRIES; i=i+1) begin
                valid[i] <= 1'b0;
            end
        end else begin
            if (clear_en) begin
                valid[update_idx] <= 1'b0;
            end else if (update_en) begin
                valid[update_idx] <= 1'b1;
            end
        end    
    end

    btb_target btb_target_inst(
        .clk        (clk),
        .a          (update_idx),
        .d          (update_target),
        .we         (update_en || clear_en),
        .dpra       (idx_if),
        .dpo        (target)
    );
    
    btb_tag btb_tag_inst(
        .clk        (clk),
        .a          (update_idx),
        .d          (update_pc[13:8]),
        .we         (update_en || clear_en),
        .dpra       (idx_if),
        .dpo        (tag)
    );
endmodule