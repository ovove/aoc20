
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
    const auto result{rate_adapters(arrange_adapters(read_adapters(ifs)))};
    std::cout << (std::get<0>(result) * std::get<2>(result)) << std::endl;
}
