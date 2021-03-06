// RotateMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#define MAX_MATRIX_SIZE  4

void rotateMatrix90(int matrix[][MAX_MATRIX_SIZE], int n)
{
	if (n > MAX_MATRIX_SIZE)
	{
		return;
	}

	for (int layer = 0; layer < n/2; ++layer)
	{
		int first = layer;
		int last = n - 1 - layer;

		for (int i = first; i < last; ++i)
		{
			int offset = i - first;
			// top    = matrix[first][i];
			// right  = matrix[i][last];
			// bottom = matrix[last][last-offset];
			// left   = matrix[last-offset][first];

			int left = matrix[last - offset][first];
			// top --> left
			matrix[last - offset][first] = matrix[first][i];
			// right --> top
			matrix[first][i] = matrix[i][last];
			// bottom ---> right
			matrix[i][last] = matrix[last][last-offset];
			//left -> bottom
			matrix[last][last-offset] = left;
		}
	}
}

void printMatrix(int matrix[][MAX_MATRIX_SIZE], int n)
{
	for (int i = 0; i < MAX_MATRIX_SIZE; ++i)
	{
		for (int j = 0; j < MAX_MATRIX_SIZE; ++j)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	int test_matrix[4][4] = { \
		{1,  2, 3, 4}, \
		{5,  6, 7, 8}, \
		{9, 10,11,12},
		{13,14,15,16} };

	printMatrix(test_matrix, MAX_MATRIX_SIZE);
	std::cout << "rotating..." << std::endl;
	rotateMatrix90(test_matrix, MAX_MATRIX_SIZE);
	printMatrix(test_matrix, MAX_MATRIX_SIZE);    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
