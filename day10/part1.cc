
#include "solver.hh"

#include <filesystem>
#include <fstream>
#include <iostream>

#include <iomanip>

int main()
{
    std::filesystem::path input{"day10/input"};
    if (not std::filesystem::exists(input)) throw std::runtime_error("File not found");
    std::ifstream ifs{input};
    const auto ratings{rate_adapters(read_adapters(ifs))};
    const auto result{std::get<0>(ratings) * std::get<2>(ratings)};
    std::cout << result << std::endl;
}
