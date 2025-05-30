#include <iostream>
#include <stdint.h>

class BittyEmulator
{
public:
	BittyEmulator();
	uint16_t 	Evaluate(uint16_t instruction);
	uint16_t 	GetRegisterValue(uint16_t reg_num);
	void 		SetRegisterValue(uint16_t reg_num, uint16_t value);
	void 		EvaluateBranchInstr();
	bool 		LoadMemoryFromFile(const std::string& filename, uint16_t start_address = 0);
	uint16_t 	Step();
private:
	std::vector<uint16_t> registers_;
	std::vector<uint16_t> memory_;
	uint16_t pc_;
	uint16_t last_alu_result_;
};