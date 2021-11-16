#include "display.h"
#include "console.h"
#include <fstream>
#include <string>
void title(){
    clear_screen();
    open_file("title.txt");
}
void open_file(string file){
    string line;
    ifstream myfile (file);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            cout << line <<'\n';
        //use line here
        }
        myfile.close();
    }

    else cout << "Unable to open file"; 
}
int game_over(){
    clear_screen();
    open_file("game_over.txt");
    return  1;
}    
void display_grid(int tab[limit][limit]){  // Affiche la grille de démineur passé en argument. Ligne Colonne 
    for(int i = 0 ; i < limit ; i++){
        for(int j = 0 ; j < limit ; j++){
            cout << tab[i][j]; // Double For pour print la grille du Tab 2D.
        }
        cout << "\n"; // Un ptit return pour afficher la grille correctement.
    }
    cout << "\n";
}   