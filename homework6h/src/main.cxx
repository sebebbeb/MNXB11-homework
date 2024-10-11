#include "checksum.h"
#include "calculateKey.h"
#include "usage.h"
#include <iostream>
#include <string>

int main(int argumentCount, char *arguments[]) {

    // Checks if the number of arguments is 3
    bool isCorrectArgumentCount = (argumentCount == 3);

    if (isCorrectArgumentCount) {

        // Descriptive names
        std::string programName{arguments[0]};
        char firstArgument{(*arguments[1])};
        size_t programNameLength{programName.size()};
        int expectedResult{std::atoi(arguments[2])};

        // Compute the checksum
        std::string inputString{arguments[1]};
        int checksum = computeCheckSum(inputString);

        int calculatedKey = calculateKey(checksum, firstArgument, programNameLength);

        // Printing intermediate results
        printResults(checksum, calculatedKey, expectedResult);


        // Condition check
        if (calculatedKey == expectedResult) {
            std::cout << "Correct!" << std::endl;
        } else {
        std::cout << "Wrong!" << std::endl;
        }

    // Prints usage instructions if the number of arguments =/ 3
    } else {
            std::cout << "Error: Invalid number of arguments.\n";
            std::cout << "This program calculates a value by summing the ASCII values of characters from a given input string\n"
                         "and compares the result to an expected value to determine if the input is correct.\n"
                         "\n";
                         
            printUsageInstructions();
            return 1; 
        }
    return 0;
}