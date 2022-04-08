#include <iostream>

using namespace std;

void snake_position_regulator(int & snakepos1,int &snakepos2, int space){
    if(snakepos1<0){
        snakepos1+=space;
    }
    if(snakepos2<0){
        snakepos2+=space;
    }
    snakepos1%=space;
    snakepos2%=space;
}