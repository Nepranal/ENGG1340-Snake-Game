#include <iostream>

using namespace std;

#include "barrier_collision.h"


bool barrier_collision(string board[][50]){
    for (int i = 6; i < 19; i++){
        if (board[6][i] == "O" ){
            return true;
        }
        if (board[16][i]== "O" ){
            return true;
        }
    }

    for (int i = 2; i < 22; i++){
        if (board[i][3]== "O" ){
            return true;
        }
    }

    for (int i = 18; i < 22; i++){
        if (board[i][18]== "O" ){
            return true;
        }
    }

    for (int i = 14; i < 22; i++){
        if (board[22][i] == "O" ){
            return true;
        }
    }
    return false;
    // if (board[foodposition[0]][foodposition[1]]=="O"){
    //     return true;
    // }
    // else
    //   return false;
}