/*************************************************************
* Author:		Justin.Urbany
* Filename:		Stub.cpp
* Date Created:	1/17/2017
* Modifications:	1/21/17 -Added Comments
**************************************************************/
#include <iostream>
using std::cout;
using std::cin;
#include "Minesweeper.h"

/**********************************************************************
* Purpose: This function intializes the board and calls StartGame()
*
*
************************************************************************/
Minesweeper::Minesweeper() : m_game(nullptr), m_level('\0')
{
	StartGame(); //Call start game
}
/**********************************************************************
* Purpose: This function deletes the board and calls all the other
*			Destructors
*
************************************************************************/
Minesweeper::~Minesweeper()
{
	delete m_game; //clean up all memory
}
/**********************************************************************
* Purpose: This function takes the intial data user inputs and creates
*			The Board for them to start playing the game with
*
* Precondtion:
*		Users in put must be 'b' 'i' or 'e' to continue on
*		Board is created and intialized with users data and
*		the playing game functio Has Been called
*
*
* Postcondition:
*		Must call NewGame and user is asked if they want to play again
*
************************************************************************/
void Minesweeper::StartGame()
{
	m_level = '\0'; //set m_level back to null incase of a newgame
	while (m_level != 'b' && m_level != 'i' && m_level != 'e') //loop until b i or e is entered
	{
		cout << "*****Starting a New Game***** \n" << "Enter level you would like to play:\n" <<
			"	b=beginner 10x10 grid with 10 mines\n" <<
			"	i=intermediate 16x16 gride with 40mines\n" <<
			"	e=expert 16x30 grids with 100 mines \n";
		cout << "Selection:"; //user enters selection they are going to use
		cin >> m_level; //takes the level that user wanted
		if (m_level != 'b' && m_level != 'i' && m_level != 'e')
		{
			cout << "In valid selection restarting\n"; //If level not valid tell them
		}
	}
	m_game = new Board(m_level); //create the Board with the level
	if (m_level == 'b')
	{
		PlayingGame(10,10); //Call Playing game with beginner board size
	}
	else if (m_level == 'i')
	{
		PlayingGame(16,16); //call Playing game with intermiedate board size
	}
	else
	{
		PlayingGame(16,30); //playing game expert board size
	}

	NewGame(); //call newgame
}
/**********************************************************************
* Purpose: The purpose of this function is to loop until the game is
*			won or has been lost taking user input along the way
*
* Precondition:
*		The Board must have been created and the height and length
*			Must be the same as the length of underneath array
*
* Postcondition:
*      Must delete memory incase of a new game and display the outcome
*		of the game as long with a visual repersentation of the board
*
************************************************************************/
void Minesweeper::PlayingGame(int height, int length)
{	
	bool win = false; //hold value to check if the user won/lost
	int row_select=-1; //variable for user ot select row on grid
	int column_select=-1; //variable for user to select column on gird
	int move = -1; //holds what user want to do with the data at point
	bool stillplaying = true; //holds if game is over
	m_game->printboard(); //Displays the board
	do //loop to keep playing tll game is over
	{
		move = 0;  // reset the move
		row_select = -1; //reset the row
		column_select = -1; //reset the column
		while (row_select<0 || row_select>height-1) //while input out of bounds
		{
			
			cout << "\nEnter row you want to select: ";
			cin >> (row_select);
			row_select--;
			if (row_select<0|| row_select>height-1)
			{
				cout << "Invalid Selection!!";
				row_select = row_select;
			}
		} //make user select valid data
		while (column_select<0 || column_select>length-1)
		{
			cout << "\nEnter column you want to select: ";
			cin >> static_cast<int>(column_select);
			column_select--;
			if (column_select<0 || column_select>length-1)
			{
				cout << "Invalid Selection!!";
				column_select = -1;
			}
		}
		while (move != 1 && move != 2) //while input not valid
		{
			cout << "\nWhat would you like to do to the cell?:(1)uncovercell, 2)flag/unflagcell:";
			cin >> move;
			if (move != 1 && move != 2)
			{
				cout << "Invalid Selection";
			}
		} //makes user select valid move selection
		if (move == 1) //if user wants to uncover cell
		{
			bool uncovered = m_game->checkuncovered(row_select, column_select);//check if cell is already ucovered
			if(!uncovered)//if cell wasn"t uncovered uncover cell
			{
				bool flagged = m_game->checkflagged(row_select, column_select); //check if cell was flagged
				if (!flagged) //if wasn't flagged
				{
					char value = m_game->uncovercell(row_select, column_select);
					if (value == 'B') // if it was a bomb
					{
						stillplaying = false; //game is over
					}

				}
				else
				{
					cout << "\n Can't uncovered flagged Cell! \n";
				}
			}
			else
			{
				cout << "\n Cell was already uncovered\n";
			}
			if (stillplaying == true) //if game not over
			{
				win = m_game->check_win(); //check to see if user won
				if (win)
				{
					stillplaying = false; //if they won games over
				}
			}
		}
		else if (move == 2)
		{
			bool uncovered = m_game->checkuncovered(row_select, column_select);
			if (!uncovered) //check if uncovered
			{
				m_game->flagcell(row_select, column_select); //if not uncovered flag cell
			}
			else
			{
				cout << "\n Can't uncover Flagged cell\n";
			}
		}
		system("cls");
		m_game->printboard(); //printboard after each move
	} while (stillplaying); //check if the game is still going
	system("cls");
	cout << '\n'; //display a new line
	m_game->displaybombs();//display the bombs on the board because game is over
	GameOver(win); //display if the
}
/**********************************************************************
* Purpose: The purpose of this function is to just return if game was 
*			won or lost
*
* Precondition:
*		Take in a bool that is the outcome
* Postcondition:
*		If the Game is lost cout that user has lost
*		else cout that the game was won
************************************************************************/
void Minesweeper::GameOver(bool outcome)
{
	if (!outcome)
	{
		cout << "\n you have lost!!! \n";
	}
	else
	{
		cout<< "\n you have won!!! \n";
	}
}
/**********************************************************************
* Purpose: The purpose of this function is to decide if the user
*			want to play another game or not
*
* Postcondition:
*      Deletes the game if the user wants to play again and call StartGame();
*	   Else ends the program
*
************************************************************************/
void Minesweeper::NewGame()
{
	char newgame = '\0';
	while (newgame != 'y' && newgame != 'n')
	{
		cout << "\n **Would You like to Play again?(y,n): ";
		{
			cin >> newgame;
		}
		if (newgame != 'y' && newgame != 'n')
		{
			cout << "Invalid Selection!";
		}
	}
	if (newgame == 'y')
	{
		delete m_game;
		StartGame();
	}
}