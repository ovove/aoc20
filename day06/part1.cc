
#include "solver.hh"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <stdexcept>
#include <string>
#include <vector>


int main()
{
    std::filesystem::path input{"day06/input"};
    if (not std::filesystem::exists(input)) throw std::runtime_error("File not found");
    std::ifstream ifs{input};
    const auto result{read_all_custom_declaration_forms(ifs)};
    const auto coll_res{collect_all_groups_declararion_forms(result)};
    const unsigned tot_yes_answers =
        std::transform_reduce(std::begin(coll_res), std::end(coll_res), 0U, std::plus<unsigned>{},
                              [](const CustomDeclarationForm& col_yes_ansers) -> unsigned {
                                  return col_yes_ansers.size();
                              });
    std::cout << tot_yes_answers << std::endl;
}
