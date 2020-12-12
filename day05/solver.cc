
#include "solver.hh"

#include <numeric>
#include <stdexcept>
#include <string>
#include <string_view>


namespace {
void validate_seat_code(const std::string_view& seat_code)
{
    if (seat_code.size() != 10) throw std::runtime_error("Invalid length");
    const auto row_code{seat_code.substr(0, 7)};
    const auto col_code{seat_code.substr(7)};
    if (row_code.find_first_not_of("FB") != std::string_view::npos)
        throw std::string("Invalid row code");
    if (col_code.find_first_not_of("LR") != std::string_view::npos)
        throw std::string("Invalid col code");
}

unsigned binary_decode(const std::string_view str, char zero, char)
{
    const auto decode_bit = [zero](char bit) { return bit == zero ? 0 : 1; };
    auto decode_binary = [](unsigned res, unsigned bit) { return (2 * res) + bit; };
    return std::transform_reduce(std::begin(str), std::end(str), 0U, decode_binary, decode_bit);
}
} // namespace


unsigned get_row(const std::string& seat_code)
{
    validate_seat_code(seat_code);
    return binary_decode(seat_code.substr(0, 7), 'F', 'B');
}


unsigned get_col(const std::string& seat_code)
{
    validate_seat_code(seat_code);
    return binary_decode(seat_code.substr(7), 'L', 'R');
}

unsigned get_id(unsigned row, unsigned col) { return (8 * row) + col; }

unsigned get_id(const std::string& seat_code)
{
    return get_id(get_row(seat_code), get_col(seat_code));
}
