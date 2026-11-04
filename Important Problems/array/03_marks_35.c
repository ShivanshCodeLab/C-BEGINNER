// Given an array of marks of 10 students, if the marks of any student is less than 35 print its roll number.
// [roll number here refers to the index of the array.]

#include <stdio.h>

int main()
{
    int marks[10]= {95,90,31,25,100,50,65,89,97,30};

    for (int i = 0; i < 10; i++)    if (marks[i]< 35)   printf("Marks less than 35 of %d roll number\n", i+1);

    return 0;
}