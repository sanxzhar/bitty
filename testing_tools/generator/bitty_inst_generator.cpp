#include "bitty_inst_generator.h"
#include <random>
#include <ctime>
#include <iostream>

uint16_t BittyInstructionGenerator::Generate(){

    uint16_t instruction = 0x0000;

    bool use_immediate = (std::rand() % 2) == 1;

    uint16_t format = use_immediate ? 0x01 : 0x00;
    instruction = instruction | format;

    uint16_t alu_sel = std::rand() % 8;
    instruction = instruction | (alu_sel << 2);

    if (use_immediate) {
        uint16_t reg1 = std::rand() % 8;
        uint16_t imm_val = std::rand() % 256;
        
        instruction = instruction | (reg1 << 13);
        instruction = instruction | (imm_val << 5);
    } else {
        uint16_t reg1 = std::rand() % 8;
        uint16_t reg2 = std::rand() % 8;
        
        instruction = instruction | (reg1 << 13);
        instruction = instruction | (reg2 << 10);
    }

    return instruction;
}