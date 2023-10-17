#include "main.h"

void printBufferValues(char buffer[], int *add_to_next_index);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_values = 0, add_to_next_index = 0;
	int flags, width, precision, size;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[add_to_next_index++] = format[i];
			if (add_to_next_index == BUFF_SIZE)
				printBufferValues(buffer, &add_to_next_index);
			/* write(1, &format[i], 1);*/
			printed_values++;
		}
		else
		{
			printBufferValues(buffer, &add_to_next_index);
			flags = flags_handler(format, &i);
			width = width_handler(format, &i, args);
			precision = precision_handler(format, &i, args);
			size = size_handler(format, &i);
			++i;
			printed = printf_handler_fun(format, &i, args, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_values += printed;
		}
	}

	printBufferValues(buffer, &add_to_next_index);

	va_end(args);

	return (printed_values);
}

/**
 * printBufferValues - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @add_to_next_index: Index at which to add next char, represents the length.
 */
void printBufferValues(char buffer[], int *add_to_next_index)
{
	if (*add_to_next_index > 0)
		write(1, &buffer[0], *add_to_next_index);

	*add_to_next_index = 0;
}
