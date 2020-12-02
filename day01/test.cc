
#include "solver.hh"
#include <gtest/gtest.h>
#include <vector>

TEST(Day01Part01, Test01) {
    const std::vector<int> data{1721, 979, 366, 299, 675, 1456};
    const auto answer = find_product_for_pair_with_sum(data, 2020);
    ASSERT_EQ(answer, 514579);
}
