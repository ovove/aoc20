
#include "solver.hh"

#include <algorithm>
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(Day02, Part1)
{
    std::vector<std::string> pwds{"1-3 a: abcde", "1-3 b: cdefg", "2-9 c: ccccccccc"};
    const auto is_pwd_valid = [](const std::string& pwd) {
        return sled_validate_password_policy_record(parse_password_policy_record(pwd));
    };
    const auto result = std::count_if(std::begin(pwds), std::end(pwds), is_pwd_valid);
    EXPECT_TRUE(is_pwd_valid(pwds[0]));
    EXPECT_FALSE(is_pwd_valid(pwds[1]));
    EXPECT_TRUE(is_pwd_valid(pwds[2]));
    ASSERT_EQ(2U, result);
}
