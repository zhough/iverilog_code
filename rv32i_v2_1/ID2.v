module ID2(
    input       [31:0]      ins,
    input       [4:0]       rd_ex,
    input       [4:0]       rd_mem,
    input       [4:0]       rd_mem2,
    input       [4:0]       rd_mem3,
    input                   rd_en_ex,
    input                   rd_en_mem,
    input                   rd_en_mem2,
    input                   rd_en_mem3,
    input                   is_load_ex,
    input                   is_load_mem,
    input                   is_load_mem2,
    input                   hit_mem,
    input                   hit_mem2,
    input       [31:0]      rs1,
    input       [31:0]      rs2,
    input       [31:0]      bypass_ex,
    input       [31:0]      bypass_mem,
    input       [31:0]      bypass_mem2,
    input       [31:0]      bypass_mem3,
    input       [31:0]      pc,
    output      reg             jump_taken,
    output      reg             branch_taken,
    output      reg [31:0]      jump_target,
    output      reg [31:0]      branch_target,
    output      [4:0]       rs1_id2,
    output      [4:0]       rs2_id2
);

    wire [4:0]    rs1_id    = ins[19:15];
    wire [4:0]    rs2_id    = ins[24:20];
    assign rs1_id2 = rs1_id;
    assign rs2_id2 = rs2_id;
    wire [6:0]    opcode    = ins[6:0];
    wire [20:0] immj = {ins[31],ins[19:12],ins[20],ins[30:21],1'b0};
    wire [11:0] immi = ins[31:20]; 
    wire [12:0] immb = {ins[31],ins[7],ins[30:25],ins[11:8],1'b0}; 
    wire [2:0] funct3 = ins[14:12];

    wire    RAW1_ex, RAW1_mem, RAW1_mem2, RAW1_mem3;
    wire    RAW2_ex, RAW2_mem, RAW2_mem2, RAW2_mem3;
    assign  RAW1_ex = (rd_ex == rs1_id) & rd_en_ex & (~is_load_ex) & (rs1_id != 5'b0);
    assign  RAW2_ex = (rd_ex == rs2_id) & rd_en_ex & (~is_load_ex) & (rs2_id != 5'b0);
    assign  RAW1_mem = (rd_mem == rs1_id) & rd_en_mem & (~is_load_mem | hit_mem) & (rs1_id != 5'b0);
    assign  RAW2_mem = (rd_mem == rs2_id) & rd_en_mem & (~is_load_mem | hit_mem) & (rs2_id != 5'b0);
    assign  RAW1_mem2 = (rd_mem2 == rs1_id) & rd_en_mem2 & (~is_load_mem2 | hit_mem2) & (rs1_id != 5'b0);
    assign  RAW2_mem2 = (rd_mem2 == rs2_id) & rd_en_mem2 & (~is_load_mem2 | hit_mem2) & (rs2_id != 5'b0);
    assign  RAW1_mem3 = (rd_mem3 == rs1_id) & rd_en_mem3 & (rs1_id != 5'b0);
    assign  RAW2_mem3 = (rd_mem3 == rs2_id) & rd_en_mem3 & (rs2_id != 5'b0);

    wire    [31:0] a =  RAW1_ex   ?  bypass_ex   :
                        RAW1_mem  ?  bypass_mem  :
                        RAW1_mem2 ?  bypass_mem2 :
                        RAW1_mem3 ?  bypass_mem3 :
                        rs1;
    wire    [31:0] b =  RAW2_ex   ?  bypass_ex   : 
                        RAW2_mem  ?  bypass_mem  :
                        RAW2_mem2 ?  bypass_mem2 :
                        RAW2_mem3 ?  bypass_mem3 :
                        rs2;

    always @(*) begin
        case (opcode)
            7'b1101111: begin
                jump_taken = 1'b1;
                jump_target = pc + {{11{immj[20]}},immj};
                branch_taken = 1'b0;
                branch_target = 32'b0;
            end
            7'b1100111: begin
                jump_taken = 1'b1;
                jump_target = (a + {{20{immi[11]}},immi}) & 32'hFFFFFFFE;
                branch_taken = 1'b0;
                branch_target = 32'b0;
            end
            7'b1100011: begin
                branch_target = pc + {{19{immb[12]}},immb};
                jump_taken = 1'b0;
                jump_target = 32'b0;
                case (funct3)
                    3'b000: branch_taken = (a == b);
                    3'b001: branch_taken = (a != b);
                    3'b100: branch_taken = ($signed(a) < $signed(b));
                    3'b101: branch_taken = ($signed(a) >= $signed(b));
                    3'b110: branch_taken = (a < b);
                    3'b111: branch_taken = (a >= b);
                    default: branch_taken = 1'b0;
                endcase 
            end
            default: begin
                jump_taken = 1'b0;
                jump_target = 32'b0;
                branch_taken = 1'b0;
                branch_target = 32'b0;
            end
        endcase
    end
endmodule