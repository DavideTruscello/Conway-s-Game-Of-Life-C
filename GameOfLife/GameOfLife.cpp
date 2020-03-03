// GameOfLife.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "game.h"
#include <sstream>
#include <string>

//to obtain a int input without errors
void getInput(int& var, std::string message,int min, int max)
{
	while ((std::cout << message) && (!(std::cin >> var) ||((var<min)||(var>max)))) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << "Invalid input; please re-enter.\n";
	}
}

int main()
{
	int rows, columns, seed;
	//Asking for the input
	getInput(rows, "Enter how many rows you want(min 10, max 30): ",10,30);
	getInput(columns, "Enter how many columns you want(min 40, max 120): ",40,120);
	getInput(seed, "Enter the seed: ",1,INT_MAX);
	
	//Game created and started
	Game g(rows, columns, seed);
	g.start();

}