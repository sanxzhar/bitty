#include "Vtop.h"
#include "verilated.h"
#include <iostream>
#include <iomanip>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vtop* top = new Vtop;

    // Initial signal setup
    top->clk = 0;
    top->reset = 1;
    top->run = 0;

    // Apply reset for a few cycles
    for (int i = 0; i < 5; i++) {
        top->clk = 0; top->eval();
        top->clk = 1; top->eval();
    }

    // Deassert reset and enable run
    top->reset = 0;
    top->run = 1;

    int instr_count = 0;
    int max_instr = 100;

    while (instr_count < max_instr) {
        for (int i = 0; i < 4; i++) {
            top->clk = 0; top->eval();
            top->clk = 1; top->eval();
        }

        instr_count++;
    }

    std::cout << "Simulation finished after " << instr_count << " instructions.\n";

    top->final();
    delete top;
    return 0;
}
