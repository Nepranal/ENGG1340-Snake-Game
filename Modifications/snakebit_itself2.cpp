#include <iostream>
#include <vector>
#include "snakebit_itself2.h"

using namespace std;

bool snakebit_itself2(int snake_length, vector<vector<int>> snake_position){
    int pos1=snake_position[0][0],pos2=snake_position[0][1];
    for(int i=1;i<snake_length;++i){
        int snakepos1=snake_position[i][0], snakepos2=snake_position[i][1];
        if(pos1==snakepos1 &&  pos2 == snakepos2)
          return true;
    }
    return false;
}