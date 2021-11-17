/*
############ Librairie homemade ############
*/


struct entry{
        int row;
        int col;
    };
typedef struct {
        int row;
        int col;
        int out;
    }mine_detection;
void clear_screen(); // Clear la console
void setup_screen(); // Règle la taille du terminal

int choice();
entry input(entry inp);