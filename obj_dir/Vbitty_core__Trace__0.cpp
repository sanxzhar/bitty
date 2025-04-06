// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vbitty_core__Syms.h"


void Vbitty_core___024root__trace_chg_0_sub_0(Vbitty_core___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vbitty_core___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root__trace_chg_0\n"); );
    // Init
    Vbitty_core___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbitty_core___024root*>(voidSelf);
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vbitty_core___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vbitty_core___024root__trace_chg_0_sub_0(Vbitty_core___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root__trace_chg_0_sub_0\n"); );
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_s));
        bufp->chgBit(oldp+1,(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_c));
        bufp->chgBit(oldp+2,(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_0));
        bufp->chgBit(oldp+3,(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_1));
        bufp->chgBit(oldp+4,(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_2));
        bufp->chgBit(oldp+5,(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_3));
        bufp->chgBit(oldp+6,(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_4));
        bufp->chgBit(oldp+7,(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_5));
        bufp->chgBit(oldp+8,(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_6));
        bufp->chgBit(oldp+9,(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_7));
        bufp->chgBit(oldp+10,(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_en_i));
        bufp->chgCData(oldp+11,(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel),3);
        bufp->chgCData(oldp+12,(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_mux_sel),4);
        bufp->chgSData(oldp+13,(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_imm_val),16);
        bufp->chgSData(oldp+14,(vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out),16);
        bufp->chgSData(oldp+15,((0xffffU & ((4U & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel))
                                             ? ((2U 
                                                 & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel))
                                                  ? 
                                                 (((IData)(vlSelfRef.bitty_core__DOT__RegS__DOT__reg_d_out) 
                                                   == (IData)(vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out))
                                                   ? 0U
                                                   : 
                                                  (((IData)(vlSelfRef.bitty_core__DOT__RegS__DOT__reg_d_out) 
                                                    > (IData)(vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out))
                                                    ? 1U
                                                    : 2U))
                                                  : 
                                                 VL_SHIFTR_III(16,16,32, (IData)(vlSelfRef.bitty_core__DOT__RegS__DOT__reg_d_out), 
                                                               (0xfU 
                                                                & (IData)(vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out))))
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel))
                                                  ? 
                                                 VL_SHIFTL_III(16,16,32, (IData)(vlSelfRef.bitty_core__DOT__RegS__DOT__reg_d_out), 
                                                               (0xfU 
                                                                & (IData)(vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out)))
                                                  : 
                                                 ((IData)(vlSelfRef.bitty_core__DOT__RegS__DOT__reg_d_out) 
                                                  ^ (IData)(vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out))))
                                             : ((2U 
                                                 & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel))
                                                  ? 
                                                 ((IData)(vlSelfRef.bitty_core__DOT__RegS__DOT__reg_d_out) 
                                                  | (IData)(vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out))
                                                  : 
                                                 ((IData)(vlSelfRef.bitty_core__DOT__RegS__DOT__reg_d_out) 
                                                  & (IData)(vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out)))
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_alu_sel))
                                                  ? 
                                                 ((IData)(vlSelfRef.bitty_core__DOT__RegS__DOT__reg_d_out) 
                                                  - (IData)(vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out))
                                                  : 
                                                 ((IData)(vlSelfRef.bitty_core__DOT__RegS__DOT__reg_d_out) 
                                                  + (IData)(vlSelfRef.bitty_core__DOT__Mux__DOT__reg_out))))))),16);
        bufp->chgBit(oldp+16,(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__reg_done));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgSData(oldp+17,(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out),16);
        bufp->chgSData(oldp+18,(vlSelfRef.bitty_core__DOT__RegC__DOT__reg_d_out),16);
        bufp->chgSData(oldp+19,(vlSelfRef.bitty_core__DOT__Reg0__DOT__reg_d_out),16);
        bufp->chgSData(oldp+20,(vlSelfRef.bitty_core__DOT__Reg1__DOT__reg_d_out),16);
        bufp->chgSData(oldp+21,(vlSelfRef.bitty_core__DOT__Reg2__DOT__reg_d_out),16);
        bufp->chgSData(oldp+22,(vlSelfRef.bitty_core__DOT__Reg3__DOT__reg_d_out),16);
        bufp->chgSData(oldp+23,(vlSelfRef.bitty_core__DOT__Reg4__DOT__reg_d_out),16);
        bufp->chgSData(oldp+24,(vlSelfRef.bitty_core__DOT__Reg5__DOT__reg_d_out),16);
        bufp->chgSData(oldp+25,(vlSelfRef.bitty_core__DOT__Reg6__DOT__reg_d_out),16);
        bufp->chgSData(oldp+26,(vlSelfRef.bitty_core__DOT__Reg7__DOT__reg_d_out),16);
        bufp->chgSData(oldp+27,(vlSelfRef.bitty_core__DOT__RegS__DOT__reg_d_out),16);
        bufp->chgCData(oldp+28,(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__current_state),2);
        bufp->chgCData(oldp+29,(vlSelfRef.bitty_core__DOT__ControlUnit__DOT__next_state),2);
        bufp->chgCData(oldp+30,((3U & (IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out))),2);
        bufp->chgCData(oldp+31,((7U & ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                       >> 2U))),3);
        bufp->chgCData(oldp+32,((7U & ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                       >> 0xdU))),3);
        bufp->chgCData(oldp+33,((7U & ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                       >> 0xaU))),3);
        bufp->chgCData(oldp+34,((0xffU & ((IData)(vlSelfRef.bitty_core__DOT__RegInst__DOT__reg_d_out) 
                                          >> 5U))),8);
    }
    bufp->chgBit(oldp+35,(vlSelfRef.clk));
    bufp->chgBit(oldp+36,(vlSelfRef.reset));
    bufp->chgBit(oldp+37,(vlSelfRef.run));
    bufp->chgSData(oldp+38,(vlSelfRef.instruction),16);
    bufp->chgBit(oldp+39,(vlSelfRef.done));
    bufp->chgBit(oldp+40,(vlSelfRef.bitty_core__DOT__Monitor__DOT__en_dpi));
}

void Vbitty_core___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core___024root__trace_cleanup\n"); );
    // Init
    Vbitty_core___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbitty_core___024root*>(voidSelf);
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
