#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int b, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', handle_char}, {'s', handle_string}, {'%', handle_percent},
		{'i', handle_int}, {'d', handle_int}, {'b', handle_binary},
		{'u', handle_unsigned}, {'o', handle_octal}, {'x', handle_hexadecimal},
		{'X', handle_hexa_upper}, {'p', handle_pointer}, {'S', handle_non_printable},
		{'r', handle_reverse}, {'R', handle_rot13string}, {'\0', NULL}
	};
	for (b = 0; fmt_types[b].fmt != '\0'; b++)
		if (fmt[*ind] == fmt_types[b].fmt)
			return (fmt_types[b].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[b].fmt == '\0')
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
	return (printed_chars);
}
