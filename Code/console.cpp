#include <iostream>
#include "console.h"
#include "game.h"
using namespace std;

void setup_screen(){
    cout << "\e[8;150;150t"; // Définition Ligne et Colonne du terminal.
}
void clear_screen(){
    cout <<  "\x1B[2J\x1B[H" << "\n"; // Clear the entire screen !
}


void display_game(char tab[limit][limit]){  // Affiche la grille de démineur passé en argument.
    for(int i = 0 ; i < limit ; i++){
        for(int j = 0 ; j < limit ; j++){
            cout << tab[i][j]; // Double For pour print la grille du Tab 2D.
        }
        cout << "\n"; // Un ptit return pour afficher la grille correctement
    }
}
void mod_grid(char tab[limit][limit],char mine[limit][limit] ,entry inp,int cas){  // Affiche la grille de démineur passé en argument.
    for(int i = 0 ; i < limit ; i++){
        for(int j = 0 ; j < limit ; j++){
            if (check_mine(mine,inp.row,inp.col) == 0 && cas == 1){
                   tab[i][j] = check_mine_around(tab,mine,i,j).out; // Double For pour print la grille du Tab 2D. 
                }
            
        }
        cout << "\n"; // Un ptit return pour afficher la grille correctement
    }
}
mine_detection check_mine_around(char tab[limit][limit],char mine[limit][limit], int ii ,int jj){
    mine_detection output;
    output.out = '0';

     for(int i = ii -1; i < ii + 1 ; i++){
        for(int j = jj - 1 ; j < jj + 1 ; j++){
            if(mine[i][j] == '*'){
                output.row = i;
                output.col = j;
            }
        }
     }
    return output;
}

entry input(entry inp){
    cout << endl << "\rEntrez les coordonées d'une case : ";
    scanf("%d %d",&inp.row ,&inp.col);
    cout << "\rVous avez choisi la case "<<inp.row<<" "<<inp.col;
    return inp;
}

int choice(){
    int choice;
    cin >> choice;
    return choice;
}
