/*************************************************************
* Author:		Justin.Urbany
* Filename:		Stub.cpp
* Date Created:	1/17/2017
* Modifications:	1/21/17 -Added Comments
**************************************************************/
#include <time.h>
#include <iostream>
#include<iomanip>
#include "Board.h"
#include "Row.h"
#include "windows.h"
using std::setw;
using std::cout;
/**********************************************************************
* Purpose:Create a board
* Precondition: Take in an character to know desired 2d Array size
************************************************************************/
Board::Board(char level)
{
	if (level == 'b')
	{
		create_beg_board();

	}
	else if (level == 'i')
	{
		create_inter_board();
	}
	else
	{
		create_exprt_board();
	}
}
/**********************************************************************
* Purpose: copy constructor make a copy of already exsiting board
************************************************************************/
Board::Board(Board & copy): m_Board(copy.m_Board)
{
}
/**********************************************************************
* Purpose: Clean up memory from board and nested Classes
************************************************************************/
Board::~Board()
{
	delete m_Board;
}
/**********************************************************************
* Purpose: Assign a Board to another Board
************************************************************************/
Board & Board::operator=(Board & rhs)
{
	m_Board = rhs.m_Board;
	return *this;
}
/**********************************************************************
* Purpose: The purpose of this function is to randomly place Bombs
*			throught the array and intialize all the current states
*			to the covered up state also for any piece of data that isn't
*			a bomb it will calculate the surrounding bombs and adjust
*			their value accordingly
*			
* Precondition: In order to properely generate an array for desired size
*				With the desried number of bombs bombs must be passed in
*				along with the height and the length
* Postcondition:
*				ALL DATA in the array that has been created must be
*				intialized with its value and state
************************************************************************/
void Board::populate_board(int bombs, int height, int length)
{
	int count = 0; //create a count for bombs
	int x = 0; //integer to hold a random value
	int y = 0; //integer to hold a random value
	srand(static_cast<int>(time(0))); //start a random number gen
	while (count < bombs)
	{
		x = rand() % height; //x is the row so take a random number then modulous
								   //it by the length-1 so that you always get a value inbounds of your 2D array
		y = rand() % length;
		if ((*m_Board)[x][y].getValue() != 'B')//if cell isn't bomb
		{
			(*m_Board)[x][y].setValue('B');// make it a bomb
			(*m_Board)[x][y].setState('?');//cover the cell
			++count;//increment the count till get to desired number of bombs
		}
	}
	for (int i = 1; i < height - 1; ++i) //set values for all the insides squares
	{
		for (int j = 1; j < length - 1; ++j) 
		{
			if ((*m_Board)[i][j].getValue() != 'B') //if it isn't a bomb
			{
				count = 0; //reset count check all squares around for bombs
							//for each bomb increment 1
				if ((*m_Board)[i - 1][j - 1].getValue() == 'B')
					++count;
				if ((*m_Board)[i][j - 1].getValue() == 'B')
					++count;
				if ((*m_Board)[i + 1][j - 1].getValue() == 'B')
					++count;
				if ((*m_Board)[i - 1][j].getValue() == 'B')
					++count;
				if ((*m_Board)[i + 1][j].getValue() == 'B')
					++count;
				if ((*m_Board)[i - 1][j + 1].getValue() == 'B')
					++count;
				if ((*m_Board)[i][j + 1].getValue() == 'B')
					++count;
				if ((*m_Board)[i + 1][j + 1].getValue() == 'B')
					++count;
				count += 0x30; // add 0x30 to get ascii value for the integer
				if (count == 0x30) //if there was zero bombs
				{
					(*m_Board)[i][j].setValue(' '); // make a blank square
				}
				else
				{
					(*m_Board)[i][j].setValue(static_cast<char>(count)); //cast the int so that it will have same value as a char
				}
				(*m_Board)[i][j].setState('?');//cover the cells
			}
		}
	}
	//All edge rows

	for (int i = 1; i < height - 1; ++i) // first column without corners
	{
		count = 0;//same as last function except only for the first colum
		if ((*m_Board)[i][0].getValue() != 'B')
		{
			if ((*m_Board)[i - 1][0].getValue() == 'B')
				++count;
			if ((*m_Board)[i - 1][1].getValue() == 'B')
				++count;
			if ((*m_Board)[i][1].getValue() == 'B')
				++count;
			if ((*m_Board)[i + 1][0].getValue() == 'B')
				++count;
			if ((*m_Board)[i + 1][1].getValue() == 'B')
				++count;
			count += 0x30; // add 0x30 to get ascii value for the integer
			if (count == 0x30)
			{
				(*m_Board)[i][0].setValue(' ');
			}
			else
			{
				(*m_Board)[i][0].setValue(static_cast<char>(count)); //cast the int so that it will have same value as a char
			}
			(*m_Board)[i][0].setState('?');
		}
	}
	for (int j = 1; j < length - 1; ++j) // first row without corners
	{
		count = 0;
		if ((*m_Board)[0][j].getValue() != 'B')
		{
			if ((*m_Board)[0][j - 1].getValue() == 'B')
				++count;
			if ((*m_Board)[1][j - 1].getValue() == 'B')
				++count;
			if ((*m_Board)[1][j].getValue() == 'B')
				++count;
			if ((*m_Board)[0][j + 1].getValue() == 'B')
				++count;
			if ((*m_Board)[1][j + 1].getValue() == 'B')
				++count;
			count += 0x30; // add 0x30 to get ascii value for the integer
			if (count == 0x30)
			{
				(*m_Board)[0][j].setValue(' ');
			}
			else
			{
				(*m_Board)[0][j].setValue(static_cast<char>(count)); //cast the int so that it will have same value as a char		
			}
			(*m_Board)[0][j].setState('?');
		}
	}

	for (int i = 1; i < height - 1; ++i) // last column
	{
		count = 0;
		if ((*m_Board)[i][length - 1].getValue() != 'B')
		{
			if ((*m_Board)[i - 1][length - 1].getValue() == 'B')
				++count;
			if ((*m_Board)[i - 1][length - 2].getValue() == 'B')
				++count;
			if ((*m_Board)[i][length - 2].getValue() == 'B')
				++count;
			if ((*m_Board)[i + 1][length - 2].getValue() == 'B')
				++count;
			if ((*m_Board)[i + 1][length - 1].getValue() == 'B')
				++count;
			count += 0x30; // add 0x30 to get ascii value for the integer
			if (count == 0x30)
			{
				(*m_Board)[i][length - 1].setValue(' ');
			}
			else
			{
				(*m_Board)[i][length - 1].setValue(static_cast<char>(count)); //cast the int so that it will have same value as a char
			}
			(*m_Board)[i][length - 1].setState('?');
		}
	}
	for (int j = 1; j < length - 1; ++j) //last row
	{
		count = 0;
		if ((*m_Board)[height-1][j].getValue() != 'B')
		{
			if ((*m_Board)[height - 1][j - 1].getValue() == 'B')
				++count;
			if ((*m_Board)[height - 2][j - 1].getValue() == 'B')
				++count;
			if ((*m_Board)[height - 2][j].getValue() == 'B')
				++count;
			if ((*m_Board)[height - 2][j + 1].getValue() == 'B')
				++count;
			if ((*m_Board)[height - 1][j + 1].getValue() == 'B')
				++count;
			count += 0x30; // add 0x30 to get ascii value for the integer
			if (count == 0x30)
			{
				(*m_Board)[height - 1][j].setValue(' ');
			}
			else
			{
				(*m_Board)[height - 1][j].setValue(static_cast<char>(count)); //cast the int so that it will have same value as a char
			}
			(*m_Board)[height-1][j].setState('?');
		}
	}

	//set corners
	count = 0;
	if ((*m_Board)[0][0].getValue() != 'B')//set the top left corner
	{
		if ((*m_Board)[0][1].getValue() == 'B')
			count++;
		if ((*m_Board)[1][0].getValue() == 'B')
			count++;
		if ((*m_Board)[1][1].getValue() == 'B')
			count++;
		count += 0x30;
		if (count == 0x30)
		{
			(*m_Board)[0][0].setValue(' ');
		}
		else
		{
			(*m_Board)[0][0].setValue(static_cast<char>(count)); //cast the int so that it will have same value as a char
		}
		(*m_Board)[0][0].setState('?');
	}

	count = 0;
	if ((*m_Board)[0][length - 1].getValue() != 'B')//top right corner
	{
		if ((*m_Board)[0][length - 2].getValue() == 'B')
			count++;
		if ((*m_Board)[1][length - 2].getValue() == 'B')
			count++;
		if ((*m_Board)[1][length - 1].getValue() == 'B')
			count++;
		count += 0x30;
		if (count == 0x30)
		{
			(*m_Board)[0][length - 1].setValue(' ');
		}
		else
		{
			(*m_Board)[0][length - 1].setValue(static_cast<char>(count)); //cast the int so that it will have same value as a char
		}
		(*m_Board)[0][length - 1].setState('?');
	}

	count = 0;
	if ((*m_Board)[height - 1][0].getValue() != 'B') //bottom left corner
	{
		if ((*m_Board)[height - 2][0].getValue() == 'B')
			count++;
		if ((*m_Board)[height - 2][1].getValue() == 'B')
			count++;
		if ((*m_Board)[height - 1][1].getValue() == 'B')
			count++;
		count += 0x30;
		if (count == 0x30)
		{
			(*m_Board)[height - 1][0].setValue(' ');
		}
		else
		{
			(*m_Board)[height - 1][0].setValue(static_cast<char>(count)); //cast the int so that it will have same value as a char

		}
		(*m_Board)[height - 1][0].setState('?');
	}

	count = 0;
	if ((*m_Board)[height - 1][length - 1].getValue() != 'B') //bottom right corner
	{
		if ((*m_Board)[height - 2][length - 1].getValue() == 'B')
			count++;
		if ((*m_Board)[height - 1][length - 2].getValue() == 'B')
			count++;
		if ((*m_Board)[height - 2][length - 2].getValue() == 'B')
			count++;
		count += 0x30;
		if (count == 0x30)
		{
			(*m_Board)[height - 1][length - 1].setValue(' ');
		}
		else
		{
			(*m_Board)[height - 1][length - 1].setValue(static_cast<char>(count));
		}
		(*m_Board)[height - 1][length - 1].setState('?');
	}
}
/**********************************************************************
* Purpose: The purpose of this function is to see if the user has won
*			the game
* Precondition: The game must not be over to call this function
* Postcondition: Returns true if the user has won
************************************************************************/
bool Board::check_win()
{
	bool won = true;
	for (int i = 0; i < m_Board->getRow(); ++i)
	{
		for (int j = 0; j < m_Board->getColumn(); ++j)
		{
			//go through all cells(if any cells are still uncovered and aren't bombs then win is false)
			if ((*m_Board)[i][j].getValue() != 'B' && (*m_Board)[i][j].getState() != 'U')
			{
				won = false;
			}
		}
	}
	return won;
}
/**********************************************************************
* Purpose: The purpose of this function is to create an array2D<cell>
*			of the beginner board length and width with the correct number
*			of bombs
* Precondition: Called from the board constructor
* Postcondition: must populate the created array
************************************************************************/
void Board::create_beg_board()
{
	m_Board = new Array2D<Cell>(10, 10);
	populate_board(10, 10, 10);

}
/**********************************************************************
* Purpose: The purpose of this function is to create an array2D<cell>
*			of the intermediate board length and width with the correct
*			number of bombs
* Precondition: Called from the board constructor
* Postcondition: must populate the created array
************************************************************************/
void Board::create_inter_board()
{
	m_Board = new Array2D<Cell>(16, 16);
	populate_board(40, 16, 16);
}
/**********************************************************************
* Purpose: The purpose of this function is to create an array2D<cell>
*			of the expert board length and width with the correct number
*			of bombs
* Precondition: Called from the board constructor
* Postcondition: must populate the created array
************************************************************************/
void Board::create_exprt_board()
{
	m_Board = new Array2D<Cell>(16,30);
	populate_board(100, 16, 30);
}
/**********************************************************************
* Purpose: The purpose of this function is to check if a cell has been
*			uncovered
* Precondition:
*			Take in the row column of cell that is wanted
* Postcondition:
*			return if the cell has or hasn't been uncovered
************************************************************************/
bool Board::checkuncovered(int row, int column)
{
	bool uncovered = false;
	if ((*m_Board)[row][column].getState() == 'U')
	{
		uncovered = true;
	}
	return uncovered;
}
/**********************************************************************
* Purpose: The purpose of this function is to check if a cell has been
*			flagged
*
* Precondition:
*			Take in the row column of cell that is wanted
* Postcondition:
*			return if the cell has been flagged
************************************************************************/
bool Board::checkflagged(int row, int column)
{
	bool flagged = false;
	if ((*m_Board)[row][column].getState() == 'F')
	{
		flagged = true;
	}
	return flagged;
}
/**********************************************************************
* Purpose: The purpose of this function is to make a square a Flagged
*		Square so that the user can place where he/she thinks a bomb
*		is also can unflag a square when they know it isn't a bomb
*
* Precondition:
*			Take in the row column of cell that is wanted
* Postcondition:
*			Change the state of the colum that is selected
************************************************************************/
void Board::flagcell(int row, int column)
{
	if ((*m_Board)[row][column].isflaged())
	{
		(*m_Board)[row][column].setState('?');
	}
	else
	{
		(*m_Board)[row][column].setState('F');
	}
}
/**********************************************************************
* Purpose: The purpose of this function is to uncover it cell and return
*			the value of that cell if cell is blank then it will
*			continue to uncover all cells in each direction until
*			a non blank cell is reached
*
* Precondition:
*			most pass in a valid row and column number
* Postcondition:
*		return the value of the current cell 
************************************************************************/
char Board::uncovercell(int row, int column)
{
	if ((*m_Board)[row][column].isflaged()==false)
	{
		(*m_Board)[row][column].setState('U');
		if ((*m_Board)[row][column].getValue() == ' ')
		{
			if (row > 0 && !checkuncovered(row - 1, column))
			{
				uncovercell(row - 1, column);
			}
			if (column > 0 && !checkuncovered(row, column - 1))
			{
				uncovercell(row, column - 1);
			}
			if (row < m_Board->getRow() - 1 && !checkuncovered(row + 1, column))
			{
				uncovercell(row + 1, column);
			}
			if (column < m_Board->getColumn() - 1 && !checkuncovered(row, column + 1))
			{
				uncovercell(row, column + 1);
			}
			if (row > 0 && column > 0 && !checkuncovered(row - 1, column - 1))
			{
				uncovercell(row - 1, column - 1);
			}
			if (row < m_Board->getRow() - 1 && column > 0 && !checkuncovered(row + 1, column - 1))
			{
				uncovercell(row + 1, column - 1);
			}
			if (row > 0 && column < m_Board->getColumn() - 1 && !checkuncovered(row - 1, column + 1))
			{
				uncovercell(row - 1, column + 1);
			}
			if (row < m_Board->getRow() - 1 && column < m_Board->getColumn() - 1 && !checkuncovered(row + 1, column + 1))
			{
				uncovercell(row + 1, column + 1);
			}
		}
	}
	return (*m_Board)[row][column].getValue();
}
/**********************************************************************
* Purpose: The purpose of this function is to show the current grid
*		   of all cells(if modified with modified values) of the
*			array2D
*
* Precondition:
*			Called everytime a move has been made
* Postcondition:
*			Must have displayed a state or value for each cell in the
*			2D array
************************************************************************/
void Board::printboard()
{
	for (int i = 0; i <m_Board->getRow(); ++i)//loop until less then total rows
	{
		if (i == 0)
		{
			for (int c = 0; c <= m_Board->getColumn(); ++c)
			{
				SetConsoleTextAttribute(hStdout, 2); //set to green
				cout << setw(3)<<c;//Print out numbers so user can see x axis grid
			}
			cout << '\n';
		}
		for (int j = 0; j <m_Board->getColumn(); ++j)//print out that corrisponding y axis value
		{
			if (j == 0)
			{
				SetConsoleTextAttribute(hStdout, 2);//set foreground to green
				cout <<setw(3)<< i + 1; // print out that corrisponding y axis value
			}
			if ((*m_Board)[i][j].getState() == 'U')
			{
				if ((*m_Board)[i][j].getValue() == 'B')
				{
					SetConsoleTextAttribute(hStdout, 4);//set foreground to red
				}
				if ((*m_Board)[i][j].getValue() == '1')
				{
					SetConsoleTextAttribute(hStdout, 9); //setforeground light Blue
				}
				if ((*m_Board)[i][j].getValue() == '2')
				{
					SetConsoleTextAttribute(hStdout, 14); //yellow
				}				
				if ((*m_Board)[i][j].getValue() == '3')
				{
					SetConsoleTextAttribute(hStdout, 10);//light green
				}
				if ((*m_Board)[i][j].getValue() == '4')
				{
					SetConsoleTextAttribute(hStdout, 5);//magneta
				}
				if ((*m_Board)[i][j].getValue() == '5')
				{
					SetConsoleTextAttribute(hStdout, 3);//cyan
				}
				if ((*m_Board)[i][j].getValue() == '6')
				{
					SetConsoleTextAttribute(hStdout, 1);//blue
				}
				if ((*m_Board)[i][j].getValue() == '7')
				{
					SetConsoleTextAttribute(hStdout, 7);//light gray
				}
				if ((*m_Board)[i][j].getValue() == '8')
				{
					SetConsoleTextAttribute(hStdout, 12);//light red
				}
				cout << setw(3)<<(*m_Board)[i][j].getValue();//if state is uncovered print out value
			}
			else
			{
				SetConsoleTextAttribute(hStdout, 15);
				cout << setw(3)<<(*m_Board)[i][j].getState();//if not uncovered print out state
			}
		}
		cout << '\n';
	}
	SetConsoleTextAttribute(hStdout, 15);
}
/**********************************************************************
* Purpose: The purpose of this function is to show all bomb locations
*			if the user has won or lost the game
*
* Precondition:
*			Only suppose to be called when game has been won or lost
* Postcondition:
*			Must have displayed a state or value for each cell in the
*			2D array
************************************************************************/
void Board::displaybombs()
{
	for (int i = 0; i <m_Board->getRow(); ++i)//loop until less then total rows
	{
		if (i == 0) //if first time
		{
			for (int c = 0; c <= m_Board->getColumn(); ++c)
			{
				SetConsoleTextAttribute(hStdout, 2);
				cout << setw(3) << c; //Print out numbers so user can see x axis grid
			}
			cout << '\n';//print a new line
		}
		for (int j = 0; j <m_Board->getColumn(); ++j) // loop until less then total columns
		{

			if (j == 0) //if first column
			{
				SetConsoleTextAttribute(hStdout, 2);				
				cout << setw(3) << i + 1; //print out that corrisponding y axis value
			}
			if ((*m_Board)[i][j].getValue() == 'B')
			{
				SetConsoleTextAttribute(hStdout, 4);//set foreground to red
			}
			if ((*m_Board)[i][j].getValue() == '1')
			{
				SetConsoleTextAttribute(hStdout, 9); //setforeground light Blue
			}
			if ((*m_Board)[i][j].getValue() == '2')
			{
				SetConsoleTextAttribute(hStdout, 14); //yellow
			}
			if ((*m_Board)[i][j].getValue() == '3')
			{
				SetConsoleTextAttribute(hStdout, 10);//light green
			}
			if ((*m_Board)[i][j].getValue() == '4')
			{
				SetConsoleTextAttribute(hStdout, 5);//magneta
			}
			if ((*m_Board)[i][j].getValue() == '5')
			{
				SetConsoleTextAttribute(hStdout, 3);//cyan
			}
			if ((*m_Board)[i][j].getValue() == '6')
			{
				SetConsoleTextAttribute(hStdout, 1);//blue
			}
			if ((*m_Board)[i][j].getValue() == '7')
			{
				SetConsoleTextAttribute(hStdout, 7);//light gray
			}
			if ((*m_Board)[i][j].getValue() == '8')
			{
				SetConsoleTextAttribute(hStdout, 12);//light red
			}
			if ((*m_Board)[i][j].getState() == 'U')
			{
				cout << setw(3) << (*m_Board)[i][j].getValue(); //if state is uncovered print out value

			}
			else if ((*m_Board)[i][j].getValue() == 'B')
			{
				cout << setw(3) << (*m_Board)[i][j].getValue(); //if it is a bomb print out bomb
			}
			else
			{
				SetConsoleTextAttribute(hStdout, 15);
				cout << setw(3) << (*m_Board)[i][j].getState(); //if not uncovered or bomb print out state
			}
		}
		SetConsoleTextAttribute(hStdout, 15);

		cout << '\n';
	}
}
