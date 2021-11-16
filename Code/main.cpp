#include <iostream>
#include <string>
#include "console.h"
#include "game.h"
using namespace std;


int main(){
    string nothing;
    char grid_start[limit][limit]; // limite de  20
    char grid_mine[limit][limit];
    bool tab1[limit][limit] ;
    char tab2[limit][limit] ;
    char tab3[limit][limit] ;
    setup_screen();
    make_grid(tab1,'-');
    make_grid2(tab3,'-');
    make_mine_grid(tab3,'*');
    //display_game(tab3);
    //display_game(tab3);
    play(tab1,tab3);
    //cin >> nothing;
    //display_game(tab3);
    
    //clear_screen();
    
    
    return(0);
}