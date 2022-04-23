# ENGG1340-Snake-Game
HKU ENGG1340 coursework

Team Number: 10

Game description:
Group 10

Game: The snake game

Description:
Player would be playing as a snake entity enclosed in an N x N space


The white dot represents the snake food in which when the snake eats it, it will increase in size.
The snake can travel through the boundary of the N x N space passing through the “#” and come out of the other side within the space. 

The game has 3 modes: Easy, Medium, and Hard.

Easy will be similar to the picture presented before.

Medium would have obstacles, labeled “|”,  inside the N x N space.

Hard would have more obstacles and poisonous food represented as “=”.

1. RNG element: food and obstacles spawn randomly

2. Data structures to store game state: arrays

3. Dynamic memory management: needed since the snake will always move without stopping. So have to update the array every unit time 

4. Input/output: User has to direct the snake itself

5. The game will be saved in the files, so users can resume the game. High Scores will be stored in the files with the player's name.

When the game is over, a message will be printed on screen.

Objective: survive as long as you can while evading to eat yourself. Once you have eaten a specific amount of food, you will be promoted to the next stage. 

Several features will be included in game: (Optional)
Food with different symbol that will slow the speed of the snake.
Food with different symbol that will increase the speed of snake.
Food that will reduce the length of the snake while the score remains the same.
Food with different symbol that has more points than other.

To create and play the game:
Download the file zip
extract the file
open terminal
go to directory with all the files

$make snake
$./snake
