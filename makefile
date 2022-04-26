createboard.o: createboard.cpp createboard.h
	g++ -pedantic-errors -std=c++11 -c createboard.cpp

delete_prev_snake.o: delete_prev_snake.cpp delete_prev_snake.h
	g++ -pedantic-errors -std=c++11 -c delete_prev_snake.cpp

foodeaten.o: foodeaten.cpp foodeaten.h
	g++ -pedantic-errors -std=c++11 -c foodeaten.cpp

fruiteaten.o: fruiteaten.cpp fruiteaten.h
	g++ -pedantic-errors -std=c++11 -c fruiteaten.cpp

poisoneaten.o: poisoneaten.cpp poisoneaten.h
	g++ -pedantic-errors -std=c++11 -c poisoneaten.cpp

createpoison.o: createpoison.cpp createpoison.h
	g++ -pedantic-errors -std=c++11 -c createpoison.cpp

barrier_collision.o: barrier_collision.cpp barrier_collision.h
	g++ -pedantic-errors -std=c++11 -c barrier_collision.cpp
	
gameover.o: gameover.cpp createboard.h printboard.h
	g++ -pedantic-errors -std=c++11 -c gameover.cpp

inc_snake.o: inc_snake.cpp inc_snake.h
	g++ -pedantic-errors -std=c++11 -c inc_snake.cpp

main.o: main.cpp createboard.h printboard.h updateboard.h spawnfood.h gameover.h play.h highscores.h createpoison.h
	g++ -pedantic-errors -std=c++11 -c main.cpp

movebody.o: movebody.cpp delete_prev_snake.h
	g++ -pedantic-errors -std=c++11 -c movebody.cpp

movehead.o: movehead.cpp delete_prev_snake.h snake_position_regulator.h
	g++ -pedantic-errors -std=c++11 -c movehead.cpp

movesnake.o: movesnake.cpp movebody.h movehead.h
	g++ -pedantic-errors -std=c++11 -c movesnake.cpp

play.o: play.cpp movesnake.h updateboard.h snakebit_itself2.h foodeaten.h inc_snake.h spawnfood.h updateboard.h printboard.h barrier_collision.h spawnpoison.h poisoneaten.h spawnfruit.h fruiteaten.h
	g++ -pedantic-errors -std=c++11 -c play.cpp

printboard.o: printboard.cpp printboard.h
	g++ -pedantic-errors -std=c++11 -c printboard.cpp

snake_position_regulator.o: snake_position_regulator.cpp snake_position_regulator.h
	g++ -pedantic-errors -std=c++11 -c snake_position_regulator.cpp

snakebit_itself2.o: snakebit_itself2.cpp snakebit_itself2.h
	g++ -pedantic-errors -std=c++11 -c snakebit_itself2.cpp

spawnfood.o: spawnfood.cpp spawnfood.h
	g++ -pedantic-errors -std=c++11 -c spawnfood.cpp

spawnpoison.o: spawnpoison.cpp spawnpoison.h
	g++ -pedantic-errors -std=c++11 -c spawnpoison.cpp

spawnfruit.o: spawnfruit.cpp spawnfruit.h
	g++ -pedantic-errors -std=c++11 -c spawnfruit.cpp

updateboard.o: updateboard.cpp updateboard.h
	g++ -pedantic-errors -std=c++11 -c updateboard.cpp

highscores.o: highscores.cpp highscores.h
	g++ -pedantic-errors -std=c++11 -c highscores.cpp

snake: main.o  spawnfruit.o  fruiteaten.o spawnpoison.o poisoneaten.o createpoison.o highscores.o play.o barrier_collision.o updateboard.o spawnfood.o snakebit_itself2.o snake_position_regulator.o printboard.o movesnake.o movehead.o movebody.o inc_snake.o gameover.o foodeaten.o delete_prev_snake.o createboard.o
	g++ -pedantic-errors -std=c++11 $^ -o snake