#include<stdio.h>

int main()
{
    int n;

    printf("\nEnter the number of rows : ");
    scanf("%d",&n);

    for ( int i=1 ; i<=n ; i++ )
    {
        for ( int sp=1 ; sp<=(n-i) ; sp++ )
        {
            printf(" ");
        }
        for ( int j=1 ; j<=(2*i-1); j++ )
        {
            printf("*");
        }
        printf("\n");
    }
    for ( int k=(n-1); k>=1; k--)
    {
        for ( int sp=1 ; sp<=(n-k) ; sp++ )
        {
            printf(" ");
        }
        for ( int j=1 ; j<=(2*k-1); j++ )
        {
            printf("*");
        }
        printf("\n");
    }

}