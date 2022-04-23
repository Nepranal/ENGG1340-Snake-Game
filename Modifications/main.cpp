#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

vector <vector<int>> snake_position={};
int space=0, foodposition[2]={{}};
string board[50][50]={};
int score = 0;

#include "createboard.h"
#include "printboard.h"
#include "updateboard.h"
#include "spawnfood.h"
#include "gameover.h"
#include "play.h"

#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

void menu(){
    cout << "\n____________________WELCOME TO SNAKE GAME_____________________\n";
    cout << "\n\n";
    cout << "____________________________MAIN MENU__________________________\n";
    cout << "1. New Game\n";
    cout << "2. Instructions\n";
    cout << "3. High Scores\n";
    cout << "4. Quit\n\n";
    cout << "Enter Menu Option.\n";
    string option;
    string choice;
    cin >> option;
    if (option == "1"){
        system("clear");
        cout << "____________________Game Mode____________________\n";
        cout << "1. Easy\n";
        cout << "2. Medium\n";
        cout << "3. Hard\n";
        cout << "4. Return to Main Menu.\n\n";
        cout << "Choose Mode.\n";
        cin >> choice;
        if (choice == "1"){
            system("clear");
            space=25;
            snake_position.push_back({space/2,space/2});
            createboard(space,board);
            updateboard(snake_position,board);
            spawnfood(space, foodposition,board);
            printboard(space,board);
            play(space,board, snake_position, foodposition, score); 
            gameover(space,board);
        }
        else if (choice == "2"){
            system("clear");
            space=25;
            snake_position.push_back({space/2,space/2});
            createboard(space,board);
            updateboard(snake_position,board);
            spawnfood(space, foodposition,board);
            printboard(space,board);
            play(space,board, snake_position, foodposition, score); 
            gameover(space,board);
        }
        else if (choice == "3"){
            system("clear");
            space=25;
            snake_position.push_back({space/2,space/2});
            createboard(space,board);
            updateboard(snake_position,board);
            spawnfood(space, foodposition,board);
            printboard(space,board);
            play(space,board, snake_position, foodposition, score); 
            gameover(space,board);
        }
        else if (choice == "4"){
            system("clear");
            menu();
        }
        else{
            system("clear");
            cout << "INVALID Mode Option!\n";
            cout << "Enter correct option for game mode.\n";
            cout << "Press any key to proceed to Main Menu.\n";
            cin.ignore();
            cin.get();
            system("clear");
            menu();
        }
    }
    else if (option == "2"){
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
        menu();
    }
    else if (option == "3"){
        
    }
    else if (option == "4"){
        
    }
    else {
        system("clear");
        cout << "INVALID Menu Option!\n";
        cout << "Enter correct option of Main Menu to proceed.\n";
        cout << "Press any key to continue.\n";
        cin.ignore();
        cin.get();
        system("clear");
        menu();
    } 
}
int main(){
    menu();
    // Shaheer has such a sexy body
    return 0;
}
