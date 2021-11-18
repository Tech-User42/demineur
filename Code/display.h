#define limit 10 // Limite de dimensions de game.
#include <iostream>
/*
############ Library by Ezio ############
*/

using namespace std;

int game_over(int display[limit][limit],int mine[limit][limit]); // Défini si on relance une game et display le gameover.
void open_file(string file); // Sert à ouvrir les splash screen avec le nom du fichier en arg.
void title(); // Affiche le titre du jeu.
void display_grid(int tab[limit][limit]); // Affiche la grille de démineur passé en argument.
void c_return(); // Affichage des contours blanc.
void display_empty(); // Display la grille vide.
void you_win(); // Display le'écran de fin de game.
void print_help(); // Affiche l'aide et la légende. 