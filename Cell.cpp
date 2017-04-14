/*************************************************************
* Author:		Justin.Urbany
* Filename:		Stub.cpp
* Date Created:	1/17/2017
* Modifications:	1/21/17 -Added Comments
**************************************************************/
#include "Cell.h"
/**********************************************************************
* Purpose: Create a cell
************************************************************************/
Cell::Cell(): m_value('\0'), m_state('\0')
{
}
/**********************************************************************
* Purpose: Create a copy of a cell
************************************************************************/
Cell::Cell(Cell & copy) : m_value(copy.m_value), m_state(copy.m_state)
{
}
/**********************************************************************
* Purpose: Destroy a Cell
************************************************************************/
Cell::~Cell()
{
}
/**********************************************************************
* Purpose: Assign a cell to another cell
************************************************************************/
Cell & Cell::operator=(Cell & rhs)
{
	m_value = rhs.m_value;
	m_state = rhs.m_state;
	return *this;
}
/**********************************************************************
* Purpose: Get the current state of a cell
*
* Postcondition: Return that state to whatever called
************************************************************************/
char Cell::getState()
{
	return m_state;
}
/**********************************************************************
* Purpose: Assign the current state of a cell to the passed in state
*
* Precondition: Take in a character
*
************************************************************************/
void Cell::setState(char state)
{
	m_state=state;
}
/**********************************************************************
* Purpose: Get the value of a current cell
*
* Postcondition: Return the value of the current cell
************************************************************************/
char Cell::getValue()
{
	return m_value;
}
/**********************************************************************
* Purpose: set the value of the current cell to the char value passed in
*
* Precondition: value must be a character
************************************************************************/
void Cell::setValue(char value)
{
	m_value=value;
}
/**********************************************************************
* Purpose: The purpose of this function is to check to see if the
*		State of the Cell is='F'
*
* Postcondition: Return a boolean value of false if the state of cell
*			isn't= to 'F' retrun true if it is
************************************************************************/
bool Cell::isflaged()
{
	bool flagged = false;
	if (m_state == 'F')
		flagged = true;
	return flagged;
}
