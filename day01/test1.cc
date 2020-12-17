
#include "solver.hh"

#include <gtest/gtest.h>
#include <numeric>
#include <vector>

TEST(day01part1, test1)
{
    const std::vector<int> data{1721, 979, 366, 299, 675, 1456};
    const auto test_for_sum = [](int expected_sum) {
        return [expected_sum](const std::vector<int>& selection) {
            const auto actual_sum = std::accumulate(std::begin(selection), std::end(selection), 0);
            return (actual_sum == expected_sum);
        };
    };
    const std::size_t nr_of_numbers = 2U;
    const auto numbers = find_combination_if(data, nr_of_numbers, test_for_sum(2020));
    const auto answer = std::accumulate(std::begin(numbers), std::end(numbers), 1,
                                        [](int a, int b) { return a * b; });
    ASSERT_EQ(answer, 514579);
}
