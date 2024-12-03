#include "day09.h"
#include <numeric>
#include <algorithm>
#include <cmath>

// Constructor using file input
Day09::Day09(const std::string& inputFilePath) : Day(inputFilePath) {}

// Constructor using direct input
Day09::Day09(const std::vector<std::string>& inputData) : Day(inputData) {}

// Initialize resources specific to Day09
void Day09::Initialize() {
    // No specific resources to initialize
}

// Day 09 specific methods - CreateDifferenceVector
std::vector<long long> Day09::CreateDifferenceVector(const std::vector<long long>& history) {
    std::vector<long long> differences;
    for (size_t i = 1; i < history.size(); i++) {
        differences.push_back(history[i] - history[i - 1]);
    }
    return differences;
}

// Solve Part 1
std::string Day09::SolvePart1() {
    // Initialize the result
    long long result = 0;

    // Iterate over each line of input
    for (size_t i = 0; i < Input.size(); i++) {
        // Split the input line into words
        std::vector<std::string> words = SplitString(Input[i]);

        // Convert the words to history values
        std::vector<long long> history;
        for (size_t j = 0; j < words.size(); j++) {
            history.push_back(std::stoll(words[j]));
        }

        // Initialize variables for finding expanded difference history
        bool found = false;
        std::vector<long long> differences = history;
        std::vector<std::vector<long long>> differenceHistory;

        // Create a vector of differences
        while (!found) {
            // Find the differences
            std::vector<long long> tempDifferences = CreateDifferenceVector(differences);

            // Check if the differences are all the all zero
            if (std::all_of(tempDifferences.begin(), tempDifferences.end(), [](long long i) { return i == 0; })) {
                found = true;
            } else {
                differences = tempDifferences;
            }

            // Add the differences to the history
            differenceHistory.push_back(tempDifferences);
        }

        // Find the last number in the history and all the difference history
        long long lastNumber = history[history.size() - 1];
        long long sum = 0;
        for (size_t j = 0; j < differenceHistory.size(); j++) {
            sum += differenceHistory[j][differenceHistory[j].size() - 1];
        }

        // Compute the previous number in the history sequence
        result += lastNumber + sum;
    }

    // Return the result as a string
    return std::to_string(result);
}

// Solve Part 2
std::string Day09::SolvePart2() {
    // Initialize the result
    long long result = 0;

    // Iterate over each line of input
    for (size_t i = 0; i < Input.size(); i++) {
        // Split the input line into words
        std::vector<std::string> words = SplitString(Input[i]);

        // Convert the words to history values
        std::vector<long long> history;
        for (size_t j = 0; j < words.size(); j++) {
            history.push_back(std::stoll(words[j]));
        }

        // Initialize variables for finding expanded difference history
        bool found = false;
        std::vector<long long> differences = history;
        std::vector<std::vector<long long>> differenceHistory;

        // Create a vector of differences
        while (!found) {
            // Find the differences
            std::vector<long long> tempDifferences = CreateDifferenceVector(differences);

            // Check if the differences are all zeros, if not find next teir
            if (std::all_of(tempDifferences.begin(), tempDifferences.end(), [](long long i) { return i == 0; })) {
                found = true;
            } else {
                differences = tempDifferences;
            }

            // Add the differences to the history
            differenceHistory.push_back(tempDifferences);
        }
        
        // Find the first number in the history and all the difference history and find the previous number
        long long firstNumber = history[0];
        long long sum = 0;

        // Iterate over the difference history in reverse order
        std::vector<std::vector<long long>> reversedDiffHistory = differenceHistory;
        std::reverse(reversedDiffHistory.begin(), reversedDiffHistory.end());

        // Iterate over the reversed difference history
        for (size_t j = 1; j < reversedDiffHistory.size(); j++) {
            sum = reversedDiffHistory[j][0] - sum;
        }

        // Compute the previous number in the history sequence
        result += firstNumber - sum;
    }

    // Return the result as a string
    return std::to_string(result);
}
