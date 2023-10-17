#include "main.h"

/** CHAR PRINTING **/

/**
 * handle_char - Printing of char
 * @types: arguments Lists
 * @buffer: Buffer array to handling printing
 * @flags: active flags calculation
 * @width: Width parameter
 * @precision: specification of Precision
 * @size: specification of Size
 * Return: The number of chars printed
 */
int handle_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char b = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/** PRINT A STRING **/

/**
 * handle_string - Printing a string
 * @types: arguments List
 * @buffer: Buffer array to handle print
 * @flags: active flags Calculation
 * @width: handle width.
 * @precision: specification of Precision
 * @size: specification of Size
 * Return: Number of chars printed
 */
int handle_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, b;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (b = width - length; b > 0; b--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (b = width - length; b > 0; b--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/** PRINT PERCENT SIGN **/
/**
 * handle_percent - handle a percent sign(print)
 * @types: arguments List
 * @buffer: Buffer array to handle print
 * @flags: active flags Calculation
 * @width: specification of  width.
 * @precision: specification of Precision
 * @size: specification of  Size
 * Return: Number of percent printed
 */

int handle_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/** PRINT INT **/
/**
 * handle_int - handle int (Print)
 * @types: arguments  List
 * @buffer: Buffer array to handle print
 * @flags:  active flags Calculation
 * @width: specification of  width
 * @precision: specification of Precision
 * @size: Size specifier
 * Return: Number of chars printed
 */
int handle_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int b = BUFF_SIZE - 2;
	int is_negative = 0;
	long int a = va_arg(types, long int);
	unsigned long int num;

	a = convert_size_number(a, size);

	if (a == 0)
		buffer[b--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)a;

	if (a < 0)
	{
		num = (unsigned long int)((-1) * a);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[b--] = (num % 10) + '0';
		num /= 10;
	}

	b++;

	return (write_number(is_negative, b, buffer, flags, width, precision, size));
}

/** PRINT BINARY **/
/**
 * handle_binary - handle an unsigned number (print)
 * @types: arguments list
 * @buffer: Buffer array to handle print
 * @flags: active flags Calculation
 * @width: specification of width.
 * @precision: specification of Precision
 * @size: specification of  Size
 * Return: Numbers of char printed.
 */

int handle_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int a, c, b, sum;
	unsigned int d[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	a = va_arg(types, unsigned int);
	c = 2147483648; /* (2 ^ 31) */
	d[0] = a / c;
	for (b = 1; b < 32; b++)
	{
		c /= 2;
		d[b] = (a / c) % 2;
	}
	for (b = 0, sum = 0, count = 0; b < 32; b++)
	{
		sum += d[b];
		if (sum || b == 31)
		{
			char z = '0' + d[b];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
