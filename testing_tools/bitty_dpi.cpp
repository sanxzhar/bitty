#include <iostream>
#include <cstdlib>
#include "emulator/bitty_emu.h"
#include "svdpi.h"
#include <stdint.h>

extern "C" void compare_results(
    svBitVecVal* instruction,
    svBitVecVal* reg0, svBitVecVal* reg1, svBitVecVal* reg2, svBitVecVal* reg3,
    svBitVecVal* reg4, svBitVecVal* reg5, svBitVecVal* reg6, svBitVecVal* reg7
) {
    static BittyEmulator emulator;

    static bool initialized = false;
    if (!initialized) {
        emulator.LoadMemoryFromFile("/Users/sanzhar/coding/mdv/bitty/testing_tools/generator/program.txt");
        initialized = true;
    }

    uint16_t inst_from_emulator = emulator.Step();
    uint16_t inst_from_verilog = instruction[0];

    uint16_t verilog_registers[8] = {
        reg0[0], reg1[0], reg2[0], reg3[0],
        reg4[0], reg5[0], reg6[0], reg7[0]
    };

    bool mismatch = false;
    for (int i = 0; i < 8; ++i) {
        uint16_t expected = emulator.GetRegisterValue(i);
        if (expected != verilog_registers[i]) {
            mismatch = true;
            break;
        }
    }

    if (!mismatch) {
        printf("Verification PASSED for instruction 0x%04x\n", inst_from_verilog); }
    else {
        printf("Verification FAILED for instruction 0x%04x\n", inst_from_verilog);

        printf("Evaluating instruction emulator: ");
        for (int bit = 15; bit >= 0; --bit)
            printf("%d", (inst_from_emulator >> bit) & 1);
        printf("\n");

        printf("Evaluating instruction verilog: ");
        for (int bit = 15; bit >= 0; --bit)
            printf("%d", (inst_from_verilog >> bit) & 1);
        printf("\n");

        printf("Verilog Simulation Register Values:\n");
        for (int i = 0; i < 8; ++i) {
            printf("  reg%d = ", i);
            for (int bit = 15; bit >= 0; --bit)
                printf("%d", (verilog_registers[i] >> bit) & 1);
            printf("\n");
        }

        printf("Emulator Expected Register Values:\n");
        for (int i = 0; i < 8; ++i) {
            uint16_t expected = emulator.GetRegisterValue(i);
            printf("  reg%d = ", i);
            for (int bit = 15; bit >= 0; --bit)
                printf("%d", (expected >> bit) & 1);
            printf("\n");
        }

        std::exit(1);
    }

}