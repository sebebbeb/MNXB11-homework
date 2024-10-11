#include "checksum.h"
#include <iostream>
#include <string>

// Function computing the checksum, i.e. the sum of ASCII values of characters
int computeCheckSum(const std::string& inputString) {
    int checksum = 0;

    // Range-based for-loop iterating over each character in the input string
    for (char character : inputString) {
        checksum += static_cast<int>(character);
    }
    return checksum;
}