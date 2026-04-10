// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__init_ram__DOT__i),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity[2U])))) {
        bufp->chgSData(oldp+1,((0x00001fffU & (vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__irom_addr 
                                               >> 2U))),13);
        bufp->chgIData(oldp+2,(vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__irom_addr),32);
        bufp->chgIData(oldp+3,(vlSelfRef.top__DOT__u_irom__DOT__mem
                               [(0x00001fffU & (vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__irom_addr 
                                                >> 2U))]),32);
        bufp->chgBit(oldp+4,(vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__nop));
        bufp->chgBit(oldp+5,(vlSelfRef.top__DOT__Core_CPU__DOT__ex_clear));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+6,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[0]),32);
        bufp->chgIData(oldp+7,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[1]),32);
        bufp->chgIData(oldp+8,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[2]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[3]),32);
        bufp->chgIData(oldp+10,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[4]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[5]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[6]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[7]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[8]),32);
        bufp->chgIData(oldp+15,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[9]),32);
        bufp->chgIData(oldp+16,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[10]),32);
        bufp->chgIData(oldp+17,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[11]),32);
        bufp->chgIData(oldp+18,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[12]),32);
        bufp->chgIData(oldp+19,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[13]),32);
        bufp->chgIData(oldp+20,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[14]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[15]),32);
        bufp->chgIData(oldp+22,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[16]),32);
        bufp->chgIData(oldp+23,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[17]),32);
        bufp->chgIData(oldp+24,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[18]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[19]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[20]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[21]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[22]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[23]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[24]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[25]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[26]),32);
        bufp->chgIData(oldp+33,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[27]),32);
        bufp->chgIData(oldp+34,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[28]),32);
        bufp->chgIData(oldp+35,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[29]),32);
        bufp->chgIData(oldp+36,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[30]),32);
        bufp->chgIData(oldp+37,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[31]),32);
        bufp->chgIData(oldp+38,(vlSelfRef.top__DOT__Core_CPU__DOT__curr_pc_if),32);
        bufp->chgIData(oldp+39,(vlSelfRef.top__DOT__Core_CPU__DOT__ins_id),32);
        bufp->chgBit(oldp+40,(vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_src_reg));
        bufp->chgCData(oldp+41,(vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg),4);
        bufp->chgIData(oldp+42,(vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg),32);
        bufp->chgBit(oldp+43,(((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
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
        bufp->chgBit(oldp+44,(((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
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
        bufp->chgBit(oldp+45,(((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                         >> 6U))) && 
                               ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                       >> 5U)) && (
                                                   (1U 
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
        bufp->chgBit(oldp+46,(((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                         >> 6U))) && 
                               ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                          >> 5U))) 
                                && ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                           >> 4U)) 
                                    && ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                  >> 3U))) 
                                        && ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                   >> 2U)) 
                                            && ((1U 
                                                 & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                    >> 1U)) 
                                                && (1U 
                                                    & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)))))))));
        bufp->chgBit(oldp+47,(vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__is_jalr_reg));
        bufp->chgBit(oldp+48,(vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__rd_en_reg));
        bufp->chgBit(oldp+49,(((0x00000040U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                ? ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                          >> 5U)) && 
                                   ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                              >> 4U))) 
                                    && ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                  >> 3U))) 
                                        && ((1U & (~ 
                                                   (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                    >> 2U))) 
                                            && ((1U 
                                                 & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                    >> 1U)) 
                                                && (1U 
                                                    & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id))))))
                                : ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                          >> 5U)) && 
                                   ((0x00000010U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                     ? ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                  >> 3U))) 
                                        && ((1U & (~ 
                                                   (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                    >> 2U))) 
                                            && ((1U 
                                                 & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                    >> 1U)) 
                                                && (1U 
                                                    & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id))))
                                     : ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                  >> 3U))) 
                                        && ((1U & (~ 
                                                   (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                    >> 2U))) 
                                            && ((1U 
                                                 & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                    >> 1U)) 
                                                && (1U 
                                                    & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)))))))));
        bufp->chgCData(oldp+50,(((0x00000040U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                  ? 7U : ((0x00000020U 
                                           & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                           ? 7U : (
                                                   (0x00000010U 
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
        bufp->chgCData(oldp+51,(((0x00000040U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                  ? 7U : ((0x00000020U 
                                           & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                           ? ((0x00000010U 
                                               & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                               ? 7U
                                               : ((8U 
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
                                                     : 7U))))
                                           : 7U))),3);
        bufp->chgCData(oldp+52,((0x0000001fU & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                >> 0x0000000fU))),5);
        bufp->chgCData(oldp+53,((0x0000001fU & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                >> 0x00000014U))),5);
        bufp->chgCData(oldp+54,((0x0000001fU & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                >> 7U))),5);
        bufp->chgIData(oldp+55,(vlSelfRef.top__DOT__Core_CPU__DOT__pc_id),32);
        bufp->chgCData(oldp+56,(vlSelfRef.top__DOT__Core_CPU__DOT__alu_op_ex),4);
        bufp->chgBit(oldp+57,(vlSelfRef.top__DOT__Core_CPU__DOT__alu_src_ex));
        bufp->chgIData(oldp+58,(vlSelfRef.top__DOT__Core_CPU__DOT__a_ex),32);
        bufp->chgIData(oldp+59,(vlSelfRef.top__DOT__Core_CPU__DOT__b_ex),32);
        bufp->chgIData(oldp+60,(vlSelfRef.top__DOT__Core_CPU__DOT__imm_ex),32);
        bufp->chgBit(oldp+61,(vlSelfRef.top__DOT__Core_CPU__DOT__jump_en_ex));
        bufp->chgBit(oldp+62,(vlSelfRef.top__DOT__Core_CPU__DOT__branch_en_ex));
        bufp->chgBit(oldp+63,(vlSelfRef.top__DOT__Core_CPU__DOT__is_jalr_ex));
        bufp->chgIData(oldp+64,(vlSelfRef.top__DOT__Core_CPU__DOT__pc_ex),32);
        bufp->chgBit(oldp+65,(vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_taken));
        bufp->chgIData(oldp+66,((IData)(((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__is_jalr_ex)
                                          ? (0x00000000fffffffeULL 
                                             & (VL_EXTENDS_QI(33,32, vlSelfRef.top__DOT__Core_CPU__DOT__a_ex) 
                                                + VL_EXTENDS_QI(33,32, vlSelfRef.top__DOT__Core_CPU__DOT__imm_ex)))
                                          : (QData)((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_target))))),32);
        bufp->chgIData(oldp+67,(vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_target),32);
        bufp->chgIData(oldp+68,(vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_result),32);
        bufp->chgIData(oldp+69,(((IData)(4U) + vlSelfRef.top__DOT__Core_CPU__DOT__pc_ex)),32);
        bufp->chgCData(oldp+70,(vlSelfRef.top__DOT__Core_CPU__DOT__store_op_ex),3);
        bufp->chgCData(oldp+71,(vlSelfRef.top__DOT__Core_CPU__DOT__load_op_ex),3);
        bufp->chgBit(oldp+72,((1U & (~ (7U == (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__load_op_ex))))));
        bufp->chgBit(oldp+73,((1U & (~ (7U == (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__store_op_ex))))));
        bufp->chgCData(oldp+74,(vlSelfRef.top__DOT__Core_CPU__DOT__rd_ex),5);
        bufp->chgBit(oldp+75,(vlSelfRef.top__DOT__Core_CPU__DOT__rd_en_ex));
        bufp->chgCData(oldp+76,(vlSelfRef.top__DOT__Core_CPU__DOT__rd_mem),5);
        bufp->chgBit(oldp+77,(vlSelfRef.top__DOT__Core_CPU__DOT__rd_en_mem));
        bufp->chgCData(oldp+78,(vlSelfRef.top__DOT__Core_CPU__DOT__rs2_ex),5);
        bufp->chgCData(oldp+79,(vlSelfRef.top__DOT__Core_CPU__DOT__rs2_mem),5);
        bufp->chgBit(oldp+80,(vlSelfRef.top__DOT__Core_CPU__DOT__is_lui_ex));
        bufp->chgBit(oldp+81,(vlSelfRef.top__DOT__Core_CPU__DOT__is_auipc_ex));
        bufp->chgBit(oldp+82,(((IData)(vlSelfRef.top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_1) 
                               & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_3))));
        bufp->chgBit(oldp+83,(((IData)(vlSelfRef.top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_2) 
                               & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_3))));
        bufp->chgBit(oldp+84,((((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_mem) 
                                == (0x0000001fU & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                   >> 0x0000000fU))) 
                               & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_en_mem))));
        bufp->chgBit(oldp+85,((((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_mem) 
                                == (0x0000001fU & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                   >> 0x00000014U))) 
                               & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_en_mem))));
        bufp->chgBit(oldp+86,(vlSelfRef.top__DOT__Core_CPU__DOT__LAR));
        bufp->chgIData(oldp+87,(vlSelfRef.top__DOT__Core_CPU__DOT__bypass_ex),32);
        bufp->chgBit(oldp+88,(vlSelfRef.top__DOT__Core_CPU__DOT__is_load_mem));
        bufp->chgBit(oldp+89,(vlSelfRef.top__DOT__Core_CPU__DOT__is_store_mem));
        bufp->chgIData(oldp+90,(vlSelfRef.top__DOT__Core_CPU__DOT__alu_result_mem),32);
        bufp->chgCData(oldp+91,(vlSelfRef.top__DOT__Core_CPU__DOT__store_op_mem),3);
        bufp->chgCData(oldp+92,(vlSelfRef.top__DOT__Core_CPU__DOT__load_op_mem),3);
        bufp->chgIData(oldp+93,(vlSelfRef.top__DOT__Core_CPU__DOT__wb_result_ex_reg),32);
        bufp->chgIData(oldp+94,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[1U]),32);
        bufp->chgIData(oldp+95,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[2U]),32);
        bufp->chgIData(oldp+96,(vlSelfRef.top__DOT__Core_CPU__DOT__rs[3U]),32);
        bufp->chgIData(oldp+97,(vlSelfRef.top__DOT__Core_CPU__DOT__rs_init__DOT__i),32);
        bufp->chgIData(oldp+98,(vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_b),32);
        bufp->chgQData(oldp+99,((0x00000001ffffffffULL 
                                 & (VL_EXTENDS_QI(33,32, vlSelfRef.top__DOT__Core_CPU__DOT__a_ex) 
                                    + VL_EXTENDS_QI(33,32, vlSelfRef.top__DOT__Core_CPU__DOT__imm_ex)))),33);
        bufp->chgCData(oldp+101,((0x0000007fU & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)),7);
        bufp->chgCData(oldp+102,((7U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                        >> 0x0000000cU))),3);
        bufp->chgCData(oldp+103,((vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                  >> 0x00000019U)),7);
        bufp->chgSData(oldp+104,((vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                  >> 0x00000014U)),12);
        bufp->chgSData(oldp+105,(((0x00000fe0U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                  >> 0x00000014U)) 
                                  | (0x0000001fU & 
                                     (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                      >> 7U)))),12);
        bufp->chgSData(oldp+106,(((((2U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                           >> 0x0000001eU)) 
                                    | (1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                             >> 7U))) 
                                   << 0x0000000bU) 
                                  | ((0x000007e0U & 
                                      (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                       >> 0x00000014U)) 
                                     | (0x0000001eU 
                                        & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                           >> 7U))))),13);
        bufp->chgIData(oldp+107,((vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                  >> 0x0000000cU)),20);
        bufp->chgIData(oldp+108,(((((0x00000200U & 
                                     (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                      >> 0x00000016U)) 
                                    | ((0x000001feU 
                                        & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                           >> 0x0000000bU)) 
                                       | (1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                >> 0x00000014U)))) 
                                   << 0x0000000bU) 
                                  | (0x000007feU & 
                                     (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                      >> 0x00000014U)))),21);
        bufp->chgIData(oldp+109,(vlSelfRef.top__DOT__u_perip__DOT__u_counter__DOT__cnt_ms),32);
        bufp->chgBit(oldp+110,(vlSelfRef.top__DOT__u_perip__DOT__u_counter__DOT__start));
        bufp->chgSData(oldp+111,(vlSelfRef.top__DOT__u_perip__DOT__u_counter__DOT__cnt_1ms),16);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgIData(oldp+112,(vlSelfRef.top__DOT__Core_CPU__DOT__bypass_mem),32);
        bufp->chgIData(oldp+113,(vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__spo),32);
        bufp->chgIData(oldp+114,(vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output),32);
    }
    bufp->chgBit(oldp+115,(vlSelfRef.clk));
    bufp->chgBit(oldp+116,(vlSelfRef.rst));
    bufp->chgIData(oldp+117,(vlSelfRef.perip_addr),32);
    bufp->chgIData(oldp+118,(vlSelfRef.perip_wdata),32);
    bufp->chgIData(oldp+119,(vlSelfRef.perip_rdata),32);
    bufp->chgCData(oldp+120,(vlSelfRef.perip_mask),3);
    bufp->chgBit(oldp+121,(vlSelfRef.perip_wen));
    bufp->chgBit(oldp+122,((1U & (~ (IData)(vlSelfRef.rst)))));
    bufp->chgBit(oldp+123,(((~ (IData)(vlSelfRef.rst)) 
                            & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__jump_en_ex))));
    bufp->chgIData(oldp+124,(((IData)(vlSelfRef.rst)
                               ? 0U : (IData)(((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__is_jalr_ex)
                                                ? (0x00000000fffffffeULL 
                                                   & (VL_EXTENDS_QI(33,32, vlSelfRef.top__DOT__Core_CPU__DOT__a_ex) 
                                                      + 
                                                      VL_EXTENDS_QI(33,32, vlSelfRef.top__DOT__Core_CPU__DOT__imm_ex)))
                                                : (QData)((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_target)))))),32);
    bufp->chgBit(oldp+125,(((~ (IData)(vlSelfRef.rst)) 
                            & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_taken))));
    bufp->chgIData(oldp+126,(((IData)(vlSelfRef.rst)
                               ? 0U : vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_target)),32);
    bufp->chgIData(oldp+127,(((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__nop)
                               ? vlSelfRef.top__DOT__Core_CPU__DOT__curr_pc_if
                               : (((~ (IData)(vlSelfRef.rst)) 
                                   & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__jump_en_ex))
                                   ? ((IData)(vlSelfRef.rst)
                                       ? 0U : (IData)(
                                                      ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__is_jalr_ex)
                                                        ? 
                                                       (0x00000000fffffffeULL 
                                                        & (VL_EXTENDS_QI(33,32, vlSelfRef.top__DOT__Core_CPU__DOT__a_ex) 
                                                           + 
                                                           VL_EXTENDS_QI(33,32, vlSelfRef.top__DOT__Core_CPU__DOT__imm_ex)))
                                                        : (QData)((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_target)))))
                                   : (((~ (IData)(vlSelfRef.rst)) 
                                       & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_taken))
                                       ? ((IData)(vlSelfRef.rst)
                                           ? 0U : vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_target)
                                       : ((IData)(4U) 
                                          + vlSelfRef.top__DOT__Core_CPU__DOT__curr_pc_if))))),32);
    bufp->chgBit(oldp+128,(((~ (IData)(vlSelfRef.rst)) 
                            & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0))));
    bufp->chgBit(oldp+129,(vlSelfRef.top__DOT__u_perip__DOT____Vcellinp__u_counter__cnt_wen));
    bufp->chgIData(oldp+130,(((2U & (IData)(vlSelfRef.perip_mask))
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
                                           ? ((0xff000000U 
                                               & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output) 
                                              | ((0x00ffff00U 
                                                  & (vlSelfRef.perip_wdata 
                                                     << 8U)) 
                                                 | (0x000000ffU 
                                                    & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output)))
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
    bufp->chgSData(oldp+131,((0x0000ffffU & (vlSelfRef.perip_addr 
                                             >> 2U))),16);
    bufp->chgCData(oldp+132,((3U & vlSelfRef.perip_addr)),2);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
