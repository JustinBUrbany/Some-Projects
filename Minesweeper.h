/*************************************************************
* Author:		Justin.Urbany
* Filename:		Stub.cpp
* Date Created:	1/17/2017
* Modifications:	1/21/17 -Added Comments
**************************************************************/
#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include "Board.h"
/************************************************************************
* Class: Minesweeper
*
* Purpose: To create a Board and drive a the created game to a win or loss
*
* Manager functions:
*	Minesweeper()
*		Intializes a board and a level calls startgame()
*   ~Minesweeper()
*		Deletes the Board
*
* Methods:
*	StartGame() 
*		Takes in data from users makes array2D and calls playinggame
*	PlayingGame(int height, int length)
*		Loops till the game ends getting information from the user
*		Hols the size of the grid that is being played on
*	GameOver(bool outcome)
*		take a bool and shows the outcome of game(win/lose)
*	NewGame()
*		Asks user if they would like to play another game or quit
*************************************************************************/
class Minesweeper
{
public:
	Minesweeper();
	~Minesweeper();
	void StartGame();
	void PlayingGame(int height, int length);
	void GameOver(bool outcome);
	void NewGame();
private:
	Board * m_game; //Pointer to Board that holds data
	char m_level; //Holds difficulty that user would want to play
};

#endif