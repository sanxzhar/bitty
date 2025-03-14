// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vregister__pch.h"

//============================================================
// Constructors

Vregister::Vregister(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vregister__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , en_i{vlSymsp->TOP.en_i}
    , d_in{vlSymsp->TOP.d_in}
    , d_out{vlSymsp->TOP.d_out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vregister::Vregister(const char* _vcname__)
    : Vregister(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vregister::~Vregister() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vregister___024root___eval_debug_assertions(Vregister___024root* vlSelf);
#endif  // VL_DEBUG
void Vregister___024root___eval_static(Vregister___024root* vlSelf);
void Vregister___024root___eval_initial(Vregister___024root* vlSelf);
void Vregister___024root___eval_settle(Vregister___024root* vlSelf);
void Vregister___024root___eval(Vregister___024root* vlSelf);

void Vregister::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vregister::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vregister___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vregister___024root___eval_static(&(vlSymsp->TOP));
        Vregister___024root___eval_initial(&(vlSymsp->TOP));
        Vregister___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vregister___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vregister::eventsPending() { return false; }

uint64_t Vregister::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vregister::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vregister___024root___eval_final(Vregister___024root* vlSelf);

VL_ATTR_COLD void Vregister::final() {
    Vregister___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vregister::hierName() const { return vlSymsp->name(); }
const char* Vregister::modelName() const { return "Vregister"; }
unsigned Vregister::threads() const { return 1; }
void Vregister::prepareClone() const { contextp()->prepareClone(); }
void Vregister::atClone() const {
    contextp()->threadPoolpOnClone();
}
