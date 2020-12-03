
#include "solver.hh"

#include <algorithm>
#include <utility>
#include <vector>

std::vector<int> find_combination_if(std::vector<int> range, std::size_t comb_len,
                                     std::function<bool(const std::vector<int>&)> pred)
{
    if (comb_len > range.size()) return std::vector<int>{};
    std::sort(std::begin(range), std::end(range));
    do {
        std::vector<int> result{std::begin(range), std::begin(range) + comb_len};
        if (pred(result)) return result;
    } while (std::next_permutation(std::begin(range), std::end(range)));
    return std::vector<int>{};
}
