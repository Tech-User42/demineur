#include <iostream>
#include "color.h"
#define limit 10 // Limite de dimensions de game.
using namespace std;
int game_over();
void open_file(string file);
void title();
void display_grid(int tab[limit][limit]); // Affiche la grille de démineur passé en argument.
void c_return(); 