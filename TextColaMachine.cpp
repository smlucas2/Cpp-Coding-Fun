#include <iostream>

int main()
{
	std::cout << "Enter the number to pick your favorite beverage.\n1. Coke  2. Water  3. Sprite  4. Doctor Pepper\n";

	int choice;
	bool isNum = false;
	do {
		try {
			std::cin >> choice;
			if (std::cin.fail()) {
				throw 1;
			}
			if (choice < 1 || choice > 4) {
				throw 2;
			}
			std::cin.ignore(32767, '\n');
			isNum = true;
		}
		catch (...) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Error. choice was not valid, here is your money back." << std::endl;
		}
	} while (!isNum);

	switch (choice)
	{
	case 1:
		std::cout << "Here is you Coke!\n";
		break;
	case 2:
		std::cout << "Here is you Water!\n";
		break;
	case 3:
		std::cout << "Here is you Sprite!\n";
		break;
	case 4:
		std::cout << "Here is you Doctor Pepper!\n";
		break;
	default:
		std::cout << "Error 404\n";
	}

	int x;
	std::cin >> x;
	return 0;
}
