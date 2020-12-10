
#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

using KeyType = std::string;
using ValueType = std::string;
using PassportData = std::map<KeyType, ValueType>;

std::vector<PassportData> read_passport_data(std::istream&);

bool is_valid_passport(const PassportData&);
bool is_valid_north_pole_credential(const PassportData&);
