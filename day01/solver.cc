
#include "solver.hh"

#include <algorithm>
#include <utility>
#include <vector>


namespace {
bool find_combination_if(const std::vector<int>& range, const std::size_t comb_len,
                         std::function<bool(const std::vector<int>&)> pred,
                         std::vector<int>::size_type index, std::vector<int>& result)
{
    if (index == comb_len) return pred(result);
    for (std::vector<int>::size_type ix = index; ix < range.size(); ++ix) {
        result[index] = range[ix];
        if (find_combination_if(range, comb_len, pred, index + 1, result)) return true;
    }
    return false;
}
} // namespace


std::vector<int> find_combination_if(const std::vector<int>& range, std::size_t comb_len,
                                     std::function<bool(const std::vector<int>&)> pred)
{
    if ((comb_len == 0) or (comb_len >= range.size())) return std::vector<int>{};
    std::vector<int> result(comb_len);
    if (find_combination_if(range, comb_len, pred, 0, result)) return result;
    return std::vector<int>{};
}
