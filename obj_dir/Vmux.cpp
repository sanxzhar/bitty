// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmux__pch.h"

//============================================================
// Constructors

Vmux::Vmux(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmux__Syms(contextp(), _vcname__, this)}
    , sel{vlSymsp->TOP.sel}
    , reg_0{vlSymsp->TOP.reg_0}
    , reg_1{vlSymsp->TOP.reg_1}
    , reg_2{vlSymsp->TOP.reg_2}
    , reg_3{vlSymsp->TOP.reg_3}
    , reg_4{vlSymsp->TOP.reg_4}
    , reg_5{vlSymsp->TOP.reg_5}
    , reg_6{vlSymsp->TOP.reg_6}
    , reg_7{vlSymsp->TOP.reg_7}
    , reg_8{vlSymsp->TOP.reg_8}
    , reg_9{vlSymsp->TOP.reg_9}
    , out{vlSymsp->TOP.out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vmux::Vmux(const char* _vcname__)
    : Vmux(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmux::~Vmux() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmux___024root___eval_debug_assertions(Vmux___024root* vlSelf);
#endif  // VL_DEBUG
void Vmux___024root___eval_static(Vmux___024root* vlSelf);
void Vmux___024root___eval_initial(Vmux___024root* vlSelf);
void Vmux___024root___eval_settle(Vmux___024root* vlSelf);
void Vmux___024root___eval(Vmux___024root* vlSelf);

void Vmux::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmux::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmux___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmux___024root___eval_static(&(vlSymsp->TOP));
        Vmux___024root___eval_initial(&(vlSymsp->TOP));
        Vmux___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmux___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vmux::eventsPending() { return false; }

uint64_t Vmux::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vmux::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmux___024root___eval_final(Vmux___024root* vlSelf);

VL_ATTR_COLD void Vmux::final() {
    Vmux___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmux::hierName() const { return vlSymsp->name(); }
const char* Vmux::modelName() const { return "Vmux"; }
unsigned Vmux::threads() const { return 1; }
void Vmux::prepareClone() const { contextp()->prepareClone(); }
void Vmux::atClone() const {
    contextp()->threadPoolpOnClone();
}
