#include <iostream>
#include "console.h"
using namespace std;
void create_tab(int tab[limit][limit]){
    for(int i = 0; i<limit;i++){
        for(int j = 0; j<limit;j++){
            tab[i][j] = 0;
        }
    }
}
void create_mines(int tab[limit][limit]){
    tab[1][0]=9; // Lignes Colonnes
    tab[2][0]=9; // Lignes Colonnes
}
void display_tab(int tab[limit][limit],int mine[limit][limit],int x,int y){
    tab[x][y] = 5;
    for(int i = 0; i<limit;i++){
        for(int j = 0; j<limit;j++){
            if (mine[i][j]!=9){
                cout << tab[i][j];
            }
            else if((x-i == 1) && (y-j == 1) || (x-i == -1) && (y-j == -1)){
                for(int t = i -1; t<i+2;t++){
                    for(int h = j - 1; h<j+2;h++){
                        if(h > 19){
                            h = 19;
                        }
                        if(t > 19){
                            t = 19;
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
                cout << tab[i][j];
            }
            else{
                cout << tab[i][j];
            }
        }
    
        cout << endl;
    }
}
int play(int tab[limit][limit],int mine[limit][limit]){
    entry inp;
    inp = input(inp);
    clear_screen();
    display_tab(tab,mine,inp.row,inp.col);

   
    return 0;
}