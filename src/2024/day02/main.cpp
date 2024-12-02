#include "day02.h"
#include <iostream>

int main() {
    try {
        // Create an instance of Day02 with input from a file
        Day02 day02("2024-02.txt");

        // Run and time the solutions
        day02.RunAllParts();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << "\n";
    }

    return 0;
}
