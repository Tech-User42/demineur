#include <iostream>
#include "console.h"
using namespace std;


void clear_screen(){
    cout <<  "\x1B[2J\x1B[H" << "\n"; // Clear the entire screen !
}

const int limit = 10;
int tab2[10][10];
void display_game(int tab[][], const int limit2){
    for(int i = 0 ; i < limit2 ; i++){
        for(int j = 0 ; j < limit2 ; j++){
        cout << tab[i][j];
        }
    }
}


display_game(tab2,limit);