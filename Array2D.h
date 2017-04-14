/*************************************************************
* Author:		Justin.Urbany
* Filename:		Stub.cpp
* Date Created:	1/17/2017
* Modifications:	1/21/17 -Added Comments
**************************************************************/
#ifndef ARRAY2D_H
#define ARRAY2D_H
#include"Cell.h"
#include "Array.h"
#include "Row.h"

//foward decleration of Array
template <typename T>
class Array;

/************************************************************************
* Class: Array2D
*
* Purpose: This class hold an array type T and holds it as a 2D array
*
* Manager functions:
* 	Array2D ( )
* 		rows and column both zero
*	Array2D (int row, int col)
*		Set the Array2D to size row and col
*	Array2D (const Array2D & copy)
*	operator = (const Array2D & copy)
*	~Array()
*
* Methods:
*	operator [ ](int index)
*		Return a Row so that one can function chain to a double [][]
*   getRow(): Return number of rows
*	setRow(int rows) set the new number of rows
*	getColumn(): return number of columns
*	Select(int row, int column) select an element from the array
*************************************************************************/

template<typename T>
class Array2D
{
public:
	Array2D();
	Array2D(int row, int col);
	Array2D(const Array2D & copy);
	~Array2D();
	Array2D<T> & operator=(const Array2D & rhs);
	Row<T> operator[](int index);
	int getRow();
	void setRow(int rows);
	int getColumn();
	void setColumn(int columns);
	T & Select(int row, int column);

private:

	Array<T> m_array;
	int m_row;
	int m_col;
};

/**********************************************************************
* Purpose: Creates a array2D size zero
*
************************************************************************/
template<typename T>
Array2D<T>::Array2D() : m_row(0), m_col(0)
{
}
/**********************************************************************
* Purpose: Set the Array2D to number of rows and colums passed in
*
* Postcondition:
*			set the length of the m_arary to (row*col)
*
************************************************************************/
template<typename T>
Array2D<T>::Array2D(int row, int col) : m_row(row), m_col(col)
{
	//if (row < 0 || col < 0)
		//throw Exception("Invalid length or width");
	m_array.setLength(row*col);
}
/**********************************************************************
* Purpose: Purpose of this function is to create a copy of an array
*
************************************************************************/
template<typename T>
Array2D<T>::Array2D(const Array2D & copy) : m_row(0), m_col(0)
{
	if (copy.m_row < 0 || m_col < 0)
	{
		//throw Exception("Invalid column or row length");
	}
	else
	{
		m_array = copy.m_array;
		m_row = copy.m_row;
		m_col = copy.m_col;
	}
}
/**********************************************************************
* Purpose: Clean up the memory of the array2D class
*
************************************************************************/
template<typename T>
Array2D<T>::~Array2D()
{
	m_array.setLength(0);

	m_col = 0;
	m_row = 0;
}
/**********************************************************************
* Purpose: The purpose of this function is to assign one Array2D to
*			another Array2D
************************************************************************/
template <typename T>
Array2D<T> & Array2D<T>::operator=(const Array2D & rhs)
{
	if (this != &rhs)
	{
		m_array = rhs.m_array;
		m_row = rhs.m_row;
		m_col = rhs.m_col;
	}
	return *this;
}
/**********************************************************************
* Purpose: This function chains the [][]so that appropriate data can
*			be returned from the array2D
*
* Precondition:
*		Pass in a valid index
* Postcondition:
*      return a Row<T> so that functions can chain
*
************************************************************************/
template <typename T>
Row<T> Array2D<T>::operator[](int index)
{
	//desired row *m_column + descired column
	//Row<T> row(*this, index); //gonna pass the desired rows to row
	//have a Row<T> with this current 2Darray and desired rows

	return Row<T>(*this, index);//got to return this Row<T> to the Row<T> operator to the
}
/**********************************************************************
* Purpose: The purpose of this function is to return total number of rows
************************************************************************/
template <typename T>
int Array2D<T>::getRow()
{
	return m_row;
}
/**********************************************************************
*Purpose: The purpose of this function is to return total number of columns
************************************************************************/ 
template <typename T>
int Array2D<T>::getColumn()
{
	return m_col;
}
/**********************************************************************
* Purpose: The purpose of this funciton it to change number of columns
*
*Precondition: Take in a valid column number
*
*Postcondition: Copy all the appropriate data to the new sized array
*
************************************************************************/
template <typename T>
void Array2D<T>::setColumn(int column)
{
	if (column > 0)
	{
		Array<T> temp(column * m_row);

		int n = 0;
		for (int i = 0; i < m_row; ++i)
		{
			for (int j = 0; j < column && j< m_col; ++j)
			{
				temp[n] = m_array[i*m_col + j];
				n++;
			}
			if (column > m_col)
			{
				n += column - m_col;
			}
		}
		m_col = column;
		m_array = temp;

	}
	else
	{
		throw Exception("Can't have columns less then zero!");
	}

}
/**********************************************************************
* Purpose: This function set the total number of rows and copys
*			over the appropriate data to the new sized array
*
* Precondition:
*			Take in a valid number of rows
* Postcondition:
*      Resized the array
*
************************************************************************/
template <typename T>
void Array2D<T>::setRow(int Row)
{
	if (Row > 0)
	{
		m_row = Row;
		m_array.setLength(m_col*m_row);
	}
	else
	{
		throw Exception("Can't have rows less then zero!");
	}
}
/**********************************************************************
* Purpose: This function return data at certain index of the m_array
*
* Precondition:
*     Take in the row and column number you want
*                    
* Postcondition:
*		Return the data at the desired element of the 1d array
************************************************************************/
template <typename T>
T & Array2D<T>::Select(int row, int column)
{
	return m_array[row*m_col + column];
}

#endif ARRAY2D_H
