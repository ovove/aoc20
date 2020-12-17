
#include "solver.hh"

#include <algorithm>
#include <gtest/gtest.h>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

namespace {
std::string input{R"(
..##.......
#...#...#..
.#....#..#.
..#.#...#.#
.#...##..#.
..#.##.....
.#.#.#....#
.#........#
#.##...#...
#...##....#
.#..#...#.#
)"};
}

TEST(Day03, Part01)
{
    std::istringstream iss{input};
    const auto tile = read_tile(iss);
    Map map{tile};

    const XY step{3, 1};
    XY curr_pos{0, 0};
    while (walk(map, curr_pos, step, tile)) {
        ;
    }

    const size_t nr_of_hit_trees = count_hit_trees(map);
    ASSERT_EQ(7U, nr_of_hit_trees);
}
