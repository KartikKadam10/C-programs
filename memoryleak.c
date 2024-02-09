#include<stdio.h>
#include<stdlib.h>

 int main()
 {
    int ch=1;
    int *ptr;

    while ( ch<50 )
    {
        printf("\nmemory leak is done.");

        ptr=(int*) malloc(40000*sizeof(int));
        
        printf("\nContinue ?");
        scanf("%d",&ch);
        free(ptr);

    }


  }