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

        // Moved oout of condition check for readability
        int calculatedKey = calculateKey(checksum, firstArgument, programNameLength);

        // Condition check
        if (calculatedKey == expectedResult) {
            std::cout << "Correct!" << std::endl;
        } else {
        std::cout << "Wrong!" << std::endl;
        }
    }
}