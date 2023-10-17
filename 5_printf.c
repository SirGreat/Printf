#include "main.h"

/**
 * handle_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @b: List of arguments to be printed.
 * Return: Precision.
 */
int handle_size(const char *format, int *b)
{
	int curr_b = *b + 1;
	int size = 0;

	if (format[curr_b] == 'l')
		size = S_LONG;
	else if (format[curr_b] == 'h')
		size = S_SHORT;

	if (size == 0)
		*b = curr_b - 1;
	else
		*b = curr_b;

	return (size);
}
