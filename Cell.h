/*************************************************************
* Author:		Justin.Urbany
* Filename:		Stub.cpp
* Date Created:	1/17/2017
* Modifications:	1/21/17 -Added Comments
**************************************************************/
#ifndef CELL_H
#define CELL_H
/************************************************************************
* Class: Cell
*
* Purpose: The purpose of this function is to be the data type for a
*			single element of an array that can compose the board for
*			a mine sweeper game
*
* Manager functions:
* 	Cell()
*		creates a cell
*	cell(Cell & copy)
*	~Cell()
*	operator=(cell &rhs);
* Methods:
*	char getState();
*		get state of a cell
*	char getValue()
*		get value of a cell
*	void setState(char state)
*		set the state of a cell
*	void setValue(char value)
*		set the value of a cell
*	bool isflaged();
*		return true if cell state is flagged
*************************************************************************/
class Cell
{
public:
	Cell();
	Cell(Cell & copy);
	~Cell();
	Cell & operator=(Cell & rhs);
	char getState();
	void setState(char state);
	char getValue();
	void setValue(char value);
	bool isflaged();
private:
	char m_value;
	char m_state;
};
#endif
