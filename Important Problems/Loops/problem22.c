/* Write a program to print out all armstrong numbers between 1 to 500. if sum of cubes of 
each digit of number is equal to the number itself, then the number is called an armstrong 
number. For example, 153 = (1*1*1)+(5*5*5)+(3*3*3). */

#include <stdio.h>

int main()
{
    int i = 1, f = 500;
    int num, digit, sum;

    while (i <= f)
    {
        num = i;
        sum = 0;

        while (num > 0)
        {
            digit = num % 10;
            sum = sum + (digit * digit * digit);
            num = num / 10;
        }

        if (sum == i)
        {
            printf("%d\n", i);
        }

        i++;
    }

    return 0;
}