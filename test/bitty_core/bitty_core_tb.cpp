#include <verilated.h>
#include <Vbitty_core.h>
#include <iostream>
#include <map>
#include <string>
#include <variant>
#include <vector>
#include <iomanip>

struct InstructionInfo {
    uint8_t alu_select_signal;
    uint8_t instr_format_type;
};

uint16_t encoder(std::string operation, std::string register1, std::variant<std::string, int> register2) {
    std::map<std::string, InstructionInfo> operations = {
        {"add",  {0b000, 0b00}}, {"addi", {0b000, 0b01}},
        {"sub",  {0b001, 0b00}}, {"subi", {0b001, 0b01}},
        {"and",  {0b010, 0b00}}, {"andi", {0b010, 0b01}},
        {"or",   {0b011, 0b00}}, {"ori",  {0b011, 0b01}},
        {"xor",  {0b100, 0b00}}, {"xori", {0b100, 0b01}},
        {"shl",  {0b101, 0b00}}, {"shli", {0b101, 0b01}},
        {"shr",  {0b110, 0b00}}, {"shri", {0b110, 0b01}},
        {"cmp",  {0b111, 0b00}}, {"cmpi", {0b111, 0b01}}
    };

    std::map<std::string, uint8_t> registers = {
        {"r0", 0b000},
        {"r1", 0b001},
        {"r2", 0b010},
        {"r3", 0b011},
        {"r4", 0b100},
        {"r5", 0b101},
        {"r6", 0b110},
        {"r7", 0b111}
    };

    if (operations.find(operation) == operations.end()) {
        std::cerr << "Error: Invalid operation '" << operation << "'\n";
        return 0xFFFF;
    }

    if (registers.find(register1) == registers.end()) {
        std::cerr << "Error: Invalid register '" << register1 << "'\n";
        return 0xFFFF;
    }

    InstructionInfo info = operations[operation];
    uint8_t alu_select_signal = info.alu_select_signal;
    uint8_t instr_format_type = info.instr_format_type;
    uint8_t register1_binary = registers[register1];

    uint16_t instruction = 0;

    if (instr_format_type == 0b00) {
        if (!std::holds_alternative<std::string>(register2)) {
            std::cerr << "Error: Second operand must be a register for this instruction type.\n";
            return 0xFFFF;
        }

        std::string register2_str = std::get<std::string>(register2);

        if (registers.find(register2_str) == registers.end()) {
            std::cerr << "Error: Invalid register '" << register2_str << "'\n";
            return 0xFFFF;
        }

        uint8_t register2_binary = registers[register2_str];
        instruction = (register1_binary << 13) | (register2_binary << 10) | (alu_select_signal << 2) | (instr_format_type);
    } 
    else if (instr_format_type == 0b01) {
        if (!std::holds_alternative<int>(register2)) {
            std::cerr << "Error: Second operand must be an immediate value for this instruction type.\n";
            return 0xFFFF;
        }

        uint16_t immediate_value = static_cast<uint16_t>(std::get<int>(register2)) & 0xFF;
        instruction = (register1_binary << 13) | (immediate_value << 5) | (alu_select_signal << 2) | (instr_format_type);
    }

    return instruction;
}

struct TestCase {
    std::string name;
    std::string operation;
    std::string dest_reg;
    std::variant<std::string, int> operand;
    uint16_t expected_result;
};

void tick(Vbitty_core* dut, bool run = false) {
    dut->run = run;
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
}

void print_registers(Vbitty_core* dut) {
    std::cout << "Registers: ";
    std::cout << "r0=" << std::setw(5) << dut->reg0_to_mux << " ";
    std::cout << "r1=" << std::setw(5) << dut->reg1_to_mux << " ";
    std::cout << "r2=" << std::setw(5) << dut->reg2_to_mux << " ";
    std::cout << "r3=" << std::setw(5) << dut->reg3_to_mux << " ";
    std::cout << "r4=" << std::setw(5) << dut->reg4_to_mux << " ";
    std::cout << "r5=" << std::setw(5) << dut->reg5_to_mux << " ";
    std::cout << "r6=" << std::setw(5) << dut->reg6_to_mux << " ";
    std::cout << "r7=" << std::setw(5) << dut->reg7_to_mux << std::endl;
}

