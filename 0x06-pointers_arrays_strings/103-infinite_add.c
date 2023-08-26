#include <stdio.h>

char *infinite_add(char *n1, char *n2, char *r, int size_r);

int main(void)
{
    // Your test cases here
    return 0;
}

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int len1 = 0, len2 = 0, carry = 0, sum, i, j;
    
    // Calculate the lengths of the input strings
    while (n1[len1] != '\0')
        len1++;
    while (n2[len2] != '\0')
        len2++;
    
    // Check if the result can fit in the buffer
    if (len1 >= size_r || len2 >= size_r)
        return 0;
    
    // Start adding from the least significant digit
    i = len1 - 1;
    j = len2 - 1;
    
    int result_index = 0;
    
    while (i >= 0 || j >= 0 || carry > 0)
    {
        // Calculate the sum of digits at the current positions
        sum = carry;
        if (i >= 0)
            sum += n1[i] - '0';
        if (j >= 0)
            sum += n2[j] - '0';
        
        // Calculate the new carry and the current digit
        carry = sum / 10;
        sum = sum % 10;
        
        // Store the digit in the result buffer
        r[result_index] = sum + '0';
        
        // Move to the next position
        i--;
        j--;
        result_index++;
    }
    
    // Null-terminate the result string
    r[result_index] = '\0';
    
    // Reverse the result string
    for (i = 0, j = result_index - 1; i < j; i++, j--)
    {
        char temp = r[i];
        r[i] = r[j];
        r[j] = temp;
    }
    
    return r;
}

