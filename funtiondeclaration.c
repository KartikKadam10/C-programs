#include<stdio.h>

void sum(); //Funtion declaration

void main()
{
    sum(); //Funtion calling
}

void sum() //Funtion definition
{
    int a,b,sum=0;

    printf("\nEnter the values of a and b:\n");
    scanf("%d %d", &a,&b);

    sum=a+b;

    printf("The sum is %d",sum);

}