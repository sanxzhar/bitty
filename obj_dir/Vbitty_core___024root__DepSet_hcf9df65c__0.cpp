// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitty_core.h for the primary calling header

#include "Vbitty_core__pch.h"
#include "Vbitty_core__Syms.h"
#include "Vbitty_core___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitty_core___024root___dump_triggers__ico(Vbitty_core___024root* vlSelf);
#endif  // VL_DEBUG

void Vbitty_core___024root___eval_triggers__ico(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_triggers__ico\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.set(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vbitty_core___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitty_core___024root___dump_triggers__act(Vbitty_core___024root* vlSelf);
#endif  // VL_DEBUG

void Vbitty_core___024root___eval_triggers__act(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_triggers__act\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__VactTriggered.set(1U, ((IData)(vlSelfRef.reset) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__reset__0))));
    vlSelfRef.__VactTriggered.set(2U, ((IData)(vlSelfRef.bitty_core__DOT__Monitor__DOT__en_dpi) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__bitty_core__DOT__Monitor__DOT__en_dpi__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
    vlSelfRef.__Vtrigprevexpr___TOP__bitty_core__DOT__Monitor__DOT__en_dpi__0 
        = vlSelfRef.bitty_core__DOT__Monitor__DOT__en_dpi;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vbitty_core___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vbitty_core___024unit____Vdpiimwrap_compare_results_TOP____024unit(SData/*15:0*/ instruction, SData/*15:0*/ reg0, SData/*15:0*/ reg1, SData/*15:0*/ reg2, SData/*15:0*/ reg3, SData/*15:0*/ reg4, SData/*15:0*/ reg5, SData/*15:0*/ reg6, SData/*15:0*/ reg7);

VL_INLINE_OPT void Vbitty_core___024root___nba_sequent__TOP__0(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___nba_sequent__TOP__0\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vbitty_core___024unit____Vdpiimwrap_compare_results_TOP____024unit(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out, (IData)(vlSelfRef.bitty_core__DOT__Reg0__DOT__reg_d_out), vlSelfRef.bitty_core__DOT__Reg1__DOT__reg_d_out, (IData)(vlSelfRef.bitty_core__DOT__Reg2__DOT__reg_d_out), vlSelfRef.bitty_core__DOT__Reg3__DOT__reg_d_out, (IData)(vlSelfRef.bitty_core__DOT__Reg4__DOT__reg_d_out), vlSelfRef.bitty_core__DOT__Reg5__DOT__reg_d_out, (IData)(vlSelfRef.bitty_core__DOT__Reg6__DOT__reg_d_out), vlSelfRef.bitty_core__DOT__Reg7__DOT__reg_d_out);
}
