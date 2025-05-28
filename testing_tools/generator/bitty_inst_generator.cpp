#include "bitty_inst_generator.h"
#include <fstream>
#include <random>
#include <ctime>
#include <iostream>

BittyInstructionGenerator::BittyInstructionGenerator() {
    std::srand(std::time(nullptr));
}

uint16_t BittyInstructionGenerator::Generate(){

    uint16_t instruction = 0x0000;

    uint8_t instruction_type = std::rand() % 4;
    uint16_t format;
    
    switch(instruction_type) {
        case 0: format = 0b00; break;  // register-register
        case 1: format = 0b01; break;  // immediate
        case 2: format = 0b10; break;  // branch
        case 3: format = 0b11; break;  // memory operation
    }
    instruction = instruction | format;

    if(format == 0b10){
        uint16_t branch_condition = std::rand() % 3;
        uint16_t branch_jump_addr = std::rand() % 65536;

        instruction = instruction | (branch_condition << 2);
        instruction = instruction | (branch_jump_addr << 4);

        return instruction;
    }

    if(format == 0b11) {
        uint16_t reg1 = std::rand() % 8;
        uint16_t reg2 = std::rand() % 8;
        uint16_t load_store_bit = std::rand() % 2;
        
        instruction = instruction | (reg1 << 13);
        instruction = instruction | (reg2 << 10);
        instruction = instruction | (load_store_bit << 2);
        
        return instruction;
    }

    uint16_t alu_sel = std::rand() % 8;
    instruction = instruction | (alu_sel << 2);

    if(format == 0b01){
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
    std::srand(std::time(nullptr));
    
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
