#include <iostream>
/*
############ Library homemade ############
*/
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
    cout << endl << "Entrez les coordon\202es d'une case (Ligne de 0 \205 "<<limit-1<<" --> Colonne de 0 \205 "<<limit-1<<"): ";
    scanf("%d %d",&inp.row ,&inp.col);
    cout << "Vous avez choisi la case "<<inp.row<<" "<<inp.col<<endl;
    return inp;
}

int choice(){
    unsigned short choice;
    cout << "Que souhaitez vous faire : 1- Creuser 2- Marquer 3- Annuler : ";
    cin >> choice;
    return choice;
}
