#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void swap( int * a , int *b )
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

/*void bubblesort( int num[],int n )
{
    int flag;

    for ( int i=0 ; i < n-1 ; i++ )
    {
        flag=0;
        for ( int j=0 ; j < n-1-i ; j++ )
        {
             if ( num[j] > num[j+1] )
             {
                swap(&num[j],&num[j+1]);
                flag=1;
             }
        }
        if ( flag==0 )
           break;
    }
}*/

/*void insertionsort( int num[], int n )
{
    for ( int i=1 ; i < n; i++ )
    {
        int temp=num[i];
        int j=i-1;

        while ( j>=0 && temp < num[j] )
        {
            num[j+1]=num[j];
            j--;
        }
        num[j+1]=temp;
    }
}
*/

/*void merge( int num[], int low, int mid , int high )
{
    int n=high-low+1;

    int temp[n];
    for ( int i=0 ; i < n ; i++ )
    {
        temp[i]=num[low+i];
    }

    int i=0;
    int j=mid-low+1;
    int k=low;

    while ( i <= mid-low && j<n )
    {
        if ( temp[i] <= temp[j] )
        {
            num[k]=temp[i];
            i++;
        }
        else
        {
            num[k]=temp[j];
            j++;
        }
        k++;
    }

    while ( i<=mid-low) 
    {
        num[k]=temp[i];
        i++;
        k++;
    }
    while ( j < n )
    {
        num[k]=temp[j];
        j++;
        k++;
    }
}

void mergesort( int num[],int low, int high )
{
    if ( low < high )
    {
        int mid=(low+high)/2;

        mergesort(num,low,mid);
        mergesort(num,mid+1,high);
        merge(num,low,mid,high);
    }
}
*/
/*int partition( int num[], int low, int high )
{
    int pivot=num[high];

    int i=low-1;

    for ( int j=low ; j<high ; j++ )
    {
        if ( num[j]<=pivot )
        {
            i++;
            swap(&num[i],&num[j]);
        }
    }
    swap(&num[i+1],&num[high]);
    return i+1;
}
void quicksort( int num[], int low, int high )
{
    if ( low < high )
    {
        int part=partition(num,low,high );

        quicksort(num,low,part-1);
        quicksort(num,part+1,high);
    }
}
*/

void heapify( int num[], int n, int i )
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if ( left < n && num[left] > num[largest] )
        largest=left;
    
    if ( right < n && num[right] > num[largest] )
        largest=right;

    if ( largest != i)
    {
        swap(&num[largest],&num[i] );
        heapify(num,n,largest);
    }
}

void heapsort( int num[], int n )
{
    for ( int i=(n/2)-1 ; i>=0; i-- )
    {
        heapify(num,n,i);
    }

    for ( int i=n-1 ; i>=0 ; i-- )
    {
        swap(&num[i],&num[0]);
        heapify(num,i,0);
    }
}


int main()
{
    int n;

    printf("\nEnter the number of elements: ");
    scanf("%d",&n);

    if ( n > 0 )
    {
        int num[n];
        
        srand(time(0));

        for ( int i=0 ; i < n ; i++ )
        {
            num[i]=rand()%100;
        }

        printf("\n\nThe array elements:\n");
        for ( int i=0 ; i<n ; i++ )
        {
            printf("\t%d",num[i]);
        }

        heapsort(num,n);

        printf("\n\nThe array elements after heap sort:\n");
        for ( int i=0 ; i<n ; i++ )
        {
            printf("\t%d",num[i]);
        }
    }
}