#include <iostream>
#include <cstdlib>
#include <ctime>

#include <vector>

using namespace std;

vector <vector<int>> snake_position={};
int space=0, foodposition[2]={{}};
string board[50][50]={};


#include "createboard.h"
#include "printboard.h"
#include "updateboard.h"
#include "spawnfood.h"
#include "gameover.h"
#include "play.h"


int main(){
    space=25;
    snake_position.push_back({space/2,space/2});
    createboard(space,board);
    updateboard(snake_position,board);
    spawnfood(space, foodposition,board);
    printboard(space,board);
    play(space,board, snake_position, foodposition);
    gameover(space,board);

    return 0;
}
