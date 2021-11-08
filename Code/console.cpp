#include <iostream>
#include "console.h"
using namespace std;


void clear_screen(){
    cout <<  "\x1B[2J\x1B[H" << "\n"; // Clear the entire screen !
}

const int limit = 10;

void display_game(int tab[][], const int limit){
    for(int i = 0 ; i < limit ; i++){
        for(int j = 0 ; j < limit ; j++){
        cout << tab[i][j];
        }
    }
}
int tab[10][10];

display_game();