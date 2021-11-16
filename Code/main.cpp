#include <iostream>
#include <string>

#include "console.h"
#include "game.h"

using namespace std;


int main(int argc, char** argv){
    int display[limit][limit] ;
    int mine[limit][limit] ;
    setup_screen(); // Définition des Colonnes et des lignes du terminal
    create_tab(display); // Fill le tableau display avec des 0
    create_tab(mine); // Fill le tableau mine avec des 0
    create_mines(mine); // Place les mines
    title(); // Display Title
    if(argv[1] == "--cheats"s){
        cout << "CHEAT ACTIIVATED !"<<endl<<endl;
        display_grid(mine);
    }
    play(display,mine); // Start la game

    
    
    return(0);
}