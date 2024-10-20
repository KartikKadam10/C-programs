#include<stdio.h>
#include<stdlib.h>

struct btree
{
    int data;
    struct btree *left;
    struct btree *right;
};

struct btree * init()
{
    return NULL;
}

struct btree * createnode( int data )
{
    struct btree* newnode;

    newnode=(struct btree*)malloc(sizeof(struct btree));
  
    newnode->data=data;  
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}

void insert( struct btree **root ,int data )
{
    if ( *root == NULL )
    {
        *root=createnode(data);
    }
    else if ( data < (*root)->data )
    {
        insert(&(*root)->left,data);
    }
    else
    {
        insert(&(*root)->right,data);
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
                   bt=init();
                   break;

            case 2 :
                   printf("\nEnter the data you want to insert: ");
                   scanf("%d",&data);
                   insert(&bt,data);
                   break;

            case 3 : 
                   printf("\nThe inorder traversal:\n");
                   inorder(bt);
                   break;

            default : 
                    printf("\nWrong choice.");
        }
    }while(choice != 6 );
}
