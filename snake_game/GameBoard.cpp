#include <iostream>
#include "GameBoard.hpp"

GameBoard::GameBoard(){
	width = 22;
	height = 22;

	gameGrid = new char* [height];

	setGridDyno(width, height);
}

GameBoard::GameBoard(int sizeX, int sizeY){
	width = sizeX+2;
	height = sizeY+2;

	gameGrid = new char* [height];
	setGridDyno(width, height);
}

void GameBoard::SetupBoard(void (*draw)(char**, int, int)){
	system("clear");

	int snakex = width/2, ysnake = height/2;

//CREATE THE GRID
	for(int i = 0; i < height; i++){				//iterate over the height first
		for(int a = 0; a < width; a++){				//iterate over the width
			if(i == 0 || i == (height-1)){			//if position in array is the first or last line, then make all the elements #
				gameGrid[i][a] = '#';
			} else{									
				if(a == 0 || a == (width-1)){		//else, check if it is the first element in the width and make them the #, everything else is a space;
					gameGrid[i][a] = '#';
				} 
				//if the position is directly in the middle of hte width, and either in the middle of the height or -1, +1, then create the snake
				else if(a == snakex && (i == ysnake || i == ysnake-1 || i == ysnake+1)) {
					(*draw)(gameGrid, a, i);					//function pointer to the snake draw function. which sends a pointer and then dereferences. 
				} else {
					gameGrid[i][a] = ' ';
				}
			}
		}
	}
}

void GameBoard::Draw(){

	//let the user know the size which is always -2 for each dimension
	std::cout << "Size of grid " << height-2 << " by " << width-2 << std::endl;

	//PRINT THE GRID
		for(int i = 0; i < height; i++){
			for(int a = 0; a < width ; a++){
				std::cout << gameGrid[i][a];
			}

			std::cout << std::endl;
		}
}

inline void GameBoard::setGridDyno(int x, int y){
	for(int i = 0; i < y; i++){				
		gameGrid[i] = new char[x];
	}
}

GameBoard::~GameBoard(){
	delete gameGrid;
}