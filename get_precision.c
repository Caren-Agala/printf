#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @form: formted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *form, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (form[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; form[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(form[curr_i]))
		{
			precision *= 10;
			precision += form[curr_i] - '0';
		}
		else if (form[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}
