/*************************************************************
* Nom ............ : Cout_Color_for_Linux Library
* Rôle ........... : Change colors in linux/MacOs terminal with a cout
* Auteur ......... : Ezio Cangialosi
* Date création .. : 16/11/2021
* Version/Màj .... : 
* Licence ........ : GPLv4
*************************************************************/

#include "color.h"

void setColor(int txtColor, int backgColor){ //Function to set the next cout color
    const unsigned short int colorLimit=7;
    //NB : 0-Black, 1-Red, 2-Green, 3-Orange, 4-Blue, 5-Magenta, 6-Cyan, 7-White, 9-Reset
    if (txtColor>colorLimit && backgColor>colorLimit){
        cout << ALL_RESET;
    }
    else if (txtColor>colorLimit && backgColor<colorLimit){
        cout << TXT_DEFAULT;
    }
    else if (backgColor>colorLimit && txtColor<colorLimit){
        cout << BACKG_DEFAULT;
    }
    else{
        cout << IDENT << txtColor+30 <<CLOSER<<IDENT<<backgColor+40<<CLOSER;
    }
}