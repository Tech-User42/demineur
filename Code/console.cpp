#include <iostream>
#include "console.h"
#include "game.h"
using namespace std;

void setup_screen(){
    cout << "\e[8;150;150t"; // Définition Ligne et Colonne du terminal.
}
void clear_screen(){
    //cout <<  "\x1B[2J\x1B[H" << "\n"; // Clear the entire screen !
    system("cls");
}


void display_game(char tab[limit][limit]){  // Affiche la grille de démineur passé en argument.
    for(int i = 0 ; i < limit ; i++){
        for(int j = 0 ; j < limit ; j++){
            cout << tab[i][j]; // Double For pour print la grille du Tab 2D.
        }
        cout << "\n"; // Un ptit return pour afficher la grille correctement
    }
}


void decouvrir_carre(bool V[20][20], int M[20][20], int m, int n, int i, int j){
	if(V[i][j]==false)
	{		
		V[i][j]=true;
		if(M[i][j]!='*')
		{
			if(i>0) {decouvrir_carre(V, M, m, n, i-1, j); }
			if(i>0 && j>0) {decouvrir_carre(V, M, m, n, i-1, j-1);}
			if(j>0) {decouvrir_carre(V, M, m, n, i, j-1);}
			if(j>0 && i<m-1) {decouvrir_carre(V, M, m, n, i+1, j-1);}
			if(i<m-1) {decouvrir_carre(V, M, m, n, i+1, j);}
			if(i>m-1 && j<n-1) {decouvrir_carre(V, M, m, n, i+1, j+1);}
			if(j<n-1) {decouvrir_carre(V, M, m, n, i, j+1);}
			if(i>0 && j<n-1) {decouvrir_carre(V, M, m, n, i-1, j+1);}
		}
	}
}


entry input(entry inp){
    cout << endl << "\rEntrez les coordonées d'une case : ";
    scanf("%d %d",&inp.row ,&inp.col);
    cout << "\rVous avez choisi la case "<<inp.row<<" "<<inp.col<<endl;
    return inp;
}

int choice(){
    int choice;
    cin >> choice;
    return choice;
}
