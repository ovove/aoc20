
#include "solver.hh"

#include <gtest/gtest.h>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>


namespace {
std::string input{
    R"(
ecl:gry pid:860033327 eyr:2020 hcl:#fffffd
byr:1937 iyr:2017 cid:147 hgt:183cm

iyr:2013 ecl:amb cid:350 eyr:2023 pid:028048884
hcl:#cfa07d byr:1929

hcl:#ae17e1 iyr:2013
eyr:2024
ecl:brn pid:760753108 byr:1931
hgt:179cm

hcl:#cfa07d eyr:2025 pid:166559648
iyr:2011 ecl:brn hgt:59in
    )"};
}


TEST(Day04, Test1)
{
    std::istringstream iss{input};
    const auto passports{read_passport_data(iss)};
    const auto validate_passport = [](const PassportData& pd) -> unsigned {
        return (is_valid_passport(pd) or is_valid_north_pole_credential(pd)) ? 1U : 0U;
    };
    const auto nr_of_valid = std::transform_reduce(std::begin(passports), std::end(passports), 0U,
                                                   std::plus<unsigned>{}, validate_passport);

    ASSERT_EQ(nr_of_valid, 2U);
}
