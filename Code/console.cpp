/*************************************************************
* Nom ............ : console.cpp
* Rôle ........... : Gérer la console en fonction du S.E
* Auteur ......... : Alex.P
* Date création .. : 2021
* Version/Màj .... : 0.1
*************************************************************/
#include <iostream>
/*
############ Library homemade ############
*/
#include "console.h"
#include "game.h"
#include "display.h"
#include "color.h"
using namespace std;

void setup_screen(){
    #ifdef linux // Parce que unifier les systèmes serait trop sympa...
    cout << "\e[8;150;155t"; // Définition Ligne et Colonne du terminal.
    #endif
    
}
void clear_screen(){ // Clear la console en fonction du S.E.
    #ifdef linux // Parce que unifier les systèmes serait trop sympa...
    system("clear"); 
    #endif
    #ifdef _WIN32
    system("cls");
    #endif

}




entry input(entry inp){ // Gère l'entrée utilisateur.
    cout << endl << "Entrez les coordon\202es d'une case (Ligne de 0 \205 "<<limit-1<<" --> Colonne de 0 \205 "<<limit-1<<"): ";
    cin >> inp.row;
    cout << " ";
    cin.ignore();
    cin >> inp.col;
    cout << "Vous avez choisi la case "<<inp.row<<" "<<inp.col<<endl;
    return inp;
}

int choice(){ // Choix de l'action.
    unsigned short choice;
    cout << "Que souhaitez vous faire : 1- Creuser 2- Marquer 3- Annuler : ";
    cin >> choice;
    cin.ignore();
    cout << "\n";
    return choice;
}
