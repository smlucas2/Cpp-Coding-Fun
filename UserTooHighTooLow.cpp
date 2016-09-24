#include <iostream>
#include <ctime>

int main()
{
	srand(static_cast<int>(time(0)));
	int randomNum = rand() % 100 + 1;

	int guess;
	int totalGuesses = 0;
	std::cout << "Guess a number between 1 and 100\n";

	do {
		try {
			std::cin >> guess;
			if (std::cin.fail() || guess < 1 || guess > 100) {
				throw 0;
			}
			std::cin.ignore(32767, '\n');
			if (guess < randomNum) {
				std::cout << "Too low.\n";
			}
			if (guess > randomNum) {
				std::cout << "Too high.\n";
			}
			totalGuesses++;
		}
		catch (...) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid number, try again.\n";
			}
	}	while (guess != randomNum);

	std::cout << "You win!\nIt took you " << totalGuesses << " guesses.\n";

	int x;
	std::cin >> x;
	return 0;
}
