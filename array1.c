#include<stdio.h>

int main()
{

    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);

    int a[n];
    printf("\nEnter the array elements:\n"); 
    for ( int i=0; i<n; i++ )
    {
        scanf("%d",&a[i]);
    }

    printf("\n array elements are:\n"); 
    for ( int i=0; i<n; i++ )
    {
        printf("%d\t",a[i]);
    }


    
    printf("\n %d", *(a+1));
    printf("\n %d", *a+1);
}
