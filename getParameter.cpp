#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

#include "getParameter.h"


void showFile()
{
    ifstream fin;
    fin.open("Game Saves.txt");
    if (fin.fail())
    {
        cout<<"An error has occurred!\n";
        exit(1);
    }

    string line;
    while(getline(fin,line))
    {
        cout<<line<<endl;
    }
    fin.close();
}

void getParameter(int &gameMode, vector<vector<int>> &snake_position, int &score)
{
    system("clear");

    showFile();

    ifstream fin;
    fin.open("Game Saves.txt");
    if (fin.fail())
    {
        cout<<"An error has occurred!\n";
        exit(1);
    }


    //gettin player's save files
    string name;
    cout<<"Enter player's name (Press 5 to go back): ";
    cin>>name;

    if(name=="5") //condition to return
    {
        return;
    }
    else
    {
        string line;
        while(getline(fin,line))
        {
            //How a game is saved: {name} {gameMode} {snake's position1}{snake's position2}... {score}
            //end of the snake's position ends with "s"
            istringstream ss(line);
            string nameInFile, snakePositions;
            ss>>nameInFile;
            if(nameInFile!=name)
            {
                continue;
            }

            //else...
            string gameModeInput;
            ss>>gameModeInput;
            gameMode = stoi(gameModeInput);

            while(ss>>snakePositions)
            {
                if (snakePositions=="s")
                {
                    break;
                }
                else
                {
                    int x=stoi(snakePositions);
                    ss>>snakePositions;
                    int y=stoi(snakePositions);
                    snake_position.push_back({x,y});
                }
            }

            string scoreInput;
            ss>>scoreInput;
            score=stoi(scoreInput);
            fin.close();
            return;
        }
    }

    fin.close();
}