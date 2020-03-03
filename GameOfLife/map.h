#ifndef MAP_H
#define MAP_H

//the map. Data is holded in a pointer to char array.
//Precise access to it is granted through set and get functions
class Map
{
public:

	Map(int rows, int columns);
	~Map();
	void display();
	void initializeAliveCells(int seed);
	void next();
private:
	int countAliveNeighborCells(int row, int column);
	char getMapLocationValue(int row, int column);
	void setMapLocationValue(int row, int column, char value);
	char* map;
	int rows;
	int columns;
};
#endif // MAP_H