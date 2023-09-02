#include <unistd.h>

int _putchar(char c)
{
    return write(1, &c, 1);
}

/* _islower.c */
int _islower(int c)
{
    return (c >= 'a' && c <= 'z');
}
