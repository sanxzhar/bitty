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
#include "Vbitty_core___024unit.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vbitty_core__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vbitty_core* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vbitty_core___024root          TOP;
    Vbitty_core___024unit          TOP____024unit;

    // CONSTRUCTORS
    Vbitty_core__Syms(VerilatedContext* contextp, const char* namep, Vbitty_core* modelp);
    ~Vbitty_core__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
