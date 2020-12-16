
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
    unsigned nr_of_possible_bags_configs = 0;
    const std::string looking_for_this_inner_bag{"shiny gold"};
    for (const auto& [bag, inner_bags]: bag_rules) {
        if (bag == looking_for_this_inner_bag) continue;
        const auto& dist = bag_containing_bag(bag_rules, bag, looking_for_this_inner_bag);
        if (not dist) continue;
        ++nr_of_possible_bags_configs;
    }
    std::cout << nr_of_possible_bags_configs << std::endl;
}
