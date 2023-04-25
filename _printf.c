#include "main.h"

void print_buffer(char buffer[], int *buffer_ind);

/**
 * Caren and Alex
 * _printf - Printf function
 * @form: format.
 * Return: Printed chars.
 */
int _printf(const char *form, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buffer_ind = 0;
	va_list list;
	char buffer[BUFFER_SIZE];

	if (form == NULL)
		return (-1);

	va_start(list, form);

	for (i = 0; form && form[i] != '\0'; i++)
	{
		if (form[i] != '%')
		{
			buffer[buffer_ind++] = form[i];
			if (buffer_ind == BUFFER_SIZE)
				print_buffer(buffer, &buffer_ind);
			/* write(1, &form[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buffer_ind);
			flags = get_flags(form, &i);
			width = get_width(form, &i, list);
			precision = get_precision(form, &i, list);
			size = get_size(form, &i);
			++i;
			printed = handle_print(form, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buffer_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buffer_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buffer_ind)
{
	if (*buffer_ind > 0)
		write(1, &buffer[0], *buffer_ind);

	*buffer_ind = 0;
}
