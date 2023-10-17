#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int b_printf(const char *format, ...);
int handle_print(const char *fmt, int *b,
va_list args, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Functions to print chars and strings */
int handle_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int handle_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int handle_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int handle_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int handle_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int handle_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int handle_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int handle_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int handle_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int handle_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int handle_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int handle_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int handle_flags(const char *format, int *b);
int handle_width(const char *format, int *b, va_list list);
int handle_precision(const char *format, int *b, va_list list);
int handle_size(const char *format, int *b);

/*Function to print string in reverse*/
int handle_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int handle_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_print_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int handle_print_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size);
int handle_num(int ind, char buffer[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int handle_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int handle_unsigned(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
