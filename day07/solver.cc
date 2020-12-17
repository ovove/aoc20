
#include "solver.hh"

#include <deque>
#include <iostream>
#include <istream>
#include <map>
#include <regex>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>


BagRules read_bag_rules(std::istream& iss)
{
    BagRules result{};
    static std::regex re{
        R"(^(\S+ \S+) bags contain (?:(\d+ \S+ \S+ bags?(?:, \d+ \S+ \S+ bags?)*)|(?:no other bags))\.$)"};
    for (std::string line; std::getline(iss, line);) {
        if (std::smatch match; std::regex_match(line, match, re)) {
            const BagName bag_name{match[1].str()};
            result[bag_name] = BagContent{};
            if (match[2].matched) {
                BagContent bag_content{};
                const std::string& content{match[2].str()};
                static std::regex re2{R"((\d+) (\S+ \S+) bags?(?:, )?)"};
                for (auto it = std::sregex_iterator{std::begin(content), std::end(content), re2};
                     it != std::sregex_iterator{}; ++it) {
                    const auto match2{*it};
                    const unsigned bag_count{static_cast<unsigned>(std::stoi(match2[1].str()))};
                    const std::string& inner_bag{match2[2].str()};
                    result[bag_name].push_back(std::tuple{inner_bag, bag_count});
                }
            }
        }
    }
    return result;
}


std::optional<BagNestingLevel>
bag_containing_bag(const BagRules& bag_rules, const BagName& outer_bag, const BagName& inner_bag)
{
    if (bag_rules.count(outer_bag) == 0) return std::nullopt;
    // Do a network graph breadth first search
    std::set<BagName> processed_bags{outer_bag};
    std::deque<BagContent> to_be_processed;
    to_be_processed.push_back(bag_rules.at(outer_bag));
    unsigned distance = 0;
    while (to_be_processed.size() > 0) {
        const auto& bags{to_be_processed.front()};
        ++distance;
        for (const auto& [bag, cnt]: bags) {
            if (bag == inner_bag) return distance;
            if (processed_bags.count(bag) != 0) continue;
            processed_bags.insert(bag);
            to_be_processed.push_back(bag_rules.at(bag));
        }
        to_be_processed.pop_front();
    }
    return std::nullopt;
}


InnerBagCount count_inner_bags(const BagRules& bag_rules, const BagName& outer_bag)
{
    InnerBagCount result{0};
    const auto& inner_bags{bag_rules.at(outer_bag)};
    for (const auto& [bag, cnt]: inner_bags) {
        result += cnt + cnt * count_inner_bags(bag_rules, bag);
    }
    return result;
}
