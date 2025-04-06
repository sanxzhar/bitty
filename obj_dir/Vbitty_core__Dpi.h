// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VBITTY_CORE__DPI_H_
#define VERILATED_VBITTY_CORE__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at rtl/bitty_monitor.v:1:30
    extern void compare_results(const svBitVecVal* instruction, const svBitVecVal* reg0, const svBitVecVal* reg1, const svBitVecVal* reg2, const svBitVecVal* reg3, const svBitVecVal* reg4, const svBitVecVal* reg5, const svBitVecVal* reg6, const svBitVecVal* reg7);

#ifdef __cplusplus
}
#endif

#endif  // guard
