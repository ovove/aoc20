
#include "solver.hh"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


int main() {
    const std::filesystem::path input{"day03/input"};
    std::ifstream ifs{input};
    const auto tile{read_tile(ifs)};
    Map map{tile};

    const XY step{3, 1};
    XY curr_pos{0, 0};
    while (walk(map, curr_pos, step, tile)) {
        ;
    }

    std::cout << count_hit_trees(map) << std::endl;
}
