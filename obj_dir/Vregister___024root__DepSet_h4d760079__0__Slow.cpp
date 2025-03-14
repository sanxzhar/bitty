// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vregister.h for the primary calling header

#include "Vregister__pch.h"
#include "Vregister__Syms.h"
#include "Vregister___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vregister___024root___dump_triggers__stl(Vregister___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vregister___024root___eval_triggers__stl(Vregister___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister___024root___eval_triggers__stl\n"); );
    Vregister__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vregister___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
