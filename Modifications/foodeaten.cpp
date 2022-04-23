#include <iostream>

#include "foodeaten.h"

using namespace std;

bool foodeaten(string board[][50], int foodposition[]){
    if (board[foodposition[0]][foodposition[1]]=="O"){
        return true;
    }
    else
      return false;
}