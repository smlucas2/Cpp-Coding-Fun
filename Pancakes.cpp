#include <iostream>
#include <array>

int main()
{
	std::cout << "Enter 10 numbers for the amount of pancakes eaten by 10 different people.\n";

	int pancakeNum = 0;
	std::array<int, 10> pancakes;
	std::array<int, 10> people = { {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} };
	int pancakeCount = 0;

	do {
		try {
			std::cout << "Enter pancakes eaten by person " << pancakeCount + 1 << " !\n";
			std::cin >> pancakeNum;
			std::cout << "\n";

			if (std::cin.fail() || pancakeNum < 0) {
				throw 0;
			}
			std::cin.ignore(32767, '\n');

			pancakes[pancakeCount] = pancakeNum;
			pancakeCount++;
		}
		catch (...) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Not a valid number, please enter again." << std::endl;
		}
	} while (pancakeCount < 10);

	std::cout << "Here is who ate the most pancakes from most to least!\n";
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (pancakes[j] > pancakes[i]) {
				std::swap(pancakes[j], pancakes[i]);
				std::swap(people[j], people[i]);
			}
		}
		std::cout << "Person " << people[i] << " ate " << pancakes[i] << " pancakes!\n";
	}

	int x;
	std::cin >> x;
	return 0;
}
