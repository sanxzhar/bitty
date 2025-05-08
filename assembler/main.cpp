#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cstdint>
#include <stdexcept>
#include <random>
#include <sstream>
#include <iomanip>
#include <algorithm>

// Instruction format constants
constexpr uint8_t R_TYPE = 0b00;
constexpr uint8_t I_TYPE = 0b01;

// ALU operation codes
enum class AluOp {
    ADD = 0b000,
    SUB = 0b001,
    AND = 0b010,
    OR  = 0b011,
    XOR = 0b100,
    SHL = 0b101,
    SHR = 0b110,
    CMP = 0b111
};

// Instruction structure
struct Instruction {
    uint8_t format;      // R-type or I-type
    uint8_t alu_op;      // ALU operation
    uint8_t rd;          // Destination register
    uint8_t rs;          // Source register (for R-type) or immediate value (for I-type)
    uint16_t imm;        // Immediate value (for I-type)
};

class Assembler {
private:
    std::map<std::string, AluOp> opcode_map;
    std::map<std::string, uint8_t> register_map;

    void initialize_maps() {
        // Initialize opcode map
        opcode_map["add"] = AluOp::ADD;
        opcode_map["sub"] = AluOp::SUB;
        opcode_map["and"] = AluOp::AND;
        opcode_map["or"]  = AluOp::OR;
        opcode_map["xor"] = AluOp::XOR;
        opcode_map["shl"] = AluOp::SHL;
        opcode_map["shr"] = AluOp::SHR;
        opcode_map["cmp"] = AluOp::CMP;
        
        opcode_map["addi"] = AluOp::ADD;
        opcode_map["subi"] = AluOp::SUB;
        opcode_map["andi"] = AluOp::AND;
        opcode_map["ori"]  = AluOp::OR;
        opcode_map["xori"] = AluOp::XOR;
        opcode_map["shli"] = AluOp::SHL;
        opcode_map["shri"] = AluOp::SHR;
        opcode_map["cmpi"] = AluOp::CMP;

        // Initialize register map
        for (int i = 0; i < 8; i++) {
            register_map["r" + std::to_string(i)] = i;
        }
    }

    uint16_t encode_r_type(const Instruction& inst) {
        return (inst.rd << 13) | (inst.rs << 10) | (inst.alu_op << 2) | R_TYPE;
    }

    uint16_t encode_i_type(const Instruction& inst) {
        int8_t imm8 = static_cast<int8_t>(inst.imm);
        return (inst.rd << 13) | ((imm8 & 0xFF) << 5) | (inst.alu_op << 2) | I_TYPE;
    }

public:
    Assembler() {
        initialize_maps();
    }

    std::vector<uint16_t> assemble(const std::string& input_file) {
        std::ifstream file(input_file);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open input file: " + input_file);
        }

        std::vector<uint16_t> machine_code;
        std::string line;

        while (std::getline(file, line)) {
            // Skip empty lines and comments
            if (line.empty() || line[0] == '#') continue;

            // Parse instruction
            Instruction inst;
            std::string opcode, rd, rs;
            std::istringstream iss(line);
            iss >> opcode >> rd >> rs;

            // Set instruction format and ALU operation
            if (opcode_map.find(opcode) == opcode_map.end()) {
                throw std::runtime_error("Unknown opcode: " + opcode);
            }
            inst.alu_op = static_cast<uint8_t>(opcode_map[opcode]);

            // Parse destination register
            if (register_map.find(rd) == register_map.end()) {
                throw std::runtime_error("Invalid register: " + rd);
            }
            inst.rd = register_map[rd];

            // Check if second operand is a register or immediate
            if (rs[0] == 'r') {
                if (register_map.find(rs) == register_map.end()) {
                    throw std::runtime_error("Invalid register: " + rs);
                }
                inst.format = R_TYPE;
                inst.rs = register_map[rs];
            } else {
                try {
                    inst.format = I_TYPE;
                    int imm = std::stoi(rs);
                    if (imm < -128 || imm > 127) {
                        throw std::runtime_error("Immediate value out of range: " + rs);
                    }
                    inst.imm = static_cast<int8_t>(imm);
                } catch (const std::exception& e) {
                    throw std::runtime_error("Invalid immediate value: " + rs);
                }
            }

            // Encode instruction
            uint16_t encoded = (inst.format == R_TYPE) ? 
                encode_r_type(inst) : encode_i_type(inst);
            machine_code.push_back(encoded);
        }

        return machine_code;
    }
};

