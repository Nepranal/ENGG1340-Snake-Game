# ENGG1340-Snake-Game
HKU ENGG1340 coursework

Team Number: 10
Members: Muhammad Ghassan Jawwad, Abel Haris Harsono





Game description:
Group 10

Game: The snake game

Description:
Player would be playing as a snake entity enclosed in an 25 x 25 space

CS Server: academy11.cs.hku.hk

The CLUB represents the snake food in which when the snake eats it, it will increase in size.
The snake can travel through the boundary of the N x N space passing through the “#” and come out of the other side within the space. 

The game has 3 modes: Easy, Medium, and Hard.

Medium would have obstacles, labeled “\xE2\x98\x92”,  inside the N x N space.

Hard would have obstacles, poisonous food represented as “DIAMOND "\xE2\x99\xA6"”, and heart food represented as HEART "\xE2\x99\xA5".

1. RNG element: food and posions spawn randomly

2. Data structures to store game state: arrays

3. Dynamic memory management: Snake is a vector which is ammended as the game is played.

4. Input/output: User has to direct the snake itself

5. The game will be saved in the files, so users can resume the game. High Scores will be stored in the files with the player's name.

When the game is over, a message will be printed on screen.

Objective: survive as long as you can while evading to eat yourself, hit barrier or eating poision. In Hard Mode, you need to eat food or other fruit/heart in a way that there are less poisions on the board and the board remains mostly clear so you can move snake easily. Try to eat food by reaching it by shortest distance possible so less poisions are on the board. You can move the snake with the W A S D keys.

Several features will be included in game:
Food with different symbol that will increase the score in hard mode.
Poison with different symbol that will kill the snake. (Poison is symbolized with the diamond symbols)
Barriers with different symbol. If you touch barrier, you will die.
You can move around the board.
Your Highscores will be saved (input x) and you can store many games and resume it again.

To create and play the game:
Download the file zip
extract the file
open terminal
go to directory with all the files

$make snake

$./snake

Quick starts:

Easy game: 1 1
Medium game: 1 2
Hard game: 1 3


Cases:
Easy Game
![image](https://user-images.githubusercontent.com/99369599/167259399-838f13d2-f500-4a09-86c7-730fd974105b.png)

Medium Game
![image](https://user-images.githubusercontent.com/99369599/167259422-5a0fc2b9-9833-4c76-99ba-553b461aeabb.png)

Hard game (The hearts are fruits (+5 points), diamonds are posion (insta death))
![image](https://user-images.githubusercontent.com/99369599/167259271-c8dfe7ab-9a82-4143-b923-f7ca09e8ebce.png)


Game Over screen

![image](https://user-images.githubusercontent.com/99369599/167259457-1f92cde9-1637-402a-83da-f0fa374bd2c0.png)

Killed by barriers

![image](https://user-images.githubusercontent.com/99369599/167259616-a1097992-c3f3-4f23-b112-b4ab3143a7b9.png)


![image](https://user-images.githubusercontent.com/99369599/167259457-1f92cde9-1637-402a-83da-f0fa374bd2c0.png)

Killed by poison

![image](https://user-images.githubusercontent.com/99369599/167259686-dd256463-878f-4e9f-aa29-025a28f17d7b.png)


![image](https://user-images.githubusercontent.com/99369599/167259457-1f92cde9-1637-402a-83da-f0fa374bd2c0.png)

Killed by biting yourself

![image](https://user-images.githubusercontent.com/99369599/167259760-57107b57-4f8f-46ad-a7e0-aa1e9c45665b.png)


![image](https://user-images.githubusercontent.com/99369599/167259457-1f92cde9-1637-402a-83da-f0fa374bd2c0.png)


High Scores board

![image](https://user-images.githubusercontent.com/99369599/167259732-de3f056a-e8d2-4cb7-b999-f097b45fd279.png)



Getting a new High score

![image](https://user-images.githubusercontent.com/99369599/167259537-cb487ad3-a755-4bf6-9f38-78bbb1a12036.png)

Load game saves

![image](https://user-images.githubusercontent.com/99369599/167259362-020dc68f-c9fd-4d15-bd79-42ca21245ee2.png)

Menu

![image](https://user-images.githubusercontent.com/99369599/167259311-3c6978bd-8945-4cee-8947-2c7a9d038434.png)

Instructions

![image](https://user-images.githubusercontent.com/99369599/167259333-c27a301b-646b-482b-9407-68992671fce0.png)


Game Saving

![image](https://user-images.githubusercontent.com/99369599/167259288-fd05d0f7-48ae-4e51-ae13-0914cb0d24ab.png)

