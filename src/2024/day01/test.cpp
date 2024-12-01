#include "day01.h"
#include <gtest/gtest.h>

// The fixture for testing AdventOfCode 2024, day 1, part 1, example 1.
TEST(Day01, SolvePart1_ExampleInput1) {
    Day01 day01_all("2024-01e1.txt");
    EXPECT_EQ(day01_all.SolvePart1(), "11");
}

// The fixture for testing AdventOfCode 2024, day 1, part 2, example 1.
TEST(Day01, SolvePart2_ExampleInput1) {
    Day01 day01_all("2024-01e1.txt");
    EXPECT_EQ(day01_all.SolvePart2(), "31");
}

// The fixture for testing AdventOfCode 2024, day 1, part 1, puzzle input.
TEST(Day01, SolvePart1_PuzzleInput) {
    Day01 day01("2024-01.txt");
    EXPECT_EQ(day01.SolvePart1(), "3714264");
}

// The fixture for testing AdventOfCode 2024, day 1, part 2, puzzle input.
TEST(Day01, SolvePart2_PuzzleInput) {
    Day01 day01("2024-01.txt");
    EXPECT_EQ(day01.SolvePart2(), "18805872");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
