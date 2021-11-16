#include <iostream>
#include <string>
#include "console.h"
#include "game.h"
using namespace std;


int main(){
    bool display[limit][limit] ;

    int mine[limit][limit] ;
    cout << "0 0";
    setup_screen();

    create_tab(display);
    create_mines(mine);
    play(display,mine);

    
    
    return(0);
}