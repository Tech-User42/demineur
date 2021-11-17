/*
############ Library homemade ############
*/
#include "display.h"
int play(int tab[limit][limit],int mine[limit][limit]);
void create_tab(int tab[limit][limit]);
void display_game(int tab[limit][limit],int mine[limit][limit],int x, int y);
void create_mines(int tab[limit][limit]);
bool check_for_mine(int mine[limit][limit],int x , int y);
