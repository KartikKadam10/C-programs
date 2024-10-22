#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *init()
{
    return NULL;
}

struct node * createnode(int data)
{
    struct node* newnode;

    newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}

void insert(struct node **root,int data )
{
    if ( *root==NULL )
    {
        *root=createnode(data);
    }
    else if ( data < (*root)->data )
    {
        insert( &(*root)->left , data );
    }
    else
    {
        insert( &(*root)->right , data );
    }
}

void inorder(struct node *root )
{
    if ( root == NULL )
       return;

    inorder(root->left);
    printf("\t%d",root->data);
    inorder(root->right);
}

struct node * search(struct node *root , int target )
{
    if ( root->data == target || root==NULL )
    {
        return root;
    }
    else if ( target < root->data )
    {
        return (search(root->left,target ));
    }
    
    return (search(root->right,target));
}

void postorder(struct node * root )
{
    if ( root== NULL )
       return;

    postorder(root->left);
    postorder(root->right);
    printf("\t%d",root->data);
}

void preorder(struct node * root )
{
    if ( root== NULL )
       return;

    printf("\t%d",root->data);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    struct node *bt;

    printf("\n-------Binary Tree operations------\n");
    printf("\n1.Create a Binary tree.");
    printf("\n2.Insert into Binary tree.");
    printf("\n3.Search in Binary tree.");
    printf("\n4.Inoder traversal.");
    printf("\n5.Postorder traversal.");
    printf("\n6.Preorder traversal.");
    printf("\n7.Exit");

    int choice,data;

    do
    { 
        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch ( choice )
        {
            case 1 :
                    bt=init();
                    printf("\nInitilized the root to null.");
                    break;
            
            case 2 :
                    printf("\nEnter the data you want to insert:");
                    scanf("%d",&data);
                    insert(&bt,data);
                    break;
            
            case 3 : 
                    printf("\nEnter the data you want to search: ");
                    scanf("%d",&data);
                    struct node * found;
                    found=search(bt,data);
                    if ( found != NULL  )
                    {
                        printf("\nThe data has been found.");
                    }
                    else
                    {
                        printf("\nThe data has not been found.");
                    }
                    break;

            case 4 :
                    printf("\nThe inorder traversal of Binary tree: \n");
                    inorder(bt);
                    break;

            case 5 :
                    printf("\nThe postorder traveral of Binary tree :\n");
                    postorder(bt);
                    break;
                
            case 6 :
                    printf("\nThe preorder traversal of Binary tree :\n");
                    preorder(bt);
                    break;
 
            case 7 :
                    printf("\nThe program executed successfully.");
                    exit(0);
            default: 
                    printf("\nWrong choice.");
        }
    }while(choice != 7 );
}
