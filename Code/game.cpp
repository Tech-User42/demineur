#include "game.h"

void make_grid(char tab[limit][limit],char symbole){ // Fill les tableaux passé en argument avec le symbole passé en argument.
     for (int row = 0; row < limit; row++)
    {
        for (int col=0; col < limit; col++) // Double for pour fill le tab 2D
        {
            tab[row][col] = symbole; // Fill du tab avec symbole
        }
    }
    
}
