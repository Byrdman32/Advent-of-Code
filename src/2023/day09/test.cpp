#include "day09.h"
#include <gtest/gtest.h>

// The fixture for testing AdventOfCode 2023, day 09, part 1, example 1.
TEST(Day09, SolvePart1_ExampleInput1) {
    Day09 day09("2023-09e1.txt");
    EXPECT_EQ(day09.SolvePart1(), "114");
}

// The fixture for testing AdventOfCode 2023, day 09, part 2, example 1.
TEST(Day09, SolvePart2_ExampleInput1) {
    Day09 day09("2023-09e1.txt");
    EXPECT_EQ(day09.SolvePart2(), "2");
}

// The fixture for testing AdventOfCode 2023, day 09, part 2, example 2.
TEST(Day09, SolvePart2_ExampleInput2) {
    Day09 day09("2023-09e2.txt");
    EXPECT_EQ(day09.SolvePart2(), "5");
}

// The fixture for testing AdventOfCode 2023, day 09, part 1, puzzle input.
TEST(Day09, SolvePart1_PuzzleInput) {
    Day09 day09("2023-09.txt");
    EXPECT_EQ(day09.SolvePart1(), "1641934234");
}

// The fixture for testing AdventOfCode 2023, day 09, part 2, puzzle input.
TEST(Day09, SolvePart2_PuzzleInput) {
    Day09 day09("2023-09.txt");
    EXPECT_EQ(day09.SolvePart2(), "975");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
