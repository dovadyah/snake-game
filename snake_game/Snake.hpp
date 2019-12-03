#ifndef SNAKE_HPP
#define SNAKE_HPP

class Snake{
public:
	Snake(){ direction = STOP; }

	static void snakeDraw(char** grid, int x, int y){ grid[y][x] = '0'; }

	//~Snake();

private:
	// int snakeX, snakeY;
	enum snakeDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
	snakeDirection direction;
};

#endif