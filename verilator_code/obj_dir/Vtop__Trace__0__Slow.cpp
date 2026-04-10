// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+113,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+115,0,"perip_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"perip_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+117,0,"perip_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+118,0,"perip_mask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+119,0,"perip_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+120,0,"cnt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+113,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+115,0,"perip_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"perip_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+117,0,"perip_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+118,0,"perip_mask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+119,0,"perip_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+120,0,"cnt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+121,0,"pc_irom",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+122,0,"irom_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+123,0,"irom_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("Core_CPU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+114,0,"cpu_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"cpu_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+122,0,"irom_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+123,0,"irom_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+115,0,"perip_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+119,0,"perip_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+118,0,"perip_mask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+116,0,"perip_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+117,0,"perip_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+124,0,"rst_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("rs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+0+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+32,0,"curr_pc_if",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+33,0,"jump_taken_if",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+34,0,"jump_target_if",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+35,0,"branch_taken_if",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+36,0,"branch_target_if",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+37,0,"nop_if",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"next_pc_if",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+122,0,"irom_addr_if",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+123,0,"ins_if",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"ins_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+40,0,"alu_src_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+41,0,"alu_op_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+42,0,"imm_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+43,0,"jump_en_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"branch_en_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"is_lui_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"is_auipc_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"is_jalr_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"rd_en_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"rs2_en_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+50,0,"load_op_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+51,0,"store_op_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+52,0,"rs1_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+53,0,"rs2_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+54,0,"rd_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+55,0,"pc_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+56,0,"alu_op_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+57,0,"alu_src_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+58,0,"a_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+59,0,"b_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+60,0,"imm_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+33,0,"jump_en_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"branch_en_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"is_jalr_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+63,0,"pc_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+33,0,"jump_taken_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"branch_taken_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+34,0,"jump_target_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"branch_target_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+64,0,"alu_result_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+65,0,"j_rd_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+66,0,"store_op_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+67,0,"load_op_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+68,0,"is_load_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"is_store_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"id_clear",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"ex_clear",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"id_nop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+72,0,"rd_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+73,0,"rd_en_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+74,0,"rd_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+75,0,"rd_en_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+76,0,"rs2_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+77,0,"rs2_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+78,0,"is_lui_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"is_auipc_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+80,0,"WAR1_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"WAR2_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"WAR1_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"WAR2_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"LAR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+84,0,"bypass_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+110,0,"bypass_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+84,0,"wb_result_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+85,0,"is_load_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"is_store_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+87,0,"alu_result_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"store_op_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+89,0,"load_op_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+110,0,"wb_result_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+90,0,"wb_result_ex_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"store_data_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+117,0,"load_data_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+92,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+93,0,"rs3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("rs_init", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+94,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_EX", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+56,0,"alu_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+57,0,"alu_src",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+58,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+59,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+60,0,"imm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+33,0,"jump_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"branch_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"is_jalr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+63,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+33,0,"jump_taken",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"branch_taken",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+34,0,"jump_target",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"branch_target",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+64,0,"alu_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+65,0,"j_rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+95,0,"alu_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+64,0,"result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+96,0,"tmp_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_ID", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+39,0,"ins",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+40,0,"alu_src",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+41,0,"alu_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+42,0,"imm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+43,0,"jump_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"branch_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"is_lui",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"is_auipc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"is_jalr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"rd_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+50,0,"load_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+51,0,"store_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+52,0,"rs1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+53,0,"rs2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+54,0,"rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+49,0,"rs2_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+99,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+100,0,"funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+101,0,"immi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+102,0,"imms",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+103,0,"immb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+104,0,"immu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 19,0);
    tracep->declBus(c+105,0,"immj",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 20,0);
    tracep->declBit(c+40,0,"alu_src_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+43,0,"jump_en_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"branch_en_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"is_jalr_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"is_lui_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"is_auipc_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"rd_en_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+41,0,"alu_op_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+42,0,"imm_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+50,0,"load_op_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+51,0,"store_op_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+49,0,"rs2_en_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_IF", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+124,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+32,0,"curr_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+33,0,"jump_taken",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+34,0,"jump_target",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+35,0,"branch_taken",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+36,0,"branch_target",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+37,0,"nop",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"next_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+122,0,"irom_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_irom", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+121,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+123,0,"spo",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_perip", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+113,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+115,0,"perip_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"perip_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+119,0,"perip_wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+118,0,"perip_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+117,0,"perip_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+130,0,"DRAM_ADDR_START",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+131,0,"DRAM_ADDR_END",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+130,0,"DRAM_ADDR_START1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+131,0,"DRAM_ADDR_END1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+132,0,"SW0_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+133,0,"SW1_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+134,0,"KEY_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+135,0,"SEG_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+136,0,"LED_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+137,0,"CNT_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+138,0,"LED",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+139,0,"SEG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+111,0,"dram_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+106,0,"cnt_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+107,0,"sim_seg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_counter", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+113,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+116,0,"perip_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+125,0,"cnt_wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+106,0,"perip_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+108,0,"start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+109,0,"cnt_1ms",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+106,0,"cnt_ms",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_dram", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+115,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+113,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+118,0,"mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+111,0,"spo",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+127,0,"din",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+128,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+129,0,"offset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+112,0,"tmp_output",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+111,0,"spo_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtop___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vtop___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+130,(0x80100000U),32);
    bufp->fullIData(oldp+131,(0x8013ffffU),32);
    bufp->fullIData(oldp+132,(0x80200000U),32);
    bufp->fullIData(oldp+133,(0x80200004U),32);
    bufp->fullIData(oldp+134,(0x80200010U),32);
    bufp->fullIData(oldp+135,(0x80200020U),32);
    bufp->fullIData(oldp+136,(0x80200040U),32);
    bufp->fullIData(oldp+137,(0x80200050U),32);
    bufp->fullIData(oldp+138,(vlSelfRef.top__DOT__u_perip__DOT__LED),32);
    bufp->fullIData(oldp+139,(vlSelfRef.top__DOT__u_perip__DOT__SEG),32);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+0,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[0]),32);
    bufp->fullIData(oldp+1,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[1]),32);
    bufp->fullIData(oldp+2,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[2]),32);
    bufp->fullIData(oldp+3,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[3]),32);
    bufp->fullIData(oldp+4,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[4]),32);
    bufp->fullIData(oldp+5,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[5]),32);
    bufp->fullIData(oldp+6,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[6]),32);
    bufp->fullIData(oldp+7,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[7]),32);
    bufp->fullIData(oldp+8,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[8]),32);
    bufp->fullIData(oldp+9,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[9]),32);
    bufp->fullIData(oldp+10,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[10]),32);
    bufp->fullIData(oldp+11,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[11]),32);
    bufp->fullIData(oldp+12,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[12]),32);
    bufp->fullIData(oldp+13,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[13]),32);
    bufp->fullIData(oldp+14,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[14]),32);
    bufp->fullIData(oldp+15,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[15]),32);
    bufp->fullIData(oldp+16,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[16]),32);
    bufp->fullIData(oldp+17,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[17]),32);
    bufp->fullIData(oldp+18,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[18]),32);
    bufp->fullIData(oldp+19,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[19]),32);
    bufp->fullIData(oldp+20,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[20]),32);
    bufp->fullIData(oldp+21,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[21]),32);
    bufp->fullIData(oldp+22,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[22]),32);
    bufp->fullIData(oldp+23,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[23]),32);
    bufp->fullIData(oldp+24,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[24]),32);
    bufp->fullIData(oldp+25,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[25]),32);
    bufp->fullIData(oldp+26,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[26]),32);
    bufp->fullIData(oldp+27,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[27]),32);
    bufp->fullIData(oldp+28,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[28]),32);
    bufp->fullIData(oldp+29,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[29]),32);
    bufp->fullIData(oldp+30,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[30]),32);
    bufp->fullIData(oldp+31,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[31]),32);
    bufp->fullIData(oldp+32,(vlSelfRef.top__DOT__Core_CPU__DOT__curr_pc_if),32);
    bufp->fullBit(oldp+33,(vlSelfRef.top__DOT__Core_CPU__DOT__jump_en_ex));
    bufp->fullIData(oldp+34,((IData)(((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__is_jalr_ex)
                                       ? (0x00000000fffffffeULL 
                                          & (VL_EXTENDS_QI(33,32, vlSelfRef.top__DOT__Core_CPU__DOT__a_ex) 
                                             + VL_EXTENDS_QI(33,32, vlSelfRef.top__DOT__Core_CPU__DOT__imm_ex)))
                                       : (QData)((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_target))))),32);
    bufp->fullBit(oldp+35,(vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_taken));
    bufp->fullIData(oldp+36,(vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_target),32);
    bufp->fullBit(oldp+37,(vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__nop));
    bufp->fullIData(oldp+38,(((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__nop)
                               ? vlSelfRef.top__DOT__Core_CPU__DOT__curr_pc_if
                               : ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__jump_en_ex)
                                   ? (IData)(((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__is_jalr_ex)
                                               ? (0x00000000fffffffeULL 
                                                  & (VL_EXTENDS_QI(33,32, vlSelfRef.top__DOT__Core_CPU__DOT__a_ex) 
                                                     + 
                                                     VL_EXTENDS_QI(33,32, vlSelfRef.top__DOT__Core_CPU__DOT__imm_ex)))
                                               : (QData)((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_target))))
                                   : ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_taken)
                                       ? vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_target
                                       : ((IData)(4U) 
                                          + vlSelfRef.top__DOT__Core_CPU__DOT__curr_pc_if))))),32);
    bufp->fullIData(oldp+39,(vlSelfRef.top__DOT__Core_CPU__DOT__ins_id),32);
    bufp->fullBit(oldp+40,(vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_src_reg));
    bufp->fullCData(oldp+41,(vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg),4);
    bufp->fullIData(oldp+42,(vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg),32);
    bufp->fullBit(oldp+43,(((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                   >> 6U)) && ((1U 
                                                & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                   >> 5U)) 
                                               && ((1U 
                                                    & (~ 
                                                       (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                        >> 4U))) 
                                                   && ((8U 
                                                        & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                                        ? 
                                                       ((1U 
                                                         & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                            >> 2U)) 
                                                        && ((1U 
                                                             & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                                >> 1U)) 
                                                            && (1U 
                                                                & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)))
                                                        : 
                                                       ((1U 
                                                         & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                            >> 2U)) 
                                                        && ((1U 
                                                             & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                                >> 1U)) 
                                                            && (1U 
                                                                & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)))))))));
    bufp->fullBit(oldp+44,(((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                   >> 6U)) && ((1U 
                                                & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                   >> 5U)) 
                                               && ((1U 
                                                    & (~ 
                                                       (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                        >> 4U))) 
                                                   && ((1U 
                                                        & (~ 
                                                           (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                            >> 3U))) 
                                                       && ((1U 
                                                            & (~ 
                                                               (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                                >> 2U))) 
                                                           && ((1U 
                                                                & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                                   >> 1U)) 
                                                               && (1U 
                                                                   & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)))))))));
    bufp->fullBit(oldp+45,(((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                      >> 6U))) && (
                                                   (1U 
                                                    & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                       >> 5U)) 
                                                   && ((1U 
                                                        & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                           >> 4U)) 
                                                       && ((1U 
                                                            & (~ 
                                                               (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                                >> 3U))) 
                                                           && ((1U 
                                                                & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                                   >> 2U)) 
                                                               && ((1U 
                                                                    & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                                       >> 1U)) 
                                                                   && (1U 
                                                                       & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)))))))));
    bufp->fullBit(oldp+46,(((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                      >> 6U))) && (
                                                   (1U 
                                                    & (~ 
                                                       (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                        >> 5U))) 
                                                   && ((1U 
                                                        & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                           >> 4U)) 
                                                       && ((1U 
                                                            & (~ 
                                                               (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                                >> 3U))) 
                                                           && ((1U 
                                                                & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                                   >> 2U)) 
                                                               && ((1U 
                                                                    & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                                       >> 1U)) 
                                                                   && (1U 
                                                                       & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)))))))));
    bufp->fullBit(oldp+47,(vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__is_jalr_reg));
    bufp->fullBit(oldp+48,(vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__rd_en_reg));
    bufp->fullBit(oldp+49,(((0x00000040U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                             ? ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                       >> 5U)) && (
                                                   (1U 
                                                    & (~ 
                                                       (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                        >> 4U))) 
                                                   && ((1U 
                                                        & (~ 
                                                           (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                            >> 3U))) 
                                                       && ((1U 
                                                            & (~ 
                                                               (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                                >> 2U))) 
                                                           && ((1U 
                                                                & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                                   >> 1U)) 
                                                               && (1U 
                                                                   & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id))))))
                             : ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                       >> 5U)) && (
                                                   (0x00000010U 
                                                    & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                                    ? 
                                                   ((1U 
                                                     & (~ 
                                                        (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                         >> 3U))) 
                                                    && ((1U 
                                                         & (~ 
                                                            (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                             >> 2U))) 
                                                        && ((1U 
                                                             & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                                >> 1U)) 
                                                            && (1U 
                                                                & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id))))
                                                    : 
                                                   ((1U 
                                                     & (~ 
                                                        (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                         >> 3U))) 
                                                    && ((1U 
                                                         & (~ 
                                                            (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                             >> 2U))) 
                                                        && ((1U 
                                                             & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                                >> 1U)) 
                                                            && (1U 
                                                                & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)))))))));
    bufp->fullCData(oldp+50,(((0x00000040U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                               ? 7U : ((0x00000020U 
                                        & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                        ? 7U : ((0x00000010U 
                                                 & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                                 ? 7U
                                                 : 
                                                ((8U 
                                                  & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                                  ? 7U
                                                  : 
                                                 ((4U 
                                                   & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                                   ? 7U
                                                   : 
                                                  ((2U 
                                                    & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                                    ? 
                                                   ((1U 
                                                     & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                                     ? 
                                                    (7U 
                                                     & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                        >> 0x0000000cU))
                                                     : 7U)
                                                    : 7U))))))),3);
    bufp->fullCData(oldp+51,(((0x00000040U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                               ? 7U : ((0x00000020U 
                                        & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                        ? ((0x00000010U 
                                            & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                            ? 7U : 
                                           ((8U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                             ? 7U : 
                                            ((4U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                              ? 7U : 
                                             ((2U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                               ? ((1U 
                                                   & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                                   ? 
                                                  (7U 
                                                   & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                      >> 0x0000000cU))
                                                   : 7U)
                                               : 7U))))
                                        : 7U))),3);
    bufp->fullCData(oldp+52,((0x0000001fU & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                             >> 0x0000000fU))),5);
    bufp->fullCData(oldp+53,((0x0000001fU & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                             >> 0x00000014U))),5);
    bufp->fullCData(oldp+54,((0x0000001fU & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                             >> 7U))),5);
    bufp->fullIData(oldp+55,(vlSelfRef.top__DOT__Core_CPU__DOT__pc_id),32);
    bufp->fullCData(oldp+56,(vlSelfRef.top__DOT__Core_CPU__DOT__alu_op_ex),4);
    bufp->fullBit(oldp+57,(vlSelfRef.top__DOT__Core_CPU__DOT__alu_src_ex));
    bufp->fullIData(oldp+58,(vlSelfRef.top__DOT__Core_CPU__DOT__a_ex),32);
    bufp->fullIData(oldp+59,(vlSelfRef.top__DOT__Core_CPU__DOT__b_ex),32);
    bufp->fullIData(oldp+60,(vlSelfRef.top__DOT__Core_CPU__DOT__imm_ex),32);
    bufp->fullBit(oldp+61,(vlSelfRef.top__DOT__Core_CPU__DOT__branch_en_ex));
    bufp->fullBit(oldp+62,(vlSelfRef.top__DOT__Core_CPU__DOT__is_jalr_ex));
    bufp->fullIData(oldp+63,(vlSelfRef.top__DOT__Core_CPU__DOT__pc_ex),32);
    bufp->fullIData(oldp+64,(vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_result),32);
    bufp->fullIData(oldp+65,(((IData)(4U) + vlSelfRef.top__DOT__Core_CPU__DOT__pc_ex)),32);
    bufp->fullCData(oldp+66,(vlSelfRef.top__DOT__Core_CPU__DOT__store_op_ex),3);
    bufp->fullCData(oldp+67,(vlSelfRef.top__DOT__Core_CPU__DOT__load_op_ex),3);
    bufp->fullBit(oldp+68,((1U & (~ (7U == (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__load_op_ex))))));
    bufp->fullBit(oldp+69,((1U & (~ (7U == (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__store_op_ex))))));
    bufp->fullBit(oldp+70,(vlSelfRef.top__DOT__Core_CPU__DOT__id_clear));
    bufp->fullBit(oldp+71,(vlSelfRef.top__DOT__Core_CPU__DOT__ex_clear));
    bufp->fullCData(oldp+72,(vlSelfRef.top__DOT__Core_CPU__DOT__rd_ex),5);
    bufp->fullBit(oldp+73,(vlSelfRef.top__DOT__Core_CPU__DOT__rd_en_ex));
    bufp->fullCData(oldp+74,(vlSelfRef.top__DOT__Core_CPU__DOT__rd_mem),5);
    bufp->fullBit(oldp+75,(vlSelfRef.top__DOT__Core_CPU__DOT__rd_en_mem));
    bufp->fullCData(oldp+76,(vlSelfRef.top__DOT__Core_CPU__DOT__rs2_ex),5);
    bufp->fullCData(oldp+77,(vlSelfRef.top__DOT__Core_CPU__DOT__rs2_mem),5);
    bufp->fullBit(oldp+78,(vlSelfRef.top__DOT__Core_CPU__DOT__is_lui_ex));
    bufp->fullBit(oldp+79,(vlSelfRef.top__DOT__Core_CPU__DOT__is_auipc_ex));
    bufp->fullBit(oldp+80,(((IData)(vlSelfRef.top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_1) 
                            & ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_en_ex) 
                               & ((7U == (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__load_op_ex)) 
                                  & (0U != (0x0000001fU 
                                            & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                               >> 0x0000000fU))))))));
    bufp->fullBit(oldp+81,(((IData)(vlSelfRef.top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_3) 
                            & ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_en_ex) 
                               & ((7U == (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__load_op_ex)) 
                                  & (0U != (0x0000001fU 
                                            & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                               >> 0x00000014U))))))));
    bufp->fullBit(oldp+82,((((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_mem) 
                             == (0x0000001fU & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                >> 0x0000000fU))) 
                            & ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_en_mem) 
                               & (0U != (0x0000001fU 
                                         & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                            >> 0x0000000fU)))))));
    bufp->fullBit(oldp+83,((((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_mem) 
                             == (0x0000001fU & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                >> 0x00000014U))) 
                            & ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_en_mem) 
                               & (0U != (0x0000001fU 
                                         & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                            >> 0x00000014U)))))));
    bufp->fullIData(oldp+84,(vlSelfRef.top__DOT__Core_CPU__DOT__bypass_ex),32);
    bufp->fullBit(oldp+85,(vlSelfRef.top__DOT__Core_CPU__DOT__is_load_mem));
    bufp->fullBit(oldp+86,(vlSelfRef.top__DOT__Core_CPU__DOT__is_store_mem));
    bufp->fullIData(oldp+87,(vlSelfRef.top__DOT__Core_CPU__DOT__alu_result_mem),32);
    bufp->fullCData(oldp+88,(vlSelfRef.top__DOT__Core_CPU__DOT__store_op_mem),3);
    bufp->fullCData(oldp+89,(vlSelfRef.top__DOT__Core_CPU__DOT__load_op_mem),3);
    bufp->fullIData(oldp+90,(vlSelfRef.top__DOT__Core_CPU__DOT__wb_result_ex_reg),32);
    bufp->fullIData(oldp+91,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[1U]),32);
    bufp->fullIData(oldp+92,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[2U]),32);
    bufp->fullIData(oldp+93,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[3U]),32);
    bufp->fullIData(oldp+94,(vlSelfRef.top__DOT__Core_CPU__DOT__rs_init__DOT__i),32);
    bufp->fullIData(oldp+95,(vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_b),32);
    bufp->fullQData(oldp+96,((0x00000001ffffffffULL 
                              & (VL_EXTENDS_QI(33,32, vlSelfRef.top__DOT__Core_CPU__DOT__a_ex) 
                                 + VL_EXTENDS_QI(33,32, vlSelfRef.top__DOT__Core_CPU__DOT__imm_ex)))),33);
    bufp->fullCData(oldp+98,((0x0000007fU & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)),7);
    bufp->fullCData(oldp+99,((7U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                    >> 0x0000000cU))),3);
    bufp->fullCData(oldp+100,((vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                               >> 0x00000019U)),7);
    bufp->fullSData(oldp+101,((vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                               >> 0x00000014U)),12);
    bufp->fullSData(oldp+102,(((0x00000fe0U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                               >> 0x00000014U)) 
                               | (0x0000001fU & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                 >> 7U)))),12);
    bufp->fullSData(oldp+103,(((((2U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                        >> 0x0000001eU)) 
                                 | (1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                          >> 7U))) 
                                << 0x0000000bU) | (
                                                   (0x000007e0U 
                                                    & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                       >> 0x00000014U)) 
                                                   | (0x0000001eU 
                                                      & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                         >> 7U))))),13);
    bufp->fullIData(oldp+104,((vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                               >> 0x0000000cU)),20);
    bufp->fullIData(oldp+105,(((((0x00000200U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                 >> 0x00000016U)) 
                                 | ((0x000001feU & 
                                     (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                      >> 0x0000000bU)) 
                                    | (1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                             >> 0x00000014U)))) 
                                << 0x0000000bU) | (0x000007feU 
                                                   & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                      >> 0x00000014U)))),21);
    bufp->fullIData(oldp+106,(vlSelfRef.top__DOT__u_perip__DOT__u_counter__DOT__cnt_ms),32);
    bufp->fullIData(oldp+107,(vlSelfRef.top__DOT__u_perip__DOT__sim_seg),32);
    bufp->fullBit(oldp+108,(vlSelfRef.top__DOT__u_perip__DOT__u_counter__DOT__start));
    bufp->fullSData(oldp+109,(vlSelfRef.top__DOT__u_perip__DOT__u_counter__DOT__cnt_1ms),16);
    bufp->fullIData(oldp+110,(vlSelfRef.top__DOT__Core_CPU__DOT__bypass_mem),32);
    bufp->fullIData(oldp+111,(vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__spo),32);
    bufp->fullIData(oldp+112,(vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output),32);
    bufp->fullBit(oldp+113,(vlSelfRef.clk));
    bufp->fullBit(oldp+114,(vlSelfRef.rst));
    bufp->fullIData(oldp+115,(vlSelfRef.perip_addr),32);
    bufp->fullIData(oldp+116,(vlSelfRef.perip_wdata),32);
    bufp->fullIData(oldp+117,(vlSelfRef.perip_rdata),32);
    bufp->fullCData(oldp+118,(vlSelfRef.perip_mask),3);
    bufp->fullBit(oldp+119,(vlSelfRef.perip_wen));
    bufp->fullIData(oldp+120,(vlSelfRef.cnt),32);
    bufp->fullSData(oldp+121,((0x00001fffU & (vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__irom_addr 
                                              >> 2U))),13);
    bufp->fullIData(oldp+122,(vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__irom_addr),32);
    bufp->fullIData(oldp+123,(vlSelfRef.top__DOT__u_irom__DOT__mem
                              [(0x00001fffU & (vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__irom_addr 
                                               >> 2U))]),32);
    bufp->fullBit(oldp+124,((1U & (~ (IData)(vlSelfRef.rst)))));
    bufp->fullBit(oldp+125,(vlSelfRef.top__DOT__u_perip__DOT____Vcellinp__u_counter__cnt_wen));
    bufp->fullBit(oldp+126,(((IData)(vlSelfRef.perip_wen) 
                             & (IData)(vlSelfRef.top__DOT__u_perip__DOT____VdfgRegularize_hff7cac4e_0_0))));
    bufp->fullIData(oldp+127,(((2U & (IData)(vlSelfRef.perip_mask))
                                ? vlSelfRef.perip_wdata
                                : ((1U & (IData)(vlSelfRef.perip_mask))
                                    ? ((2U & vlSelfRef.perip_addr)
                                        ? ((1U & vlSelfRef.perip_addr)
                                            ? vlSelfRef.perip_wdata
                                            : ((vlSelfRef.perip_wdata 
                                                << 0x00000010U) 
                                               | (0x0000ffffU 
                                                  & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output)))
                                        : ((1U & vlSelfRef.perip_addr)
                                            ? vlSelfRef.perip_wdata
                                            : ((0xffff0000U 
                                                & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output) 
                                               | (0x0000ffffU 
                                                  & vlSelfRef.perip_wdata))))
                                    : ((2U & vlSelfRef.perip_addr)
                                        ? ((1U & vlSelfRef.perip_addr)
                                            ? ((vlSelfRef.perip_wdata 
                                                << 0x00000018U) 
                                               | (0x00ffffffU 
                                                  & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output))
                                            : ((0xff000000U 
                                                & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output) 
                                               | ((0x00ff0000U 
                                                   & (vlSelfRef.perip_wdata 
                                                      << 0x00000010U)) 
                                                  | (0x0000ffffU 
                                                     & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output))))
                                        : ((1U & vlSelfRef.perip_addr)
                                            ? ((0xffff0000U 
                                                & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output) 
                                               | ((0x0000ff00U 
                                                   & (vlSelfRef.perip_wdata 
                                                      << 8U)) 
                                                  | (0x000000ffU 
                                                     & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output)))
                                            : ((0xffffff00U 
                                                & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output) 
                                               | (0x000000ffU 
                                                  & vlSelfRef.perip_wdata))))))),32);
    bufp->fullSData(oldp+128,((0x0000ffffU & (vlSelfRef.perip_addr 
                                              >> 2U))),16);
    bufp->fullCData(oldp+129,((3U & vlSelfRef.perip_addr)),2);
}
