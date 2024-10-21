#include<stdio.h>
#include<stdlib.h>


typedef struct graph
{
    int numvertices;
    int **adjmatrix;
}Graph;

Graph *creategraph( int numvertices )
{
    Graph *graph;

    graph=(Graph*)malloc(sizeof(Graph));

    graph->numvertices=numvertices;
    
    graph->adjmatrix=(int **)malloc(numvertices*sizeof(int*));

    for ( int i=0 ; i < numvertices ; i++ )
    {
        graph->adjmatrix[i]=(int*)malloc(numvertices*sizeof(int));

        for ( int j=0 ; j< numvertices ; j++ )
        {
            graph->adjmatrix[i][j]=0;
        }
    }

    return graph;
}

void addedge(Graph *graph, int src ,int dest )
{
    if ( src >=0 || src< graph->numvertices || dest >=0 || dest < graph->numvertices  )
    {
        graph->adjmatrix[src][dest]=1;
    }
}

void printmatrix(Graph * graph )
{
    printf("\nThe adjacency matrix of the given graph:\n");
    
    for ( int i=0 ; i < graph->numvertices ; i++ )
    {
        for ( int j=0 ; j < graph->numvertices ; j++ )
        {
            printf("\t%d",graph->adjmatrix[i][j]);
        }
        printf("\n");
    }
}

int outdegree(Graph *graph , int vertex )
{
    int out=0;
    for ( int i=0 ; i<graph->numvertices ; i++ )
    {
          if ( graph->adjmatrix[vertex][i]==1)
              out++;
    }

    return out;
}

int indegree(Graph *graph , int vertex )
{
    int ind=0;
    for ( int i=0 ; i<graph->numvertices ; i++ )
    {
          if ( graph->adjmatrix[i][vertex]==1)
              ind++;
    }

    return ind++;
}



int main()
{
    int numvertices, numedges, src , dest;
   
    printf("\nEnter the number of vertices of graph: ");
    scanf("%d",&numvertices);
 
    Graph *graph=creategraph(numvertices);

    printf("\nEnter the number of edges: ");
    scanf("%d",&numedges);

    for ( int i=0 ; i<numedges; i++ )
    {
        printf("\nEnter the source vertex of %d vertex: ",i+1);
        scanf("%d",&src);

        printf("\nEnter the destination vertex of %d vertex: ",i+1);
        scanf("%d",&dest);

        addedge(graph,src,dest);
    }

    printmatrix(graph);

    printf("\nThe Indegree of all vertices:\n");

    for ( int i=0 ; i<numvertices ; i++ )
    {
        printf("\n Vertex -> %d  Indegree : %d\t Outdegree : %d",i , indegree(graph,i),outdegree(graph,i));
    }

}
