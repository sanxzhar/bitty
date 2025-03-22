#include <verilated.h>
#include "Valu.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Valu* dut = new Valu;

    for (int sel = 0; sel < 8; sel++) {
        for (int test = 0; test < 10; test++) {
            uint16_t in_a = std::rand() & 0xFFFF;
            uint16_t in_b = std::rand() & 0xFFFF;

            dut->in_a = in_a;
            dut->in_b = in_b;
            dut->sel = sel;

            dut->eval();

            uint16_t expected_result;
            bool expected_cout = false;
            bool expected_cmp = false;

            switch(sel){
                case 0x0: expected_result = in_a + in_b; break;
                case 0x1: expected_result = in_a - in_b; break;
                case 0x2: expected_result = in_a & in_b; break;
                case 0x3: expected_result = in_a | in_b; break;
                case 0x4: expected_result = in_a ^ in_b; break;
                case 0x5: expected_result = in_a << in_b % 16; break;
                case 0x6: expected_result = in_a >> in_b % 16; break;
                case 0x7: expected_result = (in_a == in_b) ? 0 : (in_a > in_b) ? 1 : 2;
            }

            // Check output
            if (dut->out != expected_result) {
                std::cout << "Mismatch at Sel=" << sel
                          << " in_a=" << in_a << " in_b=" << in_b
                          << " Expected=" << expected_result
                          << " Got=" << dut->out
                          << std::endl;
            }
        }
    }

    std::cout << "Testbench completed." << std::endl;
    delete dut;
    return 0;
}
