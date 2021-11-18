/*
############ Librairie homemade ############
*/


struct entry{
        int row;
        int col;
    }; // Définition de la structure de la position du curseur.


void clear_screen(); // Clear la console.
void setup_screen(); // Règle la taille du terminal. (Bugué)

int choice(); // Choix de l'action à effectuée  Creuser Marquer Rien.
entry input(entry inp); // Fonction de récupération des coordonées.