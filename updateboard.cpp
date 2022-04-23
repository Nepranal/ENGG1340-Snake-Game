#include <iostream>
#include <vector>
#include "updateboard.h"

using namespace std;



void updateboard(std::vector<std::vector<int>> snake_position, string board[][50]){
    int x,y;
    for(int i=0;i<snake_position.size();++i ){
        x=snake_position[i][0];
        y=snake_position[i][1];
        board[x][y]="O";
    }
}