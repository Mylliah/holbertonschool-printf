#include <stdio.h>
#include "main.h"

/**
 * main - 
 * Return:
 */
int main(void)
{
    int len1, len2;

    len1 = _printf("Character: [%c]\n", 'H');
    len2 = printf("Character: [%c]\n", 'H');

    _printf("String: [%s]\n", "Hello, world!");
    printf("String: [%s]\n", "Hello, world!");

    _printf("Percent: [%%]\n");
    printf("Percent: [%%]\n");

    _printf("Integer: [%d, %i]\n", -12345, 6789);
    printf("Integer: [%d, %i]\n", -12345, 6789);

    printf("Length: [%d, %d]\n", len1, len2);

    return (0);
}
