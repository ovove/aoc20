
#pragma once

#include <string>
#include <tuple>

using PasswordPolicyRecord = std::tuple<unsigned, unsigned, char, std::string>;
PasswordPolicyRecord parse_password_policy_record(const std::string& line);
bool sled_validate_password_policy_record(const PasswordPolicyRecord&);
bool toboggan_validate_password_policy_record(const PasswordPolicyRecord&);
