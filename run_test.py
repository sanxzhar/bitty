# Copyright (c) 2025 texer.ai, Maveric @ NU.
# All rights reserved.

import argparse
import os
import shutil
import sys

def run_all_tests(should_gen_wave=False):
    for i in range(1, 201):
        run_bitty(i, should_gen_wave)

def copy_test_file(test_number):
    """Copy the test file to program.txt"""
    test_file = f"testing_tools/generator/test/program_{test_number}.txt"
    target_file = "testing_tools/generator/program.txt"
    
    if not os.path.exists(test_file):
        print(f"Error: Test file {test_file} does not exist")
        sys.exit(1)
        
    shutil.copy2(test_file, target_file)
    print(f"Copied {test_file} to {target_file}")

def run_bitty(test_number, should_gen_wave=False):
    """Run the test using bitty_run.py"""
    # First copy the test file
    copy_test_file(test_number)
    
    # Clean previous simulation
    print("Cleaning previous simulation...")
    os.system("python3 bitty_run.py -c")
    
    # Build the command
    cmd = ["python3", "bitty_run.py", "-s", "top"]
    if should_gen_wave:
        cmd.append("-w")
    
    # Run the command
    print(f"Running test {test_number}...")
    os.system(" ".join(cmd))
    
    # Run the Verilator-generated executable
    print("Running Verilator simulation...")
    os.system("./obj_dir/Vtop")

def main():
    parser = argparse.ArgumentParser(description="Run Bitty tests from the generator/test directory")
    parser.add_argument("test_number", type=int, nargs="?", help="Test number to run (e.g., 1 for program_1.txt)")
    parser.add_argument("-w", "--waveform", action="store_true", help="Generate waveform")
    parser.add_argument("-a", "--all", action="store_true", help="Run all tests from the test directory")
    
    args = parser.parse_args()

    if args.all:
        run_all_tests(args.waveform)
    else:
        run_bitty(args.test_number, args.waveform)
    
if __name__ == "__main__":
    main() 