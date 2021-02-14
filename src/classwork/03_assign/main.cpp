#include <iostream>
#include <decision.h>

using std::cin; using std::cout; using std::endl;

int main() 
{
	int grade;

	cout << "Enter a number grade between 0 and 100: ";
	cin >> grade;
	
	if (grade < 0 || grade > 100)
	{
		cout << "The grade you have entered is out of range.";
	}
	else
	{
		cout << "(If) - You have earned an " << get_letter_grade_using_if(grade) << endl;
		cout << "(Switch) - You have earned an " << get_letter_grade_using_switch(grade) << endl;
	}

	return 0;
}
