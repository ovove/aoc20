
#include "solver.hh"

#include <gtest/gtest.h>

#include <sstream>
#include <string>


TEST(Day9, Test2) {
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
    const auto value{find_incorrect_code(xmas, 5)};
    EXPECT_TRUE(value);
    EXPECT_EQ(*value, 127);
    const auto subset{find_xmas_subset(xmas, *value)};
    EXPECT_EQ(subset.size(), 4);
    const auto [min, max] = std::minmax_element(std::begin(subset), std::end(subset));
    const auto result{*min + *max};
    EXPECT_EQ(result, 62);
}
