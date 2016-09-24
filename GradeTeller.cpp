#include <iostream>

int main()
{
	std::cout << "Enter your grade 1-100." << std::endl;

	int grade;
	bool isNum = false;

	do {
		try {
			std::cin >> grade;
			if (std::cin.fail()) {
				throw 1;
			}
			if (grade < 0 || grade > 100) {
				throw 2;
			}
			std::cin.ignore(32767, '\n');
			isNum = true;
		}
		catch (...) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid grade, please enter again." << std::endl;
		}
	} while (!isNum);

	switch (grade / 10) {
	case 10: case 9:
		std::cout << "You got an \'A\'!" << std::endl;
	case 8:
		std::cout << "You got an \'B\'!" << std::endl;
	case 7:
		std::cout << "You got an \'C\'!" << std::endl;
	case 6:
		std::cout << "You got an \'D\'!" << std::endl;
	default:
		std::cout << "You got an \'F\'!" << std::endl;
		break;
	}

	int x;
	std::cin >> x;
	return 0;
}
