module CSRU(
    input               clk,
    input               rst_n,
    input               csru_en,
    input       [3:0]   op,
    input       [31:0]  pc,
    input       [31:0]  src1,
    input       [31:0]  src2,
    input       [4:0]   rd_id,
    input       [31:0]  csrreg_in,

    output  reg [31:0]  csrreg_out,
    output  reg         csru_done,
    output  reg         csrreg_wb_en,
    output  reg [31:0]  wb_result,

    output  reg         csr_redirect_en,
    output  reg [31:0]  csr_redirect_target
);

    always @(*) begin
        case (op)
            
        endcase 
    end

endmodule