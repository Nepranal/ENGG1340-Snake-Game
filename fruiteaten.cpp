#include <iostream>

#include "fruiteaten.h"

using namespace std;

bool fruiteaten(string board[][50], int fruitposition[]){
    if (board[fruitposition[0]][fruitposition[1]] == "O"){
        fruitposition[0] = 0;
        fruitposition[1] = 0;
        return true;
    }
    else
      return false;
}