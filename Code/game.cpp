#include <iostream>
/*
############ Library homemade ############
*/
#include "game.h"
#include "random.h"
#include "color.h"
#include "display.h"
#include "console.h"
using namespace std;
bool all_checked(int checked[limit][limit],int mine[limit][limit]){ // Permet de savoir si la game est finie.
    unsigned short total = 0;
    for(unsigned short i = 0; i<limit;i++){
        for(unsigned short j = 0; j<limit;j++){
            if(mine[i][j]==9&&checked[i][j]==1){
                total++;
            } 
        }
    }
    return (total == 4); 

}
void create_tab(int tab[limit][limit]){ // Fill un tableau avec des 0.
    for(unsigned short i = 0; i<limit;i++){
        for(unsigned short j = 0; j<limit;j++){
            tab[i][j] = 0;
        }
    }
}
void create_mines(int tab[limit][limit]){
    for(unsigned short i = 0; i<4;i++){
        tab[gen_random()][gen_random()]=9; // Lignes Colonnes.
    }
}
void mark_mine(int tab[limit][limit],int marked[limit][limit],int x,int y){ // Replace la case creusée par un 6.
    marked[x][y] = 1; // Sert pour savoir si la game est finie.
    tab[x][y] = 6;
}
void creuser(int tab[limit][limit],int x,int y){ // Replace la case creusée par un 5.
    tab[x][y] = 5;
}
bool check_for_mine(int mine[limit][limit],int x , int y){
    return(mine[x][y] == 9); // Return True si il y a une mine.
}
void check_for_mine_around(int tab[limit][limit],int mine[limit][limit] ,unsigned short i, unsigned short j){
    for(unsigned short t = i -1; t<i+2;t++){ // Permet d'indiquer les mines dans un rayons de 1.
        for(unsigned short h = j - 1; h<j+2;h++){
            if(h > limit-1){ // Vérification pour ne pas sortir de la grille.
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
            if ((mine[t][h]!=9) && ((tab[t][h]!=6) && (tab[t][h]!=5))){
                tab[t][h] = 1; // Si une mine est dans un rayon de 1 de cette case on remplace la case par 1.
            } 
        }
    }
    cout << tab[i][j] << "  ";
}
void display_game(int tab[limit][limit],int mine[limit][limit],int x,int y){
    print_help(); // Affiche la légende/aide.
    setColor(4, 7); // Blue FG White BG.
    cout << "   ";
    for(int i = 0; i<limit;i++){
        cout << i << "  "; // Display des numéro de colonnes.
    }
    c_return();
    for(int i  = 0; i<limit;i++){
        setColor(4, 7); // Blue FG White BG.
        cout << i ; // Display des numéro de lignes.
        setColor(9, 9); // Reset des couleurs.
        cout << "  ";
        for(int j = 0; j<limit;j++){
            if(tab[i][j]==5){
                setColor(2, 3); // Blue FG White BG.
                cout << tab[i][j]; 
                setColor(9, 9); // Reset des couleurs.
                cout << "  ";
            }
            else if(tab[i][j]==6){
                setColor(5, 3); // Magenta FG White BG
                cout << tab[i][j]; 
                setColor(9, 9); // Reset des couleurs.
                cout << "  ";
            }
            else if (mine[i][j]==9){
                cout << tab[i][j] << "  "; // On display 0. 
            }
            else if(((x-i == 1) && (y-j == 1)) || ((x-i == -1) && (y-j == -1))){ // Bon basiquement cette section sert à ne pas sortir du tableau et afficher la proximitée avec les mines.
                check_for_mine_around(tab,mine,i,j);
            }
            else{
                cout << tab[i][j]<< "  "; // Sinon juste print le conetnue du tableau.
            }
        }
        c_return(); // Permet de faire le contour de la grille en bleu blanc.
    }
}

int play(int tab[limit][limit],int mine[limit][limit],int marked[limit][limit],bool cheat){
    entry inp; // On init la structure qui comporte inp.row et inp.col pour transférer 2 paramètres.
    bool the_end = false; // Flag pour la loop de game (à revoir ça me plait pas).
    while(!the_end){
        inp = input(inp); // On demande les coords avec la fonction structurée.
        clear_screen();
        switch(choice()){
            case 1:
                if (check_for_mine(mine,inp.row,inp.col)==1){ // Si le joueur à touché une mine on trigger le Game-Over.
                    the_end = game_over(tab,mine); // Trigger le Game-Over.
                    if(the_end==0){
                        if(cheat==0){
                            display_empty(); // Display Une grille full 0
                        }
                        else{
                            display_grid(mine); // Display la grille du cheat avec les mines affichées;
                        }
                    }
                    else{
                        setColor(9,9); // Reset des couleurs.
                    }                  
                }
                else{ // Sinon on continue de run la game en affichant la grille.
                    creuser(tab,inp.row,inp.col);
                    display_game(tab,mine,inp.row,inp.col); // On affiche la grille une fois l'entrée récupérée.
                }
                break;
            case 2:
                mark_mine(tab,marked,inp.row,inp.col); // Fill un tableau avec la position du flag.
                display_game(tab,mine,inp.row,inp.col); // On redisplay la game.
                break; 
            default:
                clear_screen(); // Par défaut clear la console, ne fais rien d'autres.
                break;
        }
        if(all_checked(marked,mine)){ // Check si toutes les mines sont marquées.
            setColor(7,0);
            clear_screen();
            you_win();
            the_end = 1;
        }
    }
    return 0;
}