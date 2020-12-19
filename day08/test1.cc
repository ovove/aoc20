
#include "solver.hh"

#include <gtest/gtest.h>

#include <sstream>
#include <string>


TEST(Day8, Test1) {
    const std::string input{R"(
nop +0
acc +1
jmp +4
acc +3
jmp -3
acc -99
acc +1
jmp -4
acc +6
)"};
    std::istringstream iss{input};
    const auto tape{read_instructions(iss)};
    const auto acc{get_accumulator_when_detect_infinite_loop(tape)};
    EXPECT_TRUE(acc);
    EXPECT_EQ(*acc, 5);
}
