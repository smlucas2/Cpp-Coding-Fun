#include "Pen.h"

void Pen::fillPen()
{
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 150; j++) {
			m_pen[i][j] = '-';
		}
	}
}

void Pen::printPen() const
{
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 150; j++) {
			std::cout << m_pen[i][j];
		}
		std::cout << "\n";
	}
}

void Pen::insertBunnies(Burrow &b)
{
	for (Bunny &bun : b.getFamily()) {
		int x = bun.getPosX();
		int y = bun.getPosY();

		if (bun.isVampire()) {
			m_pen[x][y] = 'V';
		}
		else if (bun.getGender() == Sex::MALE && bun.getAge() >= 2) {
			m_pen[x][y] = 'M';
		}
		else if (bun.getGender() == Sex::FEMALE && bun.getAge() >= 2) {
			m_pen[x][y] = 'F';
		}
		else if (bun.getGender() == Sex::MALE) {
			m_pen[x][y] = 'm';
		}
		else {
			m_pen[x][y] = 'f';
		}
	}
}

void Pen::moveRabbits(Burrow &b)
{
	for (Bunny &bun : b.getFamily()) {
		int x = bun.getPosX();
		int y = bun.getPosY();
		int move = rand() % 4 + 1;
		if (move == 1) {
			if (x < 39 && m_pen[x + 1][y] == '-') {
				m_pen[x][y] = '-';
				bun.setPosX(x + 1);
				
			}
		}
		else if (move == 2) {
			if (x > 0 && m_pen[x - 1][y] == '-') {
				m_pen[x][y] = '-';
				bun.setPosX(x - 1);
			}
		}
		else if (move == 3) {
			if (y < 149 && m_pen[x][y + 1] == '-') {
				m_pen[x][y] = '-';
				bun.setPosY(y + 1);
			}
		}
		else {
			if (y > 0 && m_pen[x][y - 1] == '-') {
				m_pen[x][y] = '-';
				bun.setPosY(y - 1);
			}
		}
	}
}

char Pen::getPenChar(int x, int y) const
{
	return m_pen[x][y];
}

std::array<std::array <char, 150>, 40> Pen::getPen() const
{
	return m_pen;
}

void Pen::setPen(int x, int y, char z)
{
	m_pen[x][y] = z;
}
