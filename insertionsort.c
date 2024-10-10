#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionsort( int num[], int n )
{
    int temp;

    for ( int i=0; i<=n-1; i++ )
    {
        int j=i;
        while ( j>0 && num[j] < num[j-1] )
        {
            temp=num[j-1];
            num[j-1]=num[j];
            num[j]=temp;
            j--;
        }
    }
}



int main()
{
    int n;
    srand(time(0));

    printf("\n\nEnter the number of elements:");
    scanf("%d",&n);

    int num[n];

    for ( int i=0; i<n; i++ )
    {
        num[i]=rand()%100;
    }

    printf("\n\nThe array elements are:\n");
    for ( int i=0; i<n ; i++ )
    {
        printf("\t%d",num[i]);
    }

    
    insertionsort(num,n);
    
    printf("\n\nThe array elements after sorting are are:\n");
    for ( int i=0; i<n ; i++ )
    {
        printf("\t%d",num[i]);
    }
}