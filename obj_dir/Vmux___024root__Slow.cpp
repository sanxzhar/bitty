// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmux.h for the primary calling header

#include "Vmux__pch.h"
#include "Vmux__Syms.h"
#include "Vmux___024root.h"

void Vmux___024root___ctor_var_reset(Vmux___024root* vlSelf);

Vmux___024root::Vmux___024root(Vmux__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vmux___024root___ctor_var_reset(this);
}

void Vmux___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vmux___024root::~Vmux___024root() {
}
