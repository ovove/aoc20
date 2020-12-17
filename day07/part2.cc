
#include "solver.hh"

#include <filesystem>
#include <fstream>
#include <iostream>


int main()
{
    std::filesystem::path input{"day07/input"};
    if (not std::filesystem::exists(input)) throw std::runtime_error("File not found");
    std::ifstream ifs{input};
    const auto& bag_rules = read_bag_rules(ifs);
    const std::string looking_for_this_outer_bag{"shiny gold"};
    const auto nr_of_inner_bags = count_inner_bags(bag_rules, looking_for_this_outer_bag);
    std::cout << nr_of_inner_bags << std::endl;
}
