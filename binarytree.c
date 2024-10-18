#include<stdio.h>
#include<stdlib.h>

struct btree
{
    int data;
    struct btree *left;
    struct btree *right;
};

struct btree *root;

struct btree * initialize(struct btree * bt )
{
    root=NULL;
    bt->left=NULL;
    bt->right=NULL;
    
    return root;
}

struct btree * createnode( int data )
{
    struct btree* newnode;
    newnode=(struct btree*)malloc(sizeof(struct btree));
  
    newnode->left=NULL;
    newnode->right=NULL;

    newnode->data=data;

    return newnode;
}

struct btree *insert( struct btree * bt,int data )
{
    if ( bt == NULL )
    {
        bt=createnode(data);
    }
    else if ( data < bt->data )
    {
        insert((bt->left),data);
    }
    else
    {
        insert((bt->right),data);
    }
}

void inorder(struct btree * root )
{
    if ( root == NULL )
       return;
    
    inorder(root->left);
    printf("\t%d",root->data);
    inorder(root->right);
}

int main()
{
    printf("\n1.Initialize a Binary tree.");
    printf("\n2.Insert data into a Binary tree.");
    printf("\n3.Inorder traversal of Binary tree.");
    printf("\n4.Preorder traversal of Binary tree.");
    printf("\n5.Postorder traversal of Binary tree.");
    printf("\n6.Exit");

    int choice,data;

    struct btree *bt;

    do 
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch ( choice )
        {
            case 1 : 
                   bt=initialize(root);
                   printf("\nHello i am here");
                   break;

            case 2 :
                   printf("\nEnter the data you want to insert: ");
                   scanf("%d",&data);
                   bt=insert(root,data);
                   break;

            case 3 : 
                   printf("\nThe inorder traversal:\n");
                   inorder(root);
                   break;

            default : 
                    printf("\nWrong choice.");
        }
    }while(choice != 6 );
}