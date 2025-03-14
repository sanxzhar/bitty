// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmux.h for the primary calling header

#include "Vmux__pch.h"
#include "Vmux___024root.h"

VL_ATTR_COLD void Vmux___024root___eval_static(Vmux___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux___024root___eval_static\n"); );
    Vmux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vmux___024root___eval_initial(Vmux___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux___024root___eval_initial\n"); );
    Vmux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vmux___024root___eval_final(Vmux___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux___024root___eval_final\n"); );
    Vmux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmux___024root___dump_triggers__stl(Vmux___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vmux___024root___eval_phase__stl(Vmux___024root* vlSelf);

VL_ATTR_COLD void Vmux___024root___eval_settle(Vmux___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux___024root___eval_settle\n"); );
    Vmux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vmux___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("rtl/mux.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vmux___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmux___024root___dump_triggers__stl(Vmux___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux___024root___dump_triggers__stl\n"); );
    Vmux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vmux___024root___ico_sequent__TOP__0(Vmux___024root* vlSelf);

VL_ATTR_COLD void Vmux___024root___eval_stl(Vmux___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux___024root___eval_stl\n"); );
    Vmux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vmux___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vmux___024root___eval_triggers__stl(Vmux___024root* vlSelf);

VL_ATTR_COLD bool Vmux___024root___eval_phase__stl(Vmux___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux___024root___eval_phase__stl\n"); );
    Vmux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vmux___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vmux___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmux___024root___dump_triggers__ico(Vmux___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux___024root___dump_triggers__ico\n"); );
    Vmux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmux___024root___dump_triggers__act(Vmux___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux___024root___dump_triggers__act\n"); );
    Vmux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmux___024root___dump_triggers__nba(Vmux___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux___024root___dump_triggers__nba\n"); );
    Vmux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmux___024root___ctor_var_reset(Vmux___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux___024root___ctor_var_reset\n"); );
    Vmux__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->sel = VL_RAND_RESET_I(4);
    vlSelf->reg_0 = VL_RAND_RESET_I(16);
    vlSelf->reg_1 = VL_RAND_RESET_I(16);
    vlSelf->reg_2 = VL_RAND_RESET_I(16);
    vlSelf->reg_3 = VL_RAND_RESET_I(16);
    vlSelf->reg_4 = VL_RAND_RESET_I(16);
    vlSelf->reg_5 = VL_RAND_RESET_I(16);
    vlSelf->reg_6 = VL_RAND_RESET_I(16);
    vlSelf->reg_7 = VL_RAND_RESET_I(16);
    vlSelf->reg_8 = VL_RAND_RESET_I(16);
    vlSelf->reg_9 = VL_RAND_RESET_I(16);
    vlSelf->out = VL_RAND_RESET_I(16);
}
