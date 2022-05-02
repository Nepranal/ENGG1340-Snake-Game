#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;


bool checkName(string name)
{
    ifstream fin;
    fin.open("Game Saves.txt");
    if(fin.fail())
    {
        cout<<"An error has occured!!"<<endl;
        exit(1);
    }

    string line, nameTemp;
    while(getline(fin,line))
    {
        istringstream ss(line);
        ss>>nameTemp;
        if(name==nameTemp)
        return true;
    }

    return false;
}


void saveGame(int gameMode, vector<vector<int>> snake_position, int score)
{
    ofstream fout;
    fout.open("Game Saves.txt", ios::app);
    if(fout.fail())
    {
        cout<<"An error has occured!!"<<endl;
        exit(1);
    }


    string name;
    cout<<"Enter file name: ";
    cin>>name;

    //check if name is already saved
    while(checkName(name)==true)
    {
        cout<<"Record Already exist\nPlease enter a new name (enter 5 to go without saving): ";
        cin>>name;
        if (name=="5")
        {
            return;
        }
        checkName(name);
    }

    fout<<name<<" ";

    fout<<gameMode<<" ";

    for(int i=0;i<snake_position.size();++i)
    {
        int x = snake_position[i][0], y= snake_position[i][1];
        fout<<x<<" "<<y<<" ";
    }

    fout<<"s"<<" "<<score<<endl;

    fout.close();

    cout<<"Game Saved!\n"<<"Press enter to continue"<<endl;
    cin.ignore();
    cin.get();
}