uint16_t get_register_value(Vbitty_core* dut, const std::string& reg_name) {
    if (reg_name == "r0") return dut->reg0_to_mux;
    if (reg_name == "r1") return dut->reg1_to_mux;
    if (reg_name == "r2") return dut->reg2_to_mux;
    if (reg_name == "r3") return dut->reg3_to_mux;
    if (reg_name == "r4") return dut->reg4_to_mux;
    if (reg_name == "r5") return dut->reg5_to_mux;
    if (reg_name == "r6") return dut->reg6_to_mux;
    if (reg_name == "r7") return dut->reg7_to_mux;
    return 0xFFFF; // Error
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vbitty_core* dut = new Vbitty_core;

    bool all_tests_passed = true;
    int total_tests = 0;
    int failed_tests = 0;

    // Initialize the core
    dut->reset = 1;
    tick(dut);
    dut->reset = 0;
    
    std::vector<TestCase> test_cases = {
        // Test immediate operations
        {"Add Immediate", "addi", "r0", 10, 10},
        {"Add Immediate to existing value", "addi", "r0", 5, 15},
        {"Subtract Immediate", "subi", "r1", 7, 0xFFF9},
        {"Initialize r2", "addi", "r2", 0x0F, 0x000F},
        {"AND Immediate", "andi", "r2", 0x0F, 0x0F}, 
        {"Initialize r3", "addi", "r3", 0xF0, 0xFFF0},
        {"OR Immediate", "ori", "r3", 0xF0, 0xFFF0},
        {"Initialize r4", "addi", "r4", 0xFF, 0xFFFF},
        {"XOR Immediate", "xori", "r4", 0xAA, 0x55},
        {"Shift Left Immediate", "shli", "r0", 3, 120},
        {"Shift Right Immediate", "shri", "r0", 2, 30},

        // Test register operations
        {"Load value for register tests", "addi", "r7", 0x04, 0x0004},
        {"Add Register", "add", "r1", std::string("r7"),  static_cast<uint16_t>(0xFFF9 + 0x0004)},
        {"Subtract Register", "sub", "r2", std::string("r7"), static_cast<uint16_t>(0x0F - 0x0004)},
        {"AND Register", "and", "r3", std::string("r7"), 0xFFF0 & 0x0004},
        {"OR Register", "or", "r4", std::string("r7"), 0x55 | 0x0004},
        {"XOR Register", "xor", "r1", std::string("r7"), static_cast<uint16_t>(0xFFF9 + 0x0004) ^ 0x0004},
        {"Initialize r6", "addi", "r6", 0x02, 0x0002},
        {"Shift Left Register", "shl", "r0", std::string("r6"), 120},
        {"Shift Right Register", "shr", "r0", std::string("r6"), 30}
    };

    std::cout << "Starting bitty_core testbench..." << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    
    // Run test cases
    for (const auto& test : test_cases) {
        total_tests++;
        std::cout << "Test " << total_tests << ": " << test.name << std::endl;
        
        uint16_t instruction = encoder(test.operation, test.dest_reg, test.operand);
        std::cout << "  Instruction: 0x" << std::hex << instruction << std::dec << std::endl;
        
        dut->instraction = instruction;
        
        // First cycle: Load instruction
        tick(dut, true);
        // Second cycle: Load source operand to S register
        tick(dut, true);
        // Third cycle: Perform operation in ALU and store to C register
        tick(dut, true);
        // // Fourth cycle: Store result to destination register
        tick(dut, true);
        
        uint16_t actual_result = get_register_value(dut, test.dest_reg);
        
        bool test_passed = true;
        test_passed = (actual_result == test.expected_result);
        std::cout << "  Expected: 0x" << std::hex << test.expected_result << std::dec << std::endl;
        std::cout << "  Actual:   0x" << std::hex << actual_result << std::dec << std::endl;
        std::cout << "  " << (test_passed ? "PASSED" : "FAILED") << std::endl;
        
        if (!test_passed) {
            all_tests_passed = false;
            failed_tests++;
        }
        
        print_registers(dut);
        std::cout << "-------------------------------------" << std::endl;
    }
    
    // Special test case for done signal
    std::cout << "\nTesting done signal..." << std::endl;
    dut->instraction = encoder("addi", "r0", 1);
    std::cout << "  INITIAL_STATE: " << static_cast<int>(dut->done) << " (Expected: 0)" << std::endl;
    bool done_test1 = (dut->done == 0);

    tick(dut, true); // FROM INITIAL_STATE TO LOAD_STATE

    std::cout << "  LOAD_STATE: " << static_cast<int>(dut->done) << " (Expected: 0)" << std::endl;
    bool done_test2 = (dut->done == 0);

    tick(dut, true); // FROM LOAD_STATE TO CALCULATE_STATE
    
    std::cout << "  CALCULATE_STATE: " << static_cast<int>(dut->done) << " (Expected: 0)" << std::endl;
    bool done_test3 = (dut->done == 0);

    tick(dut, true);  // FROM CALCULATE_STATE TO STORE_STATE

    std::cout << "  STORE_STATE: " << static_cast<int>(dut->done) << " (Expected: 1)" << std::endl;
    bool done_test4 = (dut->done == 1);
    
    bool done_test_passed = done_test1 && done_test2 && done_test3 && done_test4;
    if (!done_test_passed) {
        all_tests_passed = false;
        failed_tests++;
    }
    
    std::cout << "Done signal test " << (done_test_passed ? "PASSED" : "FAILED") << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    
    std::cout << "Test Summary:" << std::endl;
    std::cout << "  Total tests: " << total_tests + 1 << std::endl;
    std::cout << "  Passed: " << (total_tests + 1 - failed_tests) << std::endl;
    std::cout << "  Failed: " << failed_tests << std::endl;
    std::cout << "  Result: " << (all_tests_passed ? "ALL TESTS PASSED" : "SOME TESTS FAILED") << std::endl;
    
    delete dut;
    return all_tests_passed ? 0 : 1;
}
