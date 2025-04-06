// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vbitty_core__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vbitty_core::Vbitty_core(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vbitty_core__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , run{vlSymsp->TOP.run}
    , done{vlSymsp->TOP.done}
    , instruction{vlSymsp->TOP.instruction}
    , __PVT____024unit{vlSymsp->TOP.__PVT____024unit}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
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
    vlSymsp->__Vm_activity = true;
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
std::unique_ptr<VerilatedTraceConfig> Vbitty_core::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vbitty_core___024root__trace_decl_types(VerilatedVcd* tracep);

void Vbitty_core___024root__trace_init_top(Vbitty_core___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vbitty_core___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbitty_core___024root*>(voidSelf);
    Vbitty_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vbitty_core___024root__trace_decl_types(tracep);
    Vbitty_core___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vbitty_core___024root__trace_register(Vbitty_core___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vbitty_core::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vbitty_core::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vbitty_core___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
