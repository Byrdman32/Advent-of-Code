#include "day01.h"
#include <numeric>
#include <algorithm>

// Constructor using file input
Day01::Day01(const std::string& inputFilePath) : Day(inputFilePath) {}

// Constructor using direct input
Day01::Day01(const std::vector<std::string>& inputData) : Day(inputData) {}

// Initialize resources specific to Day01
void Day01::Initialize() {
    // No specific resources to initialize
}

// Solve Part 1
std::string Day01::SolvePart1() {
    // Initialize vectors and sum
    std::vector<long> left;
    std::vector<long> right;
    long long sum = 0;

    // Split the input into two vectors of longs
    for (size_t i = 0; i < Input.size(); i++) {
        left.push_back(std::stol(Input[i].substr(0, Input[i].find(" "))));
        right.push_back(std::stol(Input[i].substr(Input[i].find(" ") + 3)));
    }

    // Sort both vectors
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    // Loop through both vectors and add the absolute difference of each element
    for (size_t i = 0; i < left.size(); i++) {
        if (left[i] > right[i]) {
            sum += left[i] - right[i];
        } else {
            sum += right[i] - left[i];
        }
    }

    // Return the sum as a string
    return std::to_string(sum);
}

// Solve Part 2
std::string Day01::SolvePart2() {
    // Initialize vectors and sum
    std::vector<long> left;
    std::vector<long> right;
    long long sum = 0;

    // Split the input into two vectors of longs
    for (size_t i = 0; i < Input.size(); i++) {
        left.push_back(std::stol(Input[i].substr(0, Input[i].find(" "))));
        right.push_back(std::stol(Input[i].substr(Input[i].find(" ") + 3)));
    }

    // Sort both vectors
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    // Loop through left vector and multiply by the number of occurences in right vector
    for (size_t i = 0; i < left.size(); i++) {
        sum += left[i] * std::count(right.begin(), right.end(), left[i]);
    }

    // Return the sum as a string
    return std::to_string(sum);
}
