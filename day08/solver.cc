
#include "solver.hh"

#include <istream>
#include <optional>
#include <regex>
#include <set>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>


Tape read_instructions(std::istream& is) {
    std::vector<Instruction> result{std::tuple{OpCodes::nop, +0}}; // Dummy at addr 0
    for (std::string line; std::getline(is, line); ) {
        if (line.size() == 0) continue;
        static const std::regex re{R"((?:(nop)|(jmp)|(acc))\s+([-+]\d+)$)"};
        if (std::smatch match; std::regex_match(line, match, re)) {
            const int arg{std::stoi(match[4].str())};
            // clang-format off
            if      (match[1].matched) result.emplace_back(OpCodes::nop, arg);
            else if (match[2].matched) result.emplace_back(OpCodes::jmp, arg);
            else if (match[3].matched) result.emplace_back(OpCodes::acc, arg);
            else throw std::runtime_error("Internal read instantiated error");
            // clang-format on
        }
        else {
            throw std::runtime_error("Unknown istruction");
        }
    }
    return result;
}

namespace {
using Address = unsigned;

Address alu(Address ip, OpCodes op, int arg)
{
    switch (op) {
    case OpCodes::nop: return ip + 1;
    case OpCodes::jmp: return ip + arg;
    case OpCodes::acc: return ip + 1;
    }
}
}

std::optional<unsigned> detect_infinite_loop(const Tape& tape) {
    std::set<Address> already_seen_instructions{};
    for (Address ip{1}; ip < tape.size();) {
        already_seen_instructions.insert(ip);
        const auto [op, arg] = tape.at(ip);
        const auto next_ip{alu(ip, op, arg)};
        if (already_seen_instructions.count(next_ip) != 0) return ip;
        ip = next_ip;
    }
    return std::nullopt;
}
