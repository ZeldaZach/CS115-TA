/*
 * Demo code for assignment 2 written by Zachary Halpern
 * © 2017 for deomonstration purposes only
 * http://github.com/ZeldaZach
 */

#include <iostream>

using namespace std;
int main()
{
	int first, second, third, maximum;
	
	// Read in variables
	cout << "Please enter integer #1 : ";
	cin >> first;
	cout << "Please enter integer #2 : ";
	cin >> second;
	cout << "Please enter integer #3 : ";
	cin >> third;

	if (first >= second)
	{
		if (first > third)
		{
			maximum = first;
		}
		else
		{
			maximum = third;
		}
	}
	else
	{
		if (second > third)
		{
			maximum = second;
		}
		else
		{
			maximum = third;
		}
	}
	
	cout << "Input first integer: " << first << endl;
	cout << "Input second integer: " << second << endl;
	cout << "Input third integer: " << third << endl;
	cout << "The max integer is " << maximum << endl;

	return 0;
}