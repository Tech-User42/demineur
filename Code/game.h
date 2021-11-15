const short unsigned limit = 20; // Limite de dimensions de game.
struct mine_detection{
        int row;
        int col;
        int out;
    };
void make_grid(char tab[limit][limit],char symbole); // Fill les tableaux passé en argument avec le symbole passé en argument.
void make_mine_grid(char tab[limit][limit],char symbole); // Créer la grille de mine
bool play(char tab[limit][limit] ,char mine[limit][limit]);
bool check_mine(char mine[limit][limit],int row,int col); // Check si l'entrée est une mine
void mark_mine(bool tab[limit][limit],int row, int col);