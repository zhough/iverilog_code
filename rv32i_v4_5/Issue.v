module Issue(
    input       [3:0]   ex_tag,
    input               rs1_states,
    input               rs2_states,
    input               rd_states,
    input               alu_src1_ispc,
    input               alu_src2_isimm,
    input       [4:0]   src1_addr,
    input       [4:0]   src2_addr,
    input       [4:0]   rd_addr,
    input       [31:0]  regsrc1,
    input       [31:0]  regsrc2,
    input       [31:0]  imm,
    input       [31:0]  pc,
    
    output      [15:0]  ex_unit,
    output              update_SAT_en,
    output      [31:0]  src1,
    output      [31:0]  src2,
    output              stall,
    output              flush,

    //from BCB
    input               bcb_en,
    input               pred_correct,
    input               lsu_busy,
    //from CDB
    input               cdb_en,
    input       [31:0]  cdb_result,
    input       [4:0]   cdb_id,
    input               src1_bypass_en_id,
    input               src2_bypass_en_id,
    input               rd_bypass_en

    // input       [4:0]   CCB_id,
    // input               CCB_en,
    // input       [31:0]  CCB_data
);

    // wire    src1_bypass_en, src2_bypass_en;
    wire    src1_ready, src2_ready, rd_ready;
    // assign src1_bypass_en = cdb_en && (cdb_id == src1_addr) && rs1_states;
    // assign src2_bypass_en = cdb_en && (cdb_id == src2_addr) && rs2_states;
    // assign src1_ready = !rs1_states || src1_bypass_en;
    // assign src2_ready = !rs2_states || src2_bypass_en;
    // assign rd_ready = !rd_states || (cdb_en && (cdb_id == rd_addr));
    // assign src1 =   alu_src1_ispc ? pc:
    //                 src1_bypass_en ? cdb_result:
    //                 regsrc1;
    // assign src2 =   alu_src2_isimm ? imm:
    //                 src2_bypass_en ? cdb_result:
    //                 regsrc2;

    // assign src1_ready = !rs1_states || src1_bypass_en;
    // assign src2_ready = !rs2_states || src2_bypass_en;
    // assign rd_ready = !rd_states || (CCB_en && (CCB_id == rd_addr));
    // assign src1_bypass_en = CCB_en && (CCB_id == src1_addr) && rs1_states;
    // assign src2_bypass_en = CCB_en && (CCB_id == src2_addr) && rs2_states;
    // assign src1 = alu_src1_ispc ? pc:
    //                 src1_bypass_en ? CCB_data:
    //                 regsrc1;
    // assign src2 = alu_src2_isimm ? imm:
    //                 src2_bypass_en ? CCB_data:
    //                 regsrc2;

    assign src1_ready = !rs1_states || src1_bypass_en_id;
    assign src2_ready = !rs2_states || src2_bypass_en_id;
    assign rd_ready = !rd_states;
    assign src1 = alu_src1_ispc ? pc:
                    regsrc1;
    assign src2 = alu_src2_isimm ? imm:
                    regsrc2;

    
    wire    issue_en;
    wire    is_lsu;
    assign is_lsu = (ex_tag == 4'b1);
    // 基础条件
    wire src_ready  = src1_ready && src2_ready && rd_ready;
    wire lsu_stall  = is_lsu && lsu_busy;
    wire mispred    = bcb_en && !pred_correct;

    // 控制信号
    assign stall = !src_ready || lsu_stall;
    assign flush = mispred;
    assign issue_en = src_ready && !lsu_stall && !mispred;
    
    assign ex_unit =    !issue_en           ? 16'h8000: //发射到无效单元 
                        (ex_tag == 4'b0000) ? 16'h0001:
                        (ex_tag == 4'b0001) ? 16'h0010:
                        (ex_tag == 4'b0010) ? 16'h0100: 16'h8000;
    assign update_SAT_en = issue_en;
endmodule
