
#include "solver.hh"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

int main() {
    // std::cout << "cwd: " << std::filesystem::current_path() << std::endl;
    const std::filesystem::path input{"day01/input"};
    std::ifstream ifs{input};
    std::vector<int> data;
    for (int i = 0; ifs >> i;) data.push_back(i);
    const auto answer = find_product_for_pair_with_sum(data, 2020);
    std::cout << answer << std::endl;
}
