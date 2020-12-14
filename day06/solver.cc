
#include "solver.hh"

#include <istream>
#include <regex>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>


AllGroupDeclarationForm read_all_custom_declaration_forms(std::istream& ifs)
{
    AllGroupDeclarationForm result{};
    GroupDeclarationForm group_custom_decl{};
    for (std::string line; std::getline(ifs, line);) {
        if (line.empty()) {
            if (not group_custom_decl.empty()) result.push_back(group_custom_decl);
            group_custom_decl.clear();
            continue;
        }
        static const std::regex re{R"([a-z]+)"};
        if (std::smatch match; std::regex_match(line, match, re)) {
            DeclarationForm cust_decl_form{};
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


AnalyzedDeclarationForm
analyze_all_groups_with_any_person_answered_yes(const AllGroupDeclarationForm& all_group_decl_forms)
{
    AnalyzedDeclarationForm result{};
    for (const GroupDeclarationForm& one_grp_decl_forms: all_group_decl_forms) {
        DeclarationForm collected_group_decl_forms{};
        for (const DeclarationForm& one_person_decl_form: one_grp_decl_forms) {
            collected_group_decl_forms.insert(std::begin(one_person_decl_form),
                                              std::end(one_person_decl_form));
        }
        result.push_back(collected_group_decl_forms);
    }
    return result;
}


AnalyzedDeclarationForm
analyze_all_groups_with_all_person_answered_yes(const AllGroupDeclarationForm& all_group_decl_forms)
{
    AnalyzedDeclarationForm result{};
    for (const GroupDeclarationForm& one_grp_decl_forms: all_group_decl_forms) {
        const DeclarationForm& one_person_decl_form{one_grp_decl_forms.front()};
        DeclarationForm all_yes{};
        for (const char answer: one_person_decl_form) {
            unsigned count_number_of_answers{0};
            for (const DeclarationForm& each_person_decl_form: one_grp_decl_forms) {
                if (each_person_decl_form.count(answer) == 0) break;
                ++count_number_of_answers;
            }
            if (count_number_of_answers == one_grp_decl_forms.size()) { all_yes.insert(answer); }
        }
        result.push_back(all_yes);
    }
    return result;
}
