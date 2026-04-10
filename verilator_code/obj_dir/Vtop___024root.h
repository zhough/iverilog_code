// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        VL_OUT8(perip_mask,2,0);
        VL_OUT8(perip_wen,0,0);
        CData/*3:0*/ top__DOT__Core_CPU__DOT__alu_op_ex;
        CData/*0:0*/ top__DOT__Core_CPU__DOT__alu_src_ex;
        CData/*0:0*/ top__DOT__Core_CPU__DOT__jump_en_ex;
        CData/*0:0*/ top__DOT__Core_CPU__DOT__branch_en_ex;
        CData/*0:0*/ top__DOT__Core_CPU__DOT__is_jalr_ex;
        CData/*2:0*/ top__DOT__Core_CPU__DOT__store_op_ex;
        CData/*2:0*/ top__DOT__Core_CPU__DOT__load_op_ex;
        CData/*0:0*/ top__DOT__Core_CPU__DOT__id_clear;
        CData/*0:0*/ top__DOT__Core_CPU__DOT__ex_clear;
        CData/*4:0*/ top__DOT__Core_CPU__DOT__rd_ex;
        CData/*0:0*/ top__DOT__Core_CPU__DOT__rd_en_ex;
        CData/*4:0*/ top__DOT__Core_CPU__DOT__rd_mem;
        CData/*0:0*/ top__DOT__Core_CPU__DOT__rd_en_mem;
        CData/*4:0*/ top__DOT__Core_CPU__DOT__rs2_ex;
        CData/*4:0*/ top__DOT__Core_CPU__DOT__rs2_mem;
        CData/*0:0*/ top__DOT__Core_CPU__DOT__is_lui_ex;
        CData/*0:0*/ top__DOT__Core_CPU__DOT__is_auipc_ex;
        CData/*0:0*/ top__DOT__Core_CPU__DOT__is_load_mem;
        CData/*0:0*/ top__DOT__Core_CPU__DOT__is_store_mem;
        CData/*2:0*/ top__DOT__Core_CPU__DOT__store_op_mem;
        CData/*2:0*/ top__DOT__Core_CPU__DOT__load_op_mem;
        CData/*0:0*/ top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_1;
        CData/*0:0*/ top__DOT__Core_CPU__DOT____VdfgRegularize_h9cad441e_0_3;
        CData/*0:0*/ top__DOT__Core_CPU__DOT__u_IF__DOT__nop;
        CData/*0:0*/ top__DOT__Core_CPU__DOT__u_ID__DOT__alu_src_reg;
        CData/*0:0*/ top__DOT__Core_CPU__DOT__u_ID__DOT__is_jalr_reg;
        CData/*0:0*/ top__DOT__Core_CPU__DOT__u_ID__DOT__rd_en_reg;
        CData/*3:0*/ top__DOT__Core_CPU__DOT__u_ID__DOT__alu_op_reg;
        CData/*0:0*/ top__DOT__Core_CPU__DOT__u_EX__DOT__branch_taken;
        CData/*0:0*/ top__DOT__u_perip__DOT____Vcellinp__u_counter__cnt_wen;
        CData/*0:0*/ top__DOT__u_perip__DOT____VdfgRegularize_hff7cac4e_0_0;
        CData/*0:0*/ top__DOT__u_perip__DOT__u_counter__DOT__start;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __VicoPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        SData/*15:0*/ top__DOT__u_perip__DOT__u_counter__DOT__cnt_1ms;
        VL_OUT(perip_addr,31,0);
        VL_OUT(perip_wdata,31,0);
        VL_OUT(perip_rdata,31,0);
        VL_OUT(cnt,31,0);
        IData/*31:0*/ top__DOT__Core_CPU__DOT__curr_pc_if;
        IData/*31:0*/ top__DOT__Core_CPU__DOT__ins_id;
        IData/*31:0*/ top__DOT__Core_CPU__DOT__pc_id;
        IData/*31:0*/ top__DOT__Core_CPU__DOT__a_ex;
        IData/*31:0*/ top__DOT__Core_CPU__DOT__b_ex;
        IData/*31:0*/ top__DOT__Core_CPU__DOT__imm_ex;
        IData/*31:0*/ top__DOT__Core_CPU__DOT__pc_ex;
        IData/*31:0*/ top__DOT__Core_CPU__DOT__bypass_ex;
        IData/*31:0*/ top__DOT__Core_CPU__DOT__bypass_mem;
        IData/*31:0*/ top__DOT__Core_CPU__DOT__alu_result_mem;
        IData/*31:0*/ top__DOT__Core_CPU__DOT__wb_result_ex_reg;
        IData/*31:0*/ top__DOT__Core_CPU__DOT__rs_init__DOT__i;
        IData/*31:0*/ top__DOT__Core_CPU__DOT__u_IF__DOT__next_pc;
        IData/*31:0*/ top__DOT__Core_CPU__DOT__u_IF__DOT__irom_addr;
        IData/*31:0*/ top__DOT__Core_CPU__DOT__u_ID__DOT__imm_reg;
    };
    struct {
        IData/*31:0*/ top__DOT__Core_CPU__DOT__u_EX__DOT__branch_target;
        IData/*31:0*/ top__DOT__Core_CPU__DOT__u_EX__DOT__alu_result;
        IData/*31:0*/ top__DOT__Core_CPU__DOT__u_EX__DOT__alu_b;
        IData/*31:0*/ top__DOT__u_perip__DOT__LED;
        IData/*31:0*/ top__DOT__u_perip__DOT__SEG;
        IData/*31:0*/ top__DOT__u_perip__DOT__sim_seg;
        IData/*31:0*/ top__DOT__u_perip__DOT__u_dram__DOT__spo;
        IData/*31:0*/ top__DOT__u_perip__DOT__u_dram__DOT__tmp_output;
        IData/*31:0*/ top__DOT__u_perip__DOT__u_counter__DOT__cnt_ms;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 8193> top__DOT__u_irom__DOT__mem;
        VlUnpacked<IData/*31:0*/, 32> top__DOT__Core_CPU__DOT__rs;
        VlUnpacked<IData/*31:0*/, 65536> top__DOT__u_perip__DOT__u_dram__DOT__mem;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
        VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    };

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
