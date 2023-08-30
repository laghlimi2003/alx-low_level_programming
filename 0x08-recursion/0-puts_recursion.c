#include "main.h"

/**
 * _puts_recursion - Prints a string followed by a new line using recursion.
 * @s: The input string to be printed.
 */
void _puts_recursion(char *s)
{
    if (*s == '\0') // Base case: end of the string
    {
        _putchar('\n'); // Print a new line
        return;
    }

    _putchar(*s); // Print the current character
    _puts_recursion(s + 1); // Recurse with the next character
}
:
