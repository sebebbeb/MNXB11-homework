#include "calculateKey.h"
#include <iostream>
#include <string>

// Function to calculate key
int calculateKey(int checksum, char firstArgument, size_t programNameLength) {
    return (checksum ^ (firstArgument * 3)) << (programNameLength & 0x1f);
}