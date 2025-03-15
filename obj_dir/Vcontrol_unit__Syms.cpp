// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vcontrol_unit__pch.h"
#include "Vcontrol_unit.h"
#include "Vcontrol_unit___024root.h"

// FUNCTIONS
Vcontrol_unit__Syms::~Vcontrol_unit__Syms()
{
}

Vcontrol_unit__Syms::Vcontrol_unit__Syms(VerilatedContext* contextp, const char* namep, Vcontrol_unit* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(117);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
