#include "Burrow.h"
#include "Pen.h"

void Burrow::fillNameList()
{
	std::ifstream input;
	input.open("BoyNames.txt");
	for (int i = 0; i < 100; i++)
	{
		std::string line;
		std::getline(input, line);
		m_nameListBoy[i] = line;
	}
	input.close();

	input.open("GirlNames.txt");
	for (int i = 0; i < 100; i++)
	{
		std::string line;
		std::getline(input, line);
		m_nameListGirl[i] = line;
	}
	input.close();
}

void Burrow::setCharacteristics(int &sex, std::string &name, bool &vamp)
{
	sex = rand() % 2;
	if (sex == 0) {
		name = m_nameListBoy[rand() % 100];
	}
	else {
		name = m_nameListGirl[rand() % 100];
	}

	int roll = (rand() % 100) + 1;
	if (roll > 98) {
		vamp = true;
	}
	else {
		vamp = false;
	}
}

void Burrow::makeStartingBunnies(std::ofstream &myFile, Pen &pen)
{
	myFile << "FIVE BUNNIES ARE STARTING A CIVILIZATION! THEY ARE:\n";
	for (int i = 0; i < 5; i++) {
		int sex;
		bool vamp;
		std::string name;
		setCharacteristics(sex, name, vamp);

		Bunny b(static_cast<Sex>(sex), static_cast<Fur>(rand() % 4), (rand() % 9 + 1), name, vamp);

		int x = rand() % 40;
		int y = rand() % 150;
		while (pen.getPen()[x][y] != '-') {
			x = rand() % 40;
			y = rand() % 150;
		}

		b.setPosX(x);
		b.setPosY(y);

		m_family.push_back(b);
	}

	for (Bunny &b : m_family) {
		myFile << b.getName() << ", age " << b.getAge() << " who is " << b.printGender() << " with a " << b.printCoat() << " coat and "
			<< b.printVampire() << "\n";
	}
	myFile << "========================================================================= \n";
}

void Burrow::cullOverPopulation(int &dB, std::ofstream &myFile)
{
	if (m_family.size() >= 1000) {
		std::cout << "TOO MANY BUNNIES, THEY ARE STARVING!\n";
		Sleep(1500);
		myFile << "TOO MANY BUNNIES, THEY ARE STARVING!\n";
		int count = 0;
		int selected;

		while (count < 500) {
			selected = (rand() % m_family.size());

			while (!m_family[selected].isAlive()) {
				selected = (rand() % m_family.size());
			}

			Bunny &hungryBunny = m_family[selected];
			myFile << hungryBunny.getName() << " has died of starvation!\n";
			hungryBunny.setAlive(false);
			count++;
			dB++;
		}
	}
}

void Burrow::reproduce(std::ofstream &myFile, Pen &pen)
{
	myFile << "BUNNIES BORN:\n";
	
	//Look for one male bunny.
	for (int i = 0; i < static_cast<int>(m_family.size()); i++) {
		Bunny &bunM = m_family[i];
		if (bunM.isAlive() && bunM.getGender() == Sex::MALE && bunM.getAge() >= 2 && !bunM.isVampire()) {
			//Look for all of the female bunnies
			for (int j = 0; j < static_cast<int>(m_family.size()); j++) {
				Bunny &bunF = m_family[j];
				if (bunF.isAlive() && bunF.getGender() == Sex::FEMALE && bunF.getAge() >= 2 && !bunF.isVampire()) {
					int x = bunF.getPosX();
					int y = bunF.getPosY();
					//If no room around mother, do not try to have a baby from this rabbit.
					if ((x >= 39 || pen.getPen()[x + 1][y] != '-') && (x <= 0 || pen.getPen()[x - 1][y] != '-') &&
						(y >= 149 || pen.getPen()[x][y + 1] != '-') && (y <= 0 || pen.getPen()[x][y - 1] != '-')) {
						continue;
					}
					else {
						while (true) {
							int placement = rand() % 4 + 1;
							int posX;
							int posY;

							switch (placement) {
							case 1:
								posX = bunF.getPosX() + 1;
								posY = bunF.getPosY();
								break;
							case 2:
								posX = bunF.getPosX() - 1;
								posY = bunF.getPosY();
								break;
							case 3:
								posX = bunF.getPosX();
								posY = bunF.getPosY() + 1;
								break;
							case 4:
								posX = bunF.getPosX();
								posY = bunF.getPosY() - 1;
								break;
							default:
								return;
							}

							if (posX <= 39 && posX >= 0 && posY <= 149 && posY >= 0 && pen.getPenChar(posX, posY) == '-') {
								//says that this position is now occupied so that other bunnies cannot be born here.
								pen.setPen(posX, posY, 'x');
								int sex;
								bool vamp;
								std::string name;
								setCharacteristics(sex, name, vamp);

								Bunny b(static_cast<Sex>(sex), bunF.getCoat(), 0, name, vamp);
								b.setPosX(posX);
								b.setPosY(posY);
								myFile << b.getName() << " has been born from " << bunF.getName() << "!";
								if (b.isVampire()) {
									myFile << " This rabbit is different than the others...";
								}
								myFile << "\n";
								m_family.push_back(b);
								break;
							}
						}
					}
				}
			}
			//We only needed one male, so exit the loop and stop looking for males
			break;
		}
	}
}

