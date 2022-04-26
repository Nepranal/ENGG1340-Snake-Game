#include <iostream>
#include "spawnfood.h"

using namespace std;
#define CLUB "\xE2\x99\xA3"
#define BARRIER "\xE2\x98\x92"
#define DIAMOND "\xE2\x99\xA6"
#define HEART   "\xE2\x99\xA5"


void spawnfood(int space, int foodposition[], string board[][50]){
    srand(time(NULL));
    int random_point1=rand()%space,random_point2=rand()%space;
    while(board[random_point1][random_point2] == "#" || board[random_point1][random_point2] == BARRIER || board[random_point1][random_point2] == DIAMOND || board[random_point1][random_point2] == HEART){
        random_point1=rand()%space;
        random_point2=rand()%space;
    }
    foodposition[0]=random_point1;
    foodposition[1]=random_point2;
    board[random_point1][random_point2]= CLUB;
}