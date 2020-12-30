
#include "solver.hh"


#include <algorithm>
#include <istream>
#include <iterator>
#include <stdexcept>
#include <vector>
#include <tuple>

#include <iostream>


JoltData read_adapters(std::istream& is) {
    JoltData result{};
    result.push_back(0);
    JoltData::value_type max{0};
    for (JoltData::value_type val; is >> val;) {
        max = std::max(max, val);
        result.push_back(val);
    }
    result.push_back(max + 3);
    std::sort(std::begin(result), std::end(result));
    return result;
}


JoltRatings rate_adapters(const JoltData& jd) {
    JoltRatings result{0, 0, 0};
    const auto acc_ratings = [&acc = result](JoltData::value_type v0,
                                             JoltData::value_type v1) mutable {
        const auto diff{v1 - v0};
        // clang-format off
        if      (diff == 1) ++std::get<0>(acc);
        else if (diff == 2) ++std::get<1>(acc);
        else if (diff == 3) ++std::get<2>(acc);
        else throw std::runtime_error("Invalid rating diff");
        // clang-format on
        return false;
    };
    std::adjacent_find(std::begin(jd), std::end(jd), acc_ratings);
    return result;
}


