#include "random.h"

int init_rand(){
    srand (time(NULL));
    return 0;
}

int random(){
    return (rand() % (limit-1) + 1);
}
