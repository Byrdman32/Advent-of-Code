#include "day02.h"
#include <gtest/gtest.h>

// The fixture for testing AdventOfCode 2024, day 02, part 1, example 1.
TEST(Day02, SolvePart1_ExampleInput1) {
    Day02 day02("2024-02e1.txt");
    EXPECT_EQ(day02.SolvePart1(), "2");
}

// The fixture for testing AdventOfCode 2024, day 02, part 2, example 1.
TEST(Day02, SolvePart2_ExampleInput1) {
    Day02 day02("2024-02e1.txt");
    EXPECT_EQ(day02.SolvePart2(), "4");
}

// The fixture for testing AdventOfCode 2024, day 02, part 1, puzzle input.
TEST(Day02, SolvePart1_PuzzleInput) {
    Day02 day02("2024-02.txt");
    EXPECT_EQ(day02.SolvePart1(), "224");
}

// The fixture for testing AdventOfCode 2024, day 02, part 2, puzzle input.
TEST(Day02, SolvePart2_PuzzleInput) {
    Day02 day02("2024-02.txt");
    EXPECT_EQ(day02.SolvePart2(), "293");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
