#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @form: formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *form, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (form[curr_i] == 'l')
		size = S_LONG;
	else if (form[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
