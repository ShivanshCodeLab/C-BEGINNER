// print all alphabet and their correspondings ASCII values.

#include <stdio.h>

int main()
{
    char CH = 'A';
    char ch = 'a';
    
    while (ch <= 'z' && CH <= 'Z')
    {
        printf("%c -> %d and %c -> %d\n", CH, CH, ch, ch);
        ch++;
        CH++;
    }

    return 0;
}



