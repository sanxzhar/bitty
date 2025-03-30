// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitty_core.h for the primary calling header

#include "Vbitty_core__pch.h"
#include "Vbitty_core__Syms.h"
#include "Vbitty_core___024root.h"

void Vbitty_core___024root___ctor_var_reset(Vbitty_core___024root* vlSelf);

Vbitty_core___024root::Vbitty_core___024root(Vbitty_core__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vbitty_core___024root___ctor_var_reset(this);
}

void Vbitty_core___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vbitty_core___024root::~Vbitty_core___024root() {
}
