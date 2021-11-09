#include <iostream>
#include <string>
#include "console.h"
#include "game.h"
using namespace std;


int main(){

    char grid_start[limit][limit];
    char grid_mine[limit][limit];
    char tab1[limit][limit] ;
    char tab2[limit][limit] ;
    make_grid(tab1,'-');
    make_grid(tab2,'*');
    display_game(tab1);
    display_game(tab2);
    
    return(0);
}