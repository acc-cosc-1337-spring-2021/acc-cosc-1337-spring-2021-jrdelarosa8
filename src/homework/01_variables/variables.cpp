#include "variables.h"

const double TAX_RATE = 0.0675;

double get_sales_tax(double meal_amount)
{
	return meal_amount * TAX_RATE;
}

double get_tip_amount(double meal_amount, double tip_rate)
{
	return meal_amount * tip_rate;
}
