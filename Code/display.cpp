#include <fstream>
#include <string>
/*
############ Library homemade ############
*/
#include "display.h"
#include "console.h"
#include "color.h"
#include "random.h"
#include "game.h"

void title(){
    clear_screen();
    open_file("Fonts\\title.txt");
}
void open_file(string file){
    string line;
    ifstream myfile (file);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            cout << line <<'\n';

        }
        myfile.close();
    }

    else cout << "Unable to open file"; 
}
int game_over(int display[limit][limit],int mine[limit][limit]){
    clear_screen();
    string retry;
    setColor(1, 3); // Blue FG White BG.
    cout << "Vous avez touch\202 une mine, voulez vous relancer une partie ? (O/N) ";
    cin >> retry;
    if(retry=="o"||retry=="O"||retry=="y"||retry=="Y"){
        setColor(9, 9); // Blue FG White BG.
        clear_screen();
        create_tab(display); // Fill le tableau display avec des 0.
        create_tab(mine); // Fill le tableau mine avec des 0.
        create_mines(mine); // Place les mines.
        return  0;
    }
    else{
        setColor(9, 9); // Blue FG White BG.
        clear_screen();
        open_file("Fonts\\game_over.txt");
        return  1;
    }
    
}

void c_return(){ // Fonction de retour en couleur pour faire le contour en bleu et blanc.
    cout << endl;
    setColor(4, 7); // Blue FG White BG. 
    cout << " "<<endl;
    setColor(9, 9); // Blue FG White BG. 
}

void display_grid(int tab[limit][limit]){  // Affiche la grille de démineur passé en argument. Ligne Colonne.
setColor(4, 7); // Blue FG White BG.
cout << "   ";
    for(unsigned short i = 0; i<limit;i++){
            
            cout << i << "  "; 
    }
    cout << endl << " \n";
    for(unsigned short i = 0 ; i < limit ; i++){
        setColor(4, 7); // Blue FG White BG.
        cout << i ;
        setColor(9, 9); // Reset des couleurs.
        cout << "  ";
        for(unsigned short j = 0 ; j < limit ; j++){
            if(tab[i][j]==9){
                setColor(4,1); // Vert sur Rouge.
                cout << tab[i][j] ; // Double For pour print la grille du Tab 2D.
                setColor(9,9); //  Reset des couleurs.
                cout << "  ";
            }
            else{
                cout << tab[i][j] << "  ";
            } 
        }
        cout << "\n"; // Un ptit return pour afficher la grille correctement.
        setColor(4, 7); // Blue FG White BG.
        cout << " \n" ;
        setColor(9, 9); // Reset des couleurs.
    }
    cout << "\n\n";
}   
void display_empty(){  // Affiche la grille de démineur passé en argument. Ligne Colonne.
setColor(4, 7); // Blue FG White BG.
cout << "   ";
    for(unsigned short i = 0; i<limit;i++){
            cout << i << "  "; 
    }
    cout << endl << " \n";
    for(unsigned short i = 0 ; i < limit ; i++){
        setColor(4, 7); // Blue FG White BG.
        cout << i ;
        setColor(9, 9); // Reset des couleurs.
        cout << "  ";
        cout << 0;
        for(unsigned short j = 0 ; j < limit ; j++){
            cout << "  ";
            cout << 0;
        }
        cout << "\n"; // Un ptit return pour afficher la grille correctement.
        setColor(4, 7); // Blue FG White BG.
        cout << " \n" ;
        setColor(9, 9); // Reset des couleurs.
    }
    cout << "\n\n";
}   