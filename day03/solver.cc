
#include "solver.hh"

#include <algorithm>
#include <istream>
#include <numeric>
#include <stdexcept>
#include <string>
#include <vector>


Tile read_tile(std::istream& is) {
    std::vector<std::string> tile;
    for (std::string line; std::getline(is, line);) {
        if (line.empty()) continue;
        tile.push_back(line);
    }
    return tile;
}

namespace {
Map& operator+=(Map& map, const Tile& tile) {
    for (std::size_t ix = 0; ix < map.size(); ++ix) {
        map[ix] += tile[ix];
    }
    return map;
}

constexpr char FreeSquare{'.'};
constexpr char TreeSquare{'#'};
constexpr char MarkedFreeSquare{'O'};
constexpr char MarkedTreeSquare{'X'};
} // namespace

bool walk(Map& map, XY& pos, XY step, const Tile& tile) {
    const auto [px, py] = pos;
    const auto [sx, sy] = step;
    if ((px + sx) >= map[0].size()) map += tile;
    if ((px + sx) >= map[0].size()) throw std::runtime_error("X out of bounds error");
    if ((py + sy) >= map.size()) throw std::runtime_error("Y out of bounds error");
    auto& free_or_tree = map[py + sy][px + sx]; // 1:st index is Y. 2:nd is X
    free_or_tree = (free_or_tree == FreeSquare) ? MarkedFreeSquare : free_or_tree;
    free_or_tree = (free_or_tree == TreeSquare) ? MarkedTreeSquare : free_or_tree;
    pos =  XY{px + sx, py + sy};
    return (py + sy + 1) < map.size();
}


unsigned count_hit_trees(const Map& map) {
    auto count_nr_of_hit_trees = [](const std::size_t acc, const std::string& slice) {
        return acc + std::count(std::begin(slice), std::end(slice), MarkedTreeSquare);
    };
    return std::accumulate(std::begin(map), std::end(map), 0, count_nr_of_hit_trees);
}
