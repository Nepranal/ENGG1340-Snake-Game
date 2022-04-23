#include <iostream>

#include <vector>
using namespace std;

#include "delete_prev_snake.h"

void movebody(int i,int prevpos[],int snakelength, vector<vector<int>> &snake_position,string board[][50], int space){
        int old_snake1,old_snake2,new_snake1,new_snake2;
        old_snake1=snake_position[i][0];
        old_snake2=snake_position[i][1];
        delete_prev_snake(old_snake1,old_snake2, board, space);
        new_snake1=prevpos[0];
        new_snake2=prevpos[1];
        snake_position[i][0]=new_snake1;
        snake_position[i][1]=new_snake2;
        prevpos[0]=old_snake1;
        prevpos[1]=old_snake2;
    }