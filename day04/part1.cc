
#include "solver.hh"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>


int main()
{
    const std::filesystem::path input{"day04/input"};
    std::ifstream ifs{input};
    const auto passports{read_passport_data(ifs)};
    const auto validate_passport = [](const PassportData& pd) -> unsigned {
        return (is_valid_passport(pd) or is_valid_north_pole_credential(pd)) ? 1U : 0U;
    };
    const auto nr_of_valid = std::transform_reduce(std::begin(passports), std::end(passports), 0U,
                                                   std::plus<unsigned>{}, validate_passport);
    std::cout << nr_of_valid << std::endl;
}
