#include "Deck.h"

Deck::Deck() 
{
	for (int i{ 0 }; i < 52; i++) {
		m_deck[i] = Card(static_cast<Card::CardNum>(i % 13), static_cast<Card::CardSuit>(i / 13));
	}
}

void Deck::printDeck(const std::array<Card, 52> &d) const
{
	for (Card c : d) {
		c.printCard();
	}
}

void Deck::swapCard(Card &c1, Card &c2) const
{
	Card temp = c1;
	c1 = c2;
	c2 = temp;
}

void Deck::shuffleDeck()
{
	srand(static_cast<unsigned int>(time(0)));
	for (int i{ 0 }; i < 52; i++) {
		int num = static_cast<int>(rand() % 52);
		swapCard(m_deck[i], m_deck[num]);
	}

	m_cardIndex = 0;
}

const Card& Deck::dealCard(bool p)
{
	if (p) {
		std::cout << "You draw a ";
		m_deck[m_cardIndex].printCard();
	}
	else {
		std::cout << "The dealer draws..." << std::endl;
	}

	return m_deck[m_cardIndex++];
}
