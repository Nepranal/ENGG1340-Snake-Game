#include <iostream>
#include "createpoison.h"

using namespace std;

void createpoision(int space, int poison[][50]){
    for(int i=0;i<space;++i){
        for(int j=0;j<space;++j){
            poison[i][j] = 0;
        }
    }
}