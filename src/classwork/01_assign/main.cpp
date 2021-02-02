#include <types.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() 
{
	int num, result;
	int num1 = 4;

	cout << "Enter an integer to multiply it by 5 and see the result: ";
	cin >> num;
	result = multiply_numbers(num);
	cout << num << " * 5 = " << result << endl;

	result = multiply_numbers(num1);
	cout << "Also, " << num1 << " * 5 = " << result << endl;

	return 0;
}
