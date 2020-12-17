
#include "solver.hh"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


int main()
{
    const std::filesystem::path input{"day02/input"};
    std::ifstream ifs{input};
    std::vector<std::string> pwds{};
    for (std::string line; std::getline(ifs, line);) {
        pwds.push_back(line);
    }
    const auto is_pwd_valid = [](const std::string& pwd) {
        return sled_validate_password_policy_record(parse_password_policy_record(pwd));
    };
    const auto result = std::count_if(std::begin(pwds), std::end(pwds), is_pwd_valid);
    std::cout << result << std::endl;
}
