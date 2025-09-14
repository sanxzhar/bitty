#include "bitty_emu.h"
#include <fstream>
#include <algorithm>

BittyEmulator::BittyEmulator() : registers_(8, 0), memory_(65535, 0), pc_(0), last_alu_result_(0)
{
}

uint16_t BittyEmulator::Evaluate(uint16_t instruction)
{   
    // splitting binary
    uint8_t register_1 = (instruction >> 13) & 0x7;
    uint8_t register_2 = (instruction >> 10) & 0x7;
    uint8_t alu_select = (instruction >> 2) & 0x7;
    
    uint8_t format_type = instruction & 0x3;

    if (format_type == 0b11) {
        uint8_t load_store_bit = (instruction >> 2) & 0x1;
        if (load_store_bit == 0) {
            uint16_t mem_address = registers_[register_2];
            if(mem_address > memory_.size()){
                return 0;
            }

            registers_[register_1] = memory_[mem_address];
            last_alu_result_ = registers_[register_1];
            return registers_[register_1];
        }else{
            uint16_t mem_address = registers_[register_2];
            if(mem_address > memory_.size()){
                return 0;
            }

            memory_[mem_address] = registers_[register_1];
            return memory_[mem_address];
        }
        return 0;
    }

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
    last_alu_result_ = result;
    return result;
}

void BittyEmulator::EvaluateBranchInstr(){
    uint16_t inst = memory_[pc_];

    if((inst & 0b11) != 0b10){
        return;
    }

    pc_ = pc_ + 1;
    uint8_t branch_condition = (inst >> 2) & 0b11;

    if(branch_condition > 0b10){
        return;
    }

    switch(branch_condition) {
        case 0b00:
            if (last_alu_result_ != 0) return;
            break;
        case 0b01:
            if (last_alu_result_ != 1) return;
            break;
        case 0b10:
            if (last_alu_result_ != 2) return;
            break;
    }
    uint16_t branch_jump_addr = (inst >> 4) & 0x0FFF;
    pc_ = branch_jump_addr;

    return;
}

uint16_t BittyEmulator::GetRegisterValue(uint16_t reg_num)
{
    if (reg_num < registers_.size())
    {
        return registers_[reg_num];
    }
    return 0;
}

void BittyEmulator::SetRegisterValue(uint16_t reg_num, uint16_t value)
{
    if (reg_num < registers_.size()) {
        registers_[reg_num] = value;
    }
}

bool BittyEmulator::LoadMemoryFromFile(const std::string& filename, uint16_t start_address)
{
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Failed to open instruction file: " << filename << std::endl;
        return false;
    }

    std::string line;
    uint16_t address = start_address;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        line.erase(remove_if(line.begin(), line.end(), isspace), line.end());

        uint16_t instruction = std::stoul(line, nullptr, 16);
        if (address >= memory_.size()) break;
        memory_[address++] = instruction;
    }

    pc_ = start_address;
    return true;
}

uint16_t BittyEmulator::Step()
{
    if (pc_ >= memory_.size()) return 0;

    uint16_t inst = memory_[pc_];
    uint8_t format_type = inst & 0b11;

    if (format_type == 0b10) {
        EvaluateBranchInstr();
        printf("Branch instruction executed, PC updated to %d\n", pc_);
    }

    uint16_t new_inst = memory_[pc_];
    Evaluate(new_inst);
    pc_ = pc_ + 1;


    uint8_t next_inst_format_type = memory_[pc_] & 0b11;
    while(next_inst_format_type == 0b10){
        EvaluateBranchInstr(); // pc_ updated (incremented or jumped)
        next_inst_format_type = memory_[pc_] & 0b11;
    }

    return inst;
}
