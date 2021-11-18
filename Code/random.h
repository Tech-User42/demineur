#include <stdlib.h>     /* srand, rand */
#include <time.h> // Pour le time(null).
#define limit 10 // Limite de dimensions de game.
int init_rand(); // A run au moins 1 fois avant gen_random().
int gen_random(); // Return un nombre aléatoire.