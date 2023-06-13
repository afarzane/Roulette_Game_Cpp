#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	// Initialize Values
	bool GameOver = false;
	int money = 200;
	int guess;
	int bet;
	int randSpin;
	char ans;
	srand(time(0));

	// While game isnt over (Game is over when you have no more money left)
	while(!GameOver)
	{
		// Ask what number they are guessing
		cout << "Select the number you wish to roll (between 1-38): ";
		cin >> guess;
		while (cin.fail() || guess < 1 || guess > 38)
		{
			if (cin.fail())
			{
				cout << "Value entered is not recognized. Please try again" << endl;
			}
			else if (guess < 1 || guess > 38)
			{
				cout << "Value entered is greater or smaller than the given range. Please try again." << endl;
			}
			
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Select the number you wish to roll (between 1-38): ";
			cin >> guess;
		}

		// Ask how much to bet
		cout << "Indicate how much would you like to bet (you have $" << money << "): ";
		cin >> bet;
		while (cin.fail() || bet < 1 || bet > money)
		{
			if (cin.fail())
			{
				cout << "Value entered is not recognized. Please try again" << endl;
			}
			else if (bet < 1 || bet > money)
			{
				cout << "Monetary value not in range. Please try again." << endl;
			}

			cin.clear();
			cin.ignore(256, '\n');
			cout << "Indicate how much would you like to bet (you have $" << money << "): ";
			cin >> bet;
		}

		// Check to see if guess landed on spin
		randSpin = (rand() % 38) + 1;
		money -= bet; // Give bet money to dealer

		cout << "The ball landed on " << randSpin << "!";

		// Win if guess = random spin
		if (guess == randSpin)
		{
			money += bet * 35;
			cout << "You won $" << bet * 35 << "! Your total money is now " << money << ". " << endl;
		}
		else
		{
			cout << "You lost $" << bet << ". Better luck next time!" << endl;
		}
		// If you lose all of your money, then game is over
		if (money <= 0)
		{
			GameOver = true;
			cout << "You lost all of your money. Better luck next time!" << endl;
		}
		else
		{
			// Else you can choose to continue with the money you have left
			cout << "Would you like to continue? [y or n]: ";
			cin >> ans;

			// Check for errors in input
			while (!cin.fail() && ans != 'y' && ans != 'n')
			{
				if (!cin.fail())
				{
					cout << "Value entered is not recognized. Please try again" << endl;
				}
				else if (ans != 'y' && ans != 'n')
				{
					cout << "Wrong character detected. Please try again." << endl;
				}

				cin.clear();
				cin.ignore(256, '\n');
				cout << "Would you like to continue? [y or n]: ";
				cin >> ans;
			}

			// If the player decided to continue, then game is not over
			if (ans == 'y')
			{
				GameOver = false;
				cout << "You have $" << money << " left. We will continue the game." << endl;
			}
			else if(ans == 'n')
			{
				// If player decided to end the game, then terminate program
				GameOver = true;
				cout << "You have a total of $" << money << ". Thank you for playing!" << endl;
			}
		}
	}
	
	return 0;
}
