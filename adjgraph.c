#include<stdio.h>
#include<stdlib.h>

typedef struct graph
{
    int numvertices;
    int **adjmatrix;
}Graph;


Graph *creategraph( int numvertices )
{
    Graph *G= (Graph*)malloc(sizeof(Graph));

    G->numvertices=numvertices;

    G->adjmatrix=(int **)malloc(numvertices*sizeof( int *));

    for ( int i=0 ; i < numvertices ; i++ )
    {
        G->adjmatrix[i]=(int *)malloc(numvertices * sizeof(int));
        for ( int j=0 ; j < numvertices; j++ )
        {
            G->adjmatrix[i][j]=0;
        }
    }

    return G;
}

void addedge( Graph *G , int src, int dest )
{
    if ( src>=0 && src < G->numvertices && dest>=0 && dest < G->numvertices )
    {
        G->adjmatrix[src][dest]=1;
    }
}

void printmatrix(Graph *G )
{
    printf("\n\nThe Adjacency matrix of the graph: \n");
    for ( int i=0 ; i < G->numvertices ; i++ )
    {
        for ( int j=0 ; j < G->numvertices ; j++ )
        {
            printf("\t%d",G->adjmatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int numvertices, numedges, src , dest;

    printf("\nEnter the number of vertices of graph: ");
    scanf("%d",&numvertices);

    Graph *Graph=creategraph(numvertices);

    printf("\nEnter the number of edges : ");
    scanf("%d",&numedges);

    for ( int i=0 ; i < numedges ; i++ )
    {
        printf("\nEnter the source of the vertex %d : ",i+1);
        scanf("%d", &src );

        printf("\nEnter the destination of the vertex %d : ",i+1);
        scanf("%d", &dest );

        addedge(Graph,src,dest);
    }

    printmatrix(Graph);

    return 0;
}
