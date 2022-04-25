#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "highscores.h"

void highscores(string gamemode, int& score){
    string name;
    int highscore;
    // cout<< score;
    // cout << "Press any key to continue.\n";
    //         cin.ignore();
    //         cin.get();
    if (gamemode == "1"){
        ifstream fin("highscores_easy.txt");
        if (fin.fail()){
            cout << "Error in File Opening!";
            exit(1);
        }
        fin >> name >> highscore;
        fin.close();
        if (highscore < score){
            system("clear");
            cout << "______________________CONGRATULATIONS______________________\n\n";
            cout << "NICE MOVES! NOW WELCOME TO WALL OF FAME!\n\n";
            cout << "ENTER YOUR FIRST NAME ONLY.\n";
            cin >> name;
            if (name.length() != 0){
                ofstream fout("highscores_easy.txt");
                if (fout.fail()){
                    cout << "Error in File Opening!";
                    exit(1);
                }
                fout << name << " " << score << endl;
                fout.close();
            }
            cout << endl <<"WELCOME!\n\n";
            cout << "Press any key to exit.\n";
            cin.ignore();
            cin.get();
        }
     }
    else if (gamemode == "2"){
        ifstream fin("highscores_medium.txt");
        if (fin.fail()){
            cout << "Error in File Opening!";
            exit(1);
        }
        fin >> name >> highscore;
        fin.close();
        if (highscore < score){
            system("clear");
            cout << "______________________CONGRATULATIONS______________________\n\n";
            cout << "NICE MOVES! NOW WELCOME TO WALL OF FAME!\n\n";
            cout << "ENTER YOUR FIRST NAME ONLY.\n";
            cin >> name;
            if (name.length() != 0){
                ofstream fout("highscores_medium.txt");
                if (fout.fail()){
                    cout << "Error in File Opening!";
                    exit(1);
                }
                fout << name << " " << score << endl;
                fout.close();
            }
            cout << endl <<"WELCOME!\n\n";
            cout << "Press any key to exit.\n";
            cin.ignore();
            cin.get();
        }
    }
    else if (gamemode == "3"){
        ifstream fin("highscores_hard.txt");
        if (fin.fail()){
            cout << "Error in File Opening!";
            exit(1);
        }
        fin >> name >> highscore;
        fin.close();
        if (highscore < score){
            system("clear");
            cout << "______________________CONGRATULATIONS______________________\n\n";
            cout << "NICE MOVES! NOW WELCOME TO WALL OF FAME!\n\n";
            cout << "ENTER YOUR FIRST NAME ONLY.\n";
            cin >> name;
            if (name.length() != 0){
                ofstream fout("highscores_hard.txt");
                if (fout.fail()){
                    cout << "Error in File Opening!";
                    exit(1);
                }
                fout << name << " " << score << endl;
                fout.close();
            }
            cout << endl <<"WELCOME!\n\n";
            cout << "Press any key to exit.\n";
            cin.ignore();
            cin.get();
        }
    }
}