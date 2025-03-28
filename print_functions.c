#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _putchar - function that writes a single character to stdout
 * @c: the character to print
 */

void _putchar(char c)
{
	write(1, &c, 1);
}


/**
 * print_char - function that prints a single character from va_list arguments
 * @args: variable arguments list containing the character to print
 *
 * Return: 1, number of characters printed
 */
int print_char(va_list args)
{
	_putchar(va_arg(args, int)); /* récupère et affiche le c. */
	return (1);
}


/**
 * print_specifier - function that prints a character '%'
 * @args: unused arguments list
 *
 * Return: 1, number of characters printed
 */

int print_specifier(va_list args)
{
	(void)args; /* évite un avertissement de variable non utilisée */
	_putchar('%');
	return (1);
}


/**
 * print_string - prints a string from va_list arguments
 * @args: variable arguments list containing the string pointer
 *
 * Handles NULL pointers by printing "(null)"
 * Return: total number of characters printed
 */

int print_string(va_list args)
{
	char *str = va_arg(args, char *); /* récupère la chaîne de c */
	int len = 0;

	if (!str) /* gestion du cas NULL */
		str = "(null)";

	while (*str) /* affichage c. par c. */
	{
		_putchar(*str++);
		len++;
	}
	return (len);
}


/**
 * print_int - function that prints an integer from va_list arguments
 * @args: variable arguments list containing the integer to print
 *
 * Return: number of characters printed
 */

int print_int(va_list args)
{
	int num = va_arg(args, int); /* récupère l'entier */

	int len = 0;
	unsigned int abs_num; /* stocke valeur absolue de num */
	unsigned int divisor = 1; /* pour extraire chaque chiffre */

	if (num < 0) /* gestion négatif */
	{
		_putchar('-');
		len++;
		abs_num = (unsigned int)(-num); /* obtenir valeur abs et éviter dépasser */
	}
	else /* sinon convertion directe en abs */
	{
		abs_num = (unsigned int)num;
	}

	if (abs_num == 0) /* gestion cas = 0 */
	{
		_putchar('0');
		return (len + 1);
	}

	while (abs_num / divisor > 9) /* extraire chiffres 1 par 1 si nbr de 2 ou + */
		divisor *= 10;

	while (divisor > 0) /* extraction et affichage 1 par 1 */
	{
		_putchar((abs_num / divisor) + '0'); /* conversion ASCII */
		abs_num %= divisor; /* reste division */
		divisor /= 10; /* réduction division */
		len++; /* nbr de c. imprimés */
	}

	return (len); /* maj de count dans _printf */
}
