
#pragma once

#include <string>
#include <tuple>
#include <vector>

using XY = std::tuple<int,int>;
using Tile = std::vector<std::string>;
using Map = std::vector<std::string>;

Tile read_tile(std::istream& is);

bool walk(Map&, XY&, XY, const Tile&);

unsigned count_hit_trees(const Map&);
