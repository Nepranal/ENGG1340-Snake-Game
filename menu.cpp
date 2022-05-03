#include <iostream>

using namespace std;

#include "newGame.h" 
#include "loadGame.h"
#include "showHighScores.h"
#include "menu.h"

// Funtion to print the menu. Outputs are strings.
void printOptions()
{
    cout << "\n____________________WELCOME TO SNAKE GAME_____________________\n";
    cout << "\n";
    cout << "\n_________________________MAIN MENU_____________________________\n";
    cout << "1. New Game\n";
    cout << "2. Load Game\n";
    cout << "3. Instructions\n";
    cout << "4. High Scores\n";
    cout << "5. Quit\n\n";
    cout << "Enter Menu Option.\n";
}

// Function to print the instructions. Outputs are strings.
void showInstructions()
{
        system("clear");
        cout << "TO START NEW GAME CHOOSE New Game FROM MENU.";
        cout << "\nUse the 'W' key to go UP.";
        cout << "\nUse the 'A' key to turn LEFT.";
	    cout << "\nUse the 's' key to go DOWN.";
	    cout << "\nUse the 'd' key to turn RIGHT.";
	    cout << "\nPress the 'x' key any time during the game to SAVE and EXIT.";
	    cout << "\nDO NOT reverse movement or you will LOSE.";
	    cout << "\nDO NOT eat your own tail or body, else you will LOSE!";
        cout << "\nIn Medium Mode, do not touch barriers else you will LOSE!.";
        cout << "\nIn Hard Mode, do not touch barriers else you will LOSE! Do not eat poison \xE2\x99\xA6 as it will kill  you and eat \xE2\x99\xA5 to increase score.\n";
		cout << "Press any key to continue.\n";
        cin.ignore();
        cin.get();
        system("clear");
}


//Function which prints menu. Prompts user for menu option and redirects if wrong menu option given. It executes resspective functions according to menu option provided by user.
void menu()
{
    string option;
    system("clear");
    printOptions();


    cin >> option;
    while(option != "1" && option!= "2" && option != "3" && option != "4" && option != "5")
    {
        cout << "INVALID Menu Option!\n";
        cout << "Enter correct option of Main Menu to proceed.\n";
        cin >> option;
    }

    while(option != "5")
    {
        if (option == "1")
        {
            newGame(); //Create a new game
        }
        else if (option == "2")
        {
            loadGame(); //Play from previously saved game
        }
        else if (option == "3")
        {
            showInstructions();
        }
        else if (option == "4")
        {
            showHighScores(); //show High scores from previous players in different game Modes
        }
        else if (option == "5")
        {
            return;
        }

        system("clear");
        printOptions();

        cin >> option;
        while(option != "1" && option!= "2" && option != "3" && option != "4" && option != "5")
        {
            cout << "INVALID Menu Option!\n";
            cout << "Enter correct option of Main Menu to proceed.\n";
            cin >> option;
        }
    }
}