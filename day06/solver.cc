
#include "solver.hh"

#include <istream>
#include <regex>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>


AllGroupCustomDeclarationForm read_all_custom_declaration_forms(std::istream& ifs)
{
    AllGroupCustomDeclarationForm result{};
    GroupCustomDeclarationForm group_custom_decl{};
    for (std::string line; std::getline(ifs, line);) {
        if (line.empty()) {
            if (not group_custom_decl.empty()) result.push_back(group_custom_decl);
            group_custom_decl.clear();
            continue;
        }
        static const std::regex re{R"([a-z]+)"};
        if (std::smatch match; std::regex_match(line, match, re)) {
            CustomDeclarationForm cust_decl_form{};
            for (const auto ch: match.str()) {
                if (cust_decl_form.count(ch) > 0) throw std::runtime_error("Invalid declaration");
                cust_decl_form.insert(ch);
            }
            group_custom_decl.push_back(cust_decl_form);
        } else {
            throw std::runtime_error("Incorrect declaration");
        }
    }
    if (not group_custom_decl.empty()) result.push_back(group_custom_decl);
    return result;
}


CollectedGroupCustomDeclarationForm
collect_all_groups_declararion_forms(const AllGroupCustomDeclarationForm& all_group_decl_forms)
{
    CollectedGroupCustomDeclarationForm result{};
    for (const auto& one_grp_decl_forms: all_group_decl_forms) {
        CustomDeclarationForm collected_group_decl_forms{};
        for (const auto& one_person_decl_form: one_grp_decl_forms) {
            collected_group_decl_forms.insert(std::begin(one_person_decl_form),
                                              std::end(one_person_decl_form));
        }
        result.push_back(collected_group_decl_forms);
    }
    return result;
}
