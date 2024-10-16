#include<stdio.h>
#include<stdlib.h>
#include  "doublylist.h"

int count=0;
void createdoubly()
{
    int n;
    printf("\n\nEnter the number of nodes:");
    scanf("%d",&n);
     
    head=NULL;
    if ( n<0 )
    {
        printf("\n\nNo nodes.");
        exit(0);
    }
    else
    {
        for ( int i=1; i<=n ; i++ )
        {
            newnode=(struct node* )malloc(sizeof(struct node));
            
            printf("\n\nEnter data: ");
            scanf("%d",&newnode->data);
         
            newnode->prev=NULL;
            newnode->next=NULL;

            if ( head==NULL )
            {
                head=newnode;
                tail=newnode;
                temp=newnode;
            }
            else
            {
                temp->next=newnode;
                newnode->prev=temp;
                tail=temp=newnode;
            }
            count++;

        }
    }

}

void insertbeg()
{
    newnode=(struct node*)malloc(sizeof(struct node));

    printf("\n\nEnter the data you want insert at beginning:");
    scanf("%d",&newnode->data);

    newnode->prev=NULL;

    head->prev=newnode;

    newnode->next=head;

    head=newnode;

    count++;
}

void insertend()
{
    newnode=(struct node*)malloc(sizeof(struct node));

    printf("\n\nInsert data you want to enter at end:");
    scanf("%d",&newnode->data);

    newnode->next=NULL;

    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;

    count++;
}

void insertbet()
{
    int pos;

    printf("\n\nEnter the position you want to insert the element: ");
    scanf("%d",&pos);

    if (pos<1 || pos > count )
    {
        printf("\n\nInvalid position.");
        exit(0);
    }
    else if ( pos==1 )
    {
        insertbeg();
    }
    else if( pos==count)
    {
        insertend();
    }
    else 
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\n\nEnter the data:");
        scanf("%d",&newnode->data);
        
        int i=1;
        temp=head;
        while( i < pos-1 )
        {
           temp=temp->next;
           i++;
        }

        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->next->prev=newnode;
        count++;
    }
}

void insertdoubly()
{
    printf("\n\nSelect where do you want to insert:");
    printf("\n1.Insert at beginning.");
    printf("\n2.Insert in between.");
    printf("\n3.Insert at end.");

    int choice;

    printf("\n\nEnter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
               insertbeg();
               break;
        
        case 2: 
               insertbet();
               break;

        case 3:
               insertend();
               break;
            
        default:
               printf("\n\nWrong choice.");
    }
}

void deletebeg()
{
    temp=head;

    head=temp->next;

    head->prev=NULL;

    free(temp);

    count--;
}

void deleteend()
{
    temp=tail;

    temp->prev->next=NULL;
    tail=temp->prev;

    free(temp);
    count--;
}

void deletebet()
{
    int pos;

    printf("\n\nEnter the position you want to delete the element: ");
    scanf("%d",&pos);

    if (pos<1 || pos > count )
    {
        printf("\n\nInvalid position.");
        exit(0);
    }
    else if ( pos==1 )
    {
        deletebeg();
    }
    else if( pos==count)
    {
        deleteend();
    }
    else 
    {
        int i=1;
        temp=head;
        while( i < pos )
        {
           temp=temp->next;
           i++;
        }

        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);  
        count--;  
    }
}


void deletedoubly()
{
    printf("\n\nSelect where do you want to Delete:");
    printf("\n1.Delete at beginning.");
    printf("\n2.Delete in between.");
    printf("\n3.Delete at end.");

    int choice;

    printf("\n\nEnter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
               deletebeg();
               break;
        
        case 2: 
               deletebet();
               break;

        case 3:
               deleteend();
               break;
            
        default:
               printf("\n\nWrong choice.");
    }
}

void displaydoubly()
{
    temp=head;
    
    printf("\n\nDoubly linked list in forward order:\n");
    
    while( temp!=NULL )
    {
        printf("\t%d",temp->data);
        temp=temp->next;
    }

    printf("\n\nDoubly linked list in reverse order:\n");
    temp=tail;
    while(temp!=NULL )
    {
        printf("\t%d",temp->data);
        temp=temp->prev;
    }
    
    printf("\n\nTotal Nodes are %d.\n",count);
}

void searchdoubly()
{
    int search;
    printf("\n\nEnter the element you want to search:");
    scanf("%d",&search);

    temp=head;
    int count=0;
    int found=0;
    while(temp!=NULL)
    {
        count++;
        if( temp->data==search )
        {
            printf("\n\nElement found at position %d.",count);
            found=1;
        }
        temp=temp->next;
    }
    if(found==0)
    {
        printf("\n\nElement not present in linkedlist.");
    }
}
