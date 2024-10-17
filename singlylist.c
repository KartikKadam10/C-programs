#include<stdio.h>
#include<stdlib.h>
#include "singlylist.h"

int count=0;

void createsingly()
{
    int n;
    head=NULL;
    
    printf("\nEnter the number of node:");
    scanf("%d",&n);
    
    for( int i=1; i<=n; i++ )
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        
        printf("\nEnter the data:");
        scanf("%d",&newnode->data);
         
        newnode->next=NULL;
        
        if ( head == NULL )
        {
            head=newnode;
            temp=head;
            tail=head;
        }
        else 
        {
            temp->next=newnode;
            temp=newnode;
            tail=newnode;
        }
        count++;
    }
    printf("\n\nCount is %d.\n\n",count);
}

void insertsingly()
{
    int choice;
    printf("\n\nWhere do you want to insert?\n");
    printf("\n1.Insert at beginning.");
    printf("\n2.Insert in between.");
    printf("\n3.Insert at end.");
    
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
              printf("\nWrong choice");
    }
    printf("\n\nCount is %d.",count);
    
}

void deletesingly()
{
    int choice;
    printf("\n\nWhere do you want to delete?\n");
    printf("\n1.delete at beginning.");
    printf("\n2.delete in between.");
    printf("\n3.delete at end.");
    
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
              printf("\nWrong choice");
    }
    
}

void displaysingly()
{
    temp=head;
    printf("\n\nSingly list:\n");

    if ( head== NULL )
    {
        printf("\n\nNodes are empty.");
    }
    while ( temp != NULL )
    {
        printf("\t%d",temp->data);
        temp=temp->next;
    }
}

void insertbeg()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data you want to insert at beginning:");
    scanf("%d",&newnode->data);

    newnode->next=head;
    head=newnode;
    count++;
}

void insertend()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data you want to insert at end :");
    scanf("%d",&newnode->data);
    
    newnode->next=NULL;
    temp=head;

    while( temp->next != NULL )
    {
        temp=temp->next;
    }

    temp->next=newnode;
    count++;
}

void insertbet()
{
    int pos,i;
    newnode=(struct node*)malloc(sizeof(struct node));
    
    printf("\nEnter the position:");
    scanf("%d",&pos);
    
    if ( pos < 1 || pos > count+1 )
    {
        printf("\nInvalid position.\n");
    }
    else if ( pos==1 )
    {
        insertbeg();
    }
    else if ( pos==count )
    {
        insertend();
    }
    else
    {
        temp=head;
        i=1;
        while ( i < pos-1 )
        {
            temp=temp->next;
            i++;
        }
        printf("\nEnter the data:");
        scanf("%d",&newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
        count++;
    }
    
}


void deletebeg()
{
    printf("\nAfter deleting first element.\n");
    temp=head;
    head=temp->next;
    free(temp);
    displaysingly();
}

void deleteend()
{
    struct node *prevnode;
    printf("\nAfter deleting last element.\n");
    temp = head;
    while ( temp->next != 0 )
    {
        prevnode=temp;
        temp=temp->next;
    }
    if ( temp==head )
    {
        head=0;
    }
    else
    {
    prevnode->next=0;
    }
    free(temp);
    
    displaysingly();

}

void deletebet()
{
    struct node* nextnode;
    int pos,i;
    printf("\nEnter the node you want to delete:");
    scanf("%d",&pos);
    
    temp=head;
    i=1;
    while ( i < pos-1 )
    {
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
     
    free(temp);
    displaysingly();
}


void reversesingly()
{
    struct node *prevnode,*currentnode,*nextnode;
    printf("\nReversed list is \n");
    prevnode=NULL;
    currentnode=nextnode=head;
    
    while ( nextnode!=NULL )
    {
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    head=prevnode;
}