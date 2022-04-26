#ifndef PLAY_H
#define PLAY_H

using namespace std;
void play(int space, string board[][50], vector<vector<int>> &snake_position, int foodposition[], int& score, string gamemode);
void hard_play(int space, string board[][50], vector<vector<int>> &snake_position, int foodposition[], int& score, string gamemode, int poisonposition[], int poison[][50], int fruitposition[]);

#endif