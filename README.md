# ENGG1340-Snake-Game
HKU ENGG1340 coursework

Team Number: 10

Game description:
Group 10

Game: The snake game

Description:
Player would be playing as a snake entity enclosed in an N x N space

CS Server: academy11.cs.hku.hk

The CLUB represents the snake food in which when the snake eats it, it will increase in size.
The snake can travel through the boundary of the N x N space passing through the “#” and come out of the other side within the space. 

The game has 3 modes: Easy, Medium, and Hard.

Easy will be similar to the picture presented before.

Medium would have obstacles, labeled “\xE2\x98\x92”,  inside the N x N space.

Hard would have obstacles, poisonous food represented as “DIAMOND "\xE2\x99\xA6"”, and heart food represented as HEART "\xE2\x99\xA5".

1. RNG element: food and posions spawn randomly

2. Data structures to store game state: arrays

3. Dynamic memory management: Snake is a vector which is ammended as the game is played.

4. Input/output: User has to direct the snake itself

5. The game will be saved in the files, so users can resume the game. High Scores will be stored in the files with the player's name.

When the game is over, a message will be printed on screen.

Objective: survive as long as you can while evading to eat yourself, hit barrier or eating poision. In Hard Mode, you need to eat food or other fruit/heart in a way that there are less poisions on the board and the board remains mostly clear so you can move snake easily. Try to eat food by reaching it by shortest distance possible so less poisions are on the board.

Several features will be included in game: (Optional)
Food with different symbol that will increase the score.
Poison with different symbol that will kill the snake.
Barriers with different symbol. If you touch barrier, you will die.
You can move around the board.
Your Highscores will be saved and you can store many games and resume it again.

To create and play the game:
Download the file zip
extract the file
open terminal
go to directory with all the files

$make snake

$./snake
