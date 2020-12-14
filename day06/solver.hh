
#pragma once

#include <istream>
#include <set>
#include <vector>


using DeclarationForm = std::set<char>;                            // For one person
using GroupDeclarationForm = std::vector<DeclarationForm>;         // Groups of persons
using AllGroupDeclarationForm = std::vector<GroupDeclarationForm>; // All groups
using AnalyzedDeclarationForm = std::vector<DeclarationForm>;      // Collected

AllGroupDeclarationForm read_all_custom_declaration_forms(std::istream&);

AnalyzedDeclarationForm
analyze_all_groups_with_any_person_answered_yes(const AllGroupDeclarationForm&);

AnalyzedDeclarationForm
analyze_all_groups_with_all_person_answered_yes(const AllGroupDeclarationForm&);
