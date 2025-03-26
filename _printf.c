#include "main.h"

/**
 * _printf
 * @format:
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, j, count = 0;

    print_format types[] = {
        {'c', print_char},
        {'s', print_string},
        {'%', print_percent},
        {'d', print_int},
        {'i', print_int},
        {0, NULL}
    };

    if (!format)
        return (-1);

    va_start(args, format);
    
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (!format[i])
                return (-1);

            for (j = 0; types[j].spec; j++)
            {
                if (format[i] == types[j].spec)
                {
                    count += types[j].f(args);
                    break;
                }
            }
            if (!types[j].spec)
            {
                _putchar('%');
                _putchar(format[i]);
                count += 2;
            }
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
        i++;
    }
    
    va_end(args);
    return (count);
}
