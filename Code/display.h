#define limit 10 // Limite de dimensions de game.
#include <iostream>
/*
############ Library by Ezio ############
*/



using namespace std;
int game_over(int display[limit][limit],int mine[limit][limit]);
void open_file(string file);
void title();
void display_grid(int tab[limit][limit]); // Affiche la grille de démineur passé en argument.
void c_return(); 
void display_empty();