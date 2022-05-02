#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "showHighScores.h"


void showHighScores()
{
    string playername, display_score;
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
}