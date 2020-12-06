
#include "solver.hh"

#include <algorithm>
#include <array>
#include <regex>

namespace {
    static const std::regex passwd_policy_record_regex{R"(^ *([1-9][0-9]*) *- *([1-9][0-9]*) *([a-z]) *: *([a-z]+) *$)"};
}

PasswordPolicyRecord parse_password_policy_record(const std::string& line) {
    std::smatch regex_match;
    if (std::regex_match(line, regex_match, passwd_policy_record_regex)) {
        const unsigned lower_bound = std::stoul(regex_match[1].str());
        const unsigned upper_bound = std::stoul(regex_match[2].str());
        const char required_char = regex_match[3].str()[0];
        const std::string& password = regex_match[4].str();
        return PasswordPolicyRecord{lower_bound, upper_bound, required_char, password};
    }
    return PasswordPolicyRecord{};
}

bool sled_validate_password_policy_record(const PasswordPolicyRecord& password_policy_record) {
    const auto [lower_bound, upper_bound, required_char, password] = password_policy_record;
    const auto required_char_count = std::count(std::begin(password), std::end(password), required_char);
    return (lower_bound <= required_char_count) and (required_char_count <= upper_bound);
}

bool toboggan_validate_password_policy_record(const PasswordPolicyRecord& password_policy_record)
{
    const auto [ix1, ix2, required_char, password] = password_policy_record;
    const std::array<char, 2> required_chars{password[ix1-1], password[ix2-1]};
    return ((required_chars[0] == required_char) and (required_chars[1] != required_char)) or
           ((required_chars[0] != required_char) and (required_chars[1] == required_char));
}
