#include "day##.h"
#include <iostream>

int main() {
    try {
        // Create an instance of Day## with input from a file
        Day## day##("&&&&-##.txt");

        // Run and time the solutions
        day##.RunAllParts();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << "\n";
    }

    return 0;
}
