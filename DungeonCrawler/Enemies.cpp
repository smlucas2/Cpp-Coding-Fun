#include "Enemies.h"

Enemies::Enemies()
{
}

void Enemies::moveMonster(Map &m)
{
		int move = rand() % 4 + 1;
		if (move == 1) {
			if (m_posX >= 9 || m.getCord(m_posX + 1, m_posY) == " T " || m.getCord(m_posX + 1, m_posY) == " M " || m.getCord(m_posX + 1, m_posY) == " E "){
				return;
			}
			m.setCord(m_posX, m_posY, " - ");
			m.setCord(m_posX + 1, m_posY, " M ");
			m_posX += 1;
		}
		else if (move == 2) {
			if (m_posX <= 0 || m.getCord(m_posX - 1, m_posY) == " T " || m.getCord(m_posX - 1, m_posY) == " M " || m.getCord(m_posX - 1, m_posY) == " E ") {
				return;
			}
			m.setCord(m_posX, m_posY, " - ");
			m.setCord(m_posX - 1, m_posY, " M ");
			m_posX -= 1;
		}
		else if (move == 3) {
			if (m_posY >= 9 || m.getCord(m_posX, m_posY + 1) == " T " || m.getCord(m_posX, m_posY + 1) == " M " || m.getCord(m_posX, m_posY + 1) == " E ") {
				return;
			}
			m.setCord(m_posX, m_posY, " - ");
			m.setCord(m_posX, m_posY + 1, " M ");
			m_posY += 1;
		}
		else {
			if (m_posY <= 0 || m.getCord(m_posX, m_posY - 1) == " T " || m.getCord(m_posX, m_posY - 1) == " M " || m.getCord(m_posX, m_posY - 1) == " E ") {
				return;
			}
			m.setCord(m_posX, m_posY, " - ");
			m.setCord(m_posX, m_posY - 1, " M ");
			m_posY -= 1;
		}
}

void Enemies::setPosX(int x)
{
	m_posX = x;
}

void Enemies::setPosY(int y)
{
	m_posY = y;
}

int Enemies::getPosX() const
{
	return m_posX;
}

int Enemies::getPosY() const
{
	return m_posY;
}
