
#pragma once

#include <istream>
#include <set>
#include <vector>


using CustomDeclarationForm = std::set<char>; // For one person
using GroupCustomDeclarationForm = std::vector<CustomDeclarationForm>; // Groups of persons
using AllGroupCustomDeclarationForm = std::vector<GroupCustomDeclarationForm>; // All groups

using CollectedGroupCustomDeclarationForm = std::vector<CustomDeclarationForm>; // Collected

AllGroupCustomDeclarationForm read_all_custom_declaration_forms(std::istream&);

CollectedGroupCustomDeclarationForm
collect_all_groups_declararion_forms(const AllGroupCustomDeclarationForm&);
