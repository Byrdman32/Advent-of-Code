#include "day04.h"
#include <gtest/gtest.h>

// The fixture for testing AdventOfCode 2024, day 04, part 1, example 1.
TEST(Day04, SolvePart1_ExampleInput1) {
    Day04 day04("2024-04e1.txt");
    EXPECT_EQ(day04.SolvePart1(), "18");
}

// The fixture for testing AdventOfCode 2024, day 04, part 2, example 1.
TEST(Day04, SolvePart2_ExampleInput1) {
    Day04 day04("2024-04e1.txt");
    EXPECT_EQ(day04.SolvePart2(), "9");
}

// The fixture for testing AdventOfCode 2024, day 04, part 1, puzzle input.
TEST(Day04, SolvePart1_PuzzleInput) {
    Day04 day04("2024-04.txt");
    EXPECT_EQ(day04.SolvePart1(), "2521");
}

// The fixture for testing AdventOfCode 2024, day 04, part 2, puzzle input.
TEST(Day04, SolvePart2_PuzzleInput) {
    Day04 day04("2024-04.txt");
    EXPECT_EQ(day04.SolvePart2(), "1912");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
