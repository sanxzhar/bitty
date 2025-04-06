#include "bitty_emu.h"

BittyEmulator::BittyEmulator() : registers_(8, 0)
{
}

uint16_t BittyEmulator::Evaluate(uint16_t instruction)
{   
    // splitting binary
    uint8_t register_1 = (instruction >> 13) & 0x7;
    uint8_t register_2 = (instruction >> 10) & 0x7;
    uint8_t alu_select = (instruction >> 2) & 0x7;
    
    uint8_t format_type = instruction & 0x3;

    uint8_t immediate_val = (instruction >> 5) & 0xFF;
    int16_t extended_imm_val = (immediate_val & 0x80) ? (0xFF00 | immediate_val) : immediate_val;

    // extracting stored values
    uint16_t register_1_value = registers_[register_1];
    uint16_t register_2_value = (format_type == 0b01) ? extended_imm_val : registers_[register_2];

    // calculation
    uint16_t result;
    switch(alu_select){
        case 0x0: result = register_1_value + register_2_value; break;
        case 0x1: result = register_1_value - register_2_value; break;
        case 0x2: result = register_1_value & register_2_value; break;
        case 0x3: result = register_1_value | register_2_value; break;
        case 0x4: result = register_1_value ^ register_2_value; break;
        case 0x5: result = register_1_value << register_2_value % 16; break;
        case 0x6: result = register_1_value >> register_2_value % 16; break;
        case 0x7: result = (register_1_value == register_2_value) ? 0 : (register_1_value > register_2_value) ? 1 : 2;
    }

    registers_[register_1] = result;
    return result;
}

uint16_t BittyEmulator::GetRegisterValue(uint16_t reg_num)
{
    if (reg_num < registers_.size())
    {
        return registers_[reg_num];
    }
    return 0;
}