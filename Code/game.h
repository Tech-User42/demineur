/*
############ Library homemade ############
*/
#include "display.h"

int play(int tab[limit][limit],int mine[limit][limit],int marked[limit][limit],bool cheat);// Fonction avec loop de jeu.
void create_tab(int tab[limit][limit]); // Fill un tableau avec des 0.
void display_game(int tab[limit][limit],int mine[limit][limit],int x, int y); // Affiche le démineur.
void create_mines(int tab[limit][limit]); // Génère les mines aléatoirement.
bool check_for_mine(int mine[limit][limit],int x , int y); // Return si on touche une mine.
int mark_mine(int tab,int marked,int x,int y); // Update le tableau pour afficher ou on à flag.
void creuser(int tab[limit][limit],int x,int y); // Update le tableau pour afficher ou on à creuser.
void check_for_mine_around(int tab[limit][limit],int mine[limit][limit] ,unsigned short i, unsigned short j); // Fonction qui check les mines autour (pour passer sous les 60 lignes).