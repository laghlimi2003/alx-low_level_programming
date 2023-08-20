#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int sum = 0;
    int a = 1, b = 2;

    while (b <= 4000000)
    {
        if (b % 2 == 0)
        {
            sum += b;
        }

        int next = a + b;
        a = b;
        b = next;
    }

    printf("%d\n", sum);

    return 0;
}

