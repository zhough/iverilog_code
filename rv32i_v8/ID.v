`timescale 1ns / 1ns
module ID (
    input    [31:0]        ins1,
    input    [31:0]        ins2,
    input    [31:0]        ins3,
    output   reg           alu_src,
    output   reg [3:0]     alu_op,
    output   reg [31:0]    imm,

    output   reg            jump_en,
    output   reg            branch_en,
    output   reg            is_lui,
    output   reg            is_auipc,
    output   reg            is_jalr,
    output   reg            rd_en,
    output   reg [2:0]      load_op,
    output   reg [2:0]      store_op,
    output       [4:0]      rs1,
    output       [4:0]      rs2,
    output       [4:0]      rd,
    output   reg            rs2_en,
    output   reg            rs1_en
);

//ins1控制alu_src, alu_op, is_auipc, is_lui, load_op, store_op,
//ins2控制imm
//ins3控制rd_en, rs2_en, rs1_en, is_jalr, jump_en, branch_en, rd, rs1, rs2,

wire [6:0] opcode1 = ins1[6:0];
wire [6:0] opcode2 = ins2[6:0];
wire [6:0] opcode3 = ins3[6:0];

wire [2:0] funct3 = ins1[14:12];
wire [6:0] funct7 = ins1[31:25];

wire [11:0] immi = ins2[31:20];     // I型指令立即数
wire [11:0] imms = {ins2[31:25],ins2[11:7]};      //S型指令立即数
wire [12:0] immb = {ins2[31],ins2[7],ins2[30:25],ins2[11:8],1'b0};  //B型指令立即数
wire [19:0] immu = ins2[31:12];      //U型指令立即数
wire [20:0] immj = {ins2[31],ins2[19:12],ins2[20],ins2[30:21],1'b0};    //J型指令立即数
assign rd = ins3[11:7];     //目标寄存器地址
assign rs1 = ins3[19:15];   //地址
assign rs2 = ins3[24:20];   //地址

    always @(*) begin
        case (opcode1)
            7'b0110011: begin
                alu_src = 1'b0;
                is_auipc = 1'b0;
                is_lui = 1'b0;
                load_op = 3'b111;
                store_op = 3'b111;
                case ({funct7, funct3})
                    10'b0000000000: alu_op = 4'b0001;  //ADD
                    10'b0100000000: alu_op = 4'b0010;  //SUB
                    10'b0000000111: alu_op = 4'b0011;  //and
                    10'b0000000110: alu_op = 4'b0100;  //or
                    10'b0000000100: alu_op = 4'b0101;  //xor
                    10'b0000000001: alu_op = 4'b0110;  //SLL
                    10'b0000000101: alu_op = 4'b0111;  //SRL
                    10'b0100000101: alu_op = 4'b1000;  //SRA
                    10'b0000000010: alu_op = 4'b1001;  //SLT
                    10'b0000000011: alu_op = 4'b1010;  //SLTU      
                    default: alu_op = 4'b0;          
                endcase
            end

            7'b0010011: begin
                alu_src = 1'b1;
                is_auipc = 1'b0;
                is_lui = 1'b0;
                load_op = 3'b111;
                store_op = 3'b111;
                case (funct3)
                    3'b000: alu_op = 4'b0001;  //ADDI
                    3'b010: alu_op = 4'b1001;  //SLTI
                    3'b011: alu_op = 4'b1010;  //SLTIU 
                    3'b100: alu_op = 4'b0101;  //XORI
                    3'b110: alu_op = 4'b0100;  //ORI
                    3'b111: alu_op = 4'b0011;  //ANDI
                    3'b001: alu_op = (funct7==7'b0000000) ? 4'b0110 : 4'b0000;  //SLLI
                    3'b101: alu_op = (funct7==7'b0000000) ? 4'b0111 : (funct7==7'b0100000) ? 4'b1000 : 4'b0000; //SRLI or SRAI
                    default:alu_op = 4'b0000;   
                endcase      
            end

            7'b1100011: begin
                alu_src = 1'b0;
                is_auipc = 1'b0;
                is_lui = 1'b0;
                load_op = 3'b111;
                store_op = 3'b111;
                case (funct3)
                    3'b000: alu_op = 4'b1011;  //BEQ
                    3'b001: alu_op = 4'b1100;  //BNE
                    3'b100: alu_op = 4'b1001;  //BLT
                    3'b101: alu_op = 4'b1101;  //BGE
                    3'b110: alu_op = 4'b1010;  //BLTU
                    3'b111: alu_op = 4'b1110;  //BGEU
                    default: alu_op = 4'b0000;
                endcase      
            end

            7'b1101111: begin //JAL
                alu_src = 1'b1;
                is_auipc = 1'b0;
                is_lui = 1'b0;
                alu_op = 4'b0;
                load_op = 3'b111;
                store_op = 3'b111;
            end

            7'b1100111: begin   //JALR
                alu_src = 1'b1;
                is_auipc = 1'b0;
                is_lui = 1'b0;
                alu_op = 4'b0;
                load_op = 3'b111;
                store_op = 3'b111;
            end

            7'b0110111: begin   //LUI
                alu_src = 1'b1;
                is_auipc = 1'b0;
                is_lui = 1'b1;
                alu_op = 4'b0;
                load_op = 3'b111;
                store_op = 3'b111;
            end

            7'b0010111: begin   //AUIPC
                alu_src = 1'b1;
                is_auipc = 1'b1;
                is_lui = 1'b0;
                alu_op = 4'b0;
                load_op = 3'b111;
                store_op = 3'b111;
            end

            7'b0000011: begin   //load
                alu_src = 1'b1;
                is_auipc = 1'b0;
                is_lui = 1'b0;
                alu_op = 4'b0001;
                load_op = funct3;
                store_op = 3'b111;
            end

            7'b0100011: begin   //store
                alu_src = 1'b1;
                is_auipc = 1'b0;
                is_lui = 1'b0;
                alu_op = 4'b0001;
                load_op = 3'b111;
                store_op = funct3;
            end
        
            default: begin
                alu_src = 1'b0;
                is_auipc = 1'b0;
                is_lui = 1'b0;
                alu_op = 4'b0000;
                load_op = 3'b111;
                store_op = 3'b111;
            end
        endcase
    end

    always @(*) begin
        case (opcode2)
            7'b0110011: imm = 32'b0;
            7'b0010011: imm = (funct3 == 3'b001 || funct3 == 3'b101) ? 
                                {27'd0, immi[4:0]}: {{20{immi[11]}}, immi};
            7'b1100011: imm = {{19{immb[12]}},immb};
            7'b1101111: imm = {{11{immj[20]}},immj};
            7'b1100111: imm = {{20{immi[11]}},immi};
            7'b0110111: imm = {immu, 12'd0};
            7'b0010111: imm = {immu, 12'd0};
            7'b0000011: imm = {{20{immi[11]}},immi};
            7'b0100011: imm = {{20{imms[11]}},imms};
            default: imm = 32'b0;
        endcase
    end

    //rd_en, rs2_en, rs1_en, is_jalr, jump_en, branch_en
    always @(*) begin
        case (opcode3) 
            7'b0110011: begin
                rd_en = 1'b1;
                rs2_en = 1'b1;
                rs1_en = 1'b1;
                is_jalr = 1'b0;
                jump_en = 1'b0;
                branch_en = 1'b0;
            end

            7'b0010011: begin
                rd_en = 1'b1;
                rs2_en = 1'b0;
                rs1_en = 1'b1;
                is_jalr = 1'b0;
                jump_en = 1'b0;
                branch_en = 1'b0;
            end

            7'b1100011: begin
                rd_en = 1'b0;
                rs2_en = 1'b1;
                rs1_en = 1'b1;
                is_jalr = 1'b0;
                jump_en = 1'b0;
                branch_en = 1'b1;
            end

            7'b1101111: begin
                rd_en = 1'b1;
                rs2_en = 1'b0;
                rs1_en = 1'b0;
                is_jalr = 1'b0;
                jump_en = 1'b1;
                branch_en = 1'b0;
            end

            7'b1100111: begin
                rd_en = 1'b1;
                rs2_en = 1'b0;
                rs1_en = 1'b1;
                is_jalr = 1'b1;
                jump_en = 1'b1;
                branch_en = 1'b0;
            end

            7'b0110111: begin
                rd_en = 1'b1;
                rs2_en = 1'b0;
                rs1_en = 1'b0;
                is_jalr = 1'b0;
                jump_en = 1'b0;
                branch_en = 1'b0;
            end
            
            7'b0010111: begin
                rd_en = 1'b1;
                rs2_en = 1'b0;
                rs1_en = 1'b0;
                is_jalr = 1'b0;
                jump_en = 1'b0;
                branch_en = 1'b0;
            end

            7'b0000011: begin
                rd_en = 1'b1;
                rs2_en = 1'b0;
                rs1_en = 1'b1;
                is_jalr = 1'b0;
                jump_en = 1'b0;
                branch_en = 1'b0;
            end

            7'b0100011: begin
                rd_en = 1'b0;
                rs2_en = 1'b1;
                rs1_en = 1'b1;
                is_jalr = 1'b0;
                jump_en = 1'b0;
                branch_en = 1'b0;
            end

            default: begin
                rd_en = 1'b0;
                rs2_en = 1'b0;
                rs1_en = 1'b0;
                is_jalr = 1'b0;
                jump_en = 1'b0;
                branch_en = 1'b0;
            end
        endcase
    end

endmodule