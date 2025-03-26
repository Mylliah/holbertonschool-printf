#include "main.h"

/**
 * _putchar - Affiche un caractère
 * @c: Le caractère à afficher
 * Return: 1 si succès, -1 sinon
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * _strlen - Retourne la longueur d'une chaîne de caractères
 * @s: Chaîne
 * Return: Longueur de la chaîne
 */
int _strlen(char *s)
{
    int i = 0;

    while (s[i])
        i++;

    return (i);
}

/**
 * _itoa - Convertit un entier en chaîne de caractères
 * @n: Entier à convertir
 * @buffer: Stocke la conversion
 */
void _itoa(int n, char *buffer)
{
    int i = 0, sign = n;

    if (n < 0)
        n = -n;

    do {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    } while (n > 0);

    if (sign < 0)
        buffer[i++] = '-';

    buffer[i] = '\0';
    _reverse(buffer);
}

/**
 * _reverse - Inverse une chaîne de caractères
 * @s: Chaîne à inverser
 */
void _reverse(char *s)
{
    int i, j;
    char temp;

    for (i = 0, j = _strlen(s) - 1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
