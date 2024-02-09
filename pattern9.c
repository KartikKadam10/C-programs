#include<stdio.h>
int main()
{
    int i,j;

    for(j=6;j>=1;j--)
    {
        for(i=1;i<=j;i++)
        {
            printf("%d\t",i);
        }
        printf("\n");
    }
    return 0;
}