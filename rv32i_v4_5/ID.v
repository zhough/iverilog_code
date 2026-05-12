module ID(
    input          [31:0]  inst,

    output  reg    [3:0]   ex_tag,
    output  reg    [4:0]   rs1_addr,
    output  reg    [4:0]   rs2_addr,
    output  reg    [4:0]   rd_addr,
    output  reg            alu_src1_ispc, //操作数1为pc或者寄存器
    output  reg            alu_src2_isimm, //操作数2为寄存器或者立即数
    output  reg    [31:0]  imm,
    output  reg    [3:0]   op,
    output         [11:0]  csrreg_addr
);

    wire [6:0] opcode = inst[6:0];
    wire [2:0] funct3 = inst[14:12];
    wire [6:0] funct7 = inst[31:25];
    wire [11:0] immi = inst[31:20];     // I型指令立即数
    wire [11:0] imms = {inst[31:25],inst[11:7]};      //S型指令立即数
    wire [12:0] immb = {inst[31],inst[7],inst[30:25],inst[11:8],1'b0};  //B型指令立即数
    wire [19:0] immu = inst[31:12];      //U型指令立即数
    wire [20:0] immj = {inst[31],inst[19:12],inst[20],inst[30:21],1'b0};    //J型指令立即数
    wire [4:0]  immcsr = inst[19:15];
    assign  csrreg_addr = immi;

    //rstation_tag, op
    always @(*) begin
        case (opcode)
            7'b0110011: begin   //R type
                ex_tag = 4'b0;
                case ({funct7,funct3})
                    10'b0000000000: op = 4'b0001;  //ADD
                    10'b0100000000: op = 4'b0010;  //SUB
                    10'b0000000111: op = 4'b0011;  //and
                    10'b0000000110: op = 4'b0100;  //or
                    10'b0000000100: op = 4'b0101;  //xor
                    10'b0000000001: op = 4'b0110;  //SLL
                    10'b0000000101: op = 4'b0111;  //SRL
                    10'b0100000101: op = 4'b1000;  //SRA
                    10'b0000000010: op = 4'b1001;  //SLT
                    10'b0000000011: op = 4'b1010;  //SLTU
                    default : op = 4'b0;
                endcase             
            end
            7'b0010011: begin   //I type
                ex_tag = 4'b0;
                case (funct3)
                    3'b000: op = 4'b0001;  //ADDI
                    3'b010: op = 4'b1001;  //SLTI
                    3'b011: op = 4'b1010;  //SLTIU 
                    3'b100: op = 4'b0101;  //XORI
                    3'b110: op = 4'b0100;  //ORI
                    3'b111: op = 4'b0011;  //ANDI
                    
                    3'b001: op = (funct7==7'b0000000) ? 4'b0110 : 4'b0000;  //SLLI
                    3'b101: op = (funct7==7'b0000000) ? 4'b0111 : (funct7==7'b0100000) ? 4'b1000 : 4'b0000; //SRLI or SRAI
                    default: op = 4'b0;
                endcase      
            end
            7'b1100011: begin   //B type
                ex_tag = 4'b0010;
                case (funct3) 
                    3'b000: op = 4'b0001;
                    3'b001: op = 4'b0010;
                    3'b100: op = 4'b0011;
                    3'b101: op = 4'b0100;
                    3'b110: op = 4'b0101;
                    3'b111: op = 4'b0110;
                    default: op = 4'b0000;
                endcase
            end

            7'b1101111: begin   //JAL
                ex_tag = 4'b0010;
                op = 4'b1000;
            end

            7'b1100111: begin   //JALR
                ex_tag = 4'b0010;
                op = 4'b1001;    
            end

            7'b0110111: begin   // LUI
                ex_tag = 4'b0;
                op = 4'b0001;   //加法
            end
            7'b0010111: begin   //AUIPC
                ex_tag = 4'b0;
                op = 4'b0001;   //加法
            end 
            7'b0000011: begin   //LOAD
                ex_tag = 4'b0001;
                op = {1'b1, funct3};
            end

            7'b0100011: begin   //STORE
                ex_tag = 4'b0001;
                op = {1'b0, funct3};
            end

            7'b1110011: begin   //SYSTEM
                ex_tag = 0011;
                case(funct3) 
                    3'b001: op = 4'b0001;   //CSRRW
                    3'b010: op = 4'b0010;   //CSRRS
                    3'b011: op = 4'b0011;   //CSRRC
                    3'b101: op = 4'b0100;   //CSRRWI
                    3'b110: op = 4'b0101;   //CSRRSI
                    3'b111: op = 4'b0110;   //CSRRCI
                    3'b000: begin
                        case(immi)
                            12'h000: op = 4'b1000;
                            12'h302: op = 4'b1001;
                            default: op = 4'b0000;
                        endcase
                    end
                    default: op = 4'b000;
                endcase
            end
            default: begin
                ex_tag = 4'b1111;
                op = 4'b0000;
            end
        endcase
    end

    always @(*) begin
        case (opcode)
            7'b0110011: begin
                rs1_addr = inst[19:15];
                rs2_addr = inst[24:20];
                rd_addr = inst[11:7];
                alu_src1_ispc = 1'b0;
                alu_src2_isimm = 1'b0;                
                imm = 32'b0;
            end
            7'b0010011: begin
                rs1_addr = inst[19:15];
                rs2_addr = 5'b0;
                rd_addr = inst[11:7];
                alu_src2_isimm = 1'b1;
                alu_src1_ispc = 1'b0;
                imm =   (funct3 == 3'b001 || funct3 == 3'b101) ? 
                        {27'd0, immi[4:0]}:
                        {{20{immi[11]}}, immi};
            end
            7'b1100011: begin
                rs1_addr = inst[19:15];
                rs2_addr = inst[24:20];                
                rd_addr = 5'b0;
                alu_src1_ispc = 1'b0;
                alu_src2_isimm = 1'b0;
                imm = {{19{immb[12]}},immb};
            end
            7'b1101111: begin  //JAL(J-type)
                rs1_addr = 5'b0;
                rs2_addr = 5'b0;
                rd_addr = inst[11:7];
                alu_src1_ispc = 1'b0;   //用不上无所谓
                alu_src2_isimm = 1'b0;
                imm =  {{11{immj[20]}},immj};
            end
            7'b1100111: begin  //JALR(I-type)
                rs1_addr = inst[19:15];
                rs2_addr = 5'b0;
                rd_addr = inst[11:7];
                alu_src1_ispc = 1'b0;   //用不上无所谓
                alu_src2_isimm = 1'b0;          
                imm = {{20{immi[11]}},immi};
            end

            7'b0110111: begin  //LUI(U-type)
                //应该让src1为0,src2为立即数
                rs1_addr = 5'b0;
                rs2_addr = 5'b0;
                rd_addr = inst[11:7];
                alu_src1_ispc = 1'b0;
                alu_src2_isimm = 1'b1;
                imm = {immu,12'd0};
            end
            7'b0010111: begin  //AUIPC(U-type)
                //应该让src1为pc,src2为立即数
                rs1_addr = 5'b0;
                rs2_addr = 5'b0;
                rd_addr = inst[11:7];
                alu_src1_ispc = 1'b1;
                alu_src2_isimm = 1'b1;
                imm = {immu,12'd0};
            end

            7'b0000011: begin  //load(I-type)
                rs1_addr = inst[19:15];
                rs2_addr = 5'b0;
                rd_addr = inst[11:7];
                imm = {{20{immi[11]}},immi};
                alu_src2_isimm = 1'b1;
                alu_src1_ispc = 1'b0;
            end
            7'b0100011: begin   //store(S-type)
                rs1_addr = inst[19:15];
                rs2_addr = inst[24:20];   
                rd_addr = 5'b0;
                alu_src1_ispc = 1'b0;
                alu_src2_isimm = 1'b0; 
                imm = {{20{imms[11]}},imms};
            end
            7'b1110011: begin   //system
                rs1_addr = funct3[2] ? 5'b0: inst[19:15];
                rs2_addr = 5'b0;
                rd_addr = inst[11:7];
                alu_src1_ispc = 1'b0;
                alu_src2_isimm = 1'b1;
                imm = {27'b0, inst[19:15]};
            end
            default: begin
                rs1_addr = 5'b0;
                rs2_addr = 5'b0;
                rd_addr = 5'b0;
                alu_src1_ispc = 1'b0;
                alu_src2_isimm = 1'b0;
                imm = 32'b0;
            end
        endcase
    end
endmodule
