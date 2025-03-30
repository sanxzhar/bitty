// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VBITTY_CORE__SYMS_H_
#define VERILATED_VBITTY_CORE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vbitty_core.h"

// INCLUDE MODULE CLASSES
#include "Vbitty_core___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vbitty_core__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vbitty_core* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vbitty_core___024root          TOP;

    // CONSTRUCTORS
    Vbitty_core__Syms(VerilatedContext* contextp, const char* namep, Vbitty_core* modelp);
    ~Vbitty_core__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
