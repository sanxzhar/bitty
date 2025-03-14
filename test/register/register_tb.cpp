#include <verilated.h>
#include "Vregister.h"
#include <iostream>
#include <vector>

struct TestCase {
    bool reset;
    bool en_i;
    uint16_t d_in;
    uint16_t expected_d_out;
    const char* description;
};

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vregister* dut = new Vregister;
    
    std::vector<TestCase> testCases = {
        // reset, en_i, d_in, expected_d_out, description
        {true,  false, 0x0000, 0x0000, "Reset test"},
        {false, true,  0x1234, 0x1234, "Enable and load data"},
        {false, false, 0x5678, 0x1234, "Disabled, data should not change"},
        {false, true,  0xABCD, 0xABCD, "Enable and load new data"},
        {true,  false, 0xFFFF, 0x0000, "Reset while input is high"}
    };
    
    uint16_t current_d_out = 0;
    bool test_passed = true;
    
    for (size_t i = 0; i < testCases.size(); i++) {
        const auto& test = testCases[i];
        
        dut->reset = test.reset;
        dut->en_i = test.en_i;
        dut->d_in = test.d_in;
        
        dut->clk = 0;
        dut->eval();
        
        dut->clk = 1;
        dut->eval();
        
        dut->clk = 0;
        dut->eval();
        
        if (dut->d_out != test.expected_d_out) {
            std::cout << "  FAIL: Expected d_out = 0x" << std::hex << test.expected_d_out
                      << ", Got d_out = 0x" << dut->d_out << std::dec << std::endl;
            test_passed = false;
        }
    }
    
    std::cout << "Overall test result: " << (test_passed ? "PASSED" : "FAILED") << std::endl;
    
    delete dut;
    
    return 0;
}