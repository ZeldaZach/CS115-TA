/*
 * Demo code for assignment 1 written by Zachary Halpern
 * © 2017 for deomonstration purposes only
 * http://github.com/ZeldaZach
 */

#include <iostream>

int main()
{
	int x, y;
	
	std::cout << "Enter a value for x: ";
	std::cin >> x;
	
	std::cout << "Enter a value for y: ";
	std::cin >> y;
	
	std::cout << x << " + " << y << " = " << x + y << std::endl;
	std::cout << x << " - " << y << " = " << x - y << std::endl;
	std::cout << x << " * " << y << " = " << x * y << std::endl;
	std::cout << x << " / " << y << " = " << x / y << std::endl;
	std::cout << x << " % " << y << " = " << x % y << std::endl;
}