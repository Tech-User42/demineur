/*************************************************************
* Nom ............ : DEMINEUR VERSION CONSOLE EN C++
* Rôle ........... : Jouer au démineur en version shell
* Auteur ......... : Théo MARECHAL
* Date création .. : 2021
* Version/Màj .... : 0.1
* Licence ........ : GPLv4
*************************************************************/
#include <iostream>
#include <string>
/*
############ Library homemade ############
*/
#include "console.h"
#include "game.h"

using namespace std;

int main(int argc,  char *argv[]){
    int display[limit][limit] ;
    int mine[limit][limit] ;
    setup_screen(); // Définition des Colonnes et des lignes du terminal.
    create_tab(display); // Fill le tableau display avec des 0.
    create_tab(mine); // Fill le tableau mine avec des 0.
    create_mines(mine); // Place les mines.
    title(); // Display Title.
    if ((argc > 1) == 1){ // Check si un argument est passé en argument.
        if(string(argv[1]) == "--cheats"){ // Check si le 1er argument est --cheats.
            cout << "CODE DE TRICHE ACTIF !"<<endl<<endl;
            display_grid(mine); // Display de la grille de mine.
        }
    }
    play(display,mine); // Start la game.
    return(0);
}