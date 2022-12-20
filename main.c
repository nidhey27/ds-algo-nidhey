/*
    Day 2
    1. Factorial of Number
    2. Fibonaci Series
    3. Pointers
    4. Swap - Call by Vale & Reference

    5. DS
    6. Time & Space Complexity
    7. Data Types - Built In & User Defined (int float char - struct union arrays)
    8. Algorithms 
*/

#include<stdio.h>
void swap_val(int x, int y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
    printf("%d %d",x,y);
}
void swap_ref(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
    printf("%d %d",*x,*y);
}

int main(){
    int a = 5;
    int b = 10;

    swap_ref(&a, &b);
    swap_val(a, b);
}

