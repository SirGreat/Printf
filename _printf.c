#include "main.h"

void buffer_printing(char buffer[], int *index_buff);

/**
 * b_printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int b_printf(const char *format, ...)
{
	int b, printed = 0, index_buff = 0;
	int flags, width, precision, size, printed_chars = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (b = 0; format && format[b] != '\0'; b++)
	{
		if (format[b] != '%')
		{
			buffer[index_buff++] = format[b];
			if (index_buff == BUFF_SIZE)
				buffer_printing(buffer, &index_buff);
			/* write(1, &format[b], 1);*/
			printed_chars++;
		}
		else
		{
			buffer_printing(buffer, &index_buff);
			flags = flags_handled(format, &b);
			width = width_handled(format, &b, args);
			precision = precision_handled(format, &b, args);
			size = size_handled(format, &b);
			++b;
			printed = handle_print(format, &b, args, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	buffer_printing(buffer, &index_buff);

	va_end(args);

	return (printed_chars);
}

/**
 * buffer_printing - if it exists,Prints the contents of the buffer.
 * @buffer: Chars of Array
 * @index_buff: Index at which to add next char, represents the length.
 */
void buffer_printing(char buffer[], int *index_buff)
{
	if (*index_buff > 0)
		write(1, &buffer[0], *index_buff);

	*index_buff = 0;
}

