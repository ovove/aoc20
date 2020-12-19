
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

Address alu(Address ip, OpCodes op, int arg, int& acc)
{
    switch (op) {
    case OpCodes::nop:
        return ip + 1;
    case OpCodes::jmp:
        return ip + arg;
    case OpCodes::acc: {
        acc += arg;
        return ip + 1;
    }
    }
}

class ip_out_of_range : public std::out_of_range {
public:
    ip_out_of_range(const char* msg) : std::out_of_range(msg) {}
};
}

std::optional<int> get_accumulator_when_detect_infinite_loop(const Tape& tape) {
    std::set<Address> already_seen_instructions{};
    int acc{0};
    for (Address ip{1}; ip < tape.size();) {
        already_seen_instructions.insert(ip);
        const auto [op, arg] = tape.at(ip);
        const auto next_ip{alu(ip, op, arg, acc)};
        if (already_seen_instructions.count(next_ip) != 0) return acc;
        ip = next_ip;
        if ((ip < 1) or (tape.size() < ip)) throw ip_out_of_range("Illegal IP");
    }
    return std::nullopt;
}

int get_accumulator_when_run_until_last_op(const Tape& tape) {
    int acc{0};
    for (Address ip{1}; ip < tape.size();) {
        const auto [op, arg] = tape.at(ip);
        const auto next_ip{alu(ip, op, arg, acc)};
        ip = next_ip;
    }
    return acc;
}

Tape debug_code(Tape tape) {
    for (Address ip = 1; ip < tape.size(); ++ip) {
        if (const auto [op, arg] = tape[ip]; op == OpCodes::acc)
            continue;
        else if (op == OpCodes::nop)
            tape[ip] = Instruction{OpCodes::jmp, arg};
        else
            tape[ip] = Instruction{OpCodes::nop, arg};
        try {
            const auto acc{get_accumulator_when_detect_infinite_loop(tape)};
            if (not acc) break;
        }
        catch (ip_out_of_range&) {
            // pass
        }
        if (const auto [op, arg] = tape[ip]; op == OpCodes::nop)
            tape[ip] = Instruction{OpCodes::jmp, arg};
        else
            tape[ip] = Instruction{OpCodes::nop, arg};
    }
    return tape;
}

