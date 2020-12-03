
#pragma once

#include <functional>
#include <vector>

std::vector<int> find_combination_if(std::vector<int> input, std::size_t comb_len,
                                     std::function<bool(const std::vector<int>&)> pred);
