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

void input(){
    int a , b ;
    cout << endl << "\rEntrez les coordonées d'une case : ";
    scanf("%d %d",&a ,&b);
    cout << "\rVous avez choisi la case "<<a<<" "<<b;
}
