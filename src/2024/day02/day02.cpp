#include "day02.h"
#include <numeric>
#include <algorithm>
#include <cmath>

// Constructor using file input
Day02::Day02(const std::string& inputFilePath) : Day(inputFilePath) {}

// Constructor using direct input
Day02::Day02(const std::vector<std::string>& inputData) : Day(inputData) {}

// Initialize resources specific to Day02
void Day02::Initialize() {
    // No specific resources to initialize
}

// Day 02 specific methods - ValidateLevels
bool Day02::ValidateLevels(const std::vector<long long>& levels) {
    // A single element or empty vector trivially satisfies both conditions
    if (levels.size() < 2) {
        return true;
    }

    // Determine the direction of the levels (increasing or decreasing)
    bool isIncreasing = levels[1] > levels[0];

    // Check if the levels are valid
    for (size_t i = 1; i < levels.size(); ++i) {
        int diff = levels[i] - levels[i - 1];

        // Check if the difference is within the range [1, 3]
        if (std::abs(diff) < 1 || std::abs(diff) > 3) {
            return false;
        }

        // Check if the direction remains consistent (all increasing or all decreasing)
        if ((isIncreasing && diff <= 0) || (!isIncreasing && diff >= 0)) {
            return false;
        }
    }

    // All conditions are satisfied
    return true;
}

// Day 02 specific methods - ValidateLevels with removal of a single levels
bool Day02::ValidateLevelsWithRemoval(const std::vector<long long>& levels) {
    // Check if the levels are by default valid
    if (ValidateLevels(levels)) {
        return true;
    }

    // Try removing each level one by one and check if the remaining sequence is valid
    for (size_t i = 0; i < levels.size(); ++i) {
        std::vector<long long> modifiedLevels = levels;
        modifiedLevels.erase(modifiedLevels.begin() + i);

        // Check if the modified levels are valid
        if (ValidateLevels(modifiedLevels)) {
            return true;
        }
    }

    // No valid sequence found
    return false;
}

// Solve Part 1
std::string Day02::SolvePart1() {
    // Initialize the result
    long long result = 0;

    // Iterate over each line of input
    for (size_t i = 0; i < Input.size(); i++) {
        // Split the input line into words
        std::vector<std::string> words = SplitString(Input[i]);

        // Convert the words to levels
        std::vector<long long> levels;
        for (size_t j = 0; j < words.size(); j++) {
            levels.push_back(std::stoll(words[j]));
        }

        // Check if the levels are valid
        if (ValidateLevels(levels)) {
            result++;
        }
    }

    // Return the result as a string
    return std::to_string(result);
}

// Solve Part 2
std::string Day02::SolvePart2() {
    // Initialize the result
    long long result = 0;

    // Iterate over each line of input
    for (size_t i = 0; i < Input.size(); i++) {
        // Split the input line into words
        std::vector<std::string> words = SplitString(Input[i]);

        // Convert the words to levels
        std::vector<long long> levels;
        for (size_t j = 0; j < words.size(); j++) {
            levels.push_back(std::stoll(words[j]));
        }

        // Check if the levels are valid with the option to remove a single level
        if (ValidateLevelsWithRemoval(levels)) {
            result++;
        }
    }

    // Return the result as a string
    return std::to_string(result);
}
