#define limit 20 // Limite de dimensions de game.

int play(bool tab[limit][limit],int mine[limit][limit]);
void create_tab(bool tab[limit][limit]);
void display_tab(bool tab[limit][limit],int mine[limit][limit],int x, int y);
void create_mines(int tab[limit][limit]);