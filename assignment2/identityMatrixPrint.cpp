/*
* Demo code for assignment 2 written by Zachary Halpern
* © 2017 for deomonstration purposes only
* http://github.com/ZeldaZach
*/

#include <iostream>

using namespace std;
int main()
{
	int size;
	
	cout << "Enter a size for your identity matrix: ";
	cin >> size;
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
			{
				cout << "1 ";
			}
			else
			{
				cout << "0 ";
			}
		}
		
		cout << endl;
	}
	return 0;
}