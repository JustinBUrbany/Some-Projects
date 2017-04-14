/*************************************************************
* Author:		Justin.Urbany
* Filename:		Deck.cpp
* Date Created:	2/8/2017
* Modifications:	2/13/17 -Added Comments
**************************************************************/
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include "deck.h"
#include "card.h"
using std::cout;
using std::endl;

int Deck::m_currentcard = 0; //static member to keep track of which card your on
/**********************************************************************
* Purpose:DECK DEFAULT CONSTRUCORT  INTIALIZE A DECK OF 52 CARDS TO ALL	UNIQUE VALUES
*
* Precondition: be called at the creation of a deck
*
* Postcondition: have intialized the deck to each unique card in a deck
*
************************************************************************/
Deck::Deck()
{
	m_deck = new Card *[52];
	for (int suit = 0; suit <= 3; suit++)
	{
		for (int rank = 0; rank < 13; rank++)
		{
			m_deck[suit * 13 + rank] = new Card(static_cast<Card::Rank>(rank + 1), static_cast<Card::Suit>(suit + 3));
		}
	}
}
/**********************************************************************
* Purpose: The purpose is to shuffle all the cards within in the deck
*
* Precondition: must get called within a deck class
*
* Postcondition: mix up the order of the cards so that it is random what
the next card will be
*
************************************************************************/
void Deck::Shuffle()
{

	Card *temp = nullptr;
	int number = 0;


	srand(time(0));

	for (int cur = 0; cur <= 51; cur++)
	{
		number = rand() % 51;
		temp = m_deck[cur];
		m_deck[cur] = m_deck[number];
		m_deck[number] = temp;
	}
	cout << endl << "SHUFFFLLLINGGGGGGGGGGGGGGGG!!!" << endl;

	m_currentcard = 0;
}
/**********************************************************************
* Purpose: To deal the next card of the deck to the screen or next player
*
* Precondition: be called within a deck and return a card
*
* Postcondition: return the card and increment current card
*
************************************************************************/
Card Deck::Deal()
{
	return *m_deck[m_currentcard++];
}

int Deck::GetCard()
{
	return m_currentcard;
}
/**********************************************************************
* Purpose: deck dtor delete a deck when it goes out of scope and to
de-allocate any  memory you allocated with the deck
*
* Precondition: passed nothing
*
* Postcondition: clean up any mess you have made
*
************************************************************************/

Deck::~Deck()
{
	if (m_deck != nullptr)
	{
		for (int i = 0; i < 52; i++)
		{
			delete m_deck[i];
			m_deck[i] = nullptr;
		}
		delete[] m_deck;
		m_deck = nullptr;
	}
}