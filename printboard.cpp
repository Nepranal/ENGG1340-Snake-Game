#include <iostream>
#include "printboard.h"

using namespace std;


void printboard(int space, std::string board[][50]){
    system("clear");
    for(int i=0;i<space;++i){
        for(int j=0;j<space;++j){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}