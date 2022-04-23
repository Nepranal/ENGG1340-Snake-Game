#include <iostream>

#include "delete_prev_snake.h"
using namespace std;

void delete_prev_snake(int snakepos1, int snakepos2, string board[][50], int space){
    if(snakepos1==0||snakepos2==0||snakepos1==space-1||snakepos2==space-1){
        board[snakepos1][snakepos2]="#";
    }
    else{
        board[snakepos1][snakepos2]=" ";
    }
}