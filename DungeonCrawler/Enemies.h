#pragma once

#include "Map.h"

class Enemies
{
private:
	int m_posX = 0;
	int m_posY = 0;
public:
	Enemies();
	void moveMonster(Map&);
	void setPosX(int);
	void setPosY(int);
	int getPosX() const;
	int getPosY() const;
};
