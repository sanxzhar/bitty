// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VALU__SYMS_H_
#define VERILATED_VALU__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Valu.h"

// INCLUDE MODULE CLASSES
#include "Valu___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Valu__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Valu* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Valu___024root                 TOP;

    // CONSTRUCTORS
    Valu__Syms(VerilatedContext* contextp, const char* namep, Valu* modelp);
    ~Valu__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
