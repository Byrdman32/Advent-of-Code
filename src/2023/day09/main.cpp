#include "day09.h"
#include <iostream>

int main() {
    try {
        // Create an instance of Day09 with input from a file
        Day09 day09("2023-09.txt");

        // Run and time the solutions
        day09.RunAllParts();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << "\n";
    }

    return 0;
}
