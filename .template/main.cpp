#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>
#include <string>

#include "../day.h"
// #include "day01/day01.h"
// #include "day02/day02.h"
// #include "day03/day03.h"
// #include "day04/day04.h"
// #include "day05/day05.h"
// #include "day06/day06.h"
// #include "day07/day07.h"
// #include "day08/day08.h"
// #include "day09/day09.h"
// #include "day10/day10.h"
// #include "day11/day11.h"
// #include "day12/day12.h"
// #include "day13/day13.h"
// #include "day14/day14.h"
// #include "day15/day15.h"
// #include "day16/day16.h"
// #include "day17/day17.h"
// #include "day18/day18.h"
// #include "day19/day19.h"
// #include "day20/day20.h"
// #include "day21/day21.h"
// #include "day22/day22.h"
// #include "day23/day23.h"
// #include "day24/day24.h"
// #include "day25/day25.h"

// Factory function to create Day instances
std::unique_ptr<Day> CreateDay(int day, const std::string& inputFilePath) {
    switch (day) {
        // case 1: return std::make_unique<Day01>(inputFilePath);
        // case 2: return std::make_unique<Day02>(inputFilePath);
        // case 3: return std::make_unique<Day03>(inputFilePath);
        // case 4: return std::make_unique<Day04>(inputFilePath);
        // case 5: return std::make_unique<Day05>(inputFilePath);
        // case 6: return std::make_unique<Day06>(inputFilePath);
        // case 7: return std::make_unique<Day07>(inputFilePath);
        // case 8: return std::make_unique<Day08>(inputFilePath);
        // case 9: return std::make_unique<Day09>(inputFilePath);
        // case 10: return std::make_unique<Day10>(inputFilePath);
        // case 11: return std::make_unique<Day11>(inputFilePath);
        // case 12: return std::make_unique<Day12>(inputFilePath);
        // case 13: return std::make_unique<Day13>(inputFilePath);
        // case 14: return std::make_unique<Day14>(inputFilePath);
        // case 15: return std::make_unique<Day15>(inputFilePath);
        // case 16: return std::make_unique<Day16>(inputFilePath);
        // case 17: return std::make_unique<Day17>(inputFilePath);
        // case 18: return std::make_unique<Day18>(inputFilePath);
        // case 19: return std::make_unique<Day19>(inputFilePath);
        // case 20: return std::make_unique<Day20>(inputFilePath);
        // case 21: return std::make_unique<Day21>(inputFilePath);
        // case 22: return std::make_unique<Day22>(inputFilePath);
        // case 23: return std::make_unique<Day23>(inputFilePath);
        // case 24: return std::make_unique<Day24>(inputFilePath);
        // case 25: return std::make_unique<Day25>(inputFilePath);

        // Add additional days here
        default:
            throw std::invalid_argument("Invalid day: " + std::to_string(day));
    }
}

void RunDay(int day, const std::string& inputPath) {
    try {
        auto dayInstance = CreateDay(day, inputPath);
        std::cout << "=== Running Day " << day << " ===" << std::endl;
        dayInstance->RunAllParts();
    } catch (const std::exception& e) {
        std::cerr << "Error running Day " << day << ": " << e.what() << std::endl;
    }
}

int main() {
    // List of days to run
    std::vector<int> daysToRun = {};

    for (int day : daysToRun) {
        std::string inputFilePath = "day" + std::string(day < 10 ? "0" : "") + std::to_string(day) + ".txt";
        RunDay(day, inputFilePath);
    }

    return 0;
}
