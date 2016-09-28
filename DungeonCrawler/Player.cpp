#include "Player.h"

Player::Player(int x, int y)
	:m_posX(x), m_posY(y)
{
}

//Makes sure the user enters viable input.
void Player::checkUserInput(char &move)
{
	bool isAllowed = false;
	do {
		try {
			std::cin >> move;
			if (std::cin.fail() || (move != 'a' && move != 'd' && move != 's' && move != 'w')) {
				throw 0;
			}
			std::cin.ignore(32767, '\n');
			isAllowed = true;
		}
		catch (...) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Not valid movement, try again (use lower case).\n";
		}
	} while (!isAllowed);
}

//Dictates what happens when the user enters a movement key
void Player::playerMove(Map &m, bool &alive)
{
	char movement = ' ';
	checkUserInput(movement);
	if (movement == 'a') {
		if (m_posX == 0) {
			return;
		}
		else if (m.getCord(m_posY, m_posX - 1) == " E ") {
			m.setCord(m_posY, m_posX - 1, " P ");
			m.setCord(m_posY, m_posX, " - ");
		}
		else if (m.getCord(m_posY, m_posX - 1) == " T " || m.getCord(m_posY, m_posX - 1) == " M ") {
			alive = false;
			m.setCord(m_posY, m_posX, " - ");
		}
		else {
			m.setCord(m_posY, m_posX, " - ");
			m.setCord(m_posY, m_posX - 1, " P ");
			m_posX -= 1;
		}
	}
	else if (movement == 'd') {
		if (m_posX == 9) {
			return;
		}
		else if (m.getCord(m_posY, m_posX + 1) == " E ") {
			m.setCord(m_posY, m_posX + 1, " P ");
			m.setCord(m_posY, m_posX, " - ");
		}
		else if (m.getCord(m_posY, m_posX + 1) == " T " || m.getCord(m_posY, m_posX + 1) == " M ") {
			alive = false;
			m.setCord(m_posY, m_posX, " - ");
		}
		else {
			m.setCord(m_posY, m_posX, " - ");
			m.setCord(m_posY, m_posX + 1, " P ");
			m_posX += 1;
		}
	}
	else if (movement == 'w') {
		if (m_posY == 0) {
			return;
		}
		else if (m.getCord(m_posY - 1, m_posX) == " E ") {
			m.setCord(m_posY - 1, m_posX, " P ");
			m.setCord(m_posY, m_posX, " - ");
		}
		else if (m.getCord(m_posY - 1, m_posX) == " T " || m.getCord(m_posY - 1, m_posX) == " M ") {
			alive = false;
			m.setCord(m_posY, m_posX, " - ");
		}
		else {
			m.setCord(m_posY, m_posX, " - ");
			m.setCord(m_posY - 1, m_posX, " P ");
			m_posY -= 1;
		}
	}
	else {
		if (m_posY == 9) {
			return;
		}
		else if (m.getCord(m_posY + 1, m_posX) == " E ") {
			m.setCord(m_posY + 1, m_posX, " P ");
			m.setCord(m_posY, m_posX, " - ");
		}
		else if (m.getCord(m_posY + 1, m_posX) == " T " || m.getCord(m_posY + 1, m_posX) == " M ") {
			alive = false;
			m.setCord(m_posY, m_posX, " - ");
		}
		else {
			m.setCord(m_posY, m_posX, " - ");
			m.setCord(m_posY + 1, m_posX, " P ");
			m_posY += 1;
		}
	}
}

void Player::setPosX(int x)
{
	m_posX = x;
}

void Player::setPosY(int y)
{
	m_posY = y;
}

int Player::getPosX() const
{
	return m_posX;
}

int Player::getPosY() const
{
	return m_posY;
}
