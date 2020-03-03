#include "pch.h"
#include "map.h"
#include "game.h"
#include <iostream>
#include <Windows.h>


Game::Game(int rows, int columns, int seed) :map(rows, columns){

	//initializes the first generation on the map
	map.initializeAliveCells(seed);
}


void Game::start()
{
	//display the first generation and then begins an endless loop
	//in which the following generations are calculated and 
	//displayed.
	map.display();
	while (true) {
		map.next();
		Sleep(100);
		map.display();
	}
}
