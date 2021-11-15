#include <iostream>
#include "game.h"
#include "console.h"
using namespace std;
void make_grid(char tab[limit][limit],char symbole){ // Fill les tableaux passé en argument avec le symbole passé en argument.
     for (int row = 0; row < limit; row++)
    {
        for (int col=0; col < limit; col++) // Double for pour fill le tab 2D
        {
            tab[row][col] = symbole; // Fill du tab avec symbole
        }
    }
    
}
void mark_mine(bool tab[limit][limit],int row, int col){
    tab[row][col] = true;
}
void make_mine_grid(char tab[limit][limit],char symbole){
    tab[0][0] = symbole;
    tab[19][19] = symbole;
    }

bool check_mine(char mine[limit][limit],int row,int col){
    return mine[row][col] == '*';
}
bool play(char tab[limit][limit] ,char mine[limit][limit]){
    struct entry inp; // Structure row col permetant de récup l'entrée utilisateur
    int cas;
    bool marked[limit][limit];
    while(true){
        inp = input(inp);
        cout << "1 Creuser 2 Marquer 3 Annuler."<<endl;
        cin >> cas;
        mod_grid(tab,mine,inp,cas);
        display_game(tab);
        switch (cas){
            case 1:
                if (check_mine(mine,inp.row,inp.col) == 1){
                    cout << "\nC'est perdu !"<<endl;
                    return 0;
                }
                else{
                    cout << "\nC'est gagné !"<<endl;
                }
                break;

            case 2:
                cout << "Vous avez marquer la case " <<inp.row<<" "<<inp.col<<endl;
                mark_mine(marked,inp.row,inp.col);
                break;
            case 3:
                cout << "Saisie annulé !"<<endl;
                break;
            default:
                cout << "Saisie incorrect !"<<endl;
                break;
        }
        
    }
    
}