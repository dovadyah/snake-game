#include "SnakeGame.hpp"
#include "Snake.hpp"
#include "GameBoard.hpp"

SnakeGame::SnakeGame(){
	gameOver = false;
	score = 0;
}

void SnakeGame::GameRun(){

	GameBoard firstGame;
	Snake snakey;

	firstGame.SetupBoard(Snake::snakeDraw);

	firstGame.Draw();
}