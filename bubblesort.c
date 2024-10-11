#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void bubblesort( int num[],int n)
{
    int temp,flag;

    for ( int i=n-1; i>=0 ; i++ )
    {
        flag=0;
        for ( int j=0; j<=i-1; j++ )
        {
            if ( num[j] > num[j+1] )
            {
                flag=1;
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
        if ( flag==0 )
        {
            break;
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

    
    bubblesort(num,n);
    
    printf("\n\nThe array elements after sorting are are:\n");
    for ( int i=0; i<n ; i++ )
    {
        printf("\t%d",num[i]);
    }
}