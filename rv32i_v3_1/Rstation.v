module Rstation(
    input           clk,
    input           rst_n,    
    // top 解码并输入操作数
    input   [31:0]  op_src1,
    input   [31:0]  op_src2,
    input   [31:0]  pc,
    output          issue_en,  //注意issue_en=0 时候issue的指令不允许写RAT和ROB
    // ID
    input   [3:0]   ex_tag,
    input   [3:0]   op,
    output  [15:0]  rstation_busy,
    // rob
    input   [4:0]   rob_tail,
    // CDB
    input           cdb_valid,
    input   [3:0]   cdb_rsid,
    input   [4:0]   cdb_robid,
    input   [31:0]  cdb_value,
    //RAT
    input   [4:0]   rat_src1_robid,
    input           rat_src1_valid,
    input   [4:0]   rat_src2_robid,
    input           rat_src2_valid,

    //ALU
    output          alu_en,
    output  [3:0]   alu_op,
    output  [31:0]  alu_src1,
    output  [31:0]  alu_src2,

    //LSU
    output          lsu_en,
    output  [3:0]   lsu_op,
    output  [31:0]  addr,

    //BCU
    output          bcu_en,
    output  [31:0]  bcu_src1,
    output  [31:0]  bcu_src2,
    output  [31:0]  bcu_pc,
    output  [3:0]   bcu_op,

    //bc2rs总线
    input           bcub_pred_correct,
    input           bucb_valid,

);
function [2:0] issue_line;
    input [3:0] ex_busy;
    integer i;
    begin
        issue_line = 3'b100;  // 默认：满
        for (i = 0; i < 4; i = i + 1) begin
            if (!ex_busy[i]) begin
                issue_line = {1'b0, i[1:0]};  // 未满 + 索引
                break;
            end
        end
    end
endfunction  


    //条目表
    parameter rstation_lines = 16;
    reg         busy        [0:rstation_lines - 1];
    wire        ready       [0:rstation_lines - 1];
    reg [4:0]   rob_id      [0:rstation_lines - 1];
    reg [31:0]  src1        [0:rstation_lines - 1];
    reg [31:0]  src2        [0:rstation_lines - 1];
    reg         src1_valid  [0:rstation_lines - 1];
    reg         src2_valid  [0:rstation_lines - 1];
    reg [4:0]   src1_robid  [0:rstation_lines - 1];
    reg [4:0]   src2_robid  [0:rstation_lines - 1];
    reg         branch_tag  [0:rstation_lines - 1];

    parameter BCU_lines = 1;
    reg [31:0]  bcu_pc;

    parameter LSU_lines = 4;
    reg [31:0]  lsu_addr        [0:LSU_lines - 1];
    reg         lsu_addr_en     [0:LSU_lines - 1];


    wire    [3:0]   ALU_busy    = busy[3:0];
    wire    [3:0]   LSU_busy    = busy[7:4];
    wire            BCU_busy    = busy[8];

    reg             is_branch;

    reg     [2:0]   ex_line;
    assign issue_en = ~ex_line[2];
    always @(*) begin
        case (ex_tag)
            4'b0000: ex_line = issue_line(ALU_busy);
            4'b0001: ex_line = issue_line(LSU_busy);
            4'b0010: ex_line = BCU_busy ? 3'b100: 3'b000;
            default: ex_line = 3'b000;
        endcase 
    end

    wire [3:0] issue_rs_line = {ex_tag[1:0], ex_line[1:0]};
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin: init_rs

        end else begin
            // 发射写
            if (!ex_line[2]) begin
                busy[issue_rs_line] <= 1'b1;
                rob_id[issue_rs_line] <= rob_tail;
                src1_valid[issue_rs_line] <= rat_src1_valid;
                src2_valid[issue_rs_line] <= rat_src2_valid;
                src1_robid[issue_rs_line] <= rat_src1_robid;
                src2_robid[issue_rs_line] <= rat_src2_robid;
                src1[issue_rs_line] <= op_src1;
                src2[issue_rs_line] <= op_src2;
                branch_tag[issue_rs_line] <= is_branch;
                if (issue_rs_line[3:2] == 2'b10) begin
                    bcu_pc <= pc;
                    is_branch <= 1'b1;
                end
            end
            //cdb广播更新
            if (cdb_valid) begin: broadcast_update
                integer i;
                for(i=0;i<16;i=i+1) begin
                    if ((!src1_valid[i]) && (src1_robid[i] == cdb_robid)) begin
                        src1_valid[i] <= 1'b1;
                        src1[i] <= cdb_value;
                    end
                    if ((!src2_valid[i]) && (src2_robid[i] == cdb_robid)) begin
                        src2_valid[i] <= 1'b1;
                        src2[i] <= cdb_value;
                    end                    
                end
                // 清空广播指令对保留站的占用
                busy[cdb_rsid] <= 1'b0;
            end

            //bcub广播更新
            if (bucb_valid) begin
                if (bcub_pred_correct) begin: bcub_broadcast
                    integer i;
                    for (i=0;i<16;i++) begin
                        
                end
            end
        end
    end

   
    
endmodule