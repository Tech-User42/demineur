#include <iostream>
/*
############ Library homemade ############
*/
#include "console.h"
using namespace std;

void create_tab(int tab[limit][limit]){ // Fill un tableau avec des 0.
    for(unsigned short i = 0; i<limit;i++){
        for(unsigned short j = 0; j<limit;j++){
            tab[i][j] = 0;
        }
    }
}
void create_mines(int tab[limit][limit]){
    tab[1][0]=9; // Lignes Colonnes.
    tab[2][0]=9; // Lignes Colonnes.
}
bool check_for_mine(int mine[limit][limit],int x , int y){
    return mine[x][y] == 9; // Return True si il y a une mine.
}

void display_game(int tab[limit][limit],int mine[limit][limit],int x,int y){
    tab[x][y] = 5; // Replace du point par 5.
    setColor(4, 7); // Blue FG White BG.
    cout << "   ";
    for(unsigned short i = 0; i<limit;i++){
        cout << i << "  "; // Display des numéro de colonnes.
    }
    c_return();
    for(unsigned short i = 0; i<limit;i++){
        setColor(4, 7); // Blue FG White BG.
        cout << i ; // Display des numéro de lignes.
        setColor(9, 9); // Reset des couleurs.
        cout << "  ";
        for(unsigned short j = 0; j<limit;j++){
            if(tab[i][j]==5){
                setColor(2, 3); // Blue FG White BG.
                cout << tab[i][j]; 
                setColor(9, 9); // Reset des couleurs.
                cout << "  ";
            }
            else if (mine[i][j]!=9){
                cout << tab[i][j] << "  "; // On display 0. 
            }
            else if((x-i == 1) && (y-j == 1) || (x-i == -1) && (y-j == -1)){ // Bon basiquement cette section sert à ne pas sortir du tableau et afficher la proximitée avec les mines.
                for(unsigned short t = i -1; t<i+2;t++){
                    for(unsigned short h = j - 1; h<j+2;h++){
                        if(h > limit-1){
                            h = limit-1;
                        }
                        if(t > limit-1){
                            t = limit-1;
                        }
                        if(h < 0){
                            h = 0;
                        }
                        if(t < 0){
                            t = 0;
                        }
                        if (mine[t][h]!=9){
                            tab[t][h] = 1;
                        } 
                    }
                }
                cout << tab[i][j] << "  ";
            }
            else{
                cout << tab[i][j]<< "  ";
            }
        }
        c_return();
    }
}

int play(int tab[limit][limit],int mine[limit][limit]){
    entry inp; // On init la structure qui comporte inp.row et inp.col pour transférer 2 paramètres.
    bool the_end = false; // Flag pour la loop de game (à revoir ça me plait pas).
    while(!the_end){
        inp = input(inp); // On demande les coords avec la fonction structurée.
        clear_screen();
        if (check_for_mine(mine,inp.row,inp.col)){ // Si le joueur à touché une mine on trigger le Game-Over.
            the_end = game_over(); // Trigger le Game-Over.
        }
        else{ // Sinon on continue de run la game en affichant la grille
            display_game(tab,mine,inp.row,inp.col); // On affiche la grille une fois l'entrée récupérée.
        }
    }
    return 0;
}