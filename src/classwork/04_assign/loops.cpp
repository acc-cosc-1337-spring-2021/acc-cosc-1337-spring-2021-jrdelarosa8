#include "loops.h"

int factorial(int num)
{
    auto product = 1;

    for(int i = 1; i <= num; ++i)
    {
        product = product * i;
    }

    return product;
}
