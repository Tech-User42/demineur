
struct entry{
        int row;
        int col;
    };
void clear_screen(); // Clear la console
void setup_screen(); // Règle la taille du terminal
void display_game(char tab[20][20]); // Affiche la grille de démineur passé en argument.
void mod_grid(char tab[20][20],char mine[20][20] ,entry inp,int cas);
mine_detection check_mine_around(char tab[20][20],char mine[20][20], int ii ,int jj);

int choice();
entry input(entry inp);