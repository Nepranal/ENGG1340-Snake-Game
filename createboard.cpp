#include <iostream>
#include "createboard.h"

using namespace std;


void createboard(int space, string board[][50]){
    for(int i=0;i<space;++i){
        for(int j=0;j<space;++j){
            if (i==0 || i==space-1){
                board[i][j]="#";
            }
            else{
                if(j==0 || j==space-1){
                    board[i][j]="#";
                }
                else{
                    board[i][j]=" ";
                }
            }
        }
    }
}