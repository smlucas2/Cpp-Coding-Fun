#include "Map.h"
#include "Enemies.h"

Map::Map()
{
}

void Map::fillMap()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			m_grid[i][j] = " - ";
		}
	}
	m_grid[1][1] = " P ";
	m_grid[8][8] = " E ";
}

void Map::setCord(int x, int y, std::string s)
{
	m_grid[x][y] = s;
}

std::string Map::getCord(int x, int y) const
{
	return m_grid[x][y];
}

void Map::addEnemies(std::array<Enemies, 5> &monsters, std::array<Enemies, 15> &traps)
{
	for (int i = 0; i < 15; i++) {
		while (true) {
			int x = (rand() % 10);
			int y = (rand() % 10);
			Enemies &t = traps[i];
			t.setPosX(x);
			t.setPosY(y);
			if (m_grid[x][y] != " P " && m_grid[x][y] != " T " && m_grid[x][y] != " E ") {
				m_grid[x][y] = " T ";
				break;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		while (true) {
			int x = (rand() % 10);
			int y = (rand() % 10);
			Enemies &m = monsters[i];
			m.setPosX(x);
			m.setPosY(y);
			if (m_grid[x][y] != " P " && m_grid[x][y] != " T " && m_grid[x][y] != " E " && m_grid[x][y] != " M ") {
				m_grid[x][y] = " M ";
				break;
			}
		}
	}
}

void Map::printMap() const
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << m_grid[i][j];
		}
		std::cout << "\n";
	}
}
