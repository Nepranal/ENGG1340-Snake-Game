//Purpose of this file is to play the snake game.
//The snake is of the vector data type named snake_position.
//The player will be moving around the head of the snake while the rest of the body mimics the head or the preceding body.
//3 types of game modes and their corresponding number: 1=Easy, 2=Medium, 3=Hard
//space defines the dimension of the "play ground". It is kept to be constant and equal to 25
//foodposition is an array that store the x,y coordinate of the food
//poison and poisonposition works to store the poison's position
//fruitposition is an array that stores the fruit
//score keeps the score of the player
//board stores the states of the board

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

#include "play.h"
#include "getParameter.h"
#include "saveGame.h"


#define CLUB "\xE2\x99\xA3"
#define BARRIER "\xE2\x98\x92"
#define DIAMOND "\xE2\x99\xA6"
#define HEART   "\xE2\x99\xA5"


vector <vector<int>> snake_position;
int space, foodposition[2], poisonposition[2], poison[50][50], fruitposition[2], score=0;
string board[50][50];


//Create a normal board
void createboard(){
    for(int i=0;i<space;++i){
        for(int j=0;j<space;++j){
            if (i==0 || i==space-1){
                board[i][j]="#";
            }
            else{
                if(j==0 || j==space-1){
                    board[i][j]="#";
                }
                else{
                    board[i][j]=" ";
                }
            }
        }
    }
}


//Create the board normally + barriers
void special_createboard()
{
    createboard(); 


    //Creating the barriers
    for (int i = 6; i < 19; i++){
        board[6][i] = BARRIER;
        board[16][i] = BARRIER;
    }

    for (int i = 2; i < 22; i++){
        board[i][3] = BARRIER;
    }

    for (int i = 18; i < 22; i++){
        board[i][18] = BARRIER;
    }

    for (int i = 14; i < 22; i++){
        board[22][i] = BARRIER;
    }

}


