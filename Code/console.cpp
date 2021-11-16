#include <iostream>
#include "console.h"
#include "game.h"
#include "display.h"
using namespace std;

void setup_screen(){
    #ifdef linux // Parce que unifier les systèmes serait trop sympa...
    cout << "\e[8;150;155t"; // Définition Ligne et Colonne du terminal.
    #endif
    
}
void clear_screen(){
    #ifdef linux // Parce que unifier les systèmes serait trop sympa...
    system("clear"); 
    #endif
    #ifdef _WIN32
    system("cls");
    #endif
}




entry input(entry inp){
    cout << endl << "Entrez les coordonées d'une case (Ligne de 0 à 19 --> Colonne de 0 à 19): ";
    scanf("%d %d",&inp.row ,&inp.col);
    cout << "Vous avez choisi la case "<<inp.row<<" "<<inp.col<<endl;
    return inp;
}

int choice(){
    int choice;
    cin >> choice;
    return choice;
}
