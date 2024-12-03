#include "day03.h"
#include <gtest/gtest.h>

// The fixture for testing AdventOfCode 2024, day 03, part 1, example 1.
TEST(Day03, SolvePart1_ExampleInput1) {
    Day03 day03("2024-03e1.txt");
    EXPECT_EQ(day03.SolvePart1(), "161");
}

// The fixture for testing AdventOfCode 2024, day 03, part 2, example 2.
TEST(Day03, SolvePart2_ExampleInput2) {
    Day03 day03("2024-03e2.txt");
    EXPECT_EQ(day03.SolvePart2(), "48");
}

// The fixture for testing AdventOfCode 2024, day 03, part 1, puzzle input.
TEST(Day03, SolvePart1_PuzzleInput) {
    Day03 day03("2024-03.txt");
    EXPECT_EQ(day03.SolvePart1(), "178538786");
}

// The fixture for testing AdventOfCode 2024, day 03, part 2, puzzle input.
TEST(Day03, SolvePart2_PuzzleInput) {
    Day03 day03("2024-03.txt");
    EXPECT_EQ(day03.SolvePart2(), "102467299");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
