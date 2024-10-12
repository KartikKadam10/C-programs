// A program to learn about the merge sort algorithm in detail.


#include<stdio.h>

void merge( int num[], int low, int mid, int high )
{
    int n1=mid-low+1;
    int n2=high-mid;

    int l[n1],r[n2];

    for ( int i=0; i<n1; i++ )
    {
        l[i]=num[low+i];
    }

    for ( int j=0; j<n2; j++ )
    {
        r[j]=num[mid+j+1];
    }

    int i,j,k;

    i=0;
    j=0;
    k=low;

    while ( i<n1 && j<n2 )
    {
        if ( l[i] <= r[j] )
        {
            num[k]=l[i];
            i++;
        }
        else
        {
            num[k]=r[j];
            j++;
        }
        k++;
    }

    while( i < n1)
    {
        num[k]=l[i];
        i++;
        k++;
    }

    while( j< n2 )
    {
        num[k]=r[j];
        j++;
        k++;
    }
}

// the function to divide the array in half
void mergesort( int num[], int low, int high )
{
    if ( low==high )
        return;

    int mid=(low+high)/2;

    mergesort(num,low,mid);
    mergesort(num,mid+1,high);

    merge( num,low,mid,high );
}

int main()
{
    int n;

    printf("\n\nEnter the size of the array:");
    scanf("%d",&n);

    if ( n > 0 )
    {
        int num[n];

        printf("\n\nEnter the elements of the array:\n");
        for ( int i=0; i<n; i++ )
        {
            scanf("%d",&num[i]);
        }

        printf("\n\nThe given array:\n");
        for ( int i=0; i<n ; i++ )
        {
            printf("\t%d",num[i]);
        }

        mergesort(num,0,n-1);

        printf("\n\nThe array after merge sort algorithm:\n");
        for ( int i=0 ; i<n ; i++ )
        {
            printf("\t%d", num[i]);
        }
        


    }
}