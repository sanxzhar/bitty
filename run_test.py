# Copyright (c) 2025 texer.ai, Maveric @ NU.
# All rights reserved.

import argparse
import os
import shutil
import sys
import subprocess
import signal
from datetime import datetime

class TestResult:
    def __init__(self, test_number, status, message=""):
        self.test_number = test_number
        self.status = status  # "PASS", "FAIL", "TIMEOUT", "COMPILE_ERROR"
        self.message = message
        self.timestamp = datetime.now()

def run_all_tests(should_gen_wave=False):
    results = []
    for i in range(1, 201):
        result = run_bitty(i, should_gen_wave)
        results.append(result)
        
        if result.status != "PASS":
            return results
            
    return results

def copy_test_file(test_number):
    """Copy the test file to program.txt"""
    test_file = f"testing_tools/generator/test/program_{test_number}.txt"
    target_file = "testing_tools/generator/program.txt"
    
    if not os.path.exists(test_file):
        return TestResult(test_number, "FAIL", f"Test file {test_file} does not exist")
        
    shutil.copy2(test_file, target_file)
    return TestResult(test_number, "PASS")

def run_with_timeout(cmd, timeout=20):
    """Run a command with timeout"""
    try:
        process = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout, stderr = process.communicate(timeout=timeout)
        return process.returncode, stdout.decode(), stderr.decode()
    except subprocess.TimeoutExpired:
        process.kill()
        return -1, "", f"Timeout after {timeout} seconds"

def run_bitty(test_number, should_gen_wave=False):
    """Run the test using bitty_run.py"""
    # First copy the test file
    copy_result = copy_test_file(test_number)
    if copy_result.status != "PASS":
        return copy_result
    
    # Clean previous simulation
    print(f"\nRunning test {test_number}...")
    print("Cleaning previous simulation...")
    clean_cmd = "python3 bitty_run.py -c"
    returncode, stdout, stderr = run_with_timeout(clean_cmd, 100)
    if returncode != 0:
        return TestResult(test_number, "COMPILE_ERROR", f"Clean failed: {stderr}")

    # Build and run the simulation
    print("Building Verilator simulation...")
    cmd = ["python3", "bitty_run.py", "-s", "top"]
    if should_gen_wave:
        cmd.append("-w")
    
    cmd_str = " ".join(cmd)
    returncode, stdout, stderr = run_with_timeout(cmd_str, 100)
    
    if returncode != 0:
        return TestResult(test_number, "COMPILE_ERROR", f"Compilation failed: {stderr}")
    
    # Run the Verilator simulation
    print("Running Verilator simulation...")
    returncode, stdout, stderr = run_with_timeout("./obj_dir/Vtop")
    
    if returncode == -1:
        return TestResult(test_number, "TIMEOUT", "Timeout after 20 seconds")
    elif returncode != 0:
        # Combine both stdout and stderr for the error message
        error_msg = (stdout + stderr).strip()
        if "Verification FAILED" in error_msg:
            return TestResult(test_number, "FAIL", error_msg)
        return TestResult(test_number, "FAIL", f"Simulation failed: {error_msg}")
    
    return TestResult(test_number, "PASS")

def main():
    parser = argparse.ArgumentParser(description="Run Bitty tests from the generator/test directory")
    parser.add_argument("test_number", type=int, nargs="?", help="Test number to run (e.g., 1 for program_1.txt)")
    parser.add_argument("-w", "--waveform", action="store_true", help="Generate waveform")
    parser.add_argument("-a", "--all", action="store_true", help="Run all tests from the test directory")
    
    args = parser.parse_args()

    if args.all:
        results = run_all_tests(args.waveform)
        passed_tests = sum(1 for r in results if r.status == "PASS")
        if passed_tests == len(results):
            print(f"\nAll tests passed: {passed_tests}/{len(results)}")
        else:
            failed_test = next(r for r in results if r.status != "PASS")
            print(f"\nFailed test {failed_test.test_number}: {failed_test.status}")
            print(failed_test.message)
    else:
        result = run_bitty(args.test_number, args.waveform)
        print(f"\nTest {args.test_number}: {result.status}")
        if result.status != "PASS":
            print(result.message)
    
if __name__ == "__main__":
    main() 