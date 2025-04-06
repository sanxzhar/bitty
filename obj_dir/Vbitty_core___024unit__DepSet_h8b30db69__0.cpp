// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitty_core.h for the primary calling header

#include "Vbitty_core__pch.h"
#include "Vbitty_core__Syms.h"
#include "Vbitty_core___024unit.h"

extern "C" void compare_results(const svBitVecVal* instruction, const svBitVecVal* reg0, const svBitVecVal* reg1, const svBitVecVal* reg2, const svBitVecVal* reg3, const svBitVecVal* reg4, const svBitVecVal* reg5, const svBitVecVal* reg6, const svBitVecVal* reg7);

VL_INLINE_OPT void Vbitty_core___024unit____Vdpiimwrap_compare_results_TOP____024unit(SData/*15:0*/ instruction, SData/*15:0*/ reg0, SData/*15:0*/ reg1, SData/*15:0*/ reg2, SData/*15:0*/ reg3, SData/*15:0*/ reg4, SData/*15:0*/ reg5, SData/*15:0*/ reg6, SData/*15:0*/ reg7) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vbitty_core___024unit____Vdpiimwrap_compare_results_TOP____024unit\n"); );
    // Body
    svBitVecVal instruction__Vcvt[1];
    for (size_t instruction__Vidx = 0; instruction__Vidx < 1; ++instruction__Vidx) VL_SET_SVBV_I(16, instruction__Vcvt + 1 * instruction__Vidx, instruction);
    svBitVecVal reg0__Vcvt[1];
    for (size_t reg0__Vidx = 0; reg0__Vidx < 1; ++reg0__Vidx) VL_SET_SVBV_I(16, reg0__Vcvt + 1 * reg0__Vidx, reg0);
    svBitVecVal reg1__Vcvt[1];
    for (size_t reg1__Vidx = 0; reg1__Vidx < 1; ++reg1__Vidx) VL_SET_SVBV_I(16, reg1__Vcvt + 1 * reg1__Vidx, reg1);
    svBitVecVal reg2__Vcvt[1];
    for (size_t reg2__Vidx = 0; reg2__Vidx < 1; ++reg2__Vidx) VL_SET_SVBV_I(16, reg2__Vcvt + 1 * reg2__Vidx, reg2);
    svBitVecVal reg3__Vcvt[1];
    for (size_t reg3__Vidx = 0; reg3__Vidx < 1; ++reg3__Vidx) VL_SET_SVBV_I(16, reg3__Vcvt + 1 * reg3__Vidx, reg3);
    svBitVecVal reg4__Vcvt[1];
    for (size_t reg4__Vidx = 0; reg4__Vidx < 1; ++reg4__Vidx) VL_SET_SVBV_I(16, reg4__Vcvt + 1 * reg4__Vidx, reg4);
    svBitVecVal reg5__Vcvt[1];
    for (size_t reg5__Vidx = 0; reg5__Vidx < 1; ++reg5__Vidx) VL_SET_SVBV_I(16, reg5__Vcvt + 1 * reg5__Vidx, reg5);
    svBitVecVal reg6__Vcvt[1];
    for (size_t reg6__Vidx = 0; reg6__Vidx < 1; ++reg6__Vidx) VL_SET_SVBV_I(16, reg6__Vcvt + 1 * reg6__Vidx, reg6);
    svBitVecVal reg7__Vcvt[1];
    for (size_t reg7__Vidx = 0; reg7__Vidx < 1; ++reg7__Vidx) VL_SET_SVBV_I(16, reg7__Vcvt + 1 * reg7__Vidx, reg7);
    compare_results(instruction__Vcvt, reg0__Vcvt, reg1__Vcvt, reg2__Vcvt, reg3__Vcvt, reg4__Vcvt, reg5__Vcvt, reg6__Vcvt, reg7__Vcvt);
}
