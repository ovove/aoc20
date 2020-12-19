
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
    const auto buggy_tape{read_instructions(ifs)};
    const auto tape{debug_code(buggy_tape)};
    const auto acc{get_accumulator_when_run_until_last_op(tape)};
    std::cout << acc << std::endl;
}
