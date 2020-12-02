
#include "solver.hh"

#include <vector>
#include <algorithm>
#include <utility>

int find_product_for_pair_with_sum(const std::vector<int>& input, int expected_sum) {
    for (auto first = std::begin(input); first != std::end(input); ++first) {
        const auto test_for_expected_sum = [sum = expected_sum, one = *first](int two) {
            return sum == (one + two);
        };
        const auto second = std::find_if(first + 1, std::end(input), test_for_expected_sum);
        if (second != std::end(input)) return *first * *second;
    }
    return -1;
}
