// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitty_core.h for the primary calling header

#include "Vbitty_core__pch.h"
#include "Vbitty_core___024root.h"

VL_ATTR_COLD void Vbitty_core___024root___eval_static__TOP(Vbitty_core___024root* vlSelf);

VL_ATTR_COLD void Vbitty_core___024root___eval_static(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_static\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vbitty_core___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vbitty_core___024root___eval_static__TOP(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_static__TOP\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__current_state = 0U;
}

VL_ATTR_COLD void Vbitty_core___024root___eval_initial(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_initial\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
}

VL_ATTR_COLD void Vbitty_core___024root___eval_final(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_final\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitty_core___024root___dump_triggers__stl(Vbitty_core___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vbitty_core___024root___eval_phase__stl(Vbitty_core___024root* vlSelf);

VL_ATTR_COLD void Vbitty_core___024root___eval_settle(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_settle\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vbitty_core___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("rtl/bitty_core.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vbitty_core___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitty_core___024root___dump_triggers__stl(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___dump_triggers__stl\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vbitty_core___024root___stl_sequent__TOP__0(Vbitty_core___024root* vlSelf);

VL_ATTR_COLD void Vbitty_core___024root___eval_stl(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_stl\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vbitty_core___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vbitty_core___024root___stl_sequent__TOP__0(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___stl_sequent__TOP__0\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ bitty_core__DOT__ControlUnit__DOT__reg_done;
    bitty_core__DOT__ControlUnit__DOT__reg_done = 0;
    CData/*3:0*/ bitty_core__DOT__ControlUnit__DOT__reg_mux_sel;
    bitty_core__DOT__ControlUnit__DOT__reg_mux_sel = 0;
    // Body
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_s = 0U;
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_c = 0U;
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_i = 0U;
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_0 = 0U;
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_1 = 0U;
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_2 = 0U;
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_3 = 0U;
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_4 = 0U;
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_5 = 0U;
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_6 = 0U;
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_7 = 0U;
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel = 0U;
    bitty_core__DOT__ControlUnit__DOT__reg_done = 0U;
    vlSelfRef.reg0_to_mux = vlSelfRef.bitty_core__DOT__Reg0__DOT__reg_d_out;
    vlSelfRef.reg1_to_mux = vlSelfRef.bitty_core__DOT__Reg1__DOT__reg_d_out;
    vlSelfRef.reg2_to_mux = vlSelfRef.bitty_core__DOT__Reg2__DOT__reg_d_out;
    vlSelfRef.reg3_to_mux = vlSelfRef.bitty_core__DOT__Reg3__DOT__reg_d_out;
    vlSelfRef.reg4_to_mux = vlSelfRef.bitty_core__DOT__Reg4__DOT__reg_d_out;
    vlSelfRef.reg5_to_mux = vlSelfRef.bitty_core__DOT__Reg5__DOT__reg_d_out;
    vlSelfRef.reg6_to_mux = vlSelfRef.bitty_core__DOT__Reg6__DOT__reg_d_out;
    vlSelfRef.reg7_to_mux = vlSelfRef.bitty_core__DOT__Reg7__DOT__reg_d_out;
    bitty_core__DOT__ControlUnit__DOT__reg_mux_sel = 0U;
    if (((~ (IData)(vlSelfRef.reset)) & (IData)(vlSelfRef.run))) {
        if ((1U & (~ ((IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__current_state) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__current_state))) {
                vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_s = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__current_state)))) {
                vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_i = 1U;
            }
        }
        if ((2U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__current_state))) {
            if ((1U & (~ (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__current_state)))) {
                vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_c = 1U;
                if ((0U == (3U & (IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out)))) {
                    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel 
                        = (7U & ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                 >> 2U));
                    bitty_core__DOT__ControlUnit__DOT__reg_mux_sel 
                        = (7U & ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                 >> 0xaU));
                } else if ((1U == (3U & (IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out)))) {
                    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel 
                        = (7U & ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                 >> 2U));
                    bitty_core__DOT__ControlUnit__DOT__reg_mux_sel = 8U;
                } else {
                    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel 
                        = (7U & ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                 >> 2U));
                    bitty_core__DOT__ControlUnit__DOT__reg_mux_sel 
                        = (7U & ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                 >> 0xaU));
                }
                if ((0U != (3U & (IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out)))) {
                    if ((1U == (3U & (IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out)))) {
                        vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_imm_val 
                            = ((0xff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                                          >> 0xcU)))) 
                                           << 8U)) 
                               | (0xffU & ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                           >> 5U)));
                    }
                }
            }
            if ((1U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__current_state))) {
                if ((1U & (~ ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                              >> 0xfU)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                  >> 0xeU)))) {
                        if ((1U & (~ ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                      >> 0xdU)))) {
                            vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_0 = 1U;
                        }
                        if ((0x2000U & (IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out))) {
                            vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_1 = 1U;
                        }
                    }
                    if ((0x4000U & (IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out))) {
                        if ((1U & (~ ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                      >> 0xdU)))) {
                            vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_2 = 1U;
                        }
                        if ((0x2000U & (IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out))) {
                            vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_3 = 1U;
                        }
                    }
                }
                if ((0x8000U & (IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out))) {
                    if ((1U & (~ ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                  >> 0xeU)))) {
                        if ((1U & (~ ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                      >> 0xdU)))) {
                            vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_4 = 1U;
                        }
                        if ((0x2000U & (IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out))) {
                            vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_5 = 1U;
                        }
                    }
                    if ((0x4000U & (IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out))) {
                        if ((1U & (~ ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                      >> 0xdU)))) {
                            vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_6 = 1U;
                        }
                        if ((0x2000U & (IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out))) {
                            vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_7 = 1U;
                        }
                    }
                }
                bitty_core__DOT__ControlUnit__DOT__reg_done = 1U;
            }
        } else if ((1U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__current_state))) {
            bitty_core__DOT__ControlUnit__DOT__reg_mux_sel 
                = (7U & ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                         >> 0xdU));
        }
    }
    vlSelfRef.done = bitty_core__DOT__ControlUnit__DOT__reg_done;
    vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out = 
        ((8U & (IData)(bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
          ? ((4U & (IData)(bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
              ? 0U : ((2U & (IData)(bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                       ? 0U : ((1U & (IData)(bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                                ? 0U : (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_imm_val))))
          : ((4U & (IData)(bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
              ? ((2U & (IData)(bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                  ? ((1U & (IData)(bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                      ? (IData)(vlSelfRef.reg7_to_mux)
                      : (IData)(vlSelfRef.reg6_to_mux))
                  : ((1U & (IData)(bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                      ? (IData)(vlSelfRef.reg5_to_mux)
                      : (IData)(vlSelfRef.reg4_to_mux)))
              : ((2U & (IData)(bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                  ? ((1U & (IData)(bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                      ? (IData)(vlSelfRef.reg3_to_mux)
                      : (IData)(vlSelfRef.reg2_to_mux))
                  : ((1U & (IData)(bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                      ? (IData)(vlSelfRef.reg1_to_mux)
                      : (IData)(vlSelfRef.reg0_to_mux)))));
}

VL_ATTR_COLD void Vbitty_core___024root___eval_triggers__stl(Vbitty_core___024root* vlSelf);

VL_ATTR_COLD bool Vbitty_core___024root___eval_phase__stl(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_phase__stl\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vbitty_core___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vbitty_core___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitty_core___024root___dump_triggers__ico(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___dump_triggers__ico\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
VL_ATTR_COLD void Vbitty_core___024root___dump_triggers__act(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___dump_triggers__act\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge reset)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitty_core___024root___dump_triggers__nba(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___dump_triggers__nba\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge reset)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vbitty_core___024root___ctor_var_reset(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___ctor_var_reset\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->run = VL_RAND_RESET_I(1);
    vlSelf->instraction = VL_RAND_RESET_I(16);
    vlSelf->done = VL_RAND_RESET_I(1);
    vlSelf->reg0_to_mux = VL_RAND_RESET_I(16);
    vlSelf->reg1_to_mux = VL_RAND_RESET_I(16);
    vlSelf->reg2_to_mux = VL_RAND_RESET_I(16);
    vlSelf->reg3_to_mux = VL_RAND_RESET_I(16);
    vlSelf->reg4_to_mux = VL_RAND_RESET_I(16);
    vlSelf->reg5_to_mux = VL_RAND_RESET_I(16);
    vlSelf->reg6_to_mux = VL_RAND_RESET_I(16);
    vlSelf->reg7_to_mux = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__RegInst__DOT__reg_d_out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__Reg0__DOT__reg_d_out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__Reg1__DOT__reg_d_out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__Reg2__DOT__reg_d_out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__Reg3__DOT__reg_d_out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__Reg4__DOT__reg_d_out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__Reg5__DOT__reg_d_out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__Reg6__DOT__reg_d_out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__Reg7__DOT__reg_d_out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__ControlUnit__DOT__reg_en_s = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__ControlUnit__DOT__reg_en_c = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__ControlUnit__DOT__reg_en_0 = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__ControlUnit__DOT__reg_en_1 = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__ControlUnit__DOT__reg_en_2 = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__ControlUnit__DOT__reg_en_3 = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__ControlUnit__DOT__reg_en_4 = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__ControlUnit__DOT__reg_en_5 = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__ControlUnit__DOT__reg_en_6 = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__ControlUnit__DOT__reg_en_7 = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__ControlUnit__DOT__reg_en_i = VL_RAND_RESET_I(1);
    vlSelf->bitty_core__DOT__ControlUnit__DOT__reg_alu_sel = VL_RAND_RESET_I(3);
    vlSelf->bitty_core__DOT__ControlUnit__DOT__reg_imm_val = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__ControlUnit__DOT__current_state = VL_RAND_RESET_I(2);
    vlSelf->bitty_core__DOT__Mux__DOT__reg_out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__RegS__DOT__reg_d_out = VL_RAND_RESET_I(16);
    vlSelf->bitty_core__DOT__RegC__DOT__reg_d_out = VL_RAND_RESET_I(16);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = VL_RAND_RESET_I(1);
}
