#pragma once

#include <array>
#include <iostream>
#include "Burrow.h"

class Pen
{
private:
	std::array<std::array <char, 150>, 40> m_pen;
public:
	void fillPen();
	void printPen() const;
	//Places the rabbits in their pen.
	void insertBunnies(Burrow&);
	void moveRabbits(Burrow&);
	char getPenChar(int, int) const;
	std::array<std::array <char, 150>, 40> getPen() const;
	void setPen(int, int, char);
};
