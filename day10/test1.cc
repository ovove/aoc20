
#include "solver.hh"

#include <gtest/gtest.h>

#include <sstream>
#include <string>


TEST(Day10, Test1a) {
    std::string input{R"(
16
10
15
5
1
11
7
19
6
12
4
)"};
    std::istringstream iss{input};
    const auto adapters{read_adapters(iss)};
    const auto ratings{rate_adapters(adapters)};
    EXPECT_EQ(std::get<0>(ratings), 7);
    EXPECT_EQ(std::get<1>(ratings), 0);
    EXPECT_EQ(std::get<2>(ratings), 5);
    const auto result{std::get<0>(ratings) * std::get<2>(ratings)};
    EXPECT_EQ(result, 35);
}


TEST(Day10, Test1b) {
    std::string input{R"(
28
33
18
42
31
14
46
20
48
47
24
23
49
45
19
38
39
11
1
32
25
35
8
17
7
9
4
2
34
10
3)"};
    std::istringstream iss{input};
    const auto adapters{read_adapters(iss)};
    const auto ratings{rate_adapters(adapters)};
    EXPECT_EQ(std::get<0>(ratings), 22);
    EXPECT_EQ(std::get<1>(ratings),  0);
    EXPECT_EQ(std::get<2>(ratings), 10);
    const auto result{std::get<0>(ratings) * std::get<2>(ratings)};
    EXPECT_EQ(result, 220);
}
