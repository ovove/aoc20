
#pragma once

#include <functional>
#include <vector>

std::vector<int> find_combination_if(const std::vector<int>& range, std::size_t combination_length,
                                     std::function<bool(const std::vector<int>&)> predicate);
