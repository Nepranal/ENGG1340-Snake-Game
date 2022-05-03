#include <iostream>

using namespace std;

#include "newGame.h"
#include "play.h"

// Function prints game mode menu. It prompts user for game mode, and for wrong input asks for input again. On correct game mode input it excutes play function accordingly.
void newGame()
{
    system("clear");
    string gameMode;


    cout << "____________________Game Mode____________________\n";
    cout << "1. Easy\n";
    cout << "2. Medium\n";
    cout << "3. Hard\n";
    cout << "4. Return to Main Menu.\n\n";
    cout << "Choose Mode.\n";
    cin>>gameMode;

    while (gameMode > "4" || gameMode< "1")
    {
        cout<<"Invalid game mode!"<<endl;
        cout<<"Try again"<<endl;
        cin>>gameMode;
    }

    if (gameMode == "4")
    {
        return;
    }
    else
    {
        play(stoi(gameMode));
    }
}