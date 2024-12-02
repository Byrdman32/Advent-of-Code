#include "day##.h"
#include <gtest/gtest.h>

// The fixture for testing AdventOfCode &&&&, day ##, part 1, example 1.
TEST(Day##, SolvePart1_ExampleInput1) {
    Day## day##("&&&&-##e1.txt");
    EXPECT_EQ(day##.SolvePart1(), "<Answer>");
}

// The fixture for testing AdventOfCode &&&&, day ##, part 2, example 1.
TEST(Day##, SolvePart2_ExampleInput1) {
    Day## day##("&&&&-##e1.txt");
    EXPECT_EQ(day##.SolvePart2(), "<Answer>");
}

// The fixture for testing AdventOfCode &&&&, day ##, part 1, puzzle input.
TEST(Day##, SolvePart1_PuzzleInput) {
    Day## day##("&&&&-##.txt");
    EXPECT_EQ(day##.SolvePart1(), "<Answer>");
}

// The fixture for testing AdventOfCode &&&&, day ##, part 2, puzzle input.
TEST(Day##, SolvePart2_PuzzleInput) {
    Day## day##("&&&&-##.txt");
    EXPECT_EQ(day##.SolvePart2(), "<Answer>");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
