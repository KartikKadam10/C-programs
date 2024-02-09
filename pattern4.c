#include<stdio.h>

int main()
{
    int i,j,n,m;
    printf("Enter the number of lines you would like to print:\n");
    scanf("%d",&n);
    m=n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            printf("*\t");

        } printf("\n");
          m--;
    }  return 0;
}
