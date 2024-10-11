#include <iostream>
#include <string>

int main(int argumentCount, char *arguments[]) {
    // Checks if the number of arguments is 3
    bool isCorrectArgumentCount = (argumentCount == 3);

    if (isCorrectArgumentCount) {
        // Descriptive names
        std::string programName{arguments[0]};
        char firstArgument{*(arguments[1])};
        size_t programNameLength{programName.size()};
        int expectedResult{std::atoi(arguments[2])};

        int asciiSum{0};
        int currentIndex{0};

        std::string inputString{arguments[1]};

        while (true) {
        asciiSum += inputString[currentIndex++];
        if (currentIndex >= static_cast<int>(inputString.size())) {
            break;
        }
        }
        if ((asciiSum ^ firstArgument * 3) << (programNameLength & 0x1f) == expectedResult) {
        std::cout << "Correct!" << std::endl;
        } else {
        std::cout << "Wrong!" << std::endl;
        }
    }
}