#include <iostream>

int main()
{
	int count = 0;
	int num;

	do {
		std::cout << "Enter any number other than 5.\n";
		std::cin >> num;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			count++;
			continue;
		}
		std::cin.ignore(32767, '\n');
		count++;
	} while (count < 10 && num != 5);

	if (count >= 10) {
		std::cout << "Wow your more patient than I thought, you win.\n";
	}
	else {
		std::cout << "Hey, you were not supposed to enter 5! You win.\n";
	}


	int x;
	std::cin >> x;
	return 0;
}
