#include <iostream>
#include <ctime>

#include "spawnpoison.h"

using namespace std;

#define CLUB "\xE2\x99\xA3"
#define BARRIER "\xE2\x98\x92"
#define DIAMOND "\xE2\x99\xA6"


void spawnpoison(int space, int poisonposition[], string board[][50], int score, int poison[][50]){
    if ((score > 3) && (score % 2 != 0)){
        int random_point1=rand()%space,random_point2=rand()%space;
        while(board[random_point1][random_point2] == "#" || board[random_point1][random_point2] == BARRIER ||board[random_point1][random_point2] == CLUB ){ 
            random_point1=rand()%space;
            random_point2=rand()%space;
        }
        poisonposition[0]=random_point1;
        poisonposition[1]=random_point2;
        board[random_point1][random_point2]= DIAMOND;
        poison[random_point1][random_point2]= -1;
    }
    if (score % 3 == 0){
        for(int i=0;i<space;++i){
            for(int j=0;j<space;++j){
                if (board[i][j] == DIAMOND){
                    board[i][j] = " ";
                    poison[i][j] = 0;
                }
            }
        }
    }
}
