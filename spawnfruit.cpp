#include <iostream>
#include <ctime>

#include "spawnfruit.h"

using namespace std;

#define CLUB "\xE2\x99\xA3"
#define BARRIER "\xE2\x98\x92"
#define DIAMOND "\xE2\x99\xA6"
#define HEART   "\xE2\x99\xA5"


void spawnfruit(int space, int fruitposition[], std::string board[][50], int score){
    int count=0;

    for(int i=0;i<space;++i){
        for(int j=0;j<space;++j){
            if (board[i][j] == HEART){
                count++;
            }
        }
    }

    if (score % 5 == 0 && count == 0){
        int random_point1=rand()%space,random_point2=rand()%space;
        while(board[random_point1][random_point2] == "#" || board[random_point1][random_point2] == BARRIER || board[random_point1][random_point2] == CLUB || board[random_point1][random_point2] == DIAMOND ){ 
            random_point1=rand()%space;
            random_point2=rand()%space;
        }
        fruitposition[0]=random_point1;
        fruitposition[1]=random_point2;
        board[random_point1][random_point2]= HEART;
    }

    if (score % 4 == 0){
        for(int i=0;i<space;++i){
            for(int j=0;j<space;++j){
                if (board[i][j] == HEART){
                    board[i][j] = " ";
                }
            }
        }
    }
    
}