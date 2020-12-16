
#include "solver.hh"

#include <gtest/gtest.h>
#include <sstream>
#include <string>


TEST(Day7, Test1)
{
    const std::string input{R"(
light red bags contain 1 bright white bag, 2 muted yellow bags.
dark orange bags contain 3 bright white bags, 4 muted yellow bags.
bright white bags contain 1 shiny gold bag.
muted yellow bags contain 2 shiny gold bags, 9 faded blue bags.
shiny gold bags contain 1 dark olive bag, 2 vibrant plum bags.
dark olive bags contain 3 faded blue bags, 4 dotted black bags.
vibrant plum bags contain 5 faded blue bags, 6 dotted black bags.
faded blue bags contain no other bags.
dotted black bags contain no other bags.
)"};
    std::istringstream iss{input};
    const auto& bag_rules = read_bag_rules(iss);
    unsigned nr_of_possible_bags_configs = 0;
    const std::string looking_for_this_inner_bag{"shiny gold"};
    for (const auto& [bag, inner_bags]: bag_rules) {
        if (bag == looking_for_this_inner_bag) continue;
        const auto& dist = bag_containing_bag(bag_rules, bag, looking_for_this_inner_bag);
        if (not dist) continue;
        ++nr_of_possible_bags_configs;
    }
    ASSERT_EQ(nr_of_possible_bags_configs, 4);
}
