#include "dna.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() 
{
	int function_choice = 0;
	char repeat;

	std::string dna_string;

	do
	{
		std::cout << "Get GC Content - 1" << std::endl;
		std::cout << "Get DNA Complement - 2 " << std::endl;
		std::cout << "Please enter a choice (1 or 2): ";
		cin >> function_choice;

		while(!(function_choice == 1 || function_choice == 2))
		{
			cout << "You've entered an invalid choice, try again: ";
			cin >> function_choice;
		}

		cout << "Enter a DNA string: ";
		cin >> dna_string;

		if(function_choice == 1)
		{
			cout << "The GC content of the entered DNA string is: " << get_gc_content(dna_string) * 100 << "%" << endl;
		}
		else
		{
			cout << "The complement of the DNA string entered is: " << get_dna_complement(dna_string) << endl;
		}

		cout << "Would you like to process another string? Enter 'Y' or 'y' to continue: ";
		cin >> repeat;

	} while (repeat == 'Y' || repeat == 'y');

	return 0;
}
