#include <iostream>
#include <vector>
#include "movehead.h"
#include "movebody.h"


using namespace std;

#include "movehead.h"
#include "movebody.h"

void movesnake(char move, int snakelength,int prevpos[], std::vector<std::vector<int>> &snake_position, std::string board[][50], int space){
    for(int i=0;i<snakelength;++i){
        if(i==0){
          movehead(move,prevpos, snake_position, board,space);
          }
        else 
          movebody(i,prevpos,snakelength, snake_position,board,space);
    }
}