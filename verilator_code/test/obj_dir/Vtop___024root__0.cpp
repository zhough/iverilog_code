// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop___024root___eval_triggers_vec__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__irom_addr 
        = ((IData)(vlSelfRef.rst) ? 0U : vlSelfRef.top__DOT__Core_CPU__DOT__curr_pc_if);
    vlSelfRef.top__DOT__Core_CPU__DOT__ex_clear = (
                                                   (~ (IData)(vlSelfRef.rst)) 
                                                   & ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0) 
                                                      | (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__LAR)));
    vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__nop 
        = ((~ (IData)(vlSelfRef.rst)) & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__LAR));
    vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__next_pc 
        = ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__nop)
            ? vlSelfRef.top__DOT__Core_CPU__DOT__curr_pc_if
            : (((~ (IData)(vlSelfRef.rst)) & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__jump_en_ex))
                ? ((IData)(vlSelfRef.rst) ? 0U : (IData)(
                                                         ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__is_jalr_ex)
                                                           ? 
                                                          (0x00000000fffffffeULL 
                                                           & (VL_EXTENDS_QI(33,32, vlSelfRef.top__DOT__Core_CPU__DOT__a_ex) 
                                                              + 
                                                              VL_EXTENDS_QI(33,32, vlSelfRef.top__DOT__Core_CPU__DOT__imm_ex)))
                                                           : (QData)((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_target)))))
                : (((~ (IData)(vlSelfRef.rst)) & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_taken))
                    ? ((IData)(vlSelfRef.rst) ? 0U : vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_target)
                    : ((IData)(4U) + vlSelfRef.top__DOT__Core_CPU__DOT__curr_pc_if))));
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers_vec__ico(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_triggers_vec__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((IData)(vlSelfRef.rst) 
                                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst__0))) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.clk) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ top__DOT__Core_CPU__DOT__u_ID__DOT____VdfgExtracted_h95c0b210__0;
    top__DOT__Core_CPU__DOT__u_ID__DOT____VdfgExtracted_h95c0b210__0 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_1;
    __VdfgRegularize_h6e95ff9d_0_1 = 0;
    IData/*31:0*/ __Vdly__top__DOT__Core_CPU__DOT__ins_id;
    __Vdly__top__DOT__Core_CPU__DOT__ins_id = 0;
    SData/*15:0*/ __Vdly__top__DOT__u_perip__DOT__u_counter__DOT__cnt_1ms;
    __Vdly__top__DOT__u_perip__DOT__u_counter__DOT__cnt_1ms = 0;
    IData/*31:0*/ __Vdly__top__DOT__u_perip__DOT__u_counter__DOT__cnt_ms;
    __Vdly__top__DOT__u_perip__DOT__u_counter__DOT__cnt_ms = 0;
    CData/*0:0*/ __VdlySet__top__DOT__Core_CPU__DOT__rs__v0;
    __VdlySet__top__DOT__Core_CPU__DOT__rs__v0 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__Core_CPU__DOT__rs__v34;
    __VdlyVal__top__DOT__Core_CPU__DOT__rs__v34 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__Core_CPU__DOT__rs__v34;
    __VdlyDim0__top__DOT__Core_CPU__DOT__rs__v34 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__Core_CPU__DOT__rs__v34;
    __VdlySet__top__DOT__Core_CPU__DOT__rs__v34 = 0;
    // Body
    __Vdly__top__DOT__u_perip__DOT__u_counter__DOT__cnt_1ms 
        = vlSelfRef.top__DOT__u_perip__DOT__u_counter__DOT__cnt_1ms;
    __Vdly__top__DOT__u_perip__DOT__u_counter__DOT__cnt_ms 
        = vlSelfRef.top__DOT__u_perip__DOT__u_counter__DOT__cnt_ms;
    __Vdly__top__DOT__Core_CPU__DOT__ins_id = vlSelfRef.top__DOT__Core_CPU__DOT__ins_id;
    __VdlySet__top__DOT__Core_CPU__DOT__rs__v0 = 0U;
    __VdlySet__top__DOT__Core_CPU__DOT__rs__v34 = 0U;
    vlSelfRef.top__DOT__Core_CPU__DOT__is_jalr_ex = 
        ((1U & (~ (IData)(vlSelfRef.rst))) && ((1U 
                                                & (~ (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__ex_clear))) 
                                               && (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__is_jalr_reg)));
    vlSelfRef.top__DOT__Core_CPU__DOT__is_lui_ex = 
        ((1U & (~ (IData)(vlSelfRef.rst))) && ((1U 
                                                & (~ (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__ex_clear))) 
                                               && ((1U 
                                                    & (~ 
                                                       (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                        >> 6U))) 
                                                   && ((1U 
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
    vlSelfRef.top__DOT__Core_CPU__DOT__is_auipc_ex 
        = ((1U & (~ (IData)(vlSelfRef.rst))) && ((1U 
                                                  & (~ (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__ex_clear))) 
                                                 && ((1U 
                                                      & (~ 
                                                         (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                          >> 6U))) 
                                                     && ((1U 
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
    vlSelfRef.top__DOT__Core_CPU__DOT__jump_en_ex = 
        ((1U & (~ (IData)(vlSelfRef.rst))) && ((1U 
                                                & (~ (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__ex_clear))) 
                                               && ((1U 
                                                    & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                       >> 6U)) 
                                                   && ((1U 
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
    vlSelfRef.top__DOT__Core_CPU__DOT__is_store_mem 
        = ((1U & (~ (IData)(vlSelfRef.rst))) && (1U 
                                                 & (~ 
                                                    (7U 
                                                     == (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__store_op_ex)))));
    vlSelfRef.top__DOT__Core_CPU__DOT__is_load_mem 
        = ((1U & (~ (IData)(vlSelfRef.rst))) && (1U 
                                                 & (~ 
                                                    (7U 
                                                     == (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__load_op_ex)))));
    if (vlSelfRef.rst) {
        vlSelfRef.top__DOT__Core_CPU__DOT__rs_init__DOT__i = 0x00000020U;
        __Vdly__top__DOT__u_perip__DOT__u_counter__DOT__cnt_1ms = 0U;
        __Vdly__top__DOT__u_perip__DOT__u_counter__DOT__cnt_ms = 0U;
        __Vdly__top__DOT__Core_CPU__DOT__ins_id = 0U;
        __VdlySet__top__DOT__Core_CPU__DOT__rs__v0 = 1U;
        vlSelfRef.top__DOT__Core_CPU__DOT__wb_result_ex_reg = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__curr_pc_if = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__alu_result_mem = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__alu_op_ex = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__branch_en_ex = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__pc_ex = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__alu_src_ex = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs2_mem = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__store_op_mem = 7U;
        vlSelfRef.top__DOT__Core_CPU__DOT__imm_ex = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__load_op_mem = 7U;
        vlSelfRef.top__DOT__Core_CPU__DOT__b_ex = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__a_ex = 0U;
        vlSelfRef.top__DOT__u_perip__DOT__u_counter__DOT__start = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__pc_id = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs2_ex = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__store_op_ex = 7U;
        vlSelfRef.top__DOT__Core_CPU__DOT__load_op_ex = 7U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rd_mem = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__irom_addr = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rd_ex = 0U;
    } else {
        __Vdly__top__DOT__u_perip__DOT__u_counter__DOT__cnt_1ms 
            = ((IData)(vlSelfRef.top__DOT__u_perip__DOT__u_counter__DOT__start)
                ? ((0xc34fU == (IData)(vlSelfRef.top__DOT__u_perip__DOT__u_counter__DOT__cnt_1ms))
                    ? 0U : (0x0000ffffU & ((IData)(1U) 
                                           + (IData)(vlSelfRef.top__DOT__u_perip__DOT__u_counter__DOT__cnt_1ms))))
                : 0U);
        if (((IData)(vlSelfRef.top__DOT__u_perip__DOT__u_counter__DOT__start) 
             & (0xc34fU == (IData)(vlSelfRef.top__DOT__u_perip__DOT__u_counter__DOT__cnt_1ms)))) {
            __Vdly__top__DOT__u_perip__DOT__u_counter__DOT__cnt_ms 
                = ((IData)(1U) + vlSelfRef.top__DOT__u_perip__DOT__u_counter__DOT__cnt_ms);
        }
        __Vdly__top__DOT__Core_CPU__DOT__ins_id = (
                                                   ((~ (IData)(vlSelfRef.rst)) 
                                                    & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0))
                                                    ? 0U
                                                    : 
                                                   ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__nop)
                                                     ? vlSelfRef.top__DOT__Core_CPU__DOT__ins_id
                                                     : vlSelfRef.top__DOT__u_irom__DOT__mem
                                                    [
                                                    (0x00001fffU 
                                                     & (vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__irom_addr 
                                                        >> 2U))]));
        if (((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_en_mem) 
             & (0U != (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_mem)))) {
            __VdlyVal__top__DOT__Core_CPU__DOT__rs__v34 
                = vlSelfRef.top__DOT__Core_CPU__DOT__bypass_mem;
            __VdlyDim0__top__DOT__Core_CPU__DOT__rs__v34 
                = vlSelfRef.top__DOT__Core_CPU__DOT__rd_mem;
            __VdlySet__top__DOT__Core_CPU__DOT__rs__v34 = 1U;
        }
        vlSelfRef.top__DOT__Core_CPU__DOT__wb_result_ex_reg 
            = vlSelfRef.top__DOT__Core_CPU__DOT__bypass_ex;
        vlSelfRef.top__DOT__Core_CPU__DOT__curr_pc_if 
            = vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__next_pc;
        vlSelfRef.top__DOT__Core_CPU__DOT__alu_result_mem 
            = vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_result;
        if ((1U & (~ (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__ex_clear)))) {
            vlSelfRef.top__DOT__Core_CPU__DOT__branch_en_ex 
                = ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                          >> 6U)) && ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                             >> 5U)) 
                                      && ((1U & (~ 
                                                 (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                  >> 4U))) 
                                          && ((1U & 
                                               (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                   >> 3U))) 
                                              && ((1U 
                                                   & (~ 
                                                      (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                       >> 2U))) 
                                                  && ((1U 
                                                       & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                          >> 1U)) 
                                                      && (1U 
                                                          & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)))))));
            vlSelfRef.top__DOT__Core_CPU__DOT__alu_src_ex 
                = vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_src_reg;
        }
        vlSelfRef.top__DOT__Core_CPU__DOT__rs2_mem 
            = vlSelfRef.top__DOT__Core_CPU__DOT__rs2_ex;
        vlSelfRef.top__DOT__Core_CPU__DOT__store_op_mem 
            = vlSelfRef.top__DOT__Core_CPU__DOT__store_op_ex;
        vlSelfRef.top__DOT__Core_CPU__DOT__load_op_mem 
            = vlSelfRef.top__DOT__Core_CPU__DOT__load_op_ex;
        if (((IData)(vlSelfRef.top__DOT__u_perip__DOT____Vcellinp__u_counter__cnt_wen) 
             & (0x80000000U == vlSelfRef.perip_wdata))) {
            vlSelfRef.top__DOT__u_perip__DOT__u_counter__DOT__start = 1U;
        } else if (((IData)(vlSelfRef.top__DOT__u_perip__DOT____Vcellinp__u_counter__cnt_wen) 
                    & (0xffffffffU == vlSelfRef.perip_wdata))) {
            vlSelfRef.top__DOT__u_perip__DOT__u_counter__DOT__start = 0U;
        }
        if (vlSelfRef.top__DOT__Core_CPU__DOT__ex_clear) {
            vlSelfRef.top__DOT__Core_CPU__DOT__alu_op_ex = 0U;
            vlSelfRef.top__DOT__Core_CPU__DOT__pc_ex = 0U;
            vlSelfRef.top__DOT__Core_CPU__DOT__pc_id 
                = vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__irom_addr;
            vlSelfRef.top__DOT__Core_CPU__DOT__imm_ex = 0U;
            vlSelfRef.top__DOT__Core_CPU__DOT__b_ex = 0U;
            vlSelfRef.top__DOT__Core_CPU__DOT__a_ex = 0U;
            vlSelfRef.top__DOT__Core_CPU__DOT__rd_mem 
                = vlSelfRef.top__DOT__Core_CPU__DOT__rd_ex;
            vlSelfRef.top__DOT__Core_CPU__DOT__rs2_ex = 0U;
            vlSelfRef.top__DOT__Core_CPU__DOT__store_op_ex = 7U;
            vlSelfRef.top__DOT__Core_CPU__DOT__load_op_ex = 7U;
            vlSelfRef.top__DOT__Core_CPU__DOT__rd_ex = 0U;
        } else {
            vlSelfRef.top__DOT__Core_CPU__DOT__alu_op_ex 
                = vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg;
            vlSelfRef.top__DOT__Core_CPU__DOT__pc_ex 
                = vlSelfRef.top__DOT__Core_CPU__DOT__pc_id;
            vlSelfRef.top__DOT__Core_CPU__DOT__pc_id 
                = vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__irom_addr;
            vlSelfRef.top__DOT__Core_CPU__DOT__imm_ex 
                = vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg;
            vlSelfRef.top__DOT__Core_CPU__DOT__b_ex 
                = (((IData)(vlSelfRef.top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_2) 
                    & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_3))
                    ? vlSelfRef.top__DOT__Core_CPU__DOT__bypass_ex
                    : ((((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_mem) 
                         == (0x0000001fU & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                            >> 0x00000014U))) 
                        & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_en_mem))
                        ? vlSelfRef.top__DOT__Core_CPU__DOT__bypass_mem
                        : vlSelfRef.top__DOT__Core_CPU__DOT__rs
                       [(0x0000001fU & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                        >> 0x00000014U))]));
            vlSelfRef.top__DOT__Core_CPU__DOT__a_ex 
                = (((IData)(vlSelfRef.top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_1) 
                    & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_3))
                    ? vlSelfRef.top__DOT__Core_CPU__DOT__bypass_ex
                    : ((((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_mem) 
                         == (0x0000001fU & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                            >> 0x0000000fU))) 
                        & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_en_mem))
                        ? vlSelfRef.top__DOT__Core_CPU__DOT__bypass_mem
                        : vlSelfRef.top__DOT__Core_CPU__DOT__rs
                       [(0x0000001fU & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                        >> 0x0000000fU))]));
            vlSelfRef.top__DOT__Core_CPU__DOT__rd_mem 
                = vlSelfRef.top__DOT__Core_CPU__DOT__rd_ex;
            vlSelfRef.top__DOT__Core_CPU__DOT__rs2_ex 
                = (0x0000001fU & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                  >> 0x00000014U));
            if ((0x00000040U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                vlSelfRef.top__DOT__Core_CPU__DOT__store_op_ex = 7U;
                vlSelfRef.top__DOT__Core_CPU__DOT__load_op_ex = 7U;
            } else if ((0x00000020U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                vlSelfRef.top__DOT__Core_CPU__DOT__store_op_ex 
                    = ((0x00000010U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                        ? 7U : ((8U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                 ? 7U : ((4U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                          ? 7U : ((2U 
                                                   & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                                   ? 
                                                  ((1U 
                                                    & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                                    ? 
                                                   (7U 
                                                    & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                       >> 0x0000000cU))
                                                    : 7U)
                                                   : 7U))));
                vlSelfRef.top__DOT__Core_CPU__DOT__load_op_ex = 7U;
            } else {
                vlSelfRef.top__DOT__Core_CPU__DOT__store_op_ex = 7U;
                vlSelfRef.top__DOT__Core_CPU__DOT__load_op_ex 
                    = ((0x00000010U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                        ? 7U : ((8U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                 ? 7U : ((4U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                          ? 7U : ((2U 
                                                   & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                                   ? 
                                                  ((1U 
                                                    & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                                    ? 
                                                   (7U 
                                                    & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                       >> 0x0000000cU))
                                                    : 7U)
                                                   : 7U))));
            }
            vlSelfRef.top__DOT__Core_CPU__DOT__rd_ex 
                = (0x0000001fU & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                  >> 7U));
        }
        vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__irom_addr 
            = vlSelfRef.top__DOT__Core_CPU__DOT__curr_pc_if;
    }
    vlSelfRef.top__DOT__u_perip__DOT__u_counter__DOT__cnt_ms 
        = __Vdly__top__DOT__u_perip__DOT__u_counter__DOT__cnt_ms;
    vlSelfRef.top__DOT__u_perip__DOT__u_counter__DOT__cnt_1ms 
        = __Vdly__top__DOT__u_perip__DOT__u_counter__DOT__cnt_1ms;
    if (__VdlySet__top__DOT__Core_CPU__DOT__rs__v0) {
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[0U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[1U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[2U] = 0x00001000U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[3U] = 0x00001800U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[2U] = 0x00001000U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[3U] = 0x00001800U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[4U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[5U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[6U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[7U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[8U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[9U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[10U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[11U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[12U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[13U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[14U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[15U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[16U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[17U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[18U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[19U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[20U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[21U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[22U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[23U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[24U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[25U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[26U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[27U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[28U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[29U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[30U] = 0U;
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[31U] = 0U;
    }
    if (__VdlySet__top__DOT__Core_CPU__DOT__rs__v34) {
        vlSelfRef.top__DOT__Core_CPU__DOT__rs[__VdlyDim0__top__DOT__Core_CPU__DOT__rs__v34] 
            = __VdlyVal__top__DOT__Core_CPU__DOT__rs__v34;
    }
    vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_target 
        = (vlSelfRef.top__DOT__Core_CPU__DOT__imm_ex 
           + vlSelfRef.top__DOT__Core_CPU__DOT__pc_ex);
    vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_b 
        = ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__alu_src_ex)
            ? vlSelfRef.top__DOT__Core_CPU__DOT__imm_ex
            : vlSelfRef.top__DOT__Core_CPU__DOT__b_ex);
    vlSelfRef.top__DOT__Core_CPU__DOT__rd_en_mem = 
        ((1U & (~ (IData)(vlSelfRef.rst))) && (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_en_ex));
    __VdfgRegularize_h6e95ff9d_0_1 = (vlSelfRef.top__DOT__Core_CPU__DOT__a_ex 
                                      == vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_b);
    vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_result 
        = ((8U & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__alu_op_ex))
            ? ((4U & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__alu_op_ex))
                ? ((2U & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__alu_op_ex))
                    ? ((1U & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__alu_op_ex))
                        ? 0U : ((vlSelfRef.top__DOT__Core_CPU__DOT__a_ex 
                                 >= vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_b)
                                 ? 1U : 0U)) : ((1U 
                                                 & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__alu_op_ex))
                                                 ? 
                                                (VL_GTES_III(32, vlSelfRef.top__DOT__Core_CPU__DOT__a_ex, vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_b)
                                                  ? 1U
                                                  : 0U)
                                                 : 
                                                ((IData)(__VdfgRegularize_h6e95ff9d_0_1)
                                                  ? 0U
                                                  : 1U)))
                : ((2U & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__alu_op_ex))
                    ? ((1U & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__alu_op_ex))
                        ? ((IData)(__VdfgRegularize_h6e95ff9d_0_1)
                            ? 1U : 0U) : ((vlSelfRef.top__DOT__Core_CPU__DOT__a_ex 
                                           < vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_b)
                                           ? 1U : 0U))
                    : ((1U & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__alu_op_ex))
                        ? (VL_LTS_III(32, vlSelfRef.top__DOT__Core_CPU__DOT__a_ex, vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_b)
                            ? 1U : 0U) : VL_SHIFTRS_III(32,32,5, vlSelfRef.top__DOT__Core_CPU__DOT__a_ex, 
                                                        (0x0000001fU 
                                                         & vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_b)))))
            : ((4U & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__alu_op_ex))
                ? ((2U & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__alu_op_ex))
                    ? ((1U & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__alu_op_ex))
                        ? (vlSelfRef.top__DOT__Core_CPU__DOT__a_ex 
                           >> (0x0000001fU & vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_b))
                        : (vlSelfRef.top__DOT__Core_CPU__DOT__a_ex 
                           << (0x0000001fU & vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_b)))
                    : ((1U & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__alu_op_ex))
                        ? (vlSelfRef.top__DOT__Core_CPU__DOT__a_ex 
                           ^ vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_b)
                        : (vlSelfRef.top__DOT__Core_CPU__DOT__a_ex 
                           | vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_b)))
                : ((2U & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__alu_op_ex))
                    ? ((1U & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__alu_op_ex))
                        ? (vlSelfRef.top__DOT__Core_CPU__DOT__a_ex 
                           & vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_b)
                        : (vlSelfRef.top__DOT__Core_CPU__DOT__a_ex 
                           - vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_b))
                    : ((1U & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__alu_op_ex))
                        ? (vlSelfRef.top__DOT__Core_CPU__DOT__a_ex 
                           + vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_b)
                        : 0U))));
    vlSelfRef.top__DOT__Core_CPU__DOT__rd_en_ex = (
                                                   (1U 
                                                    & (~ (IData)(vlSelfRef.rst))) 
                                                   && ((1U 
                                                        & (~ (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__ex_clear))) 
                                                       && (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__rd_en_reg)));
    vlSelfRef.top__DOT__Core_CPU__DOT__bypass_ex = 
        ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__is_lui_ex)
          ? vlSelfRef.top__DOT__Core_CPU__DOT__imm_ex
          : ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__is_auipc_ex)
              ? vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_target
              : ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__jump_en_ex)
                  ? ((IData)(4U) + vlSelfRef.top__DOT__Core_CPU__DOT__pc_ex)
                  : vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_result)));
    vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_taken 
        = ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__branch_en_ex) 
           & vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_result);
    vlSelfRef.top__DOT__Core_CPU__DOT__ins_id = __Vdly__top__DOT__Core_CPU__DOT__ins_id;
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0 = ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__jump_en_ex) 
                                                | (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_taken));
    vlSelfRef.top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_3 
        = ((7U == (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__load_op_ex)) 
           & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_en_ex));
    top__DOT__Core_CPU__DOT__u_ID__DOT____VdfgExtracted_h95c0b210__0 
        = (((- (IData)((vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                        >> 0x0000001fU))) << 0x0000000cU) 
           | (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
              >> 0x00000014U));
    if ((0x00000040U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
        vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__rd_en_reg 
            = ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                      >> 5U)) && ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                            >> 4U))) 
                                  && ((8U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                       ? ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                 >> 2U)) 
                                          && ((1U & 
                                               (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)))
                                       : ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                 >> 2U)) 
                                          && ((1U & 
                                               (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id))))));
        if ((0x00000020U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
            if ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                          >> 4U)))) {
                if ((8U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                    if ((4U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                        if ((2U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                            if ((1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__is_jalr_reg = 0U;
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                    if ((2U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                        if ((1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                            vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__is_jalr_reg = 1U;
                        }
                    }
                } else if ((2U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                    if ((1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                        vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__is_jalr_reg = 0U;
                    }
                }
            }
            if ((0x00000010U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 0U;
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg = 0U;
            } else if ((8U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 0U;
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg 
                    = ((4U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                        ? ((2U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                            ? ((1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                ? ((((0x00000ffeU & 
                                      ((- (IData)((vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                   >> 0x0000001fU))) 
                                       << 1U)) | (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                  >> 0x0000001fU)) 
                                    << 0x00000014U) 
                                   | ((((0x000001feU 
                                         & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                            >> 0x0000000bU)) 
                                        | (1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                 >> 0x00000014U))) 
                                       << 0x0000000bU) 
                                      | (0x000007feU 
                                         & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                            >> 0x00000014U))))
                                : 0U) : 0U) : 0U);
            } else if ((4U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 0U;
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg 
                    = ((2U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                        ? ((1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                            ? top__DOT__Core_CPU__DOT__u_ID__DOT____VdfgExtracted_h95c0b210__0
                            : 0U) : 0U);
            } else if ((2U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                if ((1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                    vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg 
                        = ((0x00004000U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                            ? ((0x00002000U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                ? ((0x00001000U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                    ? 0x0eU : 0x0aU)
                                : ((0x00001000U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                    ? 0x0dU : 9U)) : 
                           ((0x00002000U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                             ? 0U : ((0x00001000U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                      ? 0x0cU : 0x0bU)));
                    vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg 
                        = (((- (IData)((vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                        >> 0x0000001fU))) 
                            << 0x0000000dU) | ((((2U 
                                                  & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                     >> 0x0000001eU)) 
                                                 | (1U 
                                                    & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                       >> 7U))) 
                                                << 0x0000000bU) 
                                               | ((0x000007e0U 
                                                   & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                      >> 0x00000014U)) 
                                                  | (0x0000001eU 
                                                     & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                        >> 7U)))));
                } else {
                    vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 0U;
                    vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg = 0U;
                }
            } else {
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 0U;
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg = 0U;
            }
        } else {
            vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 0U;
            vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg = 0U;
        }
        vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_src_reg 
            = ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                      >> 5U)) && ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                            >> 4U))) 
                                  && ((8U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                       ? ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                 >> 2U)) 
                                          && ((1U & 
                                               (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)))
                                       : ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                 >> 2U)) 
                                          && ((1U & 
                                               (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id))))));
    } else if ((0x00000020U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
        if ((0x00000010U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
            if ((8U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__rd_en_reg = 0U;
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 0U;
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg = 0U;
            } else if ((4U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__rd_en_reg 
                    = ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                              >> 1U)) && (1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id));
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 0U;
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg 
                    = ((2U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                        ? ((1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                            ? (0xfffff000U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                            : 0U) : 0U);
            } else {
                if ((2U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                    if ((1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                        vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__rd_en_reg = 1U;
                        if ((1U & (~ ((((((((0U == 
                                             ((0x000003f8U 
                                               & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                  >> 0x00000016U)) 
                                              | (7U 
                                                 & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                    >> 0x0000000cU)))) 
                                            | (0x0100U 
                                               == (
                                                   (0x000003f8U 
                                                    & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                       >> 0x00000016U)) 
                                                   | (7U 
                                                      & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                         >> 0x0000000cU))))) 
                                           | (7U == 
                                              ((0x000003f8U 
                                                & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                   >> 0x00000016U)) 
                                               | (7U 
                                                  & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                     >> 0x0000000cU))))) 
                                          | (6U == 
                                             ((0x000003f8U 
                                               & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                  >> 0x00000016U)) 
                                              | (7U 
                                                 & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                    >> 0x0000000cU))))) 
                                         | (4U == (
                                                   (0x000003f8U 
                                                    & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                       >> 0x00000016U)) 
                                                   | (7U 
                                                      & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                         >> 0x0000000cU))))) 
                                        | (1U == ((0x000003f8U 
                                                   & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                      >> 0x00000016U)) 
                                                  | (7U 
                                                     & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                        >> 0x0000000cU))))) 
                                       | (5U == ((0x000003f8U 
                                                  & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                     >> 0x00000016U)) 
                                                 | (7U 
                                                    & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                       >> 0x0000000cU))))) 
                                      | (0x0105U == 
                                         ((0x000003f8U 
                                           & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                              >> 0x00000016U)) 
                                          | (7U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                   >> 0x0000000cU)))))))) {
                            if ((2U != ((0x000003f8U 
                                         & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                            >> 0x00000016U)) 
                                        | (7U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                 >> 0x0000000cU))))) {
                                if ((3U != ((0x000003f8U 
                                             & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                >> 0x00000016U)) 
                                            | (7U & 
                                               (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                >> 0x0000000cU))))) {
                                    vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__rd_en_reg = 0U;
                                }
                            }
                        }
                        vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg 
                            = (((((((((0U == ((0x000003f8U 
                                               & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                  >> 0x00000016U)) 
                                              | (7U 
                                                 & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                    >> 0x0000000cU)))) 
                                      | (0x0100U == 
                                         ((0x000003f8U 
                                           & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                              >> 0x00000016U)) 
                                          | (7U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                   >> 0x0000000cU))))) 
                                     | (7U == ((0x000003f8U 
                                                & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                   >> 0x00000016U)) 
                                               | (7U 
                                                  & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                     >> 0x0000000cU))))) 
                                    | (6U == ((0x000003f8U 
                                               & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                  >> 0x00000016U)) 
                                              | (7U 
                                                 & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                    >> 0x0000000cU))))) 
                                   | (4U == ((0x000003f8U 
                                              & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                 >> 0x00000016U)) 
                                             | (7U 
                                                & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                   >> 0x0000000cU))))) 
                                  | (1U == ((0x000003f8U 
                                             & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                >> 0x00000016U)) 
                                            | (7U & 
                                               (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                >> 0x0000000cU))))) 
                                 | (5U == ((0x000003f8U 
                                            & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                               >> 0x00000016U)) 
                                           | (7U & 
                                              (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                               >> 0x0000000cU))))) 
                                | (0x0105U == ((0x000003f8U 
                                                & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                   >> 0x00000016U)) 
                                               | (7U 
                                                  & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                     >> 0x0000000cU)))))
                                ? ((0U == ((0x000003f8U 
                                            & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                               >> 0x00000016U)) 
                                           | (7U & 
                                              (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                               >> 0x0000000cU))))
                                    ? 1U : ((0x0100U 
                                             == ((0x000003f8U 
                                                  & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                     >> 0x00000016U)) 
                                                 | (7U 
                                                    & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                       >> 0x0000000cU))))
                                             ? 2U : 
                                            ((7U == 
                                              ((0x000003f8U 
                                                & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                   >> 0x00000016U)) 
                                               | (7U 
                                                  & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                     >> 0x0000000cU))))
                                              ? 3U : 
                                             ((6U == 
                                               ((0x000003f8U 
                                                 & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                    >> 0x00000016U)) 
                                                | (7U 
                                                   & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                      >> 0x0000000cU))))
                                               ? 4U
                                               : ((4U 
                                                   == 
                                                   ((0x000003f8U 
                                                     & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                        >> 0x00000016U)) 
                                                    | (7U 
                                                       & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                          >> 0x0000000cU))))
                                                   ? 5U
                                                   : 
                                                  ((1U 
                                                    == 
                                                    ((0x000003f8U 
                                                      & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                         >> 0x00000016U)) 
                                                     | (7U 
                                                        & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                           >> 0x0000000cU))))
                                                    ? 6U
                                                    : 
                                                   ((5U 
                                                     == 
                                                     ((0x000003f8U 
                                                       & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                          >> 0x00000016U)) 
                                                      | (7U 
                                                         & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                            >> 0x0000000cU))))
                                                     ? 7U
                                                     : 8U)))))))
                                : ((2U == ((0x000003f8U 
                                            & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                               >> 0x00000016U)) 
                                           | (7U & 
                                              (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                               >> 0x0000000cU))))
                                    ? 9U : ((3U == 
                                             ((0x000003f8U 
                                               & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                  >> 0x00000016U)) 
                                              | (7U 
                                                 & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                    >> 0x0000000cU))))
                                             ? 0x0aU
                                             : 0U)));
                    } else {
                        vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__rd_en_reg = 0U;
                        vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 0U;
                    }
                } else {
                    vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__rd_en_reg = 0U;
                    vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 0U;
                }
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg = 0U;
            }
            if ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                          >> 3U)))) {
                if ((4U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                    if ((2U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                        if ((1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                            vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__is_jalr_reg = 0U;
                        }
                    }
                } else if ((2U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                    if ((1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                        vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__is_jalr_reg = 0U;
                    }
                }
            }
            vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_src_reg 
                = ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                             >> 3U))) && ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                 >> 2U)) 
                                          && ((1U & 
                                               (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id))));
        } else {
            vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__rd_en_reg = 0U;
            if ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                          >> 3U)))) {
                if ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                        if ((1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                            vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__is_jalr_reg = 0U;
                        }
                    }
                }
            }
            vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_src_reg 
                = ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                             >> 3U))) && ((1U & (~ 
                                                 (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                  >> 2U))) 
                                          && ((1U & 
                                               (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id))));
            if ((8U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 0U;
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg = 0U;
            } else if ((4U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 0U;
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg = 0U;
            } else if ((2U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                if ((1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                    vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 1U;
                    vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg 
                        = (((- (IData)((vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                        >> 0x0000001fU))) 
                            << 0x0000000cU) | ((0x00000fe0U 
                                                & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                   >> 0x00000014U)) 
                                               | (0x0000001fU 
                                                  & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                     >> 7U))));
                } else {
                    vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 0U;
                    vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg = 0U;
                }
            } else {
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 0U;
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg = 0U;
            }
        }
    } else if ((0x00000010U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
        vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__rd_en_reg 
            = ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                         >> 3U))) && ((4U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                       ? ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id))
                                       : ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id))));
        if ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                      >> 3U)))) {
            if ((4U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                if ((2U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                    if ((1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                        vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__is_jalr_reg = 0U;
                    }
                }
            } else if ((2U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                if ((1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                    vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__is_jalr_reg = 0U;
                }
            }
        }
        vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_src_reg 
            = ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                         >> 3U))) && ((4U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                       ? ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id))
                                       : ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id))));
        if ((8U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
            vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 0U;
            vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg = 0U;
        } else if ((4U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
            vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 0U;
            vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg 
                = ((2U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                    ? ((1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                        ? (0xfffff000U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                        : 0U) : 0U);
        } else if ((2U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
            if ((1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg 
                    = ((0x00004000U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                        ? ((0x00002000U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                            ? ((0x00001000U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                ? 3U : 4U) : ((0x00001000U 
                                               & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                               ? ((0U 
                                                   == 
                                                   (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                    >> 0x00000019U))
                                                   ? 7U
                                                   : 
                                                  ((0x20U 
                                                    == 
                                                    (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                     >> 0x00000019U))
                                                    ? 8U
                                                    : 0U))
                                               : 5U))
                        : ((0x00002000U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                            ? ((0x00001000U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                ? 0x0aU : 9U) : ((0x00001000U 
                                                  & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)
                                                  ? 
                                                 ((0U 
                                                   == 
                                                   (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                    >> 0x00000019U))
                                                   ? 6U
                                                   : 0U)
                                                  : 1U)));
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg 
                    = (((1U == (7U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                      >> 0x0000000cU))) 
                        | (5U == (7U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                        >> 0x0000000cU))))
                        ? (0x0000001fU & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                          >> 0x00000014U))
                        : top__DOT__Core_CPU__DOT__u_ID__DOT____VdfgExtracted_h95c0b210__0);
            } else {
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 0U;
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg = 0U;
            }
        } else {
            vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 0U;
            vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg = 0U;
        }
    } else {
        vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__rd_en_reg 
            = ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                         >> 3U))) && ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                >> 2U))) 
                                      && ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id))));
        if ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                      >> 3U)))) {
            if ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                          >> 2U)))) {
                if ((2U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                    if ((1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                        vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__is_jalr_reg = 0U;
                    }
                }
            }
        }
        vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_src_reg 
            = ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                         >> 3U))) && ((1U & (~ (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                >> 2U))) 
                                      && ((1U & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id))));
        if ((8U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
            vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 0U;
            vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg = 0U;
        } else if ((4U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
            vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 0U;
            vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg = 0U;
        } else if ((2U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
            if ((1U & vlSelfRef.top__DOT__Core_CPU__DOT__ins_id)) {
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 1U;
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg 
                    = top__DOT__Core_CPU__DOT__u_ID__DOT____VdfgExtracted_h95c0b210__0;
            } else {
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 0U;
                vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg = 0U;
            }
        } else {
            vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = 0U;
            vlSelfRef.top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg = 0U;
        }
    }
    vlSelfRef.top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_1 
        = ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_ex) 
           == (0x0000001fU & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                              >> 0x0000000fU)));
    vlSelfRef.top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_2 
        = ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_ex) 
           == (0x0000001fU & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                              >> 0x00000014U)));
    vlSelfRef.top__DOT__Core_CPU__DOT__LAR = ((~ (7U 
                                                  == (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__load_op_ex))) 
                                              & ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_1) 
                                                 | (IData)(vlSelfRef.top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_2)));
    vlSelfRef.top__DOT__Core_CPU__DOT__ex_clear = (
                                                   (~ (IData)(vlSelfRef.rst)) 
                                                   & ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0) 
                                                      | (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__LAR)));
    vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__nop 
        = ((~ (IData)(vlSelfRef.rst)) & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__LAR));
    vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__next_pc 
        = ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__nop)
            ? vlSelfRef.top__DOT__Core_CPU__DOT__curr_pc_if
            : (((~ (IData)(vlSelfRef.rst)) & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__jump_en_ex))
                ? ((IData)(vlSelfRef.rst) ? 0U : (IData)(
                                                         ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__is_jalr_ex)
                                                           ? 
                                                          (0x00000000fffffffeULL 
                                                           & (VL_EXTENDS_QI(33,32, vlSelfRef.top__DOT__Core_CPU__DOT__a_ex) 
                                                              + 
                                                              VL_EXTENDS_QI(33,32, vlSelfRef.top__DOT__Core_CPU__DOT__imm_ex)))
                                                           : (QData)((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_target)))))
                : (((~ (IData)(vlSelfRef.rst)) & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_taken))
                    ? ((IData)(vlSelfRef.rst) ? 0U : vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_target)
                    : ((IData)(4U) + vlSelfRef.top__DOT__Core_CPU__DOT__curr_pc_if))));
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VdlyVal__top__DOT__u_perip__DOT__u_dram__DOT__mem__v0;
    __VdlyVal__top__DOT__u_perip__DOT__u_dram__DOT__mem__v0 = 0;
    SData/*15:0*/ __VdlyDim0__top__DOT__u_perip__DOT__u_dram__DOT__mem__v0;
    __VdlyDim0__top__DOT__u_perip__DOT__u_dram__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__u_perip__DOT__u_dram__DOT__mem__v0;
    __VdlySet__top__DOT__u_perip__DOT__u_dram__DOT__mem__v0 = 0;
    // Body
    __VdlySet__top__DOT__u_perip__DOT__u_dram__DOT__mem__v0 = 0U;
    if (vlSelfRef.perip_wen) {
        __VdlyVal__top__DOT__u_perip__DOT__u_dram__DOT__mem__v0 
            = ((2U & (IData)(vlSelfRef.perip_mask))
                ? vlSelfRef.perip_wdata : ((1U & (IData)(vlSelfRef.perip_mask))
                                            ? ((2U 
                                                & vlSelfRef.perip_addr)
                                                ? (
                                                   (1U 
                                                    & vlSelfRef.perip_addr)
                                                    ? vlSelfRef.perip_wdata
                                                    : 
                                                   ((vlSelfRef.perip_wdata 
                                                     << 0x00000010U) 
                                                    | (0x0000ffffU 
                                                       & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output)))
                                                : (
                                                   (1U 
                                                    & vlSelfRef.perip_addr)
                                                    ? 
                                                   ((0xff000000U 
                                                     & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output) 
                                                    | ((0x00ffff00U 
                                                        & (vlSelfRef.perip_wdata 
                                                           << 8U)) 
                                                       | (0x000000ffU 
                                                          & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output)))
                                                    : 
                                                   ((0xffff0000U 
                                                     & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output) 
                                                    | (0x0000ffffU 
                                                       & vlSelfRef.perip_wdata))))
                                            : ((2U 
                                                & vlSelfRef.perip_addr)
                                                ? (
                                                   (1U 
                                                    & vlSelfRef.perip_addr)
                                                    ? 
                                                   ((vlSelfRef.perip_wdata 
                                                     << 0x00000018U) 
                                                    | (0x00ffffffU 
                                                       & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output))
                                                    : 
                                                   ((0xff000000U 
                                                     & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output) 
                                                    | ((0x00ff0000U 
                                                        & (vlSelfRef.perip_wdata 
                                                           << 0x00000010U)) 
                                                       | (0x0000ffffU 
                                                          & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output))))
                                                : (
                                                   (1U 
                                                    & vlSelfRef.perip_addr)
                                                    ? 
                                                   ((0xffff0000U 
                                                     & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output) 
                                                    | ((0x0000ff00U 
                                                        & (vlSelfRef.perip_wdata 
                                                           << 8U)) 
                                                       | (0x000000ffU 
                                                          & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output)))
                                                    : 
                                                   ((0xffffff00U 
                                                     & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output) 
                                                    | (0x000000ffU 
                                                       & vlSelfRef.perip_wdata))))));
        __VdlyDim0__top__DOT__u_perip__DOT__u_dram__DOT__mem__v0 
            = (0x0000ffffU & (vlSelfRef.perip_addr 
                              >> 2U));
        __VdlySet__top__DOT__u_perip__DOT__u_dram__DOT__mem__v0 = 1U;
    }
    if (__VdlySet__top__DOT__u_perip__DOT__u_dram__DOT__mem__v0) {
        vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__mem[__VdlyDim0__top__DOT__u_perip__DOT__u_dram__DOT__mem__v0] 
            = __VdlyVal__top__DOT__u_perip__DOT__u_dram__DOT__mem__v0;
    }
}

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.top__DOT__Core_CPU__DOT__is_store_mem) {
        vlSelfRef.perip_wen = 1U;
        vlSelfRef.perip_mask = vlSelfRef.top__DOT__Core_CPU__DOT__store_op_mem;
    } else {
        vlSelfRef.perip_wen = 0U;
        vlSelfRef.perip_mask = vlSelfRef.top__DOT__Core_CPU__DOT__load_op_mem;
    }
    vlSelfRef.perip_addr = vlSelfRef.top__DOT__Core_CPU__DOT__alu_result_mem;
    vlSelfRef.perip_wdata = vlSelfRef.top__DOT__Core_CPU__DOT__rs
        [vlSelfRef.top__DOT__Core_CPU__DOT__rs2_mem];
    vlSelfRef.top__DOT__u_perip__DOT____Vcellinp__u_counter__cnt_wen 
        = ((IData)(vlSelfRef.perip_wen) & (0x80200050U 
                                           == vlSelfRef.perip_addr));
}

