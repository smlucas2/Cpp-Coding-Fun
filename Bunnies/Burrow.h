#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <Windows.h>
#include "Bunny.h"

class Pen;

class Burrow
{
private:
	std::array<std::string, 100> m_nameListBoy;
	std::array<std::string, 100> m_nameListGirl;
	std::vector<Bunny> m_family;
public:
	void fillNameList();
	void setCharacteristics(int&, std::string&, bool&);
	void makeStartingBunnies(std::ofstream&, Pen&);
	void cullOverPopulation(int&, std::ofstream&);
	void reproduce(std::ofstream&, Pen&);
	void ageBunnies(int&, std::ofstream&);
	void cullOnCommand(int&, std::ofstream&);
	void spreadVampirism(std::ofstream&, Pen&);
	void clearDead(int&, Pen&);
	void printFamily(std::ofstream&);
	std::vector<Bunny>& getFamily();
};
