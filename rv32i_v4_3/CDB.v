module CDB(
    input           rst_n,
    input           clk,
    input           wb_en_ex,
    input   [31:0]  wb_result_ex,
    input   [4:0]   wb_id_ex,

    output  reg         cdb_en,
    output  reg [31:0]  cdb_result,
    output  reg [4:0]   cdb_id
);

    always @(*) begin
        cdb_en <= wb_en_ex;
        cdb_result <= wb_result_ex;
        cdb_id <= wb_id_ex;  
    end
    // always @(posedge clk or negedge rst_n) begin
    //     if (!rst_n) begin
    //         cdb_en <= 1'b0;
    //         cdb_result <= 32'b0;
    //         cdb_id <= 5'b0;
    //     end else begin
    //         cdb_en <= wb_en_ex;
    //         cdb_result <= wb_result_ex;
    //         cdb_id <= wb_id_ex;
    //     end
    // end

endmodule