
#include "solver.hh"

#include <istream>
#include <regex>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>


namespace {
bool is_valid_key(const std::string& key) {
    static const std::set<std::string> valid_keys{"byr", "iyr", "eyr", "hgt",
                                                  "hcl", "ecl", "pid", "cid"};
    return (valid_keys.find(key) != valid_keys.end());
}
}


bool is_valid_passport(const PassportData& pd)
{
    // All required eight fields present?
    return (pd.size() == 8);
}


bool is_valid_north_pole_credential(const PassportData& pd)
{
    // Same as for passport, but "cid" is missing. All other fields must be present
    return (pd.size() == 7 and (pd.find("cid") == pd.end()));
}


std::vector<PassportData> read_passport_data(std::istream& is)
{
    std::vector<PassportData> result{};
    PassportData passport_data{};

    const std::regex empty_line_re{R"(^\s*$)"};
    static const std::regex passport_data_re{R"(([a-z]{3}):([#a-z0-9]+))"};
    for (std::string line; std::getline(is, line);)
    {
        if (std::regex_match(line, empty_line_re)) {
            if (not passport_data.empty()) result.push_back(passport_data);
            passport_data.clear();
            continue;
        }
        for (auto it = std::sregex_iterator{std::begin(line), std::end(line), passport_data_re};
             it != std::sregex_iterator{}; ++it) {
            const auto match{*it};
            const auto key{match[1].str()};
            const auto val{match[2].str()};
            using namespace std::string_literals;
            if (passport_data.find(key) != passport_data.end()) {
                throw std::runtime_error("Key ("s + key + ") already exists");
            }
            if (not is_valid_key(key)) {
                throw std::runtime_error("Key ("s + key + ") is not a valid key");
            }
            passport_data[key] = val;
        }
    }
    if (not passport_data.empty()) result.push_back(passport_data);

    return result;
}
