
#include "solver.hh"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>


namespace {
std::size_t walk_and_count_trees(Map map, XY curr_pos, const XY step, const Tile& tile)
{
    while (walk(map, curr_pos, step, tile)) {
        ;
    }
    return count_hit_trees(map);
}
} // namespace


int main()
{
    const std::filesystem::path input{"day03/input"};
    std::ifstream ifs{input};
    const auto tile{read_tile(ifs)};
    const Map map{tile};

    const std::vector<XY> steps{{1U, 1U}, {3U, 1U}, {5U, 1U}, {7U, 1U}, {1U, 2U}};
    std::vector<std::size_t> hits(steps.size());
    std::transform(std::begin(steps), std::end(steps), std::begin(hits), [map, tile](XY step) {
        XY start_pos{0, 0};
        return walk_and_count_trees(map, start_pos, step, tile);
    });

    for (auto h: hits)
        std::cout << h << " ";
    std::cout << std::endl;

    std::cout << std::accumulate(std::begin(hits), std::end(hits), 1UL,
                                 std::multiplies<std::size_t>{})
              << std::endl;
}
