#include "day01.h"
#include <iostream>

int main() {
    try {
        // Create an instance of Day01 with input from a file
        Day01 day01("2024-01.txt");

        // Run and time the solutions
        day01.RunAllParts();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << "\n";
    }

    return 0;
}
