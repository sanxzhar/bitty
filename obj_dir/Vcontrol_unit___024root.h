// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcontrol_unit.h for the primary calling header

#ifndef VERILATED_VCONTROL_UNIT___024ROOT_H_
#define VERILATED_VCONTROL_UNIT___024ROOT_H_  // guard

#include "verilated.h"


class Vcontrol_unit__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vcontrol_unit___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(run,0,0);
    VL_OUT8(done,0,0);
    VL_OUT8(en_s,0,0);
    VL_OUT8(en_c,0,0);
    VL_OUT8(en_0,0,0);
    VL_OUT8(en_1,0,0);
    VL_OUT8(en_2,0,0);
    VL_OUT8(en_3,0,0);
    VL_OUT8(en_4,0,0);
    VL_OUT8(en_5,0,0);
    VL_OUT8(en_6,0,0);
    VL_OUT8(en_7,0,0);
    VL_OUT8(en_i,0,0);
    VL_OUT8(alu_sel,2,0);
    VL_OUT8(mux_sel,3,0);
    CData/*1:0*/ control_unit__DOT__current_state;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
    CData/*0:0*/ __VactContinue;
    VL_IN16(d_in,15,0);
    VL_OUT16(imm_val,15,0);
    SData/*15:0*/ control_unit__DOT__reg_imm_val;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vcontrol_unit__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vcontrol_unit___024root(Vcontrol_unit__Syms* symsp, const char* v__name);
    ~Vcontrol_unit___024root();
    VL_UNCOPYABLE(Vcontrol_unit___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
