#pragma once

#include <array>
#include <ctime>
#include "Card.h"

class Deck {
private:
	void swapCard(Card&, Card&) const;
	std::array<Card, 52> m_deck;
	int m_cardIndex = 0;
public:
	Deck();
	void shuffleDeck();
	void printDeck(const std::array<Card, 52>&) const;
	const Card& dealCard(bool);
};
