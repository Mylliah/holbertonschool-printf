#include "main.h"
#include <stdarg.h>

/**
 * _printf - Fonction principale qui imite printf
 * @format: Chaîne de format contenant les spécificateurs
 * Return: Nombre total de caractères imprimés
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0, i, j;

    format_specifier_t types[] = {
        {'c', print_char}, {'s', print_string},
        {'d', print_int}, {'i', print_int},
        {'u', print_unsigned}, {'o', print_octal},
        {'x', print_hex}, {'X', print_hex},
        {'p', print_pointer}, {'\0', NULL}
    };

    if (format == NULL)
        return (-1);

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%' && format[i + 1] != '\0')
        {
            i++;
            for (j = 0; types[j].specifier; j++)
            {
                if (format[i] == types[j].specifier)
                {
                    count += types[j].f(args);
                    break;
                }
            }
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
    }

    va_end(args);
    return (count);
}
