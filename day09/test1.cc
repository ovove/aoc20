
#include "solver.hh"

#include <gtest/gtest.h>

#include <sstream>
#include <string>


TEST(Day8, Test1) {
    const std::string input{R"(
35
20
15
25
47
40
62
55
65
95
102
117
150
182
127
219
299
277
309
576
)"};
    std::istringstream iss{input};
    const auto xmas{read_xmas_code(iss)};
    const auto code{find_incorrect_code(xmas, 5)};
    EXPECT_TRUE(code);
    EXPECT_EQ(*code, 127);
}
