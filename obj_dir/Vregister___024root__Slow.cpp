// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vregister.h for the primary calling header

#include "Vregister__pch.h"
#include "Vregister__Syms.h"
#include "Vregister___024root.h"

void Vregister___024root___ctor_var_reset(Vregister___024root* vlSelf);

Vregister___024root::Vregister___024root(Vregister__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vregister___024root___ctor_var_reset(this);
}

void Vregister___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vregister___024root::~Vregister___024root() {
}
