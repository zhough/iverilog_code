module CDB(
    input           wb_en_ex,
    input   [31:0]  wb_result_ex,
    input   [4:0]   wb_id_ex,

    output          cdb_en,
    output  [31:0]  cdb_result,
    output  [4:0]   cdb_id
);

    assign  cdb_en   = wb_en_ex;
    assign  cdb_result = wb_result_ex;
    assign  cdb_id = wb_id_ex;

endmodule