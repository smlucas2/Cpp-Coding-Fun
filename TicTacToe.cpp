#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <ctime>
#include <Windows.h>

//Looks to see if a spot has been chosen already.
bool beenPicked(std::vector<int> &placed, int selection) 
{
	return std::find(placed.begin(), placed.end(), selection) != placed.end();
}

//Looks at a pair of two points that line up on the grid to see if they match (i.e. someone is about to win)
bool bestMove(std::array<std::array<char, 3>, 3> &grid, int x1, int y1, int x2, int y2)
{
	return ((grid[x1][y1] == 'O' && grid[x2][y2] == 'O') || (grid[x1][y1] == 'X' && grid[x2][y2] == 'X'));
}

//Makes sure the user inputs a number that has a spot still open and is valid.
void isAvailableSpace(int &selection, std::vector<int> &placed, int min, int max) {
	bool isNum = false;
	do {
		try {
			std::cin >> selection;
			if (std::cin.fail() || beenPicked(placed, selection) ||
				selection < min || selection > max) {
				throw 0;
			}
			std::cin.ignore(32767, '\n');
			isNum = true;
		}
		catch (...) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "\nThat position is either taken or does not exist, try again!\n";
		}
	} while (!isNum);
	placed.push_back(selection);
}

//How the computer decides what position to pick based on what the user has picked.
void computerChoosing(int &selection, std::vector<int> &placed, std::array<std::array<char, 3>, 3> &grid)
{
	//Checks all horizontal moves.
	if (!beenPicked(placed, 3) && bestMove(grid, 0, 0, 0, 1)) {
		selection = 3;
	}
	else if (!beenPicked(placed, 2) && bestMove(grid, 0, 0, 0, 2)) {
		selection = 2;
	}
	else if (!beenPicked(placed, 1) && bestMove(grid, 0, 1, 0, 2)) {
		selection = 1;
	}
	else if (!beenPicked(placed, 6) && bestMove(grid, 1, 0, 1, 1)) {
		selection = 6;
	}
	else if (!beenPicked(placed, 5) && bestMove(grid, 1, 0, 1, 2)) {
		selection = 5;
	}
	else if (!beenPicked(placed, 4) && bestMove(grid, 1, 1, 1, 2)) {
		selection = 4;
	}
	else if (!beenPicked(placed, 9) && bestMove(grid, 2, 0, 2, 1)) {
		selection = 9;
	}
	else if (!beenPicked(placed, 8) && bestMove(grid, 2, 0, 2, 2)) {
		selection = 8;
	}
	else if (!beenPicked(placed, 7) && bestMove(grid, 2, 1, 2, 2)) {
		selection = 7;
	}

	//Checks vertical moves.
	else if (!beenPicked(placed, 7) && bestMove(grid, 0, 0, 1, 0)) {
		selection = 7;
	}
	else if (!beenPicked(placed, 4) && bestMove(grid, 0, 0, 2, 0)) {
		selection = 4;
	}
	else if (!beenPicked(placed, 1) && bestMove(grid, 1, 0, 2, 0)) {
		selection = 1;
	}
	else if (!beenPicked(placed, 8) && bestMove(grid, 0, 1, 1, 1)) {
		selection = 8;
	}
	else if (!beenPicked(placed, 5) && bestMove(grid, 0, 1, 2, 1)) {
		selection = 5;
	}
	else if (!beenPicked(placed, 2) && bestMove(grid, 1, 1, 2, 1)) {
		selection = 2;
	}
	else if (!beenPicked(placed, 9) && bestMove(grid, 0, 2, 1, 2)) {
		selection = 9;
	}
	else if (!beenPicked(placed, 6) && bestMove(grid, 2, 2, 0, 2)) {
		selection = 6;
	}
	else if (!beenPicked(placed, 3) && bestMove(grid, 1, 2, 2, 2)) {
		selection = 3;
	}

	//Checks diagonal moves.
	else if (!beenPicked(placed, 1) && bestMove(grid, 1, 1, 2, 2)) {
		selection = 1;
	}
	else if (!beenPicked(placed, 5) && bestMove(grid, 0, 0, 2, 2)) {
		selection = 5;
	}
	else if (!beenPicked(placed, 9) && bestMove(grid, 0, 0, 1, 1)) {
		selection = 9;
	}
	else if (!beenPicked(placed, 3) && bestMove(grid, 1, 1, 2, 0)) {
		selection = 3;
	}
	else if (!beenPicked(placed, 5) && bestMove(grid, 0, 2, 2, 0)) {
		selection = 5;
	}
	else if (!beenPicked(placed, 7) && bestMove(grid, 0, 2, 1, 1)) {
		selection = 7;
	}

	//Picks a random number, loops until it picks one that hasn't been chosen yet.
	else		{
		while (true) {
			srand(static_cast<int>(time(0)));
			selection = (rand() % 9 + 1);
			if (!beenPicked(placed, selection)) {
				break;
			}
		}
	}

	std::cout << "The computer chooses " << selection << "!\n";
	placed.push_back(selection);
}

