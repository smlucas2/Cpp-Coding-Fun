#pragma once

#include <array>
#include <string>
#include <iostream>

class Enemies;

class Map
{
private:
	const int m_height = 10;
	const int m_width = 10;
	std::array<std::array<std::string, 10>, 10> m_grid;
public:
	Map();
	void fillMap();
	void printMap() const;
	void addEnemies(std::array<Enemies, 5>&, std::array<Enemies, 15>&);
	void setCord(int, int, std::string);
	std::string getCord(int, int) const;
};
