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

void c_return(){ // Fonction de retour en couleur pour faire le contour en bleu et blanc
    cout << endl;
    setColor(4, 7); // Blue FG White BG 
    cout << " "<<endl;
    setColor(9, 9); // Blue FG White BG 
}

void display_grid(int tab[limit][limit]){  // Affiche la grille de démineur passé en argument. Ligne Colonne
setColor(4, 7); // Blue FG White BG
cout << "   ";
    for(int i = 0; i<limit;i++){
            
            cout << i << "  "; 
    }
    cout << endl;
    for(int i = 0 ; i < limit ; i++){
        setColor(4, 7); // Blue FG White BG
        cout << i ;
        setColor(9, 9); // Reset des couleurs
        cout << "  ";
        for(int j = 0 ; j < limit ; j++){
            cout << tab[i][j] << "  "; // Double For pour print la grille du Tab 2D.
        }
        cout << "\n"; // Un ptit return pour afficher la grille correctement.
        setColor(4, 7); // Blue FG White BG
        cout << " \n" ;
        setColor(9, 9); // Reset des couleurs
    }
    cout << "\n\n";
}   