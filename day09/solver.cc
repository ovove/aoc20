
#include "solver.hh"


#include <algorithm>
#include <istream>
#include <iterator>
#include <numeric>
#include <optional>
#include <stdexcept>
#include <vector>


XMASCode read_xmas_code(std::istream& is) {
    XMASCode result{};
    using IstreamIterType = std::istream_iterator<XMASCode::value_type>;
    std::copy(IstreamIterType{is}, IstreamIterType{}, std::back_inserter(result));
    return result;
}


namespace {
inline XMASCode::const_iterator iter_advance(XMASCode::const_iterator it,
                                             XMASCode::difference_type dist)
{
    std::advance(it, dist);
    return it;
}

bool validate_code(XMASCode::const_iterator first, XMASCode::const_iterator last,
                   XMASCode::value_type expected)
{
    for (auto it = first; it != last; ++it) {
        for (auto it2 = iter_advance(it, 1); it2 != last; ++it2) {
            if ((*it + *it2) == expected) return true;
        }
    }
    return false;
}
}


XMASValue find_incorrect_code(const XMASCode& xmas, std::size_t premble_length)
{
    if (premble_length > xmas.size()) throw std::out_of_range("Premble length out of range");
    for (auto premble_beg = std::begin(xmas),
              premble_end = iter_advance(premble_beg, premble_length);
         premble_end != std::end(xmas); ++premble_beg, ++premble_end) {
        const auto it{premble_end};
        if (not validate_code(premble_beg, premble_end, *it)) return *it;
    }
    return std::nullopt;
}


XMASCode find_xmas_subset(const XMASCode& xmas, XMASCode::value_type target) {
    for (auto it1{std::begin(xmas)}; it1 != std::end(xmas); ++it1) {
        for (auto it2{iter_advance(it1, 1)}; it2 != std::end(xmas); ++it2) {
            const auto sum{std::accumulate(it1, it2, 0UL)};
            if (sum == target) return XMASCode(it1, it2);
        }
    }
    return XMASCode{};
}
