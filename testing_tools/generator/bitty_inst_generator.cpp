#include "bitty_inst_generator.h"
#include <fstream>
#include <random>
#include <ctime>
#include <iostream>

uint16_t BittyInstructionGenerator::Generate(){

    uint16_t instruction = 0x0000;

    bool use_branch_instruction = (std::rand() % 3) == 2;
    bool use_immediate = (std::rand() % 2) == 1;

    uint16_t format = use_branch_instruction ? 0b10 : use_immediate ? 0b01 : 0b00;     
    instruction = instruction | format;

    if(use_branch_instruction){
        uint16_t branch_condition = std::rand() % 3;
        uint16_t branch_jump_addr = std::rand() % 256;

        instruction = instruction | (branch_condition << 2);
        instruction = instruction | (branch_jump_addr << 4);

        return instruction;
    }

    uint16_t alu_sel = std::rand() % 8;
    instruction = instruction | (alu_sel << 2);

    if(use_immediate){
        uint16_t reg1 = std::rand() % 8;
        uint16_t imm_val = std::rand() % 256;
        
        instruction = instruction | (reg1 << 13);
        instruction = instruction | (imm_val << 5);
    }else{
        uint16_t reg1 = std::rand() % 8;
        uint16_t reg2 = std::rand() % 8;
        
        instruction = instruction | (reg1 << 13);
        instruction = instruction | (reg2 << 10);
    }

    return instruction;
}

#ifdef BUILD_AS_MAIN

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <N> [output_filename]\n";
        return 1;
    }

    int n = std::atoi(argv[1]);
    if (n <= 0) {
        std::cerr << "Error: N must be a positive integer.\n";
        return 1;
    }

    std::string output_file = "program.txt";
    if (argc >= 3) {
        output_file = argv[2];
    }

    BittyInstructionGenerator gen;
    std::ofstream out(output_file);
    if (!out.is_open()) {
        std::cerr << "Failed to open output file: " << output_file << "\n";
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        uint16_t inst = gen.Generate();
        out << std::hex << std::uppercase << inst << std::endl;
    }

    out.close();
    std::cout << "Generated " << n << " instructions to '" << output_file << "'\n";
    return 0;
}

#endif
