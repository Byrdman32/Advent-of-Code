#include "day03.h"
#include <iostream>

int main() {
    try {
        // Create an instance of Day03 with input from a file
        Day03 day03("2024-03.txt");

        // Run and time the solutions
        day03.RunAllParts();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << "\n";
    }

    return 0;
}
