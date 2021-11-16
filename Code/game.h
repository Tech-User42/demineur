#define limit 20 // Limite de dimensions de game.

void make_grid(bool tab[limit][limit],char symbole); // Fill les tableaux passé en argument avec le symbole passé en argument.
void make_grid2(char tab[limit][limit],char symbole); 
void make_mine_grid(char tab[limit][limit],char symbole); // Créer la grille de mine
void afficher_champ(bool V[20][20], char M[20][20]);
bool play(bool tab[limit][limit] ,char mine[limit][limit]);
bool check_mine(char mine[limit][limit],int row,int col); // Check si l'entrée est une mine
void mark_mine(bool tab[limit][limit],int row, int col);
