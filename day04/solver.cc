
#include "solver.hh"

#include <istream>
#include <regex>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>


namespace {
bool is_valid_key(const std::string& key)
{
    static const std::set<std::string> valid_keys{"byr", "iyr", "eyr", "hgt",
                                                  "hcl", "ecl", "pid", "cid"};
    return (valid_keys.find(key) != valid_keys.end());
}

bool is_valid_byr(const PassportData& pd)
{
    static const std::regex re{R"([12][0-9]{3})"};
    if (std::smatch match; std::regex_match(pd.at("byr"), match, re)) {
        const auto val = std::stoi(match.str());
        return ((1920 <= val) and (val <= 2002));
    }
    return false;
}

bool is_valid_iyr(const PassportData& pd)
{
    static const std::regex re{R"(2[0-9]{3})"};
    if (std::smatch match; std::regex_match(pd.at("iyr"), match, re)) {
        const auto val = std::stoi(match.str());
        return ((2010 <= val) and (val <= 2020));
    }
    return false;
}

bool is_valid_eyr(const PassportData& pd)
{
    static const std::regex re{R"(2[0-9]{3})"};
    if (std::smatch match; std::regex_match(pd.at("eyr"), match, re)) {
        const auto val = std::stoi(match.str());
        return ((2020 <= val) and (val <= 2030));
    }
    return false;
}

bool is_valid_hgt(const PassportData& pd)
{
    static const std::regex re{R"(([1-9][0-9]+)(cm|in))"};
    if (std::smatch match; std::regex_match(pd.at("hgt"), match, re)) {
        const auto val = std::stoi(match[1].str());
        const auto uni = match[2].str();
        return (((uni == "cm") and ((150 <= val) and (val <= 193))) or
                ((uni == "in") and ((59 <= val) and (val <= 76))));
    }
    return false;
}

bool is_valid_hcl(const PassportData& pd)
{
    static const std::regex re{R"(#[0-9a-f]{6})"};
    return std::regex_match(pd.at("hcl"), re);
}

bool is_valid_ecl(const PassportData& pd)
{
    static const std::regex re{R"(amb|blu|brn|gry|grn|hzl|oth)"};
    return std::regex_match(pd.at("ecl"), re);
}

bool is_valid_pid(const PassportData& pd)
{
    static const std::regex re{R"([0-9]{9})"};
    return std::regex_match(pd.at("pid"), re);
}

} // namespace


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


bool is_strict_valid(const PassportData& pd)
{
    return is_valid_byr(pd) and is_valid_iyr(pd) and is_valid_eyr(pd) and is_valid_hgt(pd) and
           is_valid_hcl(pd) and is_valid_ecl(pd) and is_valid_pid(pd);
}


std::vector<PassportData> read_passport_data(std::istream& is)
{
    std::vector<PassportData> result{};
    PassportData passport_data{};

    const std::regex empty_line_re{R"(^\s*$)"};
    static const std::regex passport_data_re{R"(([a-z]{3}):([#a-z0-9]+))"};
    for (std::string line; std::getline(is, line);) {
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
