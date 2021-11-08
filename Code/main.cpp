#include <iostream>
#include <string>
using namespace std;
string OverWrite(int x) {
    string s="";
    for(int i=0;i<x;i++){s+="\b \b";}
    return s;}

int main(){   
    cout<<"Lot's of ";
    cout<<"stuff"<<OverWrite(5)<<"\rTest à la con"<<"\n";  
    return(0);
}