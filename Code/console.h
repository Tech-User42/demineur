#include "game.h"

struct entry{
        int row;
        int col;
    };
typedef struct {
        int row;
        int col;
        int out;
    }mine_detection;
void clear_screen(); // Clear la console
void setup_screen(); // Règle la taille du terminal
void display_game(char tab[limit][limit]); // Affiche la grille de démineur passé en argument.
void mod_grid(char tab[limit][limit],char mine[limit][limit] ,entry inp,int cas);
mine_detection check_mine_around(char tab[limit][limit],char mine[limit][limit], int ii ,int jj);
void decouvrir_carre(bool V[limit][limit], int M[limit][limit], int m, int n, int i, int j);


int choice();
entry input(entry inp);