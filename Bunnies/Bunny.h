#pragma once

#include <string>
#include "Enums.h"

class Bunny 
{
private:
	int m_posX = -1;
	int m_posY = -1;
	Sex m_gender;
	Fur m_coat;
	int m_age;
	std::string m_name;
	bool m_vampire;
	bool m_alive = true;
public:
	Bunny(Sex, Fur, int, std::string, bool);
	void happyBirthday();
	std::string printGender() const;
	std::string printCoat() const;
	std::string printVampire() const;
	void setAlive(bool);
	void setVampire(bool);
	void setPosX(int);
	void setPosY(int);
	Sex getGender() const;
	Fur getCoat() const;
	int getAge() const;
	std::string getName() const;
	bool isVampire() const;
	bool isAlive() const;
	int getPosX() const;
	int getPosY() const;
};
