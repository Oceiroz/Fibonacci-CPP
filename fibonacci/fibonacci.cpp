// fibonacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int GetInput(string inputMessage);

int main()
{
	int nthTerm = GetInput("how many places of fibonacci would you like to see?");
	int fibonacciLength = 2 + nthTerm;
	int fibonacci[2] = { 0, 1 };
	int* newFibonacci = new int[fibonacciLength];

	int x = 0;
	for (; x < 2; x++)
	{
		int item = fibonacci[x];
		newFibonacci[x] = item;
	}
	for (x = 0; x < nthTerm - 1; x++)
	{
		int nextStage = newFibonacci[x] + newFibonacci[x + 1];
		newFibonacci[x + 2] = nextStage;
	}
	for (x = 0; x <= nthTerm; x++)
	{
		cout << newFibonacci[x] << endl;
	}
	delete[] newFibonacci;
}
int GetInput(string inputMessage)
{
	int userInput = 0;
	while (true)
	{
		cout << inputMessage << endl;
		string rawInput;
		getline(cin, rawInput);
		try
		{
			userInput = stoi(rawInput);
			if (userInput < 0)
			{
				throw new exception;
			}
			break;
		}
		catch (...)
		{
			cout << "this is not a valid intput" << endl;
		}
	}
	return userInput;
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
