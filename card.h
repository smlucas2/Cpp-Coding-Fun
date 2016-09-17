#pragma once
#include <iostream>

class Card {
public:
	enum class CardSuit {
		SPADES = 0,
		CLUBS = 1,
		HEARTS = 2,
		DIAMONDS = 3
	};
	enum class CardNum {
		TWO = 0,
		THREE = 1,
		FOUR = 2,
		FIVE = 3,
		SIX = 4,
		SEVEN = 5,
		EIGHT = 6,
		NINE = 7,
		TEN = 8,
		JACK = 9,
		QUEEN = 10,
		KING = 11,
		ACE = 12
	};
private:
	CardNum m_num = CardNum::TWO;
	CardSuit m_suit = CardSuit::SPADES;
public:
	Card();
	Card(CardNum, CardSuit);
	void printCard() const;
	int getCardValue() const;
};
