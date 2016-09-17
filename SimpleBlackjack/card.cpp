#include "Card.h"

Card::Card()
{
}

Card::Card(CardNum n, CardSuit s)
	: m_num(n), m_suit(s)
{
}

void Card::printCard() const
{
	switch (static_cast<int>(m_num)) {
	case 0:
		std::cout << "2";
		break;
	case 1:
		std::cout << "3";
		break;
	case 2:
		std::cout << "4";
		break;
	case 3:
		std::cout << "5";
		break;
	case 4:
		std::cout << "6";
		break;
	case 5:
		std::cout << "7";
		break;
	case 6:
		std::cout << "8";
		break;
	case 7:
		std::cout << "9";
		break;
	case 8:
		std::cout << "0";
		break;
	case 9:
		std::cout << "J";
		break;
	case 10:
		std::cout << "Q";
		break;
	case 11:
		std::cout << "K";
		break;
	case 12:
		std::cout << "A";
		break;
	}

	switch (static_cast<int>(m_suit)) {
	case 0:
		std::cout << "S" << std::endl;
		break;
	case 1:
		std::cout << "H" << std::endl;
		break;
	case 2:
		std::cout << "C" << std::endl;
		break;
	case 3:
		std::cout << "D" << std::endl;
		break;
	}
}

int Card::getCardValue() const
{
	switch (static_cast<int>(m_num)) {
	case 0:
		return 2;
		break;
	case 1:
		return 3;
		break;
	case 2:
		return 4;
		break;
	case 3:
		return 5;
		break;
	case 4:
		return 6;
		break;
	case 5:
		return 7;
		break;
	case 6:
		return 8;
		break;
	case 7:
		return 9;
		break;
	case 8: case 9: case 10: case 11:
		return 10;
		break;
	case 12:
		return 11;
		break;
	default:
		return 0;
		break;
	}
}
