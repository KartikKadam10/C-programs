#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void maxheapify ( int num[],int n , int i )
{
    int largest=i; // choosing the given element as i
    int left=2*i+1; // formula for finding the left element
    int right=2*i+2;// formula for finding the right element

    if ( left < n && num[left] > num[largest] )
       largest=left;
    
    if ( right < n && num[right] > num[largest] )
       largest=right;

    if ( largest != i )
    {
        int temp=num[largest];
        num[largest]=num[i];
        num[i]=temp;

        maxheapify(num,n,largest);
    }
}

void heapsort ( int num[], int n )
{
    for ( int i=(n/2)-1 ; i>=0 ; i-- )// loop for choosing the non-leaf node and swapping the elements.
    {
        maxheapify(num,n,i);
    }

    for ( int i=n-1; i>=0; i-- ) // loop for deleting the root element and swapping it with the last element
    {
        int temp=num[i];
        num[i]=num[0];
        num[0]=temp;

        maxheapify ( num,i,0);
    }
}

int main()
{
    int n;

    printf("\n\nEnter the size of the array:");
    scanf("%d",&n);

    if( n>0 )
    {
        int num[n];

        srand(time(0));

        for ( int i=0 ; i<n ; i++ )
        {
            num[i]=rand()%100;
        }

        printf("\n\nThe given array:\n");
        for ( int i=0; i<n; i++ )
        {
            printf("\t%d",num[i]);
        }

        heapsort(num,n);

        printf("\n\nThe array after heap sort:\n");
        for ( int i=0; i<n; i++ )
        {
            printf("\t%d",num[i]);
        }
    }
    else 
    {
        printf("\n\nPlease enter valid size of the array.");
    }
}