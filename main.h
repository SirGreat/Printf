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

int _printf(const char *format, ...);
int printf_handler_fun(const char *fmt, int *i,
va_list args, char buffer[], int flags, int width, int precision, int size);

/** FUNCTIONS **/

/* Funtions to print chars and strings */
int char_handler(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int string_handler(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int percent_handler(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* Functions to print numbers */
int int_handler(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int binary_handler(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int unsigned_handler(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int octal_handler(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int hex_handler(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int upper_hex_handler(va_list types, char buffer[],
        int flags, int width, int precision, int size);

int handle_hex_up_low(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int handle_nont_a_value(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* Funcion to print memory address */
int pointer_handler(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int flags_handler(const char *format, int *i);
int width_handler(const char *format, int *i, va_list args);
int precision_handler(const char *format, int *i, va_list args);
int size_handler(const char *format, int *i);

/*Function to print string in reverse*/
int handle_reverse_fun(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int handle_rot13string(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* width handler */
int handle_printf_char(char c, char buffer[],
        int flags, int width, int precision, int size);
int handle_printf_number(int is_positive, int ind, char buffer[],
        int flags, int width, int precision, int size);
int handle_numbers(int ind, char bff[], int flags, int width, int precision,
        int length, char padd, char extra_c);
int handle_write_pointer(char buffer[], int ind, int length,
        int width, int flags, char padd, char extra_c, int padd_start);

int handle_printf_unsigned(int is_num_negat, int ind,
char buffer[],
        int flags, int width, int precision, int size);

/** UTILS **/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
