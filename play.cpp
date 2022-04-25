#include <iostream>
#include <vector>

using namespace std;


#include "movesnake.h"
#include "updateboard.h"
#include "snakebit_itself2.h"
#include "foodeaten.h"
#include "inc_snake.h"
#include "spawnfood.h"
#include "updateboard.h"
#include "printboard.h"
#include "barrier_collision.h"

void play(int space, string board[][50], vector<vector<int>> &snake_position, int foodposition[], int& score, string gamemode){
    int snakelength=1,prevpos[2]={};
    char move;
    cout << "Score : " << score << endl;
    cout<<"W A S D? ";
    cin>>move;
    move=toupper(move);

    while(move != '1'){
      movesnake(move,snakelength,prevpos, snake_position, board, space);
      updateboard(snake_position,board);
      if (gamemode == "1"){
        if (snakebit_itself2(snakelength,snake_position)==true)
        break;
      }
      else if ( gamemode == "2" || gamemode =="3"){
        if (snakebit_itself2(snakelength,snake_position)==true || barrier_collision(board)==true)
        break;
      }
      if(foodeaten(board,foodposition)==true){
          inc_snake(snakelength,prevpos,snake_position);
          spawnfood(space,foodposition,board);
          snakelength++;
          score++;
      }
      updateboard(snake_position,board);
      printboard(space,board);
      cout << "Score : " << score << endl;
      cout<<"W A S D? ";
      cin>>move;
      move=toupper(move);
    }
}