void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output 
        = vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__mem
        [(0x0000ffffU & (vlSelfRef.perip_addr >> 2U))];
    vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__spo 
        = ((4U & (IData)(vlSelfRef.perip_mask)) ? (
                                                   (2U 
                                                    & (IData)(vlSelfRef.perip_mask))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.perip_mask))
                                                     ? 
                                                    ((2U 
                                                      & vlSelfRef.perip_addr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelfRef.perip_addr)
                                                       ? 0U
                                                       : 
                                                      VL_SHIFTR_III(32,32,32, vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output, 0x00000010U))
                                                      : 
                                                     ((1U 
                                                       & vlSelfRef.perip_addr)
                                                       ? 
                                                      (0x0000ffffU 
                                                       & (vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output 
                                                          >> 8U))
                                                       : 
                                                      (0x0000ffffU 
                                                       & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output)))
                                                     : 
                                                    ((2U 
                                                      & vlSelfRef.perip_addr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelfRef.perip_addr)
                                                       ? 
                                                      VL_SHIFTR_III(32,32,32, vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output, 0x00000018U)
                                                       : 
                                                      (0x000000ffU 
                                                       & (vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output 
                                                          >> 0x00000010U)))
                                                      : 
                                                     ((1U 
                                                       & vlSelfRef.perip_addr)
                                                       ? 
                                                      (0x000000ffU 
                                                       & (vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output 
                                                          >> 8U))
                                                       : 
                                                      (0x000000ffU 
                                                       & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output)))))
            : ((2U & (IData)(vlSelfRef.perip_mask))
                ? ((1U & (IData)(vlSelfRef.perip_mask))
                    ? 0U : ((2U & vlSelfRef.perip_addr)
                             ? 0U : ((1U & vlSelfRef.perip_addr)
                                      ? 0U : vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output)))
                : ((1U & (IData)(vlSelfRef.perip_mask))
                    ? ((2U & vlSelfRef.perip_addr) ? 
                       ((1U & vlSelfRef.perip_addr)
                         ? 0U : (((- (IData)((vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output 
                                              >> 0x0000001fU))) 
                                  << 0x00000010U) | 
                                 (vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output 
                                  >> 0x00000010U)))
                        : ((1U & vlSelfRef.perip_addr)
                            ? (((- (IData)((1U & (vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output 
                                                  >> 0x00000017U)))) 
                                << 0x00000010U) | (0x0000ffffU 
                                                   & (vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output 
                                                      >> 8U)))
                            : (((- (IData)((1U & (vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output 
                                                  >> 0x0000000fU)))) 
                                << 0x00000010U) | (0x0000ffffU 
                                                   & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output))))
                    : ((2U & vlSelfRef.perip_addr) ? 
                       ((1U & vlSelfRef.perip_addr)
                         ? (((- (IData)((vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output 
                                         >> 0x0000001fU))) 
                             << 8U) | (vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output 
                                       >> 0x00000018U))
                         : (((- (IData)((1U & (vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output 
                                               >> 0x00000017U)))) 
                             << 8U) | (0x000000ffU 
                                       & (vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output 
                                          >> 0x00000010U))))
                        : ((1U & vlSelfRef.perip_addr)
                            ? (((- (IData)((1U & (vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output 
                                                  >> 0x0000000fU)))) 
                                << 8U) | (0x000000ffU 
                                          & (vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output 
                                             >> 8U)))
                            : (((- (IData)((1U & (vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output 
                                                  >> 7U)))) 
                                << 8U) | (0x000000ffU 
                                          & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output)))))));
    vlSelfRef.perip_rdata = vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__spo;
    vlSelfRef.top__DOT__Core_CPU__DOT__bypass_mem = 
        ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__is_load_mem)
          ? vlSelfRef.perip_rdata : vlSelfRef.top__DOT__Core_CPU__DOT__wb_result_ex_reg);
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

void Vtop___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("top.v", 1, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vtop___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("top.v", 1, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("top.v", 1, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vtop___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtop___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");
    }
}
#endif  // VL_DEBUG
