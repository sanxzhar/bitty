// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vbitty_core.h for the primary calling header

#ifndef VERILATED_VBITTY_CORE___024ROOT_H_
#define VERILATED_VBITTY_CORE___024ROOT_H_  // guard

#include "verilated.h"


class Vbitty_core__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vbitty_core___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(run,0,0);
    VL_OUT8(done,0,0);
    CData/*0:0*/ bitty_core__DOT__ControlUnit__DOT__reg_en_s;
    CData/*0:0*/ bitty_core__DOT__ControlUnit__DOT__reg_en_c;
    CData/*0:0*/ bitty_core__DOT__ControlUnit__DOT__reg_en_0;
    CData/*0:0*/ bitty_core__DOT__ControlUnit__DOT__reg_en_1;
    CData/*0:0*/ bitty_core__DOT__ControlUnit__DOT__reg_en_2;
    CData/*0:0*/ bitty_core__DOT__ControlUnit__DOT__reg_en_3;
    CData/*0:0*/ bitty_core__DOT__ControlUnit__DOT__reg_en_4;
    CData/*0:0*/ bitty_core__DOT__ControlUnit__DOT__reg_en_5;
    CData/*0:0*/ bitty_core__DOT__ControlUnit__DOT__reg_en_6;
    CData/*0:0*/ bitty_core__DOT__ControlUnit__DOT__reg_en_7;
    CData/*0:0*/ bitty_core__DOT__ControlUnit__DOT__reg_en_i;
    CData/*2:0*/ bitty_core__DOT__ControlUnit__DOT__reg_alu_sel;
    CData/*1:0*/ bitty_core__DOT__ControlUnit__DOT__current_state;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
    CData/*0:0*/ __VactContinue;
    VL_IN16(instraction,15,0);
    VL_OUT16(reg0_to_mux,15,0);
    VL_OUT16(reg1_to_mux,15,0);
    VL_OUT16(reg2_to_mux,15,0);
    VL_OUT16(reg3_to_mux,15,0);
    VL_OUT16(reg4_to_mux,15,0);
    VL_OUT16(reg5_to_mux,15,0);
    VL_OUT16(reg6_to_mux,15,0);
    VL_OUT16(reg7_to_mux,15,0);
    SData/*15:0*/ bitty_core__DOT__RegInst__DOT__reg_d_out;
    SData/*15:0*/ bitty_core__DOT__Reg0__DOT__reg_d_out;
    SData/*15:0*/ bitty_core__DOT__Reg1__DOT__reg_d_out;
    SData/*15:0*/ bitty_core__DOT__Reg2__DOT__reg_d_out;
    SData/*15:0*/ bitty_core__DOT__Reg3__DOT__reg_d_out;
    SData/*15:0*/ bitty_core__DOT__Reg4__DOT__reg_d_out;
    SData/*15:0*/ bitty_core__DOT__Reg5__DOT__reg_d_out;
    SData/*15:0*/ bitty_core__DOT__Reg6__DOT__reg_d_out;
    SData/*15:0*/ bitty_core__DOT__Reg7__DOT__reg_d_out;
    SData/*15:0*/ bitty_core__DOT__ControlUnit__DOT__reg_imm_val;
    SData/*15:0*/ bitty_core__DOT__Mux__DOT__reg_out;
    SData/*15:0*/ bitty_core__DOT__RegS__DOT__reg_d_out;
    SData/*15:0*/ bitty_core__DOT__RegC__DOT__reg_d_out;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vbitty_core__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vbitty_core___024root(Vbitty_core__Syms* symsp, const char* v__name);
    ~Vbitty_core___024root();
    VL_UNCOPYABLE(Vbitty_core___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
