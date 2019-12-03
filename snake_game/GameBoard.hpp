#ifndef GAME_BOARD_HPP
#define GAME_BOARD_HPP

class GameBoard{ 
public:

	GameBoard();									// default constructor
	GameBoard(int, int);							//set user input size

	void SetupBoard(void (*draw)(char**, int, int));									//Draw a game board
	void Draw();

	int getWidth() { return width; }
	int getHeight() { return height; }

	char** getGrid(){ return gameGrid; }

	~GameBoard(); 									//destructor

private:
	int width, height;

	inline void setGridDyno(int, int);

	char** gameGrid;
};

#endif