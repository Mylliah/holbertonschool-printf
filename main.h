#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>

/**
 * struct format - structure for format specifier handling
 * @type: the format specifier character
 * @f: pointer to the corresponding handler function
 */
typedef struct format
{
	char type;
	int (*f)(va_list);
} print_format;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_specifier(va_list args);
void  _putchar(char c);
int handle_specifier(const char *format, va_list args, int *index);

#endif /* MAIN_H */
