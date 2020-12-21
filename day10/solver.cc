
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
    using IStreamIterType = std::istream_iterator<JoltData::value_type>;
    std::copy(IStreamIterType{is}, IStreamIterType{}, std::back_inserter(result));
    return result;
}


JoltData arrange_adapters(const JoltData& jd) {
    const auto nr_of_adapters{jd.size()};
    JoltData result(nr_of_adapters + 2); // leading 0, and trailing +3
    std::copy(std::begin(jd), std::end(jd), std::begin(result) + 1);
    std::sort(std::begin(result) + 1, std::begin(result) + 1 + nr_of_adapters);
    result[0] = 0;
    result[nr_of_adapters + 1] = result[nr_of_adapters] + 3;
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
