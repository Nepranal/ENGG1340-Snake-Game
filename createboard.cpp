#include <iostream>
#include "createboard.h"

using namespace std;
#define BARRIER "\xE2\x98\x92"

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

void special_createboard(int space, string board[][50]){
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

    for (int i = 6; i < 19; i++){
        board[6][i] = BARRIER;
        board[16][i] = BARRIER;
    }

    for (int i = 2; i < 22; i++){
        board[i][3] = BARRIER;
    }

    for (int i = 18; i < 22; i++){
        board[i][18] = BARRIER;
    }

    for (int i = 14; i < 22; i++){
        board[22][i] = BARRIER;
    }

}