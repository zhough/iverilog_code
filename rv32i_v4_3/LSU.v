module LSU(
    input                   clk,
    input                   rst_n,
    input                   lsu_en,
    input       [3:0]       lsu_op,
    input       [31:0]      src1,
    input       [31:0]      src2,
    input       [31:0]      imm,
    input       [4:0]       dest_regid_in,
    
    input       [31:0]      perip_rdata,
    input                   cache_hit,
    input       [31:0]      cache_rdata,

    // 组合逻辑输出
    output  reg [31:0]      addr,
    output  reg [31:0]      wdata,
    output  reg             wen,
    output  reg [2:0]       mask,

    output  reg [4:0]       dest_regid_out,    
    output  reg             lsu_done,
    output  reg             wb_en,
    output  reg [31:0]      wb_result,
    output                  lsu_busy,

    output  reg [4:0]       CCB_id,
    output  reg             CCB_en,
    output  reg [31:0]      CCB_data
);

    reg cnt0,cnt1,cnt2;
    reg [4:0] dest_regid_in1, dest_regid_in2,dest_regid_in3;

    wire load_en;
    assign load_en = lsu_en && lsu_op[3];

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            cnt0 <= 1'b0;
            cnt1 <= 1'b0;
            cnt2 <= 1'b0;
            dest_regid_in1 <= 5'b0;
            dest_regid_in2 <= 5'b0;
            dest_regid_in3 <= 5'b0;
        end else begin
            dest_regid_in1 <= dest_regid_in;
            dest_regid_in2 <= dest_regid_in1;
            dest_regid_in3 <= dest_regid_in2;
            cnt0 <= load_en;
            if (cache_hit) begin
                cnt1 <= 1'b0;
            end else begin
                cnt1 <= cnt0;
            end
            cnt2 <= cnt1;
        end
    end

    assign lsu_busy = cnt1;
    
    always @(*) begin
        addr = src1 + imm;
        wdata = src2;
        mask = lsu_en ? lsu_op[2:0]: 3'b111;
        wen = lsu_en && !lsu_op[3];
        CCB_en = cnt0 && cache_hit;
        // CCB_en = 1'b0;
        CCB_id = dest_regid_in1;
        CCB_data = cache_rdata;
        // dest_regid_out = (cnt0 && cache_hit) ? dest_regid_in1: dest_regid_in3;
        // lsu_done = (cnt0 && cache_hit) || cnt2;
        // wb_en = (cnt0 && cache_hit) || cnt2;
        // wb_result = (cnt0 && cache_hit) ? cache_rdata: perip_rdata;
    end
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            dest_regid_out <= 5'b0;
            lsu_done <= 1'b0;
            wb_en <= 1'b0;
            wb_result <= 32'b0;
        end else begin
            dest_regid_out <= (cnt0 && cache_hit) ? dest_regid_in1: dest_regid_in3;
            lsu_done <= (cnt0 && cache_hit) || cnt2;
            wb_en <= (cnt0 && cache_hit) || cnt2;
            wb_result <= (cnt0 && cache_hit) ? cache_rdata: perip_rdata;
        end
    end
    
endmodule