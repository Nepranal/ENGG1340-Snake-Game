#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

vector <vector<int>> snake_position={};
int space=0, foodposition[2]={{}}, poisonposition[2]={{}}, fruitposition[2]={{}};
string board[50][50]={};
int poison[50][50]={};
int score = 0;
string gamemode;

#include "createboard.h"
#include "printboard.h"
#include "updateboard.h"
#include "spawnfood.h"
#include "gameover.h"
#include "play.h"
#include "highscores.h"
#include "createpoison.h"

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
    string playername;
    string display_score;
    cin >> option;
    if (option == "1"){
        system("clear");
        cout << "____________________Game Mode____________________\n";
        cout << "1. Easy\n";
        cout << "2. Medium\n";
        cout << "3. Hard\n";
        cout << "4. Return to Main Menu.\n\n";
        cout << "Choose Mode.\n";
        cin >> gamemode;
        if (gamemode == "1"){
            system("clear");
            space=25;
            snake_position.push_back({space/2,space/2});
            createboard(space,board);
            updateboard(snake_position,board);
            spawnfood(space, foodposition,board);
            printboard(space,board);
            play(space,board, snake_position, foodposition, score, gamemode); 
            gameover(space,board);
            highscores(gamemode,score);
            
        }
        else if (gamemode == "2"){
            system("clear");
            space=25;
            snake_position.push_back({space/2,space/2});
            special_createboard(space,board);
            updateboard(snake_position,board);
            spawnfood(space, foodposition,board);
            printboard(space,board);
            play(space,board, snake_position, foodposition, score, gamemode); 
            gameover(space,board);
            highscores(gamemode,score);
        }
        else if (gamemode == "3"){
            system("clear");
            space=25;
            createpoision(space, poison);
            snake_position.push_back({space/2,space/2});
            special_createboard(space,board);
            updateboard(snake_position,board);
            spawnfood(space, foodposition,board);
            printboard(space,board);
            hard_play(space,board, snake_position, foodposition, score, gamemode, poisonposition, poison, fruitposition); 
            gameover(space,board);
            highscores(gamemode,score);
        }

        else if (gamemode == "4"){
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
        system("clear");
        cout << "WELCOME TO WALL OF FAME!\n\n";
        cout << "EASY MODE HISHSCORE\n";
        ifstream fin_1("highscores_easy.txt");
        if (fin_1.fail()){
            cout << "Error in File Opening!" << endl;
            exit(1);
        }
        fin_1 >> playername >> display_score;
        cout << left;
        cout << setw(10) << playername << setw(5) << display_score << endl << endl;
        fin_1.close();
        cout << "MEDIUM MODE HISHSCORE\n";
        ifstream fin_2("highscores_medium.txt");;
        if (fin_2.fail()){
            cout << "Error in File Opening!" << endl;
            exit(1);
        }
        fin_2 >> playername >> display_score;
        cout << left;
        cout << setw(10) << playername << setw(5) << display_score << endl << endl;
        fin_2.close();
        cout << "HARD MODE HISHSCORE\n";
        ifstream fin_3("highscores_hard.txt");;
        if (fin_3.fail()){
            cout << "Error in File Opening!" << endl;
            exit(1);
        }
        fin_3 >> playername >> display_score;
        cout << left;
        cout << setw(10) << playername << setw(5) << display_score << endl << endl;
        fin_3.close();
        cout << "Press any key to continue.\n";
        cin.ignore();
        cin.get();
        system("clear");
        menu();
    }
    else if (option == "4"){
        exit(1);
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
    return 0;
}
