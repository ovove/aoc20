
#pragma once

#include <istream>
#include <optional>
#include <tuple>
#include <vector>


enum class OpCodes { nop, jmp, acc };
using Instruction = std::tuple<OpCodes, int>;
using Tape = std::vector<Instruction>;

Tape read_instructions(std::istream&);
std::optional<int> get_accumulator_when_detect_infinite_loop(const Tape&);
Tape debug_code(const Tape);
int get_accumulator_when_run_until_last_op(const Tape&);
