
#pragma once

#include <istream>
#include <map>
#include <optional>
#include <string>
#include <vector>


using BagName = std::string;
using BagContent = std::vector<BagName>;
using BagRules = std::map<BagName, BagContent>;

using BagCount = unsigned; // Number of contained bags


BagRules read_bag_rules(std::istream&);

std::optional<BagCount> bag_containing_bag(const BagRules& bag_rules, const BagName& outer_bag,
                                           const BagName& inner_bag);
