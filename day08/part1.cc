
#include "solver.hh"

#include <filesystem>
#include <fstream>
#include <iostream>

#include <iomanip>

int main()
{
    std::filesystem::path input{"day08/input"};
    if (not std::filesystem::exists(input)) throw std::runtime_error("File not found");
    std::ifstream ifs{input};
    const auto& tape{read_instructions(ifs)};
    const auto acc{get_accumulator_when_detect_infinite_loop(tape)};
    std::cout << *acc << std::endl;
}