class Disassembler {
private:
    std::map<AluOp, std::string> opcode_map_r;
    std::map<AluOp, std::string> opcode_map_i;
    std::map<uint8_t, std::string> register_map;

    void initialize_maps() {
        // Initialize opcode map
        opcode_map_r[AluOp::ADD] = "add";
        opcode_map_r[AluOp::SUB] = "sub";
        opcode_map_r[AluOp::AND] = "and";
        opcode_map_r[AluOp::OR]  = "or";
        opcode_map_r[AluOp::XOR] = "xor";
        opcode_map_r[AluOp::SHL] = "shl";
        opcode_map_r[AluOp::SHR] = "shr";
        opcode_map_r[AluOp::CMP] = "cmp";
        
        opcode_map_i[AluOp::ADD] = "addi";
        opcode_map_i[AluOp::SUB] = "subi";
        opcode_map_i[AluOp::AND] = "andi";
        opcode_map_i[AluOp::OR]  = "ori";
        opcode_map_i[AluOp::XOR] = "xori";
        opcode_map_i[AluOp::SHL] = "shli";
        opcode_map_i[AluOp::SHR] = "shri";
        opcode_map_i[AluOp::CMP] = "cmpi";

        // Initialize register map
        for (int i = 0; i < 8; i++) {
            register_map[i] = "r" + std::to_string(i);
        }
    }

public:
    Disassembler() {
        initialize_maps();
    }

    std::vector<std::string> disassemble(const std::string& input_file) {
        std::ifstream file(input_file, std::ios::binary);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open input file: " + input_file);
        }

        std::vector<std::string> assembly;
        uint16_t instruction;

        while (file.read(reinterpret_cast<char*>(&instruction), sizeof(instruction))) {
            uint8_t format = instruction & 0x3;
            uint8_t alu_op = (instruction >> 2) & 0x7;
            uint8_t rd = (instruction >> 13) & 0x7;

            std::string line;

            if (format == R_TYPE) {
                uint8_t rs = (instruction >> 10) & 0x7;
                line = opcode_map_r[static_cast<AluOp>(alu_op)] + " " + register_map[rd] + " " + register_map[rs];
            } else {
                int8_t imm8 = static_cast<int8_t>((instruction >> 5) & 0xFF);
                line = opcode_map_i[static_cast<AluOp>(alu_op)] + " " + register_map[rd] + " " + std::to_string(static_cast<int>(imm8));
            }

            assembly.push_back(line);
        }

        return assembly;
    }
};

void print_usage() {
    std::cout << "Usage: assembler_tool -i <input file> [-o <output file>] -a|-d\n"
              << "Flags:\n"
              << "  -i <input file>: Input file containing assembly or machine code\n"
              << "  -o <output file>: (Optional) Output file for the result\n"
              << "  -a: Assemble the input file\n"
              << "  -d: Disassemble the input file\n";
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        print_usage();
        return 1;
    }

    std::string input_file;
    std::string output_file;
    bool assemble = false;
    bool disassemble = false;

    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "-i" && i + 1 < argc) {
            input_file = argv[++i];
        } else if (arg == "-o" && i + 1 < argc) {
            output_file = argv[++i];
        } else if (arg == "-a") {
            assemble = true;
        } else if (arg == "-d") {
            disassemble = true;
        }
    }

    // Validate arguments
    if (input_file.empty()) {
        std::cerr << "Error: Input file is required\n";
        print_usage();
        return 1;
    }

    if (!assemble && !disassemble) {
        std::cerr << "Error: Either -a or -d flag must be specified\n";
        print_usage();
        return 1;
    }

    try {
        if (assemble) {
            Assembler assembler;
            auto machine_code = assembler.assemble(input_file);

            if (output_file.empty()) {
                // Print to console
                for (uint16_t instruction : machine_code) {
                    std::cout << std::hex << std::setw(4) << std::setfill('0') 
                              << instruction << std::endl;
                }
            } else {
                // Write to file
                std::ofstream out(output_file, std::ios::binary);
                for (uint16_t instruction : machine_code) {
                    out.write(reinterpret_cast<const char*>(&instruction), 
                             sizeof(instruction));
                }
            }
        } else {
            Disassembler disassembler;
            auto assembly = disassembler.disassemble(input_file);

            if (output_file.empty()) {
                // Print to console
                for (const auto& line : assembly) {
                    std::cout << line << std::endl;
                }
            } else {
                // Write to file
                std::ofstream out(output_file);
                for (const auto& line : assembly) {
                    out << line << std::endl;
                }
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
