#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <Vbitty_core.h>
#include "../../testing_tools/generator/bitty_inst_generator.h"

// Global simulation time
vluint64_t main_time = 0;

void clockPulse(Vbitty_core* dut, VerilatedVcdC* tfp) {
    dut->clk = 0;
    dut->eval();
    tfp->dump(main_time++);
    
    dut->clk = 1;
    dut->eval();
    tfp->dump(main_time++);
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vbitty_core* dut = new Vbitty_core;

    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("dump.vcd");

    BittyInstructionGenerator gen;

    std::cout << "========================================\n";
    std::cout << "       Bitty Core Random Testbench\n";
    std::cout << "========================================\n";

    // Apply reset
    dut->reset = 1;
    dut->run = 1;
    dut->clk = 0;
    dut->eval();
    tfp->dump(main_time++);
    dut->clk = 1;
    dut->eval();
    tfp->dump(main_time++);

    // Release reset
    dut->reset = 0;
    dut->clk = 0;
    dut->eval();
    tfp->dump(main_time++);

    // Run 100 test instructions
    for (int i = 0; i < 10000; ++i) {
        uint16_t instruction = gen.Generate();
        dut->instruction = instruction;

        std::cout << "Test " << i + 1 << ": Executing instruction 0x" 
                  << std::hex << instruction << std::dec << "\n";

        for (int cycle = 0; cycle < 4; ++cycle) {
            clockPulse(dut, tfp);
        }
    }

    std::cout << "========================================\n";
    std::cout << "         Simulation Complete\n";
    std::cout << "========================================\n";

    tfp->close();
    dut->final();
    delete dut;
    delete tfp;

    return 0;
}