#include </opt/homebrew/Cellar/googletest/1.14.0/include/gtest/gtest.h>

#include <sstream>
#include "PCCounter.cpp" // Include the implementation

TEST(PCCounterTest, CorrectlyCountsPCOccurrences) {
    std::istringstream input("0x1A2\n0x1A2\n0x3B4");
    std::ostringstream output;
    countPCOccurrences(input, output);

    std::string expected =
        "Program Counter: 0x1A2, Count: 2\n"
        "Program Counter: 0x3B4, Count: 1\n";
    EXPECT_EQ(output.str(), expected);
}

TEST(PCCounterTest, HandlesEmptyInput) {
    std::istringstream input("");
    std::ostringstream output;
    countPCOccurrences(input, output);

    EXPECT_EQ(output.str(), "");
}

TEST(PCCounterTest, HandlesSingleLineInput) {
    std::istringstream input("0xABC");
    std::ostringstream output;
    countPCOccurrences(input, output);

    std::string expected = "Program Counter: 0xABC, Count: 1\n";
    EXPECT_EQ(output.str(), expected);
}
