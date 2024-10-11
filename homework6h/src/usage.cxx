#include "usage.h"
#include <iostream>
#include <string>


//Usage instructions and intermediate results

void printUsageInstructions() {
    std::cout << "Usage: ./program_name <input_string> <expected_key>\n";
    std::cout << " <input_string> : String to be checked e.g. 'MNXB11'\n";
    std::cout << " <expected_key> : The expected key e.g. '23552'\n";
}

void printResults(int checksum, int calculatedKey, int expectedKey) {
    std::cout << "Calculated Checksum: " << checksum << "\n";
    std::cout << "Calculated Key: " << calculatedKey << "\n";
    std::cout << "Expected Key: " << expectedKey << "\n";
    }