#include "random.h"

int init_rand(){ // Init du random avec le timestamp, nécessaire de le faire au moins une fois avant d'utiliser gen_random().
    srand (time(NULL));
    return 0;
}

int gen_random(){ // Return un nombre entre 0 et limit-1 (0-->9).
    return (rand() % (limit-1));
}
