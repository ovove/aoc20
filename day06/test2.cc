
#include "solver.hh"

#include <gtest/gtest.h>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>


TEST(Day6, Test2)
{
    std::string input{R"(
abc

a
b
c

ab
ac

a
a
a
a

b
)"};
    std::istringstream iss{input};
    const auto all_forms{read_all_custom_declaration_forms(iss)};
    const auto coll_res{analyze_all_groups_with_all_person_answered_yes(all_forms)};
    const unsigned tot_all_yes_answers = std::transform_reduce(
        std::begin(coll_res), std::end(coll_res), 0U, std::plus<unsigned>{},
        [](const DeclarationForm& col_yes_ansers) -> unsigned { return col_yes_ansers.size(); });
    ASSERT_EQ(tot_all_yes_answers, 6U);
}
