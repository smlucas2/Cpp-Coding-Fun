#include "Bunny.h"

Bunny::Bunny(Sex g, Fur c, int a, std::string n, bool v)
	:m_gender(g), m_coat(c), m_age(a), m_name(n), m_vampire(v)
{
}

void Bunny::happyBirthday()
{
	m_age += 1;
}

std::string Bunny::printGender() const
{
	if (m_gender == Sex::MALE) {
		return "male";
	}
	else {
		return "female";
	}
}

std::string Bunny::printCoat() const
{
	if (m_coat == Fur::BLACK) {
		return "black";
	}
	else if (m_coat == Fur::BROWN) {
		return "brown";
	}
	else if (m_coat == Fur::WHITE) {
		return "white";
	}
	else {
		return "spotted";
	}
}

std::string Bunny::printVampire() const
{
	if (m_vampire == true) {
		return "is a vampire!";
	}
	else {
		return "is not a vampire.";
	}
}

void Bunny::setAlive(bool b)
{
	m_alive = b;
}

void Bunny::setVampire(bool b)
{
	m_vampire = b;
}

void Bunny::setPosX(int x)
{
	m_posX = x;
}

void Bunny::setPosY(int y)
{
	m_posY = y;
}

Sex Bunny::getGender() const
{
	return m_gender;
}

Fur Bunny::getCoat() const
{
	return m_coat;
}

int Bunny::getAge() const
{
	return m_age;
}

std::string Bunny::getName() const
{
	return m_name;
}

bool Bunny::isVampire() const
{
	return m_vampire;
}

bool Bunny::isAlive() const
{
	return m_alive;
}

int Bunny::getPosX() const
{
	return m_posX;
}

int Bunny::getPosY() const
{
	return m_posY;
}
