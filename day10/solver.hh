
#pragma once


#include <istream>
#include <vector>
#include <tuple>


using JoltData = std::vector<unsigned>;
using JoltRatings = std::tuple<unsigned, unsigned, unsigned>;

JoltData read_adapters(std::istream&);
JoltData arrange_adapters(const JoltData&);
JoltRatings rate_adapters(const JoltData&);
