#include "day04.h"
#include <numeric>
#include <algorithm>

// Constructor using file input
Day04::Day04(const std::string& inputFilePath) : Day(inputFilePath) {}

// Constructor using direct input
Day04::Day04(const std::vector<std::string>& inputData) : Day(inputData) {}

// Initialize resources specific to Day04
void Day04::Initialize() {
    // No specific resources to initialize
}

// Day 04 specific methods - CheckDirection to check if a segment in a direction is equal to a checksum
bool Day04::CheckDirection(std::vector<std::string> grid, long long x, long long y, int xStep, int yStep, std::string checksum)
{
    // Initialize a string to store the segment
    std::string segment = "";

    // Get the dimensions of the grid
    long long dimensionsOfGridX = grid[0].length();
    long long dimensionsOfGridY = grid.size();

    // Loop through the positions of the checksum to generate the segment
    for (std::string::size_type c = 0; c < checksum.length(); c++) {
        // Check if the next position is out of bounds and if so, return false
        if ((x + c*xStep >= static_cast<unsigned long long>(dimensionsOfGridX)) || (y + c*yStep >= static_cast<unsigned long long>(dimensionsOfGridY))) {
            return false;
        }

        // Add the character at the next position to the segment
        segment += grid[x+c*xStep][y+c*yStep];
    }

    // Check if the segment is equal to the checksum
    if (segment == checksum) {
        return true;
    }

    // Return false if the segment is not equal to the checksum
    return false;
}

// Solve Part 1
std::string Day04::SolvePart1() {
    // Initialize the result
    long long result = 0;

    // Get the dimensions of the grid
    long long dimensionsOfGridX = Input[0].length();
    long long dimensionsOfGridY = Input.size();

    // Initialize the checksum
    std::string checksum = "XMAS";

    // Loop through the xGrid 
    for (int xPos = 0; xPos < dimensionsOfGridX; xPos++) {
        // Loop through the yGrid
        for (int yPos = 0; yPos < dimensionsOfGridY; yPos++) {
            // Loop through the xStep
            for (int xStep = -1; xStep <= 1; xStep++) {
                // Loop through the yStep
                for (int yStep = -1; yStep <= 1; yStep++) {
                    // Check if the current position is part of a 'XMAS' segment in any direction if so, increment the result
                    if (CheckDirection(Input, xPos, yPos, xStep, yStep, checksum)) {
                        result++;
                    }
                }
            }
        }
    }

    // Return the result as a string
    return std::to_string(result);
}

// Solve Part 2
std::string Day04::SolvePart2() {
    // Initialize the result
    long long result = 0;

    // Get the dimensions of the grid
    long long dimensionsOfGridX = Input[0].length();
    long long dimensionsOfGridY = Input.size();

    // Initialize the checksum
    std::string checksum = "MAS";

    // Loop through the xGrid subtracting 1 from the size to avoid out of bounds
    for (int xPos = 1; xPos < dimensionsOfGridX - 1; xPos++) {
        // Loop through the yGrid subtracting 1 from the size to avoid out of bounds
        for (int yPos = 1; yPos < dimensionsOfGridY - 1; yPos++) {
            // Create 4 options for the direction of the segment
            bool mas1 = CheckDirection(Input, xPos + 1, yPos + 1, -1, -1, checksum);  // top left to bottom right
            bool mas2 = CheckDirection(Input, xPos - 1, yPos - 1,  1,  1, checksum);  // bottom right to top left
            bool mas3 = CheckDirection(Input, xPos - 1, yPos + 1,  1, -1, checksum);  // top right to bottom left
            bool mas4 = CheckDirection(Input, xPos + 1, yPos - 1, -1,  1, checksum);  // bottom left to top right

            // Check if the current position is part of a 'MAS' segment in any direction if so, increment the result
            if ((mas1 || mas2) && (mas3 || mas4)) {
                result++;
            }
        }
    }

    // Return the result as a string
    return std::to_string(result);
}
