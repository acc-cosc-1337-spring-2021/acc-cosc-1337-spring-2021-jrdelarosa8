#include "variables.h"
#include <iostream>
#include <iomanip>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::setw;
using std::string;

int main()
{
	double meal_amount, tax_amount, tip_amount, tip_rate, total;
	string divider = "-----------------------";

	cout << "Enter the cost of the meal: ";
	cin >> meal_amount;

	cout << "Enter the tip rate (as a decimal): ";
	cin >> tip_rate;
	
	tax_amount = get_sales_tax(meal_amount);
	tip_amount = get_tip_amount(meal_amount, tip_rate);
	total = meal_amount + tax_amount + tip_amount;
	
	cout << endl << setw(23) << "Meal Receipt" << endl;
	cout << divider << endl;
	cout << setprecision(2) << fixed;

	cout << setw(15) << "Meal Amount: " << setw(8) << meal_amount << endl;
	cout << setw(15) << "Sales Tax: " << setw(8) << tax_amount << endl;
	cout << setw(15) << "Tip Amount: " << setw(8) << tip_amount << endl;

	cout << divider << endl;

	cout << setw(15) << "Total: " << setw(8) << total << endl;

	return 0;
}
