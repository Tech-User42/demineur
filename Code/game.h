#define limit 20 // Limite de dimensions de game.

int play(int tab[limit][limit],int mine[limit][limit]);
void create_tab(int tab[limit][limit]);
void display_tab(int tab[limit][limit],int mine[limit][limit],int x, int y);
void create_mines(int tab[limit][limit]);