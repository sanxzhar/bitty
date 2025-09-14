# Bitty – 16-bit Microprocessor

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)  
[![Verilog](https://img.shields.io/badge/HDL-Verilog-blue)]()  
[![C++](https://img.shields.io/badge/Testing-C++-orange)]()  
[![Python](https://img.shields.io/badge/Scripts-Python-yellow)]()  

🚀 **Bitty** is a custom **16-bit Turing-complete microprocessor**, built from scratch with a **32-instruction ISA**.  
It supports flexible programmability, UART-based I/O, and modular hardware design — verified through C++ testbenches and automated Python scripts.  


## ✨ Features  

- 🖥 **Custom 16-bit ISA** – 32 instructions covering arithmetic, logic, branching, and memory.  
- ⚙️ **Modular Microarchitecture** – PC, Instruction Fetch, Branch Logic, Control Unit, UART, ALU, and Registers.  
- 📡 **UART Module** – for external communication and program loading.  
- ✅ **Verified CPU** – 92% instruction coverage achieved with C++ testbenches and Verilog simulations.  
- 🛠 **Cross-Language Tooling** – Verilog for RTL design, C++ for simulation, Python for automation.  


## 🖼 Microarchitecture Overview  

![Architecture Diagram](https://github.com/user-attachments/assets/4f61ccc8-66e8-4205-ac3e-0d8a24bb61ef)

*Main components: PC, Fetch Instruction Unit, Branch Logic, UART, and the Bitty Core.*  


## 🔧 Project Structure  
```
bitty/
│── rtl/ # Verilog source files (CPU core, modules)
│── test/ # Simulation testbenches (C++ / Verilog)
│── bitty_run.py/ # Python automation scripts
└── README.md # Project documentation
```


## 📜 Instruction Set Architecture (ISA)  

- **R-Type**: Arithmetic & logic operations (`ADD`, `SUB`, `AND`, `OR`, `XOR`, etc.)  
- **I-Type**: Immediate-based instructions (`ADDI`, `LOADI`, etc.)  
- **M-Type**: Memory and I/O instructions (`LOAD`, `STORE`, `IN`, `OUT`)  
- **Branching**: Conditional and unconditional jumps (`BEQ`, `BNE`, `JMP`)  


## 🧪 Verification  

- Developed **C++ testbenches** to simulate instruction execution.  
- Automated testing pipeline with **Python scripts** for waveform analysis and regression tests.  
- Achieved **92% instruction coverage** across all ISA operations.  


## 🚀 Getting Started  

### Prerequisites  
- Verilog simulator (e.g., Icarus Verilog, ModelSim, or Verilator)  
- C++ compiler (GCC/Clang)  
- Python 3.x  

### 📚 Example Program

Here’s an example program that adds two numbers and stores the result:

```verilog
LOADI R1, 5      ; Load 5 into R1
LOADI R2, 3      ; Load 3 into R2
ADD   R3, R1, R2 ; R3 = R1 + R2
OUT   R3         ; Output result (8)
```
