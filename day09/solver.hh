
#pragma once

#include <istream>
#include <optional>
#include <vector>


using XMASCode = std::vector<std::uint64_t>;
using XMASValue = std::optional<XMASCode::value_type>;

XMASCode read_xmas_code(std::istream&);
XMASValue find_incorrect_code(const XMASCode&, std::size_t premble_length);

XMASCode find_xmas_subset(const XMASCode&, XMASCode::value_type);
