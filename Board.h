/*************************************************************
* Author:		Justin.Urbany
* Filename:		Stub.cpp
* Date Created:	1/17/2017
* Modifications:	1/21/17 -Added Comments
**************************************************************/
#ifndef BOARD_H
#define BOARD_H
#include "Cell.h"
#include "Array2D.h"
#include "windows.h"
//foward decleration of Array2D
template<typename T>
class Array2D;
//foward decleration of Cell
class Cell;
/************************************************************************
* Class: Board
*
* Purpose: Purpose of this class is to hold the game or an array2D of cells
*
* Manager functions:
* 	Board()
* 		create a board
*	Board(char level)
*		create a board based on the passed in value
*	~Board()
*		clean up memory from the board
* Methods:
*	Populate_board(int bombs, int length, int height)
*		populate board with n bombs and pass in the height and length of
*		the array2D
*	check_win()
*		return true if player one or false if they haven't won
*	create_beg_board()
*		create a 10x10 array2d with 10 bombs
*	create_inter_board()
*		create a 16X16 array2d with 40 bombs
*	create_expert_board()
*		create a 16x30 array2d with 100 bombs
*	bool checkuncoverred(int row, int column)
*		return true if [row][column element of array has been uncovered
*	bool checkflagged(int row, int column)
*		return true if [row][column] element of array has been flagged
*	void flaggcell(int row, int column)
*		flag the [row][column] element of the array
*	char uncovercell(int row, int column)
*		change state of the cell of [row][column] element and return its val
*	printboard()
*		print the current state of the board
*	displaybombs()
*		print current state of board plus uncover all bombs
*************************************************************************/
class Board
{
public:
	Board(char level);
	Board(Board & copy);
	~Board();
	Board & operator=(Board & rhs);
	void populate_board(int bombs, int length, int height);
	bool check_win();
	void create_beg_board();
	void create_inter_board();
	void create_exprt_board();
	bool checkuncovered(int row, int column);
	bool checkflagged(int row, int column);
	void flagcell(int row, int column);
	char uncovercell(int row, int column);
	void printboard();
	void displaybombs();
private:
	Array2D<Cell> * m_Board;
	HANDLE hStdout =  GetStdHandle(STD_OUTPUT_HANDLE);
};




#endif