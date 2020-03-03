#ifndef GAME_H
#define GAME_H
#include "map.h"

//This class will take care of holding the map, starting the gol
//and displaying it.
class Game
{
public:
	Game(int rows, int columns, int seed);
	void start();
private:
	Map map;
};
#endif // GAME_H