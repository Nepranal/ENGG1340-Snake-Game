#include <iostream>

using namespace std;

#include "newGame.h"
#include "play.h"

void newGame()
{
    system("clear");
    int gameMode;


    cout << "____________________Game Mode____________________\n";
    cout << "1. Easy\n";
    cout << "2. Medium\n";
    cout << "3. Hard\n";
    cout << "4. Return to Main Menu.\n\n";
    cout << "Choose Mode.\n";
    cin>>gameMode;

    while (gameMode>4 || gameMode<1)
    {
        cout<<"Invalid game mode!"<<endl;
        cout<<"Try again"<<endl;
        cin>>gameMode;
    }

    if (gameMode == 4)
    {
        return;
    }
    else
    {
        play(gameMode);
    }
}