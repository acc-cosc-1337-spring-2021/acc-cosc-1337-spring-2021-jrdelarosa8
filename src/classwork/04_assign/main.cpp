#include "loops.h"
#include <iostream>

using std::cin; using std::cout;

int main() 
{
	char choice;
	int num;

	do
	{
		cout << "Enter a number between 1 and 10 (inclusive) to calculate its factorial: ";
		cin >> num;
		
		while (num > 10 || num < 1)
		{
			cout << "You've entered an invalid choice, try again: " << std::endl;
			cin >> num;
		}

		cout << "The factorial of " << num << " is " << factorial(num) << "." << std::endl;
		
		cout << "Enter 'c' or 'C' to continue: ";
		cin >> choice;
		
	} while (choice == 'c' || choice == 'C');
	

	return 0;
}
