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

void mod_grid(char tab[limit][limit],char mine[limit][limit] ,entry inp,int cas){  // Affiche la grille de démineur passé en argument.
    for(int i = inp.row -1; i < inp.row + 1 ; i++){ // [DeHautEnBas][DeGaucheADroite]
        for(int j = inp.col -1 ; j < inp.col +1 ; j++){ // [DeHautEnBas][DeGaucheADroite]
            if(i< 0){
                i = 0;
            }
            else if(i> 19){
                j = 19;
            }
            if(j< 0){
                j = 0;
            }
            else if(j > 19){
                j = 19;
            }
            
            if (check_mine(mine,inp.row,inp.col) == 0 && cas == 1){
                   tab[i][j] = check_mine_around(tab,mine,i,j).out; // Double For pour print la grille du Tab 2D. 
                }
            
        }
        cout << "\n"; // Un ptit return pour afficher la grille correctement
    }
}
void decouvrir_carre(char V[20][20], char M[20][20], int m, int n, int i, int j){
	if(V[i][j]=='-')
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

mine_detection check_mine_around(char tab[limit][limit],char mine[limit][limit], int ii ,int jj){
    mine_detection output;
    output.out = '0';
    if(mine[ii-1][jj-1] == '*'){ // En haut à Gauche
        output.out = '1';
    }
    if(mine[ii-1][jj+1] == '*'){ // En haut à Droite
        output.out = '1';
    }
    if(mine[ii-1][jj] == '*'){ // En haut au milieu
        output.out = '1';
    }
    if(mine[ii+1][jj-1] == '*'){ // En bas à gauche
        output.out = '1';
    }
    if(mine[ii+1][jj+1] == '*'){ // En bas à droite
        output.out = '1';
    }
    if(mine[ii+1][jj] == '*'){ // En bas au milieu
        output.out = '1';
    }
    if(mine[ii][jj-1] == '*'){ // A gauche
        output.out = '1';
    }
    if(mine[ii][jj+1] == '*'){
        output.out = '1';
    }
    return output;
}

entry input(entry inp){
    cout << endl << "\rEntrez les coordonées d'une case : ";
    scanf("%d %d",&inp.row ,&inp.col);
    cout << "\rVous avez choisi la case "<<inp.row<<" "<<inp.col;
    return inp;
}

int choice(){
    int choice;
    cin >> choice;
    return choice;
}
