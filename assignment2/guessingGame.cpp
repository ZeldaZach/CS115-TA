/*
 * Demo code for assignment 2 written by Zachary Halpern
 * © 2017 for deomonstration purposes only
 * http://github.com/ZeldaZach
 */

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
int main()
{
	int randomNumber, guess = 0, timesGuessed = 1;
	
	// Random number generated
	srand(static_cast<unsigned>(time(NULL)));
	randomNumber = ((rand() % 100) + 1); // [1,100]
	
	while (true)
	{
		cout << "Enter a guess: ";
		cin >> guess;
		
		if (timesGuessed > 5)
		{
			cout << "You ran out of tries, better luck next time! The random number was " << randomNumber << endl;
			break;
		}
		else if (guess > randomNumber)
		{
			cout << "Incorrect guess, the number is lower." << endl;
		}
		else if (guess < randomNumber)
		{
			cout << "Incorrect guess, the number is higher." << endl;
		}
		else
		{
			cout << "Correct guess! You took " << timesGuessed << " tries." << endl;
			break;
		}

		timesGuessed++;		
	}

	return 0;
}