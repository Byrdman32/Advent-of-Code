#include "day04.h"
#include <iostream>

int main() {
    try {
        // Create an instance of Day04 with input from a file
        Day04 day04("2024-04.txt");

        // Run and time the solutions
        day04.RunAllParts();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << "\n";
    }

    return 0;
}
