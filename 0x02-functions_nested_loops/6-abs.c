#include "main.h"

/**
 *omputes the absolute value of an integer.
 *Return:returns the abs value.
 *
 */
int _abs(int a)
{
	int k = a;
	int absvalue;

	if (k < 0)
	{
		k = k * (-1);
	}
	absvalue = k;
	return (absvalue);
}

