#include <Vtop.h>
#include <verilated.h>
#include <iostream>
#include <iomanip>
#include <verilated_vcd_c.h>

vluint64_t main_time = 0;

void clockPulse(Vtop* dut, VerilatedVcdC* tfp) {
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

    Vtop* top = new Vtop;
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("dump.vcd");

    // Initial signal setup
    top->clk = 0;
    top->reset = 1;
    top->run = 0;

    // Apply reset for a few cycles
    for (int i = 0; i < 5; i++) {
        clockPulse(top, tfp);
    }

    // Deassert reset and enable run
    top->reset = 0;
    top->run = 1;

    int instr_count = 0;
    int max_instr = 10000;

    while (instr_count < max_instr) {
        for (int i = 0; i < 4; i++) {
            clockPulse(top, tfp);
        }
        std::cout << "Done\n";
        instr_count++;
    }

    std::cout << "Simulation finished after " << instr_count << " instructions.\n";

    tfp->close();
    top->final();
    delete top;
    return 0;
}
