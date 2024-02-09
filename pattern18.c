#include<stdio.h>

int main()
{

    for ( int i=1; i<=5; i++ )
    {
        for( int sp=0; sp<=(i-1); sp++ )
        {
            printf(" ");
        }
        for ( int j=1; j<=5; j++ )
        {
            printf("*");
        }
        printf("\n");
    }
}