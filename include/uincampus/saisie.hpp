 #pragma once
#include <string>
#include <string_view>
namespace uin {
// Lit une ligne de texte (espace compris).
std::string LireTexte(std::string_view invite);
// Lit un entier compris entre min et max ; redemande tant que la saisie est invalide.
int LireEntier(std::string_view invite, int min, int max);
// Lit une note valide ; accepte la virgule décimale. 
double LireNote(std::string_view invite);
} // namespace uin
