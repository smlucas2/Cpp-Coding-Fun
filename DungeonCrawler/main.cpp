#include <iostream>
#include <ctime>
#include <array>
#include <stdlib.h>
#include "Player.h"
#include "Enemies.h"
#include "Map.h"

int main()
{
	srand(static_cast<int>(time(0)));
	
	bool alive = true;
	Player theUser(1, 1);
	Map map;
	std::array<Enemies, 15> traps;
	std::array<Enemies, 5> monsters;

	map.fillMap();
	map.addEnemies(monsters, traps);
	map.printMap();
	
	std::cout << "You are player \"P\", try to get to the exit \"E\" without touching monsters \"M\" or traps \"T\"!\n";
	std::cout << "Press \"a\" to move left, \"d\" to move right, \"s\" to move down, and \"w\" to move up.\n";

	do {
		for (int i = 0; i < 5; i++) {
			monsters[i].moveMonster(map);
		}
		theUser.playerMove(map, alive);
		//Bad practice I know, but makes this program look a lot prettier.
		system("cls");
		map.printMap();
	} while (map.getCord(8, 8) != " P " && alive);

	if (alive) {
		std::cout << "You win!\n";
	}
	else {
		std::cout << "You died!\n";
	}

	int x;
	std::cin >> x;
	return 0;
}
