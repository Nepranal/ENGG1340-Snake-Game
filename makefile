main.o : main.cpp menu.h
	g++ -pedantic-errors -std=c++11 -c main.cpp

showHighScores.o : showHighScores.cpp showHighScores.h
	g++ -pedantic-errors -std=c++11 -c showHighScores.cpp

getParameter.o : getParameter.cpp getParameter.h
	g++ -pedantic-errors -std=c++11 -c getParameter.cpp

saveGame.o : saveGame.cpp saveGame.h
	g++ -pedantic-errors -std=c++11 -c saveGame.cpp

play.o : play.cpp play.h getParameter.h saveGame.h
	g++ -pedantic-errors -std=c++11 -c play.cpp

newGame.o : newGame.cpp newGame.h play.h
	g++ -pedantic-errors -std=c++11 -c newGame.cpp

loadGame.o : loadGame.cpp loadGame.h play.h
	g++ -pedantic-errors -std=c++11 -c loadGame.cpp

menu.o : menu.cpp newGame.h showHighScores.h menu.h loadGame.h
	g++ -pedantic-errors -std=c++11 -c menu.cpp

snake : menu.o newGame.o play.o showHighScores.o main.o loadGame.o getParameter.o saveGame.o
	g++ -pedantic-errors -std=c++11 $^ -o snake

clean:
	rm -f snake menu.o newGame.o play.o showHighScores.o main.o loadGame.o getParameter.o saveGame.o