// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitty_core.h for the primary calling header

#include "Vbitty_core__pch.h"
#include "Vbitty_core___024root.h"

void Vbitty_core___024root___ico_sequent__TOP__0(Vbitty_core___024root* vlSelf);

void Vbitty_core___024root___eval_ico(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_ico\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vbitty_core___024root___ico_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vbitty_core___024root___ico_sequent__TOP__0(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___ico_sequent__TOP__0\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
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
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_done = 0U;
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel = 0U;
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
                    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel 
                        = (7U & ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                 >> 0xaU));
                } else if ((1U == (3U & (IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out)))) {
                    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel 
                        = (7U & ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                 >> 2U));
                    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel = 8U;
                } else {
                    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel 
                        = (7U & ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                 >> 2U));
                    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel 
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
                vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_done = 1U;
            }
        } else if ((1U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__current_state))) {
            vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel 
                = (7U & ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                         >> 0xdU));
        }
    }
    vlSelfRef.done = vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_done;
    vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out = 
        ((8U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
          ? ((4U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
              ? 0U : ((2U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                       ? 0U : ((1U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                                ? 0U : (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_imm_val))))
          : ((4U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
              ? ((2U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                  ? ((1U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                      ? (IData)(vlSelfRef.bitty_core__DOT__Reg7__DOT__reg_d_out)
                      : (IData)(vlSelfRef.bitty_core__DOT__Reg6__DOT__reg_d_out))
                  : ((1U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                      ? (IData)(vlSelfRef.bitty_core__DOT__Reg5__DOT__reg_d_out)
                      : (IData)(vlSelfRef.bitty_core__DOT__Reg4__DOT__reg_d_out)))
              : ((2U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                  ? ((1U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                      ? (IData)(vlSelfRef.bitty_core__DOT__Reg3__DOT__reg_d_out)
                      : (IData)(vlSelfRef.bitty_core__DOT__Reg2__DOT__reg_d_out))
                  : ((1U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                      ? (IData)(vlSelfRef.bitty_core__DOT__Reg1__DOT__reg_d_out)
                      : (IData)(vlSelfRef.bitty_core__DOT__Reg0__DOT__reg_d_out)))));
}

void Vbitty_core___024root___eval_triggers__ico(Vbitty_core___024root* vlSelf);

bool Vbitty_core___024root___eval_phase__ico(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_phase__ico\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vbitty_core___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vbitty_core___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vbitty_core___024root___eval_act(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_act\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vbitty_core___024root___nba_sequent__TOP__0(Vbitty_core___024root* vlSelf);
void Vbitty_core___024root___nba_sequent__TOP__1(Vbitty_core___024root* vlSelf);
void Vbitty_core___024root___nba_sequent__TOP__2(Vbitty_core___024root* vlSelf);

void Vbitty_core___024root___eval_nba(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_nba\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vbitty_core___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vbitty_core___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vbitty_core___024root___nba_sequent__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
}

VL_INLINE_OPT void Vbitty_core___024root___nba_sequent__TOP__1(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___nba_sequent__TOP__1\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.bitty_core__DOT__Monitor__DOT__en_dpi 
        = vlSelfRef.done;
}

extern const VlUnpacked<CData/*1:0*/, 4> Vbitty_core__ConstPool__TABLE_hcac39648_0;

VL_INLINE_OPT void Vbitty_core___024root___nba_sequent__TOP__2(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___nba_sequent__TOP__2\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*1:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    if (vlSelfRef.reset) {
        vlSelfRef.bitty_core__DOT__ControlUnit__DOT__current_state = 0U;
        vlSelfRef.bitty_core__DOT__Reg0__DOT__reg_d_out = 0U;
        vlSelfRef.bitty_core__DOT__Reg1__DOT__reg_d_out = 0U;
        vlSelfRef.bitty_core__DOT__Reg2__DOT__reg_d_out = 0U;
        vlSelfRef.bitty_core__DOT__Reg3__DOT__reg_d_out = 0U;
        vlSelfRef.bitty_core__DOT__Reg4__DOT__reg_d_out = 0U;
        vlSelfRef.bitty_core__DOT__Reg5__DOT__reg_d_out = 0U;
        vlSelfRef.bitty_core__DOT__Reg6__DOT__reg_d_out = 0U;
        vlSelfRef.bitty_core__DOT__Reg7__DOT__reg_d_out = 0U;
        vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out = 0U;
        vlSelfRef.bitty_core__DOT__RegC__DOT__reg_d_out = 0U;
        vlSelfRef.bitty_core__DOT__RegS__DOT__reg_d_out = 0U;
    } else {
        if (vlSelfRef.run) {
            vlSelfRef.bitty_core__DOT__ControlUnit__DOT__current_state 
                = vlSelfRef.bitty_core__DOT__ControlUnit__DOT__next_state;
        }
        if (vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_0) {
            vlSelfRef.bitty_core__DOT__Reg0__DOT__reg_d_out 
                = vlSelfRef.bitty_core__DOT__RegC__DOT__reg_d_out;
        }
        if (vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_1) {
            vlSelfRef.bitty_core__DOT__Reg1__DOT__reg_d_out 
                = vlSelfRef.bitty_core__DOT__RegC__DOT__reg_d_out;
        }
        if (vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_2) {
            vlSelfRef.bitty_core__DOT__Reg2__DOT__reg_d_out 
                = vlSelfRef.bitty_core__DOT__RegC__DOT__reg_d_out;
        }
        if (vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_3) {
            vlSelfRef.bitty_core__DOT__Reg3__DOT__reg_d_out 
                = vlSelfRef.bitty_core__DOT__RegC__DOT__reg_d_out;
        }
        if (vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_4) {
            vlSelfRef.bitty_core__DOT__Reg4__DOT__reg_d_out 
                = vlSelfRef.bitty_core__DOT__RegC__DOT__reg_d_out;
        }
        if (vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_5) {
            vlSelfRef.bitty_core__DOT__Reg5__DOT__reg_d_out 
                = vlSelfRef.bitty_core__DOT__RegC__DOT__reg_d_out;
        }
        if (vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_6) {
            vlSelfRef.bitty_core__DOT__Reg6__DOT__reg_d_out 
                = vlSelfRef.bitty_core__DOT__RegC__DOT__reg_d_out;
        }
        if (vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_7) {
            vlSelfRef.bitty_core__DOT__Reg7__DOT__reg_d_out 
                = vlSelfRef.bitty_core__DOT__RegC__DOT__reg_d_out;
        }
        if (vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_i) {
            vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out 
                = vlSelfRef.instruction;
        }
        if (vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_c) {
            vlSelfRef.bitty_core__DOT__RegC__DOT__reg_d_out 
                = (0xffffU & ((4U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel))
                               ? ((2U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel))
                                   ? ((1U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel))
                                       ? (((IData)(vlSelfRef.bitty_core__DOT__RegS__DOT__reg_d_out) 
                                           == (IData)(vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out))
                                           ? 0U : (
                                                   ((IData)(vlSelfRef.bitty_core__DOT__RegS__DOT__reg_d_out) 
                                                    > (IData)(vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out))
                                                    ? 1U
                                                    : 2U))
                                       : VL_SHIFTR_III(16,16,32, (IData)(vlSelfRef.bitty_core__DOT__RegS__DOT__reg_d_out), 
                                                       (0xfU 
                                                        & (IData)(vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out))))
                                   : ((1U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel))
                                       ? VL_SHIFTL_III(16,16,32, (IData)(vlSelfRef.bitty_core__DOT__RegS__DOT__reg_d_out), 
                                                       (0xfU 
                                                        & (IData)(vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out)))
                                       : ((IData)(vlSelfRef.bitty_core__DOT__RegS__DOT__reg_d_out) 
                                          ^ (IData)(vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out))))
                               : ((2U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel))
                                   ? ((1U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel))
                                       ? ((IData)(vlSelfRef.bitty_core__DOT__RegS__DOT__reg_d_out) 
                                          | (IData)(vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out))
                                       : ((IData)(vlSelfRef.bitty_core__DOT__RegS__DOT__reg_d_out) 
                                          & (IData)(vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out)))
                                   : ((1U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel))
                                       ? ((IData)(vlSelfRef.bitty_core__DOT__RegS__DOT__reg_d_out) 
                                          - (IData)(vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out))
                                       : ((IData)(vlSelfRef.bitty_core__DOT__RegS__DOT__reg_d_out) 
                                          + (IData)(vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out))))));
        }
        if (vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_s) {
            vlSelfRef.bitty_core__DOT__RegS__DOT__reg_d_out 
                = vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out;
        }
    }
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_i = 0U;
    __Vtableidx1 = vlSelfRef.bitty_core__DOT__ControlUnit__DOT__current_state;
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__next_state 
        = Vbitty_core__ConstPool__TABLE_hcac39648_0
        [__Vtableidx1];
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_done = 0U;
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_0 = 0U;
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_1 = 0U;
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_2 = 0U;
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_3 = 0U;
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_4 = 0U;
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_5 = 0U;
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_6 = 0U;
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_7 = 0U;
    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel = 0U;
    if (((~ (IData)(vlSelfRef.reset)) & (IData)(vlSelfRef.run))) {
        if ((2U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__current_state))) {
            if ((1U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__current_state))) {
                vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_done = 1U;
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
            }
            vlSelfRef.done = vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_done;
            vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_c = 0U;
            vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel = 0U;
            if ((1U & (~ (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__current_state)))) {
                if ((0U == (3U & (IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out)))) {
                    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel 
                        = (7U & ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                 >> 0xaU));
                    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel 
                        = (7U & ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                 >> 2U));
                } else if ((1U == (3U & (IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out)))) {
                    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel = 8U;
                    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel 
                        = (7U & ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                 >> 2U));
                } else {
                    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel 
                        = (7U & ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                 >> 0xaU));
                    vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel 
                        = (7U & ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                 >> 2U));
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
                vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_c = 1U;
            }
        } else {
            vlSelfRef.done = vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_done;
            vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_c = 0U;
            vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel = 0U;
            if ((1U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__current_state))) {
                vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel 
                    = (7U & ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                             >> 0xdU));
            }
        }
        vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_s = 0U;
        if ((1U & (~ ((IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__current_state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__current_state)))) {
                vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_i = 1U;
            }
            if ((1U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__current_state))) {
                vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_s = 1U;
            }
        }
    } else {
        vlSelfRef.done = vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_done;
        vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_c = 0U;
        vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel = 0U;
        vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_s = 0U;
    }
    vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out = 
        ((8U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
          ? ((4U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
              ? 0U : ((2U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                       ? 0U : ((1U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                                ? 0U : (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_imm_val))))
          : ((4U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
              ? ((2U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                  ? ((1U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                      ? (IData)(vlSelfRef.bitty_core__DOT__Reg7__DOT__reg_d_out)
                      : (IData)(vlSelfRef.bitty_core__DOT__Reg6__DOT__reg_d_out))
                  : ((1U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                      ? (IData)(vlSelfRef.bitty_core__DOT__Reg5__DOT__reg_d_out)
                      : (IData)(vlSelfRef.bitty_core__DOT__Reg4__DOT__reg_d_out)))
              : ((2U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                  ? ((1U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                      ? (IData)(vlSelfRef.bitty_core__DOT__Reg3__DOT__reg_d_out)
                      : (IData)(vlSelfRef.bitty_core__DOT__Reg2__DOT__reg_d_out))
                  : ((1U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel))
                      ? (IData)(vlSelfRef.bitty_core__DOT__Reg1__DOT__reg_d_out)
                      : (IData)(vlSelfRef.bitty_core__DOT__Reg0__DOT__reg_d_out)))));
}

void Vbitty_core___024root___eval_triggers__act(Vbitty_core___024root* vlSelf);

bool Vbitty_core___024root___eval_phase__act(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_phase__act\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vbitty_core___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vbitty_core___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vbitty_core___024root___eval_phase__nba(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_phase__nba\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vbitty_core___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitty_core___024root___dump_triggers__ico(Vbitty_core___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitty_core___024root___dump_triggers__nba(Vbitty_core___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitty_core___024root___dump_triggers__act(Vbitty_core___024root* vlSelf);
#endif  // VL_DEBUG

void Vbitty_core___024root___eval(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vbitty_core___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("rtl/bitty_core.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vbitty_core___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vbitty_core___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/bitty_core.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vbitty_core___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/bitty_core.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vbitty_core___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vbitty_core___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vbitty_core___024root___eval_debug_assertions(Vbitty_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root___eval_debug_assertions\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY(((vlSelfRef.run & 0xfeU)))) {
        Verilated::overWidthError("run");}
}
#endif  // VL_DEBUG
