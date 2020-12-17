
#pragma once

#include <istream>
#include <optional>
#include <tuple>
#include <vector>


enum class OpCodes { nop, jmp, acc };
using Instruction = std::tuple<OpCodes, int>;
using Tape = std::vector<Instruction>;

Tape read_instructions(std::istream&);

std::optional<unsigned> detect_infinite_loop(const Tape&);