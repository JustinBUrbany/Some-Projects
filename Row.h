/*************************************************************
* Author:		Justin.Urbany
* Filename:		Stub.cpp
* Date Created:	1/17/2017
* Modifications:	1/21/17 -Added Comments
**************************************************************/
#ifndef ROW_H
#define ROW_H
//foward deleration of array2d
template<typename T>
class Array2D;
/************************************************************************
* Class: Row
*
* Purpose: The purpose of this class is to be able to overload [][]
*			and return appropriate values from a 2d array
*
* Manager functions:
* 	Row(Array2D<T> & array, int row )
* 		intialize m_array2D to the array, and intialize the m_row to row
*
* Methods:
*	operator [ ] (int column)
*			Take the column passed and the row you want and pass it to
*			The array2D select function and then return the value that
*			is taken from the 1d array
*************************************************************************/
template<typename T>
class Row
{
public:
	Row(Array2D<T> & array, int row);
	T & operator [](int column);
private:
	Array2D<T> & m_array2D;
	int m_row;

};
/**********************************************************************
* Purpose: Intialize the row with the current 2Darray, and the desired
*			row
************************************************************************/
template<typename T>
Row<T>::Row(Array2D<T> & array, int row) : m_array2D(array), m_row(row) //row is the desired row
{}
/**********************************************************************
* Purpose: This function returns the data at the array[i][n] postion
*
* Precondition:
*		Take in a valid column
*
* Postcondition:
*      call the array2D.select function and return the value at that
*		element of the 1d array
************************************************************************/
template<typename T>
T &  Row<T>::operator[](int column)
{

	return m_array2D.Select(m_row, column);
}
#endif
