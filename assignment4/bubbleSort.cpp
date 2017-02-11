/*
 * Demo code for assignment 4 written by Zachary Halpern
 * © 2017 for deomonstration purposes only
 * http://github.com/ZeldaZach
 */

#include <iostream>
#include <fstream>
#include <string>

const static int ARRAY_SIZE = 10;
void SortAscending(int data[], int count);
void SortDescending(int data[], int count);
void printArray(int data[], int count);

int main()
{
	int nums[ARRAY_SIZE];
	std::string line;

	// Open "data.txt" for reading only
	std::ifstream file;
	file.open("data.txt", std::ios::in);

	/*
	 * For each line, turn it to an integer and 
	 * add it to the array
	 */
	for (int i = 0; getline(file, line); i++)
		nums[i] = std::stoi(line);

	std::cout << "Data before sorting" << std::endl;
	printArray(nums, ARRAY_SIZE);
	
	SortAscending(nums, ARRAY_SIZE);
	std::cout << "Data after sorting ascending" << std::endl;
	printArray(nums, ARRAY_SIZE);
	
	SortDescending(nums, ARRAY_SIZE);
	std::cout << "Data after sorting descending" << std::endl;
	printArray(nums, ARRAY_SIZE);

	return 0;
}

void printArray(int data[], int count)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;
}

void SortAscending(int data[], int count)
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count-1; j++)
		{
			if (data[j+1] < data[j])
			{
				int tmp = data[j];
				data[j] = data[j+1];
				data[j+1] = tmp;
			}
		}
	}
}

void SortDescending(int data[], int count)
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count-1; j++)
		{
			if (data[j+1] > data[j])
			{
				int tmp = data[j];
				data[j] = data[j+1];
				data[j+1] = tmp;
			}
		}
	}
}
