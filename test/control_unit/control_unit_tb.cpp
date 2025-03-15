
#include <verilated.h>
#include "Vcontrol_unit.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vcontrol_unit* dut = new Vcontrol_unit;
    
    bool test_passed = true;
    int failed_tests = 0;
    
    for (int test = 0; test < 1000; test++) {
        uint16_t d_in = std::rand() & 0xFFFF;
        
        uint8_t first_operand = (d_in >> 13) & 0x7;
        uint8_t second_operand = (d_in >> 10) & 0x7;
        uint8_t alu_selection = (d_in >> 3) & 0xF;
        uint8_t alu_mode = (d_in >> 2) & 0x1;
        
        dut->reset = 1;
        dut->run = 0;
        dut->d_in = d_in;
        
        // Evaluate with reset active
        dut->clk = 0;
        dut->eval();
        dut->clk = 1;
        dut->eval();
        
        // Take out of reset, keep run=0
        dut->reset = 0;
        dut->clk = 0;
        dut->eval();
        dut->clk = 1;
        dut->eval();
        
        // Verify all outputs are inactive after reset
        if (dut->en_i || dut->en_s || dut->en_c || dut->done || 
            dut->en_0 || dut->en_1 || dut->en_2 || dut->en_3 || 
            dut->en_4 || dut->en_5 || dut->en_6 || dut->en_7) {
            std::cout << "Test " << test << " FAIL: Some outputs active after reset but before run" << std::endl;
            test_passed = false;
            failed_tests++;
        }
        
        // Now assert run to start the state machine
        dut->run = 1;
        dut->eval();
        
        // We should now be in INITIAL_STATE with en_i=1
        if (!dut->en_i) {
            std::cout << "Test " << test << " FAIL: Expected en_i = true in INITIAL_STATE, Got en_i = false" << std::endl;
            std::cout << "Debug - run: " << dut->run << ", reset: " << dut->reset << std::endl;
            test_passed = false;
            failed_tests++;
        }
        
        // Clock to move to LOAD_STATE
        dut->clk = 0;
        dut->eval();
        dut->clk = 1;
        dut->eval();
        
        // Check LOAD_STATE outputs
        if (!dut->en_s) {
            std::cout << "Test " << test << " FAIL: Expected en_s = true in LOAD_STATE, Got en_s = false" << std::endl;
            test_passed = false;
            failed_tests++;
        }
        
        if (dut->mux_sel != first_operand) {
            std::cout << "Test " << test << " FAIL: Expected mux_sel = " << static_cast<int>(first_operand)
                      << " in LOAD_STATE, Got mux_sel = " << static_cast<int>(dut->mux_sel) << std::endl;
            test_passed = false;
            failed_tests++;
        }
        
        // Clock to move to CALCULATE_STATE
        dut->clk = 0;
        dut->eval();
        dut->clk = 1;
        dut->eval();
        
        // Check CALCULATE_STATE outputs
        if (!dut->en_c) {
            std::cout << "Test " << test << " FAIL: Expected en_c = true in CALCULATE_STATE, Got en_c = false" << std::endl;
            test_passed = false;
            failed_tests++;
        }
        
        if (dut->alu_sel != alu_selection) {
            std::cout << "Test " << test << " FAIL: Expected alu_sel = " << static_cast<int>(alu_selection)
                      << " in CALCULATE_STATE, Got alu_sel = " << static_cast<int>(dut->alu_sel) << std::endl;
            test_passed = false;
            failed_tests++;
        }
        
        if (dut->mode != alu_mode) {
            std::cout << "Test " << test << " FAIL: Expected mode = " << static_cast<int>(alu_mode)
                      << " in CALCULATE_STATE, Got mode = " << static_cast<int>(dut->mode) << std::endl;
            test_passed = false;
            failed_tests++;
        }
        
        if (dut->mux_sel != second_operand) {
            std::cout << "Test " << test << " FAIL: Expected mux_sel = " << static_cast<int>(second_operand)
                      << " in CALCULATE_STATE, Got mux_sel = " << static_cast<int>(dut->mux_sel) << std::endl;
            test_passed = false;
            failed_tests++;
        }
        
        // Clock to move to STORE_STATE
        dut->clk = 0;
        dut->eval();
        dut->clk = 1;
        dut->eval();
        
        // Check STORE_STATE outputs
        if (!dut->done) {
            std::cout << "Test " << test << " FAIL: Expected done = true in STORE_STATE, Got done = false" << std::endl;
            test_passed = false;
            failed_tests++;
        }
        
        // Check that the correct register enable signal is set based on first_operand
        bool correct_reg_enable = false;
        switch (first_operand) {
            case 0: correct_reg_enable = dut->en_0; break;
            case 1: correct_reg_enable = dut->en_1; break;
            case 2: correct_reg_enable = dut->en_2; break;
            case 3: correct_reg_enable = dut->en_3; break;
            case 4: correct_reg_enable = dut->en_4; break;
            case 5: correct_reg_enable = dut->en_5; break;
            case 6: correct_reg_enable = dut->en_6; break;
            case 7: correct_reg_enable = dut->en_7; break;
        }
        
        if (!correct_reg_enable) {
            std::cout << "Test " << test << " FAIL: Register enable signal for register " << static_cast<int>(first_operand)
                      << " not set correctly in STORE_STATE" << std::endl;
            test_passed = false;
            failed_tests++;
        }
        
        // Verify only one register enable is active
        int active_enables = 
            dut->en_0 + dut->en_1 + dut->en_2 + dut->en_3 + 
            dut->en_4 + dut->en_5 + dut->en_6 + dut->en_7;
            
        if (active_enables != 1) {
            std::cout << "Test " << test << " FAIL: Expected exactly 1 active register enable in STORE_STATE, got " 
                      << active_enables << std::endl;
            test_passed = false;
            failed_tests++;
        }
        
        // Clock once more to return to INITIAL_STATE
        dut->clk = 0;
        dut->eval();
        dut->clk = 1;
        dut->eval();
        
        // Should be back in INITIAL_STATE with en_i=1
        if (!dut->en_i) {
            std::cout << "Test " << test << " FAIL: Expected en_i = true after cycle completion, Got en_i = false" << std::endl;
            test_passed = false;
            failed_tests++;
        }
    }
    
    std::cout << "Overall test result: " << (test_passed ? "PASSED" : "FAILED") << std::endl;
    if (!test_passed) {
        std::cout << "Failed " << failed_tests << " tests." << std::endl;
    }
    
    delete dut;
    return test_passed ? 0 : 1;
}