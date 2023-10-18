#include "main.h"
/**
 * printf_handler_fun - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @args: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int printf_handler_fun(const char *fmt, int *ind, va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_values = -1;
	fmt_t fmt_types[] = {
		{'c', char_handler}, {'s', string_handler}, {'%', percent_handler},
		{'i', int_handler}, {'d', int_handler}, {'b', binary_handler},
		{'u', unsigned_handler}, {'o', octal_handler}, {'x', hex_handler},
		{'X', upper_hex_handler}, {'p', pointer_handler}, {'S', handle_nont_a_value},
		{'r', handle_reverse_fun}, {'R', handle_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(args, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_values);
}
