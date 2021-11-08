#include <iostream>
#include <string>
#include "console.h"
using namespace std;


int main(){  
    string input; 
    int i = 0;
    cout<<"Ce texte sera remplacé si vous entrez O" << "\n" ;
    cin >> input;
    if(input == "o" || input == "o"){
        cout<<"\rTexte effacé !"<<"\n"<< flush;
    }
    else{
        cout<<"Sayonnara"<<"\n";  
    }
    while(1){
        cout<<"\r"<<i<< "\n" ;
        clear_screen();
        i++;
    }
    return(0);
}