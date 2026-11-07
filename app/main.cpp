#include "uincampus/regles.hpp"
#include "uincampus/saisie.hpp"
#include "uincampus/version.hpp"
#include <array>
#include <cmath>
#include <format>
#include <print>
#include <string>
#include <vector>
int main() {
  std::println("UIN-Campus {} - Statistiques d'une serie de notes\n", uincampus::get_version());
  const std::string ue  = uin::LireTexte("Nom de l'UE : ");
  const int nbEtudiants = uin::LireEntier("Nombre d'etudiants (1 à 200) : ", 1, 200);
  std::vector<double> notes{};
  for (int i{1}; i <=nbEtudiants; ++i) {
      notes.push_back(uin::LireNote(std::format(" Note {} : ", i)));
  }
  // --- Calculs ---
  double min{notes[0]};
  double max{notes[0]};
  double somme{0.0};
  int admis{0};
  std::array<int, 5> compteurs{0, 0, 0, 0, 0,};
  for (double n : notes) { 
      if (n < min) { 
         min = n;
      }
      if (n > max) {
         max = n;
      }
      somme += n;
      if (n >= uin::seuilValidation) {
         ++admis;
      }
      const auto mention = uin::mentionPour(n);
      compteurs[static_cast<std::size_t>(mention)]++;
  }
  const double moyenne{static_cast<double>(somme) / static_cast<double>(notes.size())};
  double sommeCarres{0.0};
  for (double n : notes) { 
      const double ecart{n - moyenne};
      sommeCarres += ecart * ecart;
  }
  const double ecartType{std::sqrt(sommeCarres / static_cast<double>(notes.size()))};
  const double pourcentAdmis{100.0 * static_cast<double>(admis) / static_cast<double>(notes.size())};
  // --- Affichage comme l'enonce ---
  std::println("\nStatiques - {} ({} etudiants)", ue, notes.size());
  std::println("\n{:-<40}", "");
  std::println("{:<15} : {:>6.2f}", "Note minimale", min);
  std::println("{:<15} : {:>6.2f}", "Note maximale", max);
  std::println("{:<15} : {:>6.2f}", "Moyenne", moyenne);
  std::println("{:<15} : {:>6.2f}", "Ecart-type", ecartType);
  std::println("{:<15} : {} ({:.1f} %)", "Admis", admis,pourcentAdmis);
  std::println("\nRepartition par mention");
  const std::array<std::string, 5> noms{"Ajourne", "Passable", "Assez bien", "Bien", "Tres bien"};
  for (std::size_t i{0}; i < noms.size(); ++i) {
      std::println("{:<12} {} ({})", noms[i], std::string(static_cast<std::size_t>(compteurs[i]), '*'), compteurs[i]);
  }
  return 0;
}
