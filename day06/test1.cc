
#include "solver.hh"

#include <gtest/gtest.h>

#include <iostream>
#include <numeric>
#include <sstream>
#include <string>


TEST(Day6, Test1) {
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
    const auto result{read_all_custom_declaration_forms(iss)};
    const auto coll_res{collect_all_groups_declararion_forms(result)};
    const unsigned tot_yes_answers =
        std::transform_reduce(std::begin(coll_res), std::end(coll_res), 0U, std::plus<unsigned>{},
                              [](const CustomDeclarationForm& col_yes_ansers) -> unsigned {
                                  return col_yes_ansers.size();
                              });
    ASSERT_EQ(tot_yes_answers, 11U);
}
