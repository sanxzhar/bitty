#include <verilated.h>
#include "Vmux.h"
#include <iostream>
#include <vector>
struct TestCase {
    int sel;
    int reg_0;
    int reg_1;
    int reg_2;
    int reg_3;
    int reg_4;
    int reg_5;
    int reg_6;
    int reg_7;
    int reg_8;
    int reg_9;
    int expected_out;
    const char* description;
};

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vmux* dut = new Vmux;

    std::vector<TestCase> testCases = {
        // sel, reg_0, reg_1, reg_2, reg_3, reg_4, reg_5, reg_6, reg_7, reg_8, reg_9, expected_out, description
        {0, 15, 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, "reg_0 selection"},
        {1, 0, 15, 2, 3, 4, 5, 6, 7, 8, 9, 15, "reg_1 selection"},
        {2, 0, 1, 15, 3, 4, 5, 6, 7, 8, 9, 15, "reg_2 selection"},
        {3, 0, 1, 2, 15, 4, 5, 6, 7, 8, 9, 15, "reg_3 selection"},
        {4, 0, 1, 2, 3, 15, 5, 6, 7, 8, 9, 15, "reg_4 selection"},
        {5, 0, 1, 2, 3, 4, 15, 6, 7, 8, 9, 15, "reg_5 selection"},
        {6, 0, 1, 2, 3, 4, 5, 15, 7, 8, 9, 15, "reg_6 selection"},
        {7, 0, 1, 2, 3, 4, 5, 6, 15, 8, 9, 15, "reg_7 selection"},
        {8, 0, 1, 2, 3, 4, 5, 6, 7, 15, 9, 15, "reg_8 selection"},
        {9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 15, 15, "reg_9 selection"},
        {12, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, "non-reg selection"},
    };

    u_int16_t current_out = 0;
    bool test_passed = true;

    for (size_t i = 0; i < testCases.size(); i++) {
        const auto& test = testCases[i];

        dut->sel = test.sel;
        dut->reg_0 = test.reg_0;
        dut->reg_1 = test.reg_1;
        dut->reg_2 = test.reg_2;
        dut->reg_3 = test.reg_3;
        dut->reg_4 = test.reg_4;
        dut->reg_5 = test.reg_5;
        dut->reg_6 = test.reg_6;
        dut->reg_7 = test.reg_7;
        dut->reg_8 = test.reg_8;
        dut->reg_9 = test.reg_9;
        dut->eval();

        if (dut->out != test.expected_out) {
            std::cout << "  FAIL: Expected out = " << test.expected_out
                      << ", Got out = " << dut->out << std::endl;
            test_passed = false;
        }

    }

    std::cout << "Overall test result: " << (test_passed ? "PASSED" : "FAILED") << std::endl;

    delete dut;
    
    return 0;
}