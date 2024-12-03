#include "day03.h"
#include <numeric>
#include <algorithm>
#include <regex>

// Constructor using file input
Day03::Day03(const std::string& inputFilePath) : Day(inputFilePath) {}

// Constructor using direct input
Day03::Day03(const std::vector<std::string>& inputData) : Day(inputData) {}

// Initialize resources specific to Day03
void Day03::Initialize() {
    // No specific resources to initialize
}

// Solve Part 1
std::string Day03::SolvePart1() {
    // Initialize the result
    long long result = 0;

    // Regular expression to match valid instructions
    std::regex pattern(R"(mul\((\d+),(\d+)\))");

    // Iterate over each line of input
    for (size_t i = 0; i < Input.size(); i++) {
        // Vector to store the matches
        std::vector<std::string> matches;

        // Iterators to search through the string for matches
        std::sregex_iterator words_begin = std::sregex_iterator(Input[i].begin(), Input[i].end(), pattern);
        std::sregex_iterator words_end = std::sregex_iterator();

        // Store the matches in the vector
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            matches.push_back(match.str());
        }

        // Iterate over the matches and calculate the result
        for (size_t j = 0; j < matches.size(); j++) {
            // Regular expression to match the mul(X,Y) instruction
            std::regex mul_regex(R"(mul\((\d+),(\d+)\))");
            std::smatch match;

            // If the match is found, extract the values and calculate the result
            if (std::regex_match(matches[j], match, mul_regex)) {
                int x = std::stoi(match[1].str());
                int y = std::stoi(match[2].str());

                result += x * y;
            }
        }
    }

    // Return the result as a string
    return std::to_string(result);
}

// Solve Part 2
std::string Day03::SolvePart2() {
    // Initialize the result
    long long result = 0;

    // Regular expression to match valid instructions
    std::regex pattern(R"(mul\(\d+,\d+\)|do\(\)|don't\(\))");

    // Flag to determine if the "do" instruction is active
    bool do_flag = true;

    // Iterate over each line of input
    for (size_t i = 0; i < Input.size(); i++) {
        // Vector to store the matches
        std::vector<std::string> matches;

        // Iterators to search through the string for matches
        std::sregex_iterator words_begin = std::sregex_iterator(Input[i].begin(), Input[i].end(), pattern);
        std::sregex_iterator words_end = std::sregex_iterator();

        // Store the matches in the vector
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            matches.push_back(match.str());
        }

        // Iterate over the matches and calculate the result
        for (size_t j = 0; j < matches.size(); j++) {
            // If the "do" instruction is found, set the flag to true
            if (matches[j] == "do()") {
                do_flag = true;
            }
            // If the "don't" instruction is found, set the flag to false
            else if (matches[j] == "don't()") {
                do_flag = false;
            }
            // If the do flag is set, check for the mul instruction
            else if (do_flag) {
                // Regular expression to match the mul(X,Y) instruction
                std::regex mul_regex(R"(mul\((\d+),(\d+)\))");
                std::smatch match;

                // If the match is found, extract the values and calculate the result
                if (std::regex_match(matches[j], match, mul_regex)) {
                    int x = std::stoi(match[1].str());
                    int y = std::stoi(match[2].str());

                    result += x * y;
                }
            }
        }
    }

    // Return the result as a string
    return std::to_string(result);
}