void Burrow::ageBunnies(int &dB, std::ofstream &myFile)
{
	myFile << "BUNNIES DIED:\n";
	for (Bunny &bunny : m_family) {
		if (!bunny.isVampire() && bunny.getAge() >= 10 && bunny.isAlive()) {
			myFile << bunny.getName() << " has died of old age.\n";
			bunny.setAlive(false);
			dB++;
		}
		else if (bunny.isVampire() && bunny.getAge() >= 50 && bunny.isAlive()) {
			myFile << bunny.getName() << " has died of old age.\n";
			bunny.setAlive(false);
			dB++;
		}
		else {
			bunny.happyBirthday();
		}
	}
}

void Burrow::cullOnCommand(int &dB, std::ofstream &myFile)
{
	std::cout << "PRESS \"k\" IF YOU WANT TO KILL HALF THE RABBITS\n";
	std::cout << m_family.size() << "\n";
	if (GetAsyncKeyState(0x4B)) {
		int count = 0;
		int hungryBunny;
		while (count < static_cast<int>(m_family.size()) / 2) {
			hungryBunny = (rand() % m_family.size());
			while (m_family[hungryBunny].isAlive() == false) {
				hungryBunny = (rand() % m_family.size());
			}
			myFile << m_family[hungryBunny].getName() << " has been culled!\n";
			m_family[hungryBunny].setAlive(false);
			count++;
			dB++;
		}
	}
}

void Burrow::spreadVampirism(std::ofstream &myFile, Pen &pen)
{
	myFile << "BUNNIES INFECTED:\n";

	//Look for vampires in all the bunnies.
	for (int i = 0; i < static_cast<int>(m_family.size()); i++) {
		//If this bunny is not a vampire, try the next bunny
		if (m_family[i].isVampire() == false) {
			continue;
		}

		Bunny &vamp = m_family[i];
		//choose a random direction to start
		int selection = rand() % 4;;
		int x = -1;
		int y = -1;
		int count = 0;

		//Keep going until we have looked in all 4 directions.
		while (count < 4) {
			switch (selection) {
			case 0:
				if (vamp.getPosX() + 1 >= 40) {
					break;
				}
				x = vamp.getPosX() + 1;
				y = vamp.getPosY();
				break;
			case 1:
				if (vamp.getPosY() + 1 >= 150) {
					break;
				}
				x = vamp.getPosX();
				y = vamp.getPosY() + 1;
				break;
			case 2:
				if (vamp.getPosX() - 1 <= 0) {
					break;
				}
				x = vamp.getPosX() - 1;
				y = vamp.getPosY();
				break;
			case 3:
				if (vamp.getPosY() - 1 <= 0) {
					break;
				}
				x = vamp.getPosX();
				y = vamp.getPosY() - 1;
				break;
			default:
				break;
			}

			//turn 90 degrees if there was edge/nothing/vamp in that direction.
			if ((x == -1 && y == -1) || pen.getPenChar(x, y) == '-' || pen.getPenChar(x, y) == 'V') {
				selection = (selection + 1) % 4;
				count++;
				continue;
			}

			//if we have found a suitable bunny
			else {
				//find the bunny who is at these coordinates and infect them.
				for (Bunny &bun : m_family) {
					if (bun.getPosX() == x && bun.getPosY() == y) {
						bun.setVampire(true);
						myFile << bun.getName() << " is now a vampire!\n";
						//Once we infect that bunny we do not need to search for it any longer
						break;
					}
				}
				//go to the next vampire.
				break;
			}
		}		
	}
}

void Burrow::clearDead(int &dB, Pen &pen)
{
	int length = m_family.size();
	//Sort vector so all dead bunnies are at the front.
	for (int i = 0; i < length - 1; i++) {
		for (int j = i; j < length; j++) {
			if (!m_family[j].isAlive()) {
				pen.setPen(m_family[j].getPosX(), m_family[j].getPosY(), '-');
				std::swap(m_family[i], m_family[j]);
				break;
			}
		}
	}
	m_family.erase(m_family.begin(), m_family.begin() + dB);
}

void Burrow::printFamily(std::ofstream &myFile)
{
	myFile << "\nYOUR CURRENT BUNNIES ARE:\n";
	int length = m_family.size();
	for (int i = 0; i < length - 1; i++) {
		for (int j = i + 1; j < length; j++) {
			if (m_family[j].getAge() > m_family[i].getAge()) {
				std::swap(m_family[j], m_family[i]);
			}
		}
	}
	for (int i = 0; i < length; i++) {
		Bunny b = m_family[i];
		myFile << b.getName() << ", age " << b.getAge() << " who is " << b.printGender() << " with a " << b.printCoat() << " coat and "
			<< b.printVampire() << "\n";
	}
}

std::vector<Bunny>& Burrow::getFamily()
{
	return m_family;
}
