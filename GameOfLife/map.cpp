#include "pch.h"
#include "map.h"
#include <iostream>
#include <string>
#define alive '0'
#define dead '.'
#define proportions 0.70

Map::Map(int a_rows, int a_columns) :rows(a_rows), columns(a_columns), map(new char[(a_rows)*(a_columns)])
{}


Map::~Map()
{delete[] map;}


//Loads the map into a string and then prints it
//(composing the string and then printing it avoids flickering)
void Map::display()
{
	std::string s = "\n\n\n\n";
	for (int i = 0; i < rows; ++i)
	{
		s += '\n';
		for (int j = 0; j < columns; ++j)
		{
			s += getMapLocationValue(i, j);
		}

	}
	std::cout << s;
}

//uses the user-determined seed to generate alive cells in their
//initial position
void Map::initializeAliveCells(int seed)
{
	std::srand(seed);
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			double chance = ((double)std::rand() / (double)RAND_MAX);
			if (chance > proportions)
			{
				setMapLocationValue(i, j, alive);
			}
			else
			{
				setMapLocationValue(i, j, dead);
			}

		}
	}
}


//Updates the map to the following generation
void Map::next()
{
	//to hold the new generation
	char* new_map = new char[rows*columns];


	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			int count = countAliveNeighborCells(i, j);


			if (count < 2 || count>3)
			{
				new_map[((i)*columns) + (j)] = dead;
			}
			else if (count == 3)
			{
				new_map[((i)*columns) + (j)] = alive;
			}
			else
			{
				new_map[((i)*columns) + (j)] = getMapLocationValue(i, j);
			}

		}
	}
	delete[] map;
	map = new_map;
}


//counts how many cells there are in the close proximity of the
//specified position
int Map::countAliveNeighborCells(int row, int column)
{
	int count = 0;
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			int location_row = row + i;
			if (location_row == -1)
			{
				location_row = rows - 1;
			}
			if (location_row == rows)
			{
				location_row = 0;
			}
			int location_column = column + j;
			if (location_column == -1)
			{
				location_column = columns - 1;
			}
			if (location_column == columns)
			{
				location_column = 0;
			}
			char cell = getMapLocationValue(location_row, location_column);
			if (cell == alive) { count++; }

		}
	}
	if(getMapLocationValue(row,column)==alive)
	{
		--count;
	}
	return count;
}

//getter of a position of the map
char Map::getMapLocationValue(int row, int column)
{
	return map[((row)*columns) + (column)];
}

//setter of a position of the map
void Map::setMapLocationValue(int row, int column, char value)
{
	map[((row)*columns) + (column)] = value;
}



