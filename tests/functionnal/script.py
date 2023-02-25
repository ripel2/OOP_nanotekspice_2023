#!/usr/bin/env python3

import os
import sys

import subprocess


EXECUTABLE_NAME = "./nanotekspice"
TESTS_PATH = "./tests/functionnal/"
TESTS_CONFIGS_PATH = "./tests/configs/"

def get_test_files() -> list:
    """
    Return a list of all the test files in the tests/functionnal directory
    """
    files = os.listdir(TESTS_PATH)
    return [f for f in files if f.endswith(".test")]

def parse_test_file(file_name: str) -> dict:
    data = {
        "name": "",
        "description": "",
        "file": "",
        "check_for": "output",
        "stdin": "",
        "stdout": "",
        "return_code": 0
    }

    with open(TESTS_PATH + file_name, "r") as file:
        lines = file.read().splitlines()

    for i in range(len(lines)):
        if lines[i].startswith("NAME"):
            data["name"] = lines[i].split("=")[1].strip()

        if lines[i].startswith("DESCRIPTION"):
            data["description"] = lines[i].split("=")[1].strip()
        
        if lines[i].startswith("FILE"):
            data["file"] = lines[i].split("=")[1].strip()
        
        if lines[i].startswith("CHECK_FOR"):
            data["check_for"] = lines[i].split("=")[1].strip()

        if lines[i].startswith("RETURN_CODE"):
            data["return_code"] = int(lines[i].split("=")[1].strip())

        if lines[i].startswith("STDIN"):
            eof = lines[i].split("=")[1].strip()
            i += 1
            while lines[i] != eof:
                data["stdin"] += lines[i] + "\n"
                i += 1
        
        if lines[i].startswith("STDOUT"):
            eof = lines[i].split("=")[1].strip()
            i += 1
            while lines[i] != eof:
                data["stdout"] += lines[i] + "\n"
                i += 1
            
    return data


def run_test(test: dict) -> bool:
    """
    Run a test
    """
    print("Running test:\t" + test["name"])
    print("Description:\t" + test["description"])
    print("File:\t\t" + test["file"])
    print("Check for:\t" + test["check_for"] + f" ({test['return_code'] if test['check_for'] == 'return_code' else 'see test file'})")
    test_file = TESTS_CONFIGS_PATH + test["file"]
    process = subprocess.Popen([EXECUTABLE_NAME, test_file], stdout=subprocess.PIPE, stdin=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate(input=test["stdin"].encode())
    stdout = stdout.decode()
    stderr = stderr.decode()
    stdout = stdout.replace("> ", "")
    stdout = stdout.replace(">", "")

    if test["check_for"] == "output":
        if stdout != test["stdout"]:
            print("\033[31mTest failed: wrong output\033[0m")
            return False
        else:
            print("\033[32mTest passed\033[0m")
            return True
    
    if test["check_for"] == "return_code":
        if process.returncode != test["return_code"]:
            print("\033[31mTest failed: wrong return code ({} != {})\033[0m".format(
                process.returncode, test["return_code"]))
            return False
        else:
            print("\033[32mTest passed\033[0m")
            return True
    
    return False
    

if __name__ == "__main__":
    test_files = get_test_files()
    success, failed = 0, 0
    for test_file in test_files:
        test = parse_test_file(test_file)
        is_success = run_test(test)
        if is_success:
            success += 1
        else:
            failed += 1
        print("\n--------------------\n")

    print(f"Success:\t{success}/{success + failed}")
    print(f"Failed:\t\t{failed}/{success + failed}")

    if failed > 0:
        # Exit with error code 1 if at least one test failed
        sys.exit(1)
    