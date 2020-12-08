
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

class Day03 : public ::testing::Test {
public:
    Day03() : tile_{make_tile(input)}, map_{tile_} {}

protected:
    std::size_t walk_and_count_trees(const XY step)
    {
        XY curr_pos{0, 0};
        while (walk(map_, curr_pos, step, tile_)) {
            ;
        }
        return count_hit_trees(map_);
    }

private:
    static Tile make_tile(const std::string& input)
    {
        std::istringstream iss{input};
        return read_tile(iss);
    }

    const Tile tile_;
    Map map_;
};

TEST_F(Day03, Part02_1_1)
{
    const XY step{1, 1};
    ASSERT_EQ(2U, walk_and_count_trees(step));
}

TEST_F(Day03, Part02_3_1)
{
    const XY step{3, 1};
    ASSERT_EQ(7U, walk_and_count_trees(step));
}

TEST_F(Day03, Part02_5_1)
{
    const XY step{5, 1};
    ASSERT_EQ(3U, walk_and_count_trees(step));
}

TEST_F(Day03, Part02_7_1)
{
    const XY step{7, 1};
    ASSERT_EQ(4U, walk_and_count_trees(step));
}

TEST_F(Day03, Part02_1_2)
{
    const XY step{1, 2};
    ASSERT_EQ(2U, walk_and_count_trees(step));
}
