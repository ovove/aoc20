
#include "solver.hh"

#include <filesystem>
#include <fstream>
#include <iostream>

#include <iomanip>

int main()
{
    std::filesystem::path input{"day09/input"};
    if (not std::filesystem::exists(input)) throw std::runtime_error("File not found");
    std::ifstream ifs{input};
    const auto xmas{read_xmas_code(ifs)};
    const auto value{find_incorrect_code(xmas, 25)};
    const auto subset{find_xmas_subset(xmas, *value)};
    const auto [min, max] = std::minmax_element(std::begin(subset), std::end(subset));
    const auto result{*min + *max};
    std::cout << result << std::endl;
}
