/*************************************************************
* Author:		Justin.Urbany
* Filename:		Stub.cpp
* Date Created:	1/17/2017
* Modifications:	1/21/17 -Added Comments
**************************************************************/
#define _CRTDB_MAP_ALLOC
#include <iostream>
using std::cout;
using std::cin;
#include "Minesweeper.h"
#include <crtdbg.h>



/*************************************************************
*
* Lab/Assignment: Lab 1-minesweeper
*
* Overview:
*	This program will create an array that will hold bombs or 
*   the number of bombs that are around each piece of the array
*   when the user enters a number and a column it will reveal
*   a numbers for coordinates on the grid(how the array is displayed
*   it will reveal the value of that piece in the array
*   if it is a bomb the game is over and the user loses
*   otherwise the uer can continues to enter in coordinates
*   until all the peices of the array that aren't bombs
*   are revealed or a bomb is revealed and then the user
*   wins or loses and can quit or play again
*
* Input:
*   The input consists of coordinates that the user can
*   enter in to select pieces of data within the array
*   also the user can put in what option they want to
*   do with the piece they have select and the user 
*   can input what they want to do with that piece of
*   data also the user can enter what level difficutly
*   they would want to play
*	
* Output:
*   The output of this program is to display the array of data
*   as a grid and it will reveal the state of all the data
*   and the value of the data depending if the data has been
*   modified by the user
************************************************************/

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_crtBreakAlloc = 140;
	
	Minesweeper start; //call the Minesweeper constructor and start the game


	return 0;
}