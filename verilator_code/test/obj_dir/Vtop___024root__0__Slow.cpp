// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop___024root____Vm_traceActivitySetAll(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_static__TOP(vlSelf);
    Vtop___024root____Vm_traceActivitySetAll(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
}

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->top__DOT__Core_CPU__DOT__rs_init__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3190486148428065233ull);
    vlSelf->top__DOT__u_perip__DOT__u_dram__DOT__init_ram__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11475104900743253298ull);
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    Vtop___024root____Vm_traceActivitySetAll(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_READMEM_N(true, 32, 8193, 0, "test.hex"s,  &(vlSelfRef.top__DOT__u_irom__DOT__mem)
                 , 0, ~0ULL);
    vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__init_ram__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00010000U, vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__init_ram__DOT__i)) {
        vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__mem[(0x0000ffffU 
                                                            & vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__init_ram__DOT__i)] = 0U;
        vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__init_ram__DOT__i 
            = ((IData)(1U) + vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__init_ram__DOT__i);
    }
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("top.v", 1, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtop___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vtop___024root___eval_triggers_vec__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ top__DOT__Core_CPU__DOT__u_ID__DOT____VdfgExtracted_h95c0b210__0;
    top__DOT__Core_CPU__DOT__u_ID__DOT____VdfgExtracted_h95c0b210__0 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_1;
    __VdfgRegularize_h6e95ff9d_0_1 = 0;
    // Body
    vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__irom_addr 
        = ((IData)(vlSelfRef.rst) ? 0U : vlSelfRef.top__DOT__Core_CPU__DOT__curr_pc_if);
    vlSelfRef.top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_3 
        = ((7U == (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__load_op_ex)) 
           & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_en_ex));
    vlSelfRef.perip_wdata = vlSelfRef.top__DOT__Core_CPU__DOT__rs
        [vlSelfRef.top__DOT__Core_CPU__DOT__rs2_mem];
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
    if (vlSelfRef.top__DOT__Core_CPU__DOT__is_store_mem) {
        vlSelfRef.perip_wen = 1U;
        vlSelfRef.perip_mask = vlSelfRef.top__DOT__Core_CPU__DOT__store_op_mem;
    } else {
        vlSelfRef.perip_wen = 0U;
        vlSelfRef.perip_mask = vlSelfRef.top__DOT__Core_CPU__DOT__load_op_mem;
    }
    vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_target 
        = (vlSelfRef.top__DOT__Core_CPU__DOT__imm_ex 
           + vlSelfRef.top__DOT__Core_CPU__DOT__pc_ex);
    vlSelfRef.top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_1 
        = ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_ex) 
           == (0x0000001fU & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                              >> 0x0000000fU)));
    vlSelfRef.top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_2 
        = ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__rd_ex) 
           == (0x0000001fU & (vlSelfRef.top__DOT__Core_CPU__DOT__ins_id 
                              >> 0x00000014U)));
    vlSelfRef.perip_addr = vlSelfRef.top__DOT__Core_CPU__DOT__alu_result_mem;
    vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_b 
        = ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__alu_src_ex)
            ? vlSelfRef.top__DOT__Core_CPU__DOT__imm_ex
            : vlSelfRef.top__DOT__Core_CPU__DOT__b_ex);
    vlSelfRef.top__DOT__Core_CPU__DOT__LAR = ((~ (7U 
                                                  == (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__load_op_ex))) 
                                              & ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_1) 
                                                 | (IData)(vlSelfRef.top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_2)));
    vlSelfRef.top__DOT__u_perip__DOT____Vcellinp__u_counter__cnt_wen 
        = ((IData)(vlSelfRef.perip_wen) & (0x80200050U 
                                           == vlSelfRef.perip_addr));
    vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__tmp_output 
        = vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__mem
        [(0x0000ffffU & (vlSelfRef.perip_addr >> 2U))];
    __VdfgRegularize_h6e95ff9d_0_1 = (vlSelfRef.top__DOT__Core_CPU__DOT__a_ex 
                                      == vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__alu_b);
    vlSelfRef.top__DOT__Core_CPU__DOT__u_IF__DOT__nop 
        = ((~ (IData)(vlSelfRef.rst)) & (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__LAR));
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
    vlSelfRef.perip_rdata = vlSelfRef.top__DOT__u_perip__DOT__u_dram__DOT__spo;
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
    vlSelfRef.top__DOT__Core_CPU__DOT__bypass_mem = 
        ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__is_load_mem)
          ? vlSelfRef.perip_rdata : vlSelfRef.top__DOT__Core_CPU__DOT__wb_result_ex_reg);
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0 = ((IData)(vlSelfRef.top__DOT__Core_CPU__DOT__jump_en_ex) 
                                                | (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__u_EX__DOT__branch_taken));
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
    vlSelfRef.top__DOT__Core_CPU__DOT__ex_clear = (
                                                   (~ (IData)(vlSelfRef.rst)) 
                                                   & ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0) 
                                                      | (IData)(vlSelfRef.top__DOT__Core_CPU__DOT__LAR)));
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        Vtop___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root____Vm_traceActivitySetAll(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vm_traceActivitySetAll\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
}

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->perip_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1416728468776563980ull);
    vlSelf->perip_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12332798090878616354ull);
    vlSelf->perip_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8881359032996310212ull);
    vlSelf->perip_mask = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11206691864274418739ull);
    vlSelf->perip_wen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8673429438361807766ull);
    for (int __Vi0 = 0; __Vi0 < 8193; ++__Vi0) {
        vlSelf->top__DOT__u_irom__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5205021887605429744ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__Core_CPU__DOT__rs[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11065142238278649994ull);
    }
    vlSelf->top__DOT__Core_CPU__DOT__curr_pc_if = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5781772083734552645ull);
    vlSelf->top__DOT__Core_CPU__DOT__ins_id = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1416182889179704082ull);
    vlSelf->top__DOT__Core_CPU__DOT__pc_id = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3624364772898448021ull);
    vlSelf->top__DOT__Core_CPU__DOT__alu_op_ex = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15507227255812958402ull);
    vlSelf->top__DOT__Core_CPU__DOT__alu_src_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2979397692809509120ull);
    vlSelf->top__DOT__Core_CPU__DOT__a_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6198742262592014407ull);
    vlSelf->top__DOT__Core_CPU__DOT__b_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4903180227490798816ull);
    vlSelf->top__DOT__Core_CPU__DOT__imm_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 756603068634338972ull);
    vlSelf->top__DOT__Core_CPU__DOT__jump_en_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2468981229770276001ull);
    vlSelf->top__DOT__Core_CPU__DOT__branch_en_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13056693022017084733ull);
    vlSelf->top__DOT__Core_CPU__DOT__is_jalr_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12631721371701732710ull);
    vlSelf->top__DOT__Core_CPU__DOT__pc_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4133175940656945580ull);
    vlSelf->top__DOT__Core_CPU__DOT__store_op_ex = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 437043971029262656ull);
    vlSelf->top__DOT__Core_CPU__DOT__load_op_ex = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10086496404773067014ull);
    vlSelf->top__DOT__Core_CPU__DOT__ex_clear = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5400678360753628437ull);
    vlSelf->top__DOT__Core_CPU__DOT__rd_ex = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13472597262633900928ull);
    vlSelf->top__DOT__Core_CPU__DOT__rd_en_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5174194619668273020ull);
    vlSelf->top__DOT__Core_CPU__DOT__rd_mem = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 22632372593929824ull);
    vlSelf->top__DOT__Core_CPU__DOT__rd_en_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1114074597708406138ull);
    vlSelf->top__DOT__Core_CPU__DOT__rs2_ex = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 18432718840672844157ull);
    vlSelf->top__DOT__Core_CPU__DOT__rs2_mem = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15533158008969721118ull);
    vlSelf->top__DOT__Core_CPU__DOT__is_lui_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6807351806144286666ull);
    vlSelf->top__DOT__Core_CPU__DOT__is_auipc_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11983852667651786972ull);
    vlSelf->top__DOT__Core_CPU__DOT__LAR = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18094534963797638445ull);
    vlSelf->top__DOT__Core_CPU__DOT__bypass_ex = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12838318535232407282ull);
    vlSelf->top__DOT__Core_CPU__DOT__bypass_mem = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15924674663390275741ull);
    vlSelf->top__DOT__Core_CPU__DOT__is_load_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1789058555812411618ull);
    vlSelf->top__DOT__Core_CPU__DOT__is_store_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6483697475256982629ull);
    vlSelf->top__DOT__Core_CPU__DOT__alu_result_mem = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7556492219360413051ull);
    vlSelf->top__DOT__Core_CPU__DOT__store_op_mem = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12902187185226055673ull);
    vlSelf->top__DOT__Core_CPU__DOT__load_op_mem = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7635618589211977564ull);
    vlSelf->top__DOT__Core_CPU__DOT__wb_result_ex_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11429834204813670271ull);
    vlSelf->top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_1 = 0;
    vlSelf->top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_2 = 0;
    vlSelf->top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_3 = 0;
    vlSelf->top__DOT__Core_CPU__DOT__u_IF__DOT__nop = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7136714084287769139ull);
    vlSelf->top__DOT__Core_CPU__DOT__u_IF__DOT__next_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10470252615958907146ull);
    vlSelf->top__DOT__Core_CPU__DOT__u_IF__DOT__irom_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7933542339997265062ull);
    vlSelf->top__DOT__Core_CPU__DOT__u_ID__DOT__alu_src_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1909236030422342575ull);
    vlSelf->top__DOT__Core_CPU__DOT__u_ID__DOT__is_jalr_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2697973127225554140ull);
    vlSelf->top__DOT__Core_CPU__DOT__u_ID__DOT__rd_en_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2128236224390144920ull);
    vlSelf->top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12939895770733245646ull);
    vlSelf->top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3198911394573559754ull);
    vlSelf->top__DOT__Core_CPU__DOT__u_EX__DOT__branch_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7677319727073218670ull);
    vlSelf->top__DOT__Core_CPU__DOT__u_EX__DOT__branch_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2866116361309785141ull);
    vlSelf->top__DOT__Core_CPU__DOT__u_EX__DOT__alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8129971654601081709ull);
    vlSelf->top__DOT__Core_CPU__DOT__u_EX__DOT__alu_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10630318120171847936ull);
    vlSelf->top__DOT__u_perip__DOT__LED = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1894426308412184407ull);
    vlSelf->top__DOT__u_perip__DOT__SEG = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17325043110998937731ull);
    vlSelf->top__DOT__u_perip__DOT____Vcellinp__u_counter__cnt_wen = 0;
    vlSelf->top__DOT__u_perip__DOT__u_dram__DOT__spo = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4589575433549223965ull);
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->top__DOT__u_perip__DOT__u_dram__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10879169642896802155ull);
    }
    vlSelf->top__DOT__u_perip__DOT__u_dram__DOT__tmp_output = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5181475601198042246ull);
    vlSelf->top__DOT__u_perip__DOT__u_counter__DOT__start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10456829150226572281ull);
    vlSelf->top__DOT__u_perip__DOT__u_counter__DOT__cnt_1ms = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3540873619712340833ull);
    vlSelf->top__DOT__u_perip__DOT__u_counter__DOT__cnt_ms = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7686826653675721915ull);
    vlSelf->__VdfgRegularize_h6e95ff9d_0_0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
