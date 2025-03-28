#include "main.h"
#include <stdarg.h>

/**
 * handle_specifier - handles format specifiers after '%' character
 * @format: format string to be handle
 * @args: variable arguments list
 * @index: pointer to current position index in format string
 *
 * Calls the corresponding function
 * Return: number of characters printed for the specifier found
 */

int handle_specifier(const char *format, va_list args, int *index)
{
	int count = 0; /* nbr total caractères imprimés pour le spéc. */
	int type_found = 0; /* pour indiquer si spéc. trouvé */
	int type_index = 0; /* pour parcourir la structure */

	print_format types[] = {    /* tableau associant chaque sp à sa fonction */
		{'c', print_char},
		{'s', print_string},
		{'%', print_specifier},
		{'d', print_int},
		{'i', print_int},
		{'\0', NULL}
	};

	/* Recherche du spec. correspondant */
	for (type_index = 0 ; types[type_index].type ; type_index++)
	{
		if (format[*index] == types[type_index].type)
		{
			count += types[type_index].f(args); /* Appel de la fonction assosicée */
			type_found = 1;
			break; /* sort une fois le type trouvé */
		}
	}

	if (!type_found) /* si aucun sp trouvé, affiché % et le c. suivant */
	{
		_putchar('%');
		_putchar(format[*index]);
		count += 2; /* car 2 c. affichés */
	}
	return (count); /* retourne le nb de c. affichés */
}


/**
 * _printf - implementation of printf
 * @format: format string containing text and specifiers
 *
 * Return: -1 for NULL, empty format strg OR total number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args; /* liste des arguments variables */
	int index = 0; /* position actuelle dans la chaîne */
	int count = 0; /* nbr total c. imprimés */

	va_start(args, format); /* initialisation de la liste d'args */

	if (!format || format[0] == '\0') /* vérification */
		return (-1);

	while (format && format[index]) /* parcourt format */
	{
		if (format[index] == '%') /* détection sp */
		{
			if (format[index + 1] == '\0') /* si % en fin de chaîne */
			{
				va_end(args);
				return (-1); /* retourne erreur */
			}
			index++; /* continue le parcourt */
			count += handle_specifier(format, args, &index); /* maj de count */
		}
		else    /* c. standard à afficher directement */
		{
			_putchar(format[index]);
			count++;
		}
		index++;
	}

	va_end(args); /* libération de la liste d'args */
	return (count); /* retourne le nb total de c. imprimés */
}
