
#pragma once

#include <istream>
#include <map>
#include <optional>
#include <string>
#include <tuple>
#include <vector>


using BagName = std::string;
using BagCount = std::tuple<BagName, unsigned>;
using BagContent = std::vector<BagCount>;
using BagRules = std::map<BagName, BagContent>;

using BagNestingLevel = unsigned; // Number of contained bags


BagRules read_bag_rules(std::istream&);

std::optional<BagNestingLevel>
bag_containing_bag(const BagRules& bag_rules, const BagName& outer_bag, const BagName& inner_bag);
