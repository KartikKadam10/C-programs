#include<stdio.h>


int  accept(int a[100][100],int r,int c);

int  display(int a[100][100],int r,int c);

int  display_transpose(int a[100][100],int r,int c);

int main()
{
    int A[100][100];
    int m,n;
    
    printf("\nEnter the number of rows :");
    scanf("%d",&m);

    printf("\nEnter the number of colomns :");
    scanf("%d",&n);

    printf("\nEnter the matrix elements :");

    accept(A,m,n);

    printf("\nThe matrix is :\n");

    display(A,m,n);

    printf("\nThe transpose of the given matrix is : \n");

    display_transpose(A,m,n);

}

int accept(int a[100][100],int r,int c)
{
    int i,j;

    for ( i=0 ; i<r ; i++)
    
        for( j=0 ; j<c; j++)
        
          scanf("%d",&a[i][j]);
        
        
    
}

int display( int a[100][100],int r,int c)
{
    int i,j;

    for ( i=0 ; i<r; i++)
    {
        for( j=0 ; j<c ; j++)
        {
          printf("%d\t",a[i][j]);
        }
        printf("\n");
        
    }
}


int display_transpose( int a[100][100],int r,int c)
{
    int i,j;

    for ( j=0 ; j<r ; j++)
    {
        for( i=0 ; i<c ; i++)
        {
          printf("%d\t",a[i][j]);
        }
        printf("\n");
        
    }
}