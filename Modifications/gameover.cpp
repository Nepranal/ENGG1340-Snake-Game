#include <iostream>
#include "createboard.h"
#include "printboard.h"

using namespace std;

void gameover(int space,string board[][50]){
    createboard(space,board);
    int mid=space/2;
    board[mid][mid-4]="G";
    board[mid][mid-3]="A";
    board[mid][mid-2]="M";
    board[mid][mid-1]="E";
    board[mid][mid]=" ";
    board[mid][mid+1]="O";
    board[mid][mid+2]="V";
    board[mid][mid+3]="E";
    board[mid][mid+4]="R";
    
    board[mid+1][mid-8]="T";
    board[mid+1][mid-7]="H";
    board[mid+1][mid-6]="A";
    board[mid+1][mid-5]="N";
    board[mid+1][mid-4]="K";
    board[mid+1][mid-3]="S";
    board[mid+1][mid-2]=" ";
    board[mid+1][mid-1]="F";
    board[mid+1][mid]="O";
    board[mid+1][mid+1]="R";
    board[mid+1][mid+2]=" ";
    board[mid+1][mid+3]="P";
    board[mid+1][mid+4]="L";
    board[mid+1][mid+5]="A";
    board[mid+1][mid+6]="Y";
    board[mid+1][mid+7]="I";
    board[mid+1][mid+8]="N";
    board[mid+1][mid+9]="G";
    
    printboard(space,board);
}