//How we place the character into its respective position on the grid.
void placeCharacter(std::array<std::array<char, 3>, 3> &grid, int placement, char c) 
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (placement == 1 + j + (i * 3)) {
				grid[i][j] = c;
			}
		}
	}
}

void printGrid(std::array<std::array<char, 3>, 3> &g) 
{
	std::cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << g[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

//Looks for three of the same character in a row to determine if the user or computer won yet.
int winCondition(std::array<std::array<char, 3>, 3> &grid)
{
	int counterX = 0;
	int counterO = 0;

	//Looks for winning horizontally.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid[i][j] == 'X') {
				counterX++;
				counterO = 0;
			}
			if (grid[i][j] == 'O') {
				counterO++;
				counterX = 0;
			}
		}
		if (counterX == 3) {
			return 1;
		}
		if (counterO == 3) {
			return 2;
		}
		counterO = 0;
		counterX = 0;
	}

	//Looks for winning vertically.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid[j][i] == 'X') {
				counterX++;
				counterO = 0;
			}
			if (grid[j][i] == 'O') {
				counterO++;
				counterX = 0;
			}
		}
		if (counterX == 3) {
			return 1;
		}
		if (counterO == 3) {
			return 2;
		}
		counterO = 0;
		counterX = 0;
	}

	//Looks for winning diagonally.
	if (grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O') {
		return 2;
	}
	if (grid[0][2] == 'O' && grid[1][1] == 'O' && grid[2][0] == 'O') {
		return 2;
	}

	if (grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X') {
		return 1;
	}
	if (grid[0][2] == 'X' && grid[1][1] == 'X' && grid[2][0] == 'X') {
		return 1;
	}
	
	return 0;
}

int main()
{
	std::cout << "Lets play a game of tictactoe!\nYou can be X's, so you get to go first.\nPick an empty position by typing the number.\n";
	std::array<std::array<char, 3>, 3> grid = { { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} } };
	printGrid(grid);

	int userSelection;
	int compSelection;
	int counter = 0;
	std::vector<int> placed;
	int win = 0;

	while (win == 0 && counter < 9) {
		isAvailableSpace(userSelection, placed, 1, 9);
		placeCharacter(grid, userSelection, 'X');
		counter++;
		printGrid(grid);
		win = winCondition(grid);

		if (win == 0 && counter < 9) {
			//Makes it look like the computer is thinking about its next more.
			std::cout << "The computer is thinking...\n";
			Sleep(2000);
			
			computerChoosing(compSelection, placed, grid);
			placeCharacter(grid, compSelection, 'O');
			counter++;
			printGrid(grid);
			win = winCondition(grid);
		}
	}

	if (win == 1) {
		std::cout << "You win!\n";
	}
	if (win == 2) {
		std::cout << "You Lose!\n";
	}
	if (win == 0) {
		std::cout << "No moves left, tie!\n";
	}

	int x;
	std::cin >> x;
	return 0;
}
