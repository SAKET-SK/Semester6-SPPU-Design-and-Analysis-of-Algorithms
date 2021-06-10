#include<stdio.h>
#define infinity 65535

struct edge
{
    int source,destination,weight;
};

struct graph
{
    int nvertices,nedges;
    struct edge edges[10];
};

struct graph creategraph(int nv,int ne)
{
    struct graph graph1;
    graph1.nvertices=nv;
    graph1.nedges=ne;
    return graph1;
}


void bellmanford(struct graph g)
{
    int u,v,w,i,j,flag=0;
    int dist[g.nvertices];

    for(i=0;i<g.nedges;i++)
        dist[i]=infinity;
    dist[0]=0;

    for(i=0;i<g.nvertices-1;i++)
    {
        for(j=0;j<g.nedges;j++)
        {
            u=g.edges[j].source;
            v=g.edges[j].destination;
            w=g.edges[j].weight;
            if((dist[u]+w)<dist[v])
                dist[v]=dist[u]+w;
        }
    }

    printf("\nBELLMAN FORD ALGORITHM OUTPUT:\n");
    printf("\nVERTEX\tDISTANCE\n");
    for(i=0;i<g.nvertices;i++)
        printf("%d\t%d\n",i,dist[i]);

    for(i=0;i<g.nedges;i++)
    {
        u=g.edges[i].source;
        v=g.edges[i].destination;
        w=g.edges[i].weight;
        if((dist[u]+w)<dist[v])
            flag=1;
    }

    if(flag==1)
        printf("\nNEGATIVE EDGES CYCLE DETECTED....\n");
    else
        printf("\nNO NEGATIVE EDGES CYCLE DETECTED....\n");
}

int main()
{
    int nv,ne,sv,i;

    printf("\nEnter the no. of vertices: ");
    scanf("%d",&nv);

    do
    {
        printf("\nEnter the no. of edges (edges<=10): ");
        scanf("%d",&ne);
    }while(ne>10);

    struct graph g=creategraph(nv,ne);

    for(i=0;i<ne;i++)
    {
        printf("\nEnter Source Vertex For Edge No. %d: ",i);
        scanf("%d",&g.edges[i].source);
        printf("\nEnter Destination Vertex For Edge No. %d: ",i);
        scanf("%d",&g.edges[i].destination);
        printf("\nEnter Weight For Edge No. %d: ",i);
        scanf("%d",&g.edges[i].weight);
    }
    printf("\nGRAPH CREATED....\n");

    printf("\nGRAPH IS AS FOLLOWS:\n");
    printf("\nNO. OF VERTICES: %d\n",g.nvertices);
    printf("\nNO. OF EDGES: %d\n",g.nedges);
    printf("\nSOURCE\tDESTINATION\tWEIGHT\n");
    for(i=0;i<ne;i++)
        printf("%d\t%d\t\t%d\n",g.edges[i].source,g.edges[i].destination,g.edges[i].weight);

    bellmanford(g);

    return 0;
}



