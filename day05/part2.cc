
#include "solver.hh"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <stdexcept>
#include <string>
#include <vector>


int main()
{
    const std::filesystem::path input{"day05/input"};
    if (not std::filesystem::exists(input)) std::runtime_error("Input not found");
    std::ifstream ifs{input};
    std::vector<std::string> seat_codes{};
    std::copy(std::istream_iterator<std::string>{ifs}, std::istream_iterator<std::string>{},
              std::back_inserter(seat_codes));
    std::vector<unsigned> seat_id(seat_codes.size());
    std::transform(std::begin(seat_codes), std::end(seat_codes), std::begin(seat_id),
                   [](auto code) { return get_id(code); });
    std::sort(std::begin(seat_id), std::end(seat_id));
    const auto it{std::adjacent_find(std::begin(seat_id), std::end(seat_id),
                                     [](auto s1, auto s2) { return ((s2 - s1) == 2); })};
    std::cout << (*it + 1) << std::endl;
}
