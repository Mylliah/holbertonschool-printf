#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Struct */
typedef struct print_format
{
    char spec;
    int (*f)(va_list);
} print_format;

/* Prototypes */
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
void _itoa(int n, char *buffer);
void _reverse(char *s);
int _strlen(char *s);
int _putchar(char c);

#endif /* MAIN_H */
