#include <iostream>
#include "console.h"
using namespace std;


void clear_screen(){
    cout <<  "\x1B[2J\x1B[H" << "\n"; // Clear the entire screen !
}