//Print the board
void printboard()
{
    system("clear");
    cout<<"Score: "<<score<<endl;

    for(int i=0;i<space;++i){
        for(int j=0;j<space;++j){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}


//Update the board with the snake
void updateboard(){
    int x,y;
    for(int i=0;i<snake_position.size();++i ){
        x=snake_position[i][0];
        y=snake_position[i][1];
        board[x][y]="O";
    }
    
}


//Spawn snake food. Is randomized with time
void spawnfood(){
    srand(time(NULL));
    int random_point1=rand()%space,random_point2=rand()%space;
    while(board[random_point1][random_point2]!=" ") //Making sure the food only spawn on an empty space
    {
        random_point1=rand()%space;
        random_point2=rand()%space;
    }
    foodposition[0]=random_point1;
    foodposition[1]=random_point2;
    board[random_point1][random_point2]=CLUB;
}


//Spawn poison with an extra rule
void spawnpoison(){

    if ((score > 3) && (score % 2 != 0)){
        int random_point1=rand()%space,random_point2=rand()%space;
        while(board[random_point1][random_point2]!=" " ){ 
            random_point1=rand()%space;
            random_point2=rand()%space;
        }
        poisonposition[0]=random_point1;
        poisonposition[1]=random_point2;
        board[random_point1][random_point2]= DIAMOND;
        poison[random_point1][random_point2]= -1;
    }
    if (score % 3 == 0){
        for(int i=0;i<space;++i){
            for(int j=0;j<space;++j){
                if (board[i][j] == DIAMOND){
                    board[i][j] = " ";
                    poison[i][j] = 0;
                }
            }
        }
    }
}


//Spawn fruit with rules
void spawnfruit(){
    int count=0;

    for(int i=0;i<space;++i){
        for(int j=0;j<space;++j){
            if (board[i][j] == HEART){
                count++;
            }
        }
    }

    if (score % 5 == 0 && count == 0){
        int random_point1=rand()%space,random_point2=rand()%space;
        while(board[random_point1][random_point2]!=" " ){ 
            random_point1=rand()%space;
            random_point2=rand()%space;
        }
        fruitposition[0]=random_point1;
        fruitposition[1]=random_point2;
        board[random_point1][random_point2]= HEART;
    }

    if (score % 4 == 0){
        for(int i=0;i<space;++i){
            for(int j=0;j<space;++j){
                if (board[i][j] == HEART){
                    board[i][j] = " ";
                }
            }
        }
    }
    
}


//Checking if poison is eaten
bool poisoneaten(){
    for(int i=0;i<space;++i){
        for(int j=0;j<space;++j){
            if (poison[i][j] == -1){
                if (board[i][j] == "O"){
                    return true;
                }
            }
        }
    }
    return false;
}


//Check if food has been eaten
bool foodeaten(){
    if (board[foodposition[0]][foodposition[1]]=="O"){
        return true;
    }
    else
      return false;
}


//Check if fruit has been eaten
bool fruiteaten(){
    if (board[fruitposition[0]][fruitposition[1]] == "O")
    {
        fruitposition[0] = 0;
        fruitposition[1] = 0;
        return true;
    }
    else
      return false;
}


//Cheking only for if the head went and inhibit the same space it bodies are on
bool snakebit_itself2(){
    int pos1=snake_position[0][0],pos2=snake_position[0][1]; 
    for(int i=1;i<snake_position.size();++i){
        int snakepos1=snake_position[i][0], snakepos2=snake_position[i][1];
        if(pos1 == snakepos1 &&  pos2 == snakepos2)
          return true;
    }
    return false;
}


//Checking if the snake hit the barrier. only checking for the head
bool barrier_collision(){
    for (int i = 6; i < 19; i++){
        if (board[6][i] == "O" ){
            return true;
        }
        if (board[16][i]== "O" ){
            return true;
        }
    }

    for (int i = 2; i < 22; i++){
        if (board[i][3]== "O" ){
            return true;
        }
    }

    for (int i = 18; i < 22; i++){
        if (board[i][18]== "O" ){
            return true;
        }
    }

    for (int i = 14; i < 22; i++){
        if (board[22][i] == "O" ){
            return true;
        }
    }
    return false;
    // if (board[foodposition[0]][foodposition[1]]=="O"){
    //     return true;
    // }
    // else
    //   return false;
}


//A function that faciliates moving the snake and "deleting" previous version of it from the board
void delete_prev_snake(int snakepos1, int snakepos2){
    //If snake is on the boundary, must replace with #. Otherwise, " "
    if(snakepos1==0||snakepos2==0||snakepos1==space-1||snakepos2==space-1)
    {
        board[snakepos1][snakepos2]="#"; 
    }
    else{
        board[snakepos1][snakepos2]=" ";
    }
}


//Making sure the snake is not glitching to unintended positions
void snake_position_regulator(int & snakepos1,int &snakepos2){
    if(snakepos1<0){
        snakepos1+=space;
    }
    if(snakepos2<0){
        snakepos2+=space;
    }
    snakepos1%=space;
    snakepos2%=space;
}


//The part of the snake that is controllable
void movehead(char move,int prevpos[]){
    int old_snake1=0,old_snake2=0,new_snake1=0,new_snake2=0;
    prevpos[0]=snake_position[0][0];        //storing position before moving
    prevpos[1]=snake_position[0][1];
    old_snake1=prevpos[0];
    old_snake2=prevpos[1];
    
    delete_prev_snake(old_snake1,old_snake2); //"delete" them from the board because the head is going to change

    new_snake1=old_snake1;
    new_snake2=old_snake2;
    if(move=='W'){
        new_snake1 = old_snake1-1;
    }
    else if(move == 'S'){
        new_snake1 = old_snake1+1;
    }
    else if(move=='A'){
        new_snake2= old_snake2-1;
    }
    else if(move=='D'){
        new_snake2=old_snake2+1;
    }
    
    snake_position_regulator(new_snake1,new_snake2); 
    snake_position[0][0]=new_snake1;//Applying the new change
    snake_position[0][1]=new_snake2;
}


//Moving the body of the snake. They will follow whatever part of the snake that came before them
void movebody(int i,int prevpos[])
{
    //similar mechanisms to moving the head
    int old_snake1,old_snake2,new_snake1,new_snake2;
    old_snake1=snake_position[i][0];
    old_snake2=snake_position[i][1];

    delete_prev_snake(old_snake1,old_snake2);

    new_snake1=prevpos[0];
    new_snake2=prevpos[1];
    snake_position[i][0]=new_snake1;
    snake_position[i][1]=new_snake2;
    prevpos[0]=old_snake1;
    prevpos[1]=old_snake2;
}

//Snake is split into 2 segments. Player can only really control the head
//Rest of the body follows whatever is in front of them
void movesnake(char move ,int prevpos[]){
    for(int i=0;i< snake_position.size();++i){
        if(i==0)
        {
          movehead(move,prevpos);
        }
        else 
          movebody(i,prevpos);
    }
}


//A function to increase the size of the snake
void inc_snake(int prevpos[]){
    snake_position.push_back({prevpos[0],prevpos[1]});
}


//Displaying the highscores
void highscores(int gamemode){
    string name;
    int highscore;
    // cout<< score;
    // cout << "Press any key to continue.\n";
    //         cin.ignore();
    //         cin.get();
    if (gamemode == 1){
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
    else if (gamemode == 2){
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
    else if (gamemode == 3){
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


void gameover()
{
    createboard();
    int mid=space/2;
    board[mid][mid-4]="G";
    board[mid][mid-3]="A";
    board[mid][mid-2]="M";
    board[mid][mid-1]="E";
    board[mid][mid]=" ";
    board[mid][mid+1]="O";
    board[mid][mid+2]="V";
    board[mid][mid+3]="E";
    board[mid][mid+4]="R";
    
    board[mid+1][mid-8]="T";
    board[mid+1][mid-7]="H";
    board[mid+1][mid-6]="A";
    board[mid+1][mid-5]="N";
    board[mid+1][mid-4]="K";
    board[mid+1][mid-3]="S";
    board[mid+1][mid-2]=" ";
    board[mid+1][mid-1]="F";
    board[mid+1][mid]="O";
    board[mid+1][mid+1]="R";
    board[mid+1][mid+2]=" ";
    board[mid+1][mid+3]="P";
    board[mid+1][mid+4]="L";
    board[mid+1][mid+5]="A";
    board[mid+1][mid+6]="Y";
    board[mid+1][mid+7]="I";
    board[mid+1][mid+8]="N";
    board[mid+1][mid+9]="G";

    printboard();

    cout<<"Press any keys to continue"<<endl;
    cin.ignore();
    cin.get();
    
}


void playGame(int gameMode){
    int prevpos[2]={}; //for storing previous part of the moved snake
    char move;

    updateboard();//update the board with the snake's current position
    spawnfood();
    printboard();

    cout<<"W A S D? ";
    cin>>move;
    move=toupper(move);

    while(move != '1'){
        
      if(move == 'X') //Option for saving a game
      {
        saveGame(gameMode, snake_position, score);
        break;
      }

      movesnake(move, prevpos);
      updateboard();

      //Game Over conditions
      if (snakebit_itself2()==true)
        break;
        
      if(gameMode == 2 || gameMode == 3)
      {
          if (barrier_collision()==true)
            break;
      }


      //special conditions for hard mode
      if(gameMode == 3)
      {
          if(poisoneaten() == true)
          {
              break;
          }
          if(fruiteaten() == true)
          {
              score+=5;
              inc_snake(prevpos);
          }
          spawnpoison();
          spawnfruit();
      }


      //If the snake ate a food, the dot, then it will increase in size and score would be incremented by 1
      if(foodeaten()==true){
          inc_snake(prevpos);
          spawnfood();
          score++;
      }

      updateboard();
      printboard();
      cout<<"W A S D? ";
      cin>>move;
      move=toupper(move);
    }

    //Game over prompts
    //Only if the player didn't save
    if(move !='X')
    {
        gameover();
        highscores(gameMode);
    }
}


//1=Easy, 2=Medium, 3= Hard
void play(int gameMode)
{
    system("clear");

    //Initializing
    snake_position={};
    foodposition[2]={}; poisonposition[2]={}; poison[50][50]={}; fruitposition[2]={}; score=0; space=25;
    createboard(); //Initializing the board

    if (gameMode>0 && gameMode<4)
    {
        //Initial conditions for any types of new game
        snake_position.push_back({space/2,space/2});
    }
    else
    {
        //Getting saved data
        getParameter(gameMode, snake_position, score);
        if (gameMode==5) //In case user doesn't want to process with loading a save data
        {
            return;
        }
    }

    if (gameMode ==1)
    {
        createboard();
    }
    else
    {
        //Medium and hard types will have barriers
        special_createboard();
    }

    playGame(gameMode);
}
