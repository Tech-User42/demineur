/*************************************************************
* Nom ............ : DEMINEUR VERSION CONSOLE EN C++
* Rôle ........... : Jouer au démineur en version shell
* Auteur ......... : Théo MARECHAL
* Date création .. : 2021
* Version/Màj .... : 0.1
* Licence ........ : GPLv4
*************************************************************/
/*
############ Library homemade ############
*/
#include "main.h"




void setup_game(int display[limit][limit],int mine[limit][limit],int marked[limit][limit]){
    init_rand();
    setup_screen(); // Définition des Colonnes et des lignes du terminal.
    create_tab(display); // Fill le tableau display avec des 0.
    create_tab(mine); // Fill le tableau mine avec des 0.
    create_tab(marked); // Fill le tableau mine avec des 0.
    create_mines(mine); // Place les mines.
    title(); // Display Title.
    
}

int main(int argc,  char *argv[]){
    int display[limit][limit];
    int mine[limit][limit];
    int marked[limit][limit];
    bool cheat = 0;
    setup_game(display,mine,marked);
    if ((argc > 1) == 1){ // Check si un argument est passé en argument.
        if(string(argv[1]) == "--cheats"){ // Check si le 1er argument est --cheats.
            setColor(4,1); // Vert sur Rouge.
            cout << "      CODE DE TRICHE ACTIF !     "<<endl<<endl;
            setColor(9,9); // Vert sur Rouge.
            display_grid(mine); // Display de la grille de mine.
            cheat = 1;
        }
        else{
            display_grid(display); // Display de la grille de mine.
        }
        
    }
    else{
        display_grid(display); // Display de la grille de mine.
    }
    play(display,mine,marked,cheat); // Start la game.
    return(0);
}
