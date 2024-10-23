// A code for singly linked list creation and all its operation.
#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node* next;
};

struct node *head,*newnode,*temp,*tail;
int count;

struct node * create()
{
    int n,data;
    
    head=NULL;

    printf("\nHow many nodes you want to create: ");
    scanf("%d",&n);
    
    count=0;

    if ( n>0 )
    {
    for ( int i=0 ; i<n ; i++ )
    {
        printf("\nEnter the data of node %d: ",i+1);
        scanf("%d",&data);

        newnode=(struct node*)malloc(sizeof(struct node));
        
        newnode->data=data;
        newnode->next=NULL;

        if ( head==NULL )
        {
            head=temp=newnode;
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
    }
    else
    {
        printf("\nPlease enter valid number.");
    }

    return head;
}

void display(struct node *head )
{
    temp=head;

    while(temp!=NULL)
    {
        printf("\t%d",temp->data);
        temp=temp->next;
    }
    printf("\tNULL");
}

struct node * insertatbeg(struct node * head )
{
    int data;
    printf("\nEnter the data you want to insert at beginning: ");
    scanf("%d",&data);

    newnode=(struct node *)malloc(sizeof(struct node));
    
    newnode->data=data;
    newnode->next=NULL;

    if ( head==NULL )
    {
        head=newnode;
    }
    else
    {
        temp=head;
        head=newnode;
        newnode->next=temp;
    }
    count++;
    return head;
}

struct node *insertatend(struct node * head )
{
   int data;
   printf("\nEnter the data you want to insert at end:");
   scanf("%d",&data);

   newnode=(struct node *)malloc(sizeof(struct node));
   newnode->data=data;
   newnode->next=NULL;

   tail->next=newnode;
   tail=newnode;
   count++;
   return head;
}

struct node * insertinbet(struct node*head )
{
    int pos;
    printf("\nEnter the position of the data: ");
    scanf("%d",&pos);

    if ( pos==1 )
    {
        return(insertatbeg(head));
    }
    else if ( pos==count+1 )
    {
        return(insertatend(head));
    }
    else
    {
       int data;
       printf("\nEnter the data you want to insert in between: ");
       scanf("%d",&data);

       newnode=(struct node *)malloc(sizeof(struct node));
    
       newnode->data=data;
       newnode->next=NULL;
       
       int i=1;
       temp=head;
       while ( i < pos-1 )
       {
        temp=temp->next;
        i++;
       }

       newnode->next=temp->next;
       temp->next=newnode;
       count++;
       return head;
    }
    
}

struct node* insert(struct node *head )
{
    int choice;
    printf("\nWhere do you want to insert: ");
    printf("\n1.At beginning.");
    printf("\n2.In between.");
    printf("\n3.At end.");

    printf("\n\nEnter your choice for insertion:");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1 :
               return (insertatbeg(head));
               break;

        case 2 :
               return (insertinbet(head));
               break;

        case 3 :
               return (insertatend(head));
               break;          
        
        default :
               printf("\nYou have entered wrong choice.");

    }
}

struct node *deletefront(struct node*head )
{
    temp=head;
    head=head->next;

    free(temp);
    count--;
    return head;
}

struct node *deleteend(struct node*head )
{
    temp=head;

    while ( temp->next->next != NULL )
    {
        temp=temp->next;
    }

    temp->next=NULL;
    free(tail);
    tail=temp;
    count--;
    return head;
}

struct node * deletein(struct node * head,int node )
{
    if ( node > 0 && node < count+1 )
    {
    if ( node==1 )
    {
        return( deletefront( head ));
    }
    else if ( node==count )
    {
        return ( deleteend(head) );
    }
    else
    {
        int i=1;
        temp=head;
        struct node * current;
        while ( i < node )
        {
            current=temp;
            temp=temp->next;
            i++;
        }

        current->next=temp->next;
        free(temp);
        count--;
        return head;
    }
    }
    else
    {
        printf("\nEnter valid number.");
    }
}

struct node* delete(struct node *head )
{
    int pos;
    printf("\nWhich Node do you want to delete : ");
    scanf("%d",&pos);

    if ( pos==1 )
    {
        return(deletefront(head));
    }
    else if ( pos==count )
    {
        return ( deleteend(head) );
    }
    else
    {
        return ( deletein(head,pos) );
    }
}


int main()
{
   printf("\n-------Singly linked list operations------\n");
   printf("1.Create.\n");
   printf("2.Insert.\n");
   printf("3.Delete.\n");
   printf("4.Display.\n");
   printf("5.Exit\n");

   int choice;

   do
   {
       printf("\nEnter your choice:");
       scanf("%d",&choice);

       switch(choice)
       {
          case 1:
                 head=create();
                 break;

          case 2:
                 head=insert(head);
                 break;

          case 3:
                 head=delete(head);
                 break;
        
          case 4:
                 printf("\nThe singly linked list:\n ");
                 display(head);
                 break;

          case 5:
                printf("\nThe program has executed successfully.");
                exit(0);  
          default:
                 printf("\nYou have entered wrong choice.");
                 
       }
   }while ( choice != 5 );
   
}