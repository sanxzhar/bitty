// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcontrol_unit__pch.h"

//============================================================
// Constructors

Vcontrol_unit::Vcontrol_unit(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vcontrol_unit__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , run{vlSymsp->TOP.run}
    , done{vlSymsp->TOP.done}
    , en_s{vlSymsp->TOP.en_s}
    , en_c{vlSymsp->TOP.en_c}
    , en_0{vlSymsp->TOP.en_0}
    , en_1{vlSymsp->TOP.en_1}
    , en_2{vlSymsp->TOP.en_2}
    , en_3{vlSymsp->TOP.en_3}
    , en_4{vlSymsp->TOP.en_4}
    , en_5{vlSymsp->TOP.en_5}
    , en_6{vlSymsp->TOP.en_6}
    , en_7{vlSymsp->TOP.en_7}
    , en_i{vlSymsp->TOP.en_i}
    , alu_sel{vlSymsp->TOP.alu_sel}
    , mux_sel{vlSymsp->TOP.mux_sel}
    , d_in{vlSymsp->TOP.d_in}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vcontrol_unit::Vcontrol_unit(const char* _vcname__)
    : Vcontrol_unit(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vcontrol_unit::~Vcontrol_unit() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vcontrol_unit___024root___eval_debug_assertions(Vcontrol_unit___024root* vlSelf);
#endif  // VL_DEBUG
void Vcontrol_unit___024root___eval_static(Vcontrol_unit___024root* vlSelf);
void Vcontrol_unit___024root___eval_initial(Vcontrol_unit___024root* vlSelf);
void Vcontrol_unit___024root___eval_settle(Vcontrol_unit___024root* vlSelf);
void Vcontrol_unit___024root___eval(Vcontrol_unit___024root* vlSelf);

void Vcontrol_unit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcontrol_unit::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vcontrol_unit___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vcontrol_unit___024root___eval_static(&(vlSymsp->TOP));
        Vcontrol_unit___024root___eval_initial(&(vlSymsp->TOP));
        Vcontrol_unit___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vcontrol_unit___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vcontrol_unit::eventsPending() { return false; }

uint64_t Vcontrol_unit::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vcontrol_unit::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vcontrol_unit___024root___eval_final(Vcontrol_unit___024root* vlSelf);

VL_ATTR_COLD void Vcontrol_unit::final() {
    Vcontrol_unit___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vcontrol_unit::hierName() const { return vlSymsp->name(); }
const char* Vcontrol_unit::modelName() const { return "Vcontrol_unit"; }
unsigned Vcontrol_unit::threads() const { return 1; }
void Vcontrol_unit::prepareClone() const { contextp()->prepareClone(); }
void Vcontrol_unit::atClone() const {
    contextp()->threadPoolpOnClone();
}
