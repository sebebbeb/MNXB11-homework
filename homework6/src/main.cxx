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

// Function to calculate key
int calculateKey(int checksum, char firstArgument, size_t programNameLength) {
    return (checksum ^ (firstArgument * 3)) << (programNameLength & 0x1f);
}

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