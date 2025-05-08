Command to build CLI tool:
g++ -std=c++17 -O2 -o assembler_tool main.cpp

Command to convert .asm file to .bin file
./assembler_tool -a -i test.asm -o test.bin 

Command to convert .bin file to .asm file
./assembler_tool -d -i test.bin -o test_dis.asm