#include <ctime>
#include <stdlib.h>
#include "Bunny.h"
#include "Burrow.h"
#include "Pen.h"

void endOfTurn(int &turn, std::ofstream &myfile)
{
	myfile << "========================================================================= " << turn << "\n";
	turn++;
}

int main() 
{
	srand(static_cast<int>(time(0)));

	Burrow family;
	Pen enclosure;

	family.fillNameList();

	std::ofstream myfile;
	myfile.open("Situation.txt");

	enclosure.fillPen();
	family.makeStartingBunnies(myfile, enclosure);

	int turn = 0;
	while (!family.getFamily().empty()) {
		int deadBunnies = 0;
		enclosure.insertBunnies(family);
		enclosure.printPen();
		family.ageBunnies(deadBunnies, myfile);
		family.cullOnCommand(deadBunnies, myfile);
		family.cullOverPopulation(deadBunnies, myfile);
		family.clearDead(deadBunnies, enclosure);
		Sleep(500);
		system("cls");
		family.spreadVampirism(myfile, enclosure);
		family.reproduce(myfile, enclosure);
		enclosure.moveRabbits(family);
		family.printFamily(myfile);
		endOfTurn(turn, myfile);
	}

	myfile << "\nYour bunny civilization survived for " << turn << " years!\n";

	myfile.close();

	int x;
	std::cin >> x;
	return 0;
}
