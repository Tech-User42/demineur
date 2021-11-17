/*
############ Library homemade ############
*/
#include "display.h"

int play(int tab[limit][limit],int mine[limit][limit],int marked[limit][limit],bool cheat);
void create_tab(int tab[limit][limit]);
void display_game(int tab[limit][limit],int mine[limit][limit],int x, int y);
void create_mines(int tab[limit][limit]);
bool check_for_mine(int mine[limit][limit],int x , int y);
int mark_mine(int tab,int marked,int x,int y);
void creuser(int tab[limit][limit],int x,int y);