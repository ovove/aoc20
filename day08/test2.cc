
#include "solver.hh"

#include <gtest/gtest.h>

#include <sstream>
#include <string>


TEST(Day8, Test2) {
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
    const auto buggy_tape{read_instructions(iss)};
    const auto tape{debug_code(buggy_tape)};
    const auto acc{get_accumulator_when_run_until_last_op(tape)};
    EXPECT_EQ(acc, 8);
}
