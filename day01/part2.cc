
#include "solver.hh"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    const std::filesystem::path input{"day01/input"};
    std::ifstream ifs{input};
    std::vector<int> data;
    for (int i = 0; ifs >> i;) data.push_back(i);
    const auto test_for_sum = [](int expected_sum) {
        return [expected_sum](const std::vector<int>& selection) {
            const auto actual_sum = std::accumulate(std::begin(selection), std::end(selection), 0);
            return (actual_sum == expected_sum);
        };
    };
    const auto numbers = find_combination_if(data, 3U, test_for_sum(2020));
    const auto answer = std::accumulate(std::begin(numbers), std::end(numbers), 1,
                                        [](int a, int b) { return a * b; });
    std::cout << answer << std::endl;
}
