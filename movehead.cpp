#include <iostream>

#include <vector>
using namespace std;


#include "delete_prev_snake.h"
#include "snake_position_regulator.h"

void movehead(char move,int prevpos[], vector<vector<int>> &snake_position, string board[][50], int space){
    int old_snake1=0,old_snake2=0,new_snake1=0,new_snake2=0;
    prevpos[0]=snake_position[0][0];
    prevpos[1]=snake_position[0][1];
    old_snake1=prevpos[0];
    old_snake2=prevpos[1];
    
    delete_prev_snake(old_snake1,old_snake2, board,space);

    new_snake1=old_snake1;
    new_snake2=old_snake2;
    if(move=='W'){
        new_snake1 = old_snake1-1;
    }
    else if(move == 'S'){
        new_snake1 = old_snake1+1;
    }
    else if(move=='A'){
        new_snake2= old_snake2-1;
    }
    else if(move=='D'){
        new_snake2=old_snake2+1;
    }
    
    snake_position_regulator(new_snake1,new_snake2, space);
    snake_position[0][0]=new_snake1;
    snake_position[0][1]=new_snake2;
}