#include "uincampus/saisie.hpp"
#include "uincampus/regles.hpp"
#include <iostream>
#include <sstream>
namespace uin {
namespace { // espace de noms anonyme : fonctions internes à ce fichier (chapitre)
std::string LireLigne(std::string_view invite) 
{ 
  std::cout << invite;
  std::string ligne;
  std::getline(std::cin, ligne);
  return ligne;
}
bool estEntierStrict(const std::string& texte, int& valeur)
{
  std::istringstream flux{texte};
  char reste{};
  return (flux >> valeur) && !(flux >> reste);
} 
bool estReelStrict(std::string texte, double& valeur) 
{
  for (char& c : texte) {
     if (c == ',') { c = '.'; }
}
  std::istringstream flux{texte};
  char reste{};
  return (flux >> valeur) && !(flux >> reste);
}
} // namespace 
std::string LireTexte(std::string_view invite)
{
  return LireLigne(invite);
}
int LireEntier(std::string_view invite, int min, int max)
{
  while (std::cin) {
      const std::string ligne = LireLigne(invite);
      int valeur{};
      if (!estEntierStrict(ligne, valeur)) {
         std::cout << " saisie invalide : entrez un nombre entier.\n";
      } else if (valeur < min || valeur > max) {
      } else {
         return valeur;
      }
  }
  return min; // fin d'entrée : valeur de repli (sera remplacée par une exception au chapitre 15)
}
double LireNote(std::string_view invite)
{
  while (std::cin) {
     const std::string ligne = LireLigne(invite);
     double note{};
     if (!estReelStrict(ligne, note)) {
        std::cout << " saisie invalide : entrez un nombre (ex. 12.5 ou 12,5).\n";
     } else if (!estNoteValide(note)) {
         std::cout << " la note doit etre comprise entre " << noteMin << " et " << noteMax << ".\n";
     } else {
         return note;
     }
  }
  return noteMin;
}
} // namespace uin;
       

