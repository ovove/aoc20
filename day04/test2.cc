
#include "solver.hh"

#include <gtest/gtest.h>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>


TEST(Day04, Test2_Invalid_1)
{
    const std::string input{R"(eyr:1972 cid:100
hcl:#18171d ecl:amb hgt:170 pid:186cm iyr:2018 byr:1926)"};
    std::istringstream iss{input};
    const auto passports{read_passport_data(iss)};
    ASSERT_EQ(passports.size(), 1U);
    EXPECT_TRUE(is_valid_passport(passports[0]));
    ASSERT_FALSE(is_strict_valid(passports[0]));
}

TEST(Day04, Test2_Invalid_2)
{
    const std::string input{R"(iyr:2019
hcl:#602927 eyr:1967 hgt:170cm
ecl:grn pid:012533040 byr:1946)"};
    std::istringstream iss{input};
    const auto passports{read_passport_data(iss)};
    ASSERT_EQ(passports.size(), 1U);
    EXPECT_TRUE(is_valid_north_pole_credential(passports[0]));
    ASSERT_FALSE(is_strict_valid(passports[0]));
}

TEST(Day04, Test2_Invalid_3)
{
    const std::string input{R"(hcl:dab227 iyr:2012
ecl:brn hgt:182cm pid:021572410 eyr:2020 byr:1992 cid:277)"};
    std::istringstream iss{input};
    const auto passports{read_passport_data(iss)};
    ASSERT_EQ(passports.size(), 1U);
    EXPECT_TRUE(is_valid_passport(passports[0]));
    ASSERT_FALSE(is_strict_valid(passports[0]));
}

TEST(Day04, Test2_Invalid_4)
{
    const std::string input{R"(hgt:59cm ecl:zzz
eyr:2038 hcl:74454a iyr:2023
pid:3556412378 byr:2007
)"};
    std::istringstream iss{input};
    const auto passports{read_passport_data(iss)};
    ASSERT_EQ(passports.size(), 1U);
    EXPECT_TRUE(is_valid_north_pole_credential(passports[0]));
    ASSERT_FALSE(is_strict_valid(passports[0]));
}

TEST(Day04, Test2_Valid_1)
{
    const std::string input{R"(pid:087499704 hgt:74in ecl:grn iyr:2012 eyr:2030 byr:1980
hcl:#623a2f)"};
    std::istringstream iss{input};
    const auto passports{read_passport_data(iss)};
    ASSERT_EQ(passports.size(), 1U);
    EXPECT_TRUE(is_valid_north_pole_credential(passports[0]));
    ASSERT_TRUE(is_strict_valid(passports[0]));
}

TEST(Day04, Test2_Valid_2)
{
    const std::string input{R"(eyr:2029 ecl:blu cid:129 byr:1989
iyr:2014 pid:896056539 hcl:#a97842 hgt:165cm
)"};
    std::istringstream iss{input};
    const auto passports{read_passport_data(iss)};
    ASSERT_EQ(passports.size(), 1U);
    EXPECT_TRUE(is_valid_passport(passports[0]));
    ASSERT_TRUE(is_strict_valid(passports[0]));
}

TEST(Day04, Test2_Valid_3)
{
    const std::string input{R"(hcl:#888785
hgt:164cm byr:2001 iyr:2015 cid:88
pid:545766238 ecl:hzl
eyr:2022
)"};
    std::istringstream iss{input};
    const auto passports{read_passport_data(iss)};
    ASSERT_EQ(passports.size(), 1U);
    EXPECT_TRUE(is_valid_passport(passports[0]));
    ASSERT_TRUE(is_strict_valid(passports[0]));
}

TEST(Day04, Test2_Valid_4)
{
    const std::string input{
        R"(iyr:2010 hgt:158cm hcl:#b6652a ecl:blu byr:1944 eyr:2021 pid:093154719)"};
    std::istringstream iss{input};
    const auto passports{read_passport_data(iss)};
    ASSERT_EQ(passports.size(), 1U);
    EXPECT_TRUE(is_valid_north_pole_credential(passports[0]));
    ASSERT_TRUE(is_strict_valid(passports[0]));
}
