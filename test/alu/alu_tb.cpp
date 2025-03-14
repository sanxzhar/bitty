#include <verilated.h>
#include "Valu.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Valu* alu = new Valu;

    for (int sel = 0; sel < 16; sel++) {
        for (int test = 0; test < 1000; test++) {
            uint16_t in_a = std::rand() & 0xFFFF;
            uint16_t in_b = std::rand() & 0xFFFF;
            int mode = std::rand() % 2;
            int carry_in = std::rand() % 2;

            alu->in_a = in_a;
            alu->in_b = in_b;
            alu->select = sel;
            alu->mode = mode;
            alu->carry_in = carry_in;

            alu->eval();

            uint16_t expected_result;
            bool expected_cout = false;
            bool expected_cmp = false;

            if (mode == 1) {
                switch (sel) {
                    case 0x0: expected_result = ~in_a; break;
                    case 0x1: expected_result = ~(in_a | in_b); break;
                    case 0x2: expected_result = ~in_a & in_b; break;
                    case 0x3: expected_result = 0x0000; break;
                    case 0x4: expected_result = ~(in_a & in_b); break;
                    case 0x5: expected_result = ~in_b; break;
                    case 0x6: expected_result = in_a ^ in_b; break;
                    case 0x7: expected_result = in_a & ~in_b; break;
                    case 0x8: expected_result = ~in_a | in_b; break;
                    case 0x9: expected_result = ~(in_a ^ in_b); break;
                    case 0xA: expected_result = in_b; break;
                    case 0xB: expected_result = in_a & in_b; break;
                    case 0xC: expected_result = 0x0001; break;
                    case 0xD: expected_result = in_a | ~in_b; break;
                    case 0xE: expected_result = in_a | in_b; break;
                    case 0xF: expected_result = in_a; break;
                }
            }

            else {
                int32_t result = 0;
                switch (sel) {
                    case 0x0: result = in_a; break;
                    case 0x1: result = in_a | in_b; break;
                    case 0x2: result = in_a | ~in_b; break;
                    case 0x3: result = 0xFFFF; break;
                    case 0x4: result = in_a | (in_a & ~in_b); break;
                    case 0x5: result = (in_a | in_b) + (in_a & ~in_b) + carry_in; break;
                    case 0x6: result = in_a - in_b - 1; break;
                    case 0x7: result = (in_a & ~in_b) - 1; break;
                    case 0x8: result = in_a + (in_a & in_b) + carry_in; break;
                    case 0x9: result = in_a + in_b + carry_in; break;
                    case 0xA: result = (in_a | ~in_b) + (in_a & in_b) + carry_in; break;
                    case 0xB: result = (in_a & in_b) - 1; break;
                    case 0xC: result = in_a + in_a + carry_in; break;
                    case 0xD: result = (in_a | in_b) + in_a + carry_in; break;
                    case 0xE: result = (in_a | ~in_b) + in_a + carry_in; break;
                    case 0xF: result = in_a - 1; break;
                }
                expected_result = result & 0xFFFF;
                expected_cout = (result >> 16);
                expected_cmp = in_a == in_b;
            }

            // Check output
            if (alu->alu_out != expected_result || alu->carry_out != expected_cout || alu->compare != expected_cmp) {
                std::cout << "Mismatch at Sel=" << sel
                          << " in_a=" << in_a << " in_b=" << in_b
                          << " mode=" << mode << " carry_in=" << carry_in
                          << " Expected=" << expected_result
                          << " Got=" << alu->alu_out
                          << " Expected COut=" << expected_cout
                          << " Got COut=" << (int)alu->carry_out
                          << " Expected Cmp=" << expected_cmp
                          << " Got Cmp=" << (int)alu->compare
                          << std::endl;
            }
        }
    }

    std::cout << "Testbench completed." << std::endl;
    delete alu;
    return 0;
}
