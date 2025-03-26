#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct format_specifier - Structure pour les spécificateurs de format
 * @specifier: Le caractère du format (%c, %s, %d, etc.)
 * @f: Pointeur vers la fonction de traitement associée
 */
typedef struct format_specifier
{
    char specifier;
    int (*f)(va_list);
} format_specifier_t;

int _printf(const char *format, ...);

/* Fonctions pour l'affichage des formats */
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args, int uppercase);
int print_pointer(va_list args);

/* Fonctions utilitaires */
int _putchar(char c);
int _strlen(char *s);
char *_itoa(int num, char *str, int base);

#endif
