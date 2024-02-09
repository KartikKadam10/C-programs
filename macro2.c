#include<stdio.h>

#define MAX(a,b) if ( a>b) \
                printf("%d is max ",a);\
                else \
                printf("%d is max",b);
int main()
{
    MAX(5,6);

    #undef MAX


}