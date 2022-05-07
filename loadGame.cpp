#include <iostream>

using namespace std;

#include "loadGame.h"
#include "play.h"

// It loads up the game with option "5" a special option to load saved games.
// Takes no arguments and return no arguments.
void loadGame()
{
    play(5); //5 is an abritrary int argument. Any number except [1,4] is acceptable. It is only to activate the getParameter function in play()
}
