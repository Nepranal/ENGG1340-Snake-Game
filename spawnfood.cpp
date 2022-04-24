#include <iostream>
#include "spawnfood.h"

using namespace std;
#define CLUB "\xE2\x99\xA3"

void spawnfood(int space, int foodposition[], string board[][50]){
    srand(time(NULL));
    int random_point1=rand()%space,random_point2=rand()%space;
    while(board[random_point1][random_point2]=="#"){
        random_point1=rand()%space;
        random_point2=rand()%space;
    }
    foodposition[0]=random_point1;
    foodposition[1]=random_point2;
    board[random_point1][random_point2]= CLUB;
}