#include <iostream>

#include "poisoneaten.h"

using namespace std;
#define DIAMOND "\xE2\x99\xA6"

bool poisoneaten(string board[][50], int poison[][50], int space){
    for(int i=0;i<space;++i){
        for(int j=0;j<space;++j){
            if (poison[i][j] == -1){
                if (board[i][j] == "O"){
                    return true;
                }
            }
        }
    }
    return false;
}