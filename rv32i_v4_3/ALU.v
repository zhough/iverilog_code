module ALU(
    input               clk,
    input               rst_n,
    input       [3:0]   alu_op,
    input       [31:0]  src1,
    input       [31:0]  src2,
    input               alu_en,
    input       [4:0]   dest_regid_in,
    
    output  reg         alu_done,
    output  reg [31:0]  alu_result,
    output  reg [4:0]   dest_regid_out
);

    reg [31:0] result;
    always @(*) begin
        case(alu_op)
            4'b0001 : result = src1 + src2;   //加
            4'b0010 : result = src1 - src2;   //减
            4'b0011 : result = src1 & src2;   //按位与
            4'b0100 : result = src1 | src2;   //按位或
            4'b0101 : result = src1 ^ src2;   //按位异或
            4'b0110 : result = src1 << src2[4:0];     //逻辑左移
            4'b0111 : result = src1 >> src2[4:0];     //逻辑右移
            4'b1000 : result = $signed(src1) >>> src2[4:0];   //有符号数算术右移
            4'b1001 : result = ($signed(src1) < ($signed(src2))) ? 32'b1 : 32'b0;   //有符号数比较小于
            4'b1010 : result = (src1 < src2) ? 32'b1 : 32'b0;   //无符号数比较小于
            4'b1011 : result = (src1 == src2) ?  32'b1 : 32'b0;
            4'b1100 : result = (src1 != src2) ?  32'b1 : 32'b0;
            4'b1101 : result = ($signed(src1) >= ($signed(src2))) ? 32'b1 : 32'b0; //有符号数比较大于等于
            4'b1110 : result = (src1 >= src2) ? 32'b1 : 32'b0;    //无符号数比较大于等于
            default : result = 32'b0;
        endcase
    end

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            alu_done <= 1'b0;
            alu_result <= 32'b0;
            dest_regid_out <= 32'b0;
        end else begin
            alu_done <= alu_en;
            alu_result <= result;
            dest_regid_out <= dest_regid_in;
        end
    end
endmodule