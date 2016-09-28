#pragma once

#include "Map.h"

class Player
{
private:
	int m_posX;
	int m_posY;
public:
	Player(int, int);
	void checkUserInput(char&);
	void playerMove(Map&, bool&);
	void setPosX(int);
	void setPosY(int);
	int getPosX() const;
	int getPosY() const;
};
