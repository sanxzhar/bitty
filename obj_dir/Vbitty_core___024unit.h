// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vbitty_core.h for the primary calling header

#ifndef VERILATED_VBITTY_CORE___024UNIT_H_
#define VERILATED_VBITTY_CORE___024UNIT_H_  // guard

#include "verilated.h"


class Vbitty_core__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vbitty_core___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vbitty_core__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vbitty_core___024unit(Vbitty_core__Syms* symsp, const char* v__name);
    ~Vbitty_core___024unit();
    VL_UNCOPYABLE(Vbitty_core___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
