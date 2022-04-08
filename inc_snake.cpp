#include <iostream>

#include <vector>

using namespace std;

void inc_snake(int snakelength, int prevpos[], vector<vector<int>> &snake_position){
    snake_position.push_back({prevpos[0],prevpos[1]});
}