// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vbitty_core__pch.h"

//============================================================
// Constructors

Vbitty_core::Vbitty_core(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vbitty_core__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , run{vlSymsp->TOP.run}
    , done{vlSymsp->TOP.done}
    , instraction{vlSymsp->TOP.instraction}
    , reg0_to_mux{vlSymsp->TOP.reg0_to_mux}
    , reg1_to_mux{vlSymsp->TOP.reg1_to_mux}
    , reg2_to_mux{vlSymsp->TOP.reg2_to_mux}
    , reg3_to_mux{vlSymsp->TOP.reg3_to_mux}
    , reg4_to_mux{vlSymsp->TOP.reg4_to_mux}
    , reg5_to_mux{vlSymsp->TOP.reg5_to_mux}
    , reg6_to_mux{vlSymsp->TOP.reg6_to_mux}
    , reg7_to_mux{vlSymsp->TOP.reg7_to_mux}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vbitty_core::Vbitty_core(const char* _vcname__)
    : Vbitty_core(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vbitty_core::~Vbitty_core() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vbitty_core___024root___eval_debug_assertions(Vbitty_core___024root* vlSelf);
#endif  // VL_DEBUG
void Vbitty_core___024root___eval_static(Vbitty_core___024root* vlSelf);
void Vbitty_core___024root___eval_initial(Vbitty_core___024root* vlSelf);
void Vbitty_core___024root___eval_settle(Vbitty_core___024root* vlSelf);
void Vbitty_core___024root___eval(Vbitty_core___024root* vlSelf);

void Vbitty_core::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbitty_core::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vbitty_core___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vbitty_core___024root___eval_static(&(vlSymsp->TOP));
        Vbitty_core___024root___eval_initial(&(vlSymsp->TOP));
        Vbitty_core___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vbitty_core___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vbitty_core::eventsPending() { return false; }

uint64_t Vbitty_core::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vbitty_core::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vbitty_core___024root___eval_final(Vbitty_core___024root* vlSelf);

VL_ATTR_COLD void Vbitty_core::final() {
    Vbitty_core___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vbitty_core::hierName() const { return vlSymsp->name(); }
const char* Vbitty_core::modelName() const { return "Vbitty_core"; }
unsigned Vbitty_core::threads() const { return 1; }
void Vbitty_core::prepareClone() const { contextp()->prepareClone(); }
void Vbitty_core::atClone() const {
    contextp()->threadPoolpOnClone();
}
