
#pragma once

#include <string>

unsigned get_row(const std::string& seat_code);
unsigned get_col(const std::string& seat_code);

unsigned get_id(unsigned row, unsigned col);
unsigned get_id(const std::string& seat_code);
