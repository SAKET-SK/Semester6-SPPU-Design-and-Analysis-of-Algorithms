#include<stdio.h>

#define INF 999
int cost[5][5],reduced[5][5],ocost,n,InitialVertex=0,citycost[5],visited[5],Mat[5][5];

void copymat(int a[5][5], int b[5][5])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            a[i][j]=b[i][j];
    }
}

void getcost()
{
    int i,j;

    printf("\nEnter the Number of Cities (Number<=5): ");
    scanf("%d",&n);

    printf("\nEnter The Distance From Cities:\n");
    for(i=0;i<n;i++)
    {
        printf("\nEnter Distances From City %d\n",i+1);
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                printf("\nEnter Distance from city %d to city %d: ",i+1,j+1);
                scanf("%d",&cost[i][j]);
            }
            else
                cost[i][j]=INF;
        }
        visited[i]=0;
    }
    printf("\nThe Distance Matrix is:\n");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
            if(cost[i][j]!=INF)
                printf("\t%d",cost[i][j]);
            else
                printf("\t0");
        }
    }
}

int rowred()
{
    int i,j,min=INF,rowsum=0;
    for(i=0;i<n;i++)
    {
        min=INF;
        for(j=0;j<n;j++)
        {
            if(Mat[i][j]<min)
                min=Mat[i][j];
        }
        if((min!=INF)&&(min!=0))
        {
            rowsum+=min;
            for(j=0;j<n;j++)
            {
                if((Mat[i][j]!=INF)&&(Mat[i][j]!=0))
                    Mat[i][j]-=min;
            }
        }
    }
    return rowsum;
}

int colred()
{
    int i,j,min=INF,colsum=0;
    for(i=0;i<n;i++)
    {
        min=INF;
        for(j=0;j<n;j++)
        {
            if(Mat[j][i]<min)
                min=Mat[j][i];
        }
        if((min!=INF)&&(min!=0))
        {
            colsum+=min;
            for(j=0;j<n;j++)
            {
                if((Mat[j][i]!=INF)&&(Mat[j][i]!=0))
                    Mat[j][i]-=min;
            }
        }
    }
    return colsum;
}

void reduce(int city, int ncity)
{
    int i;
    copymat(Mat,cost);
    for(i=0;i<n;i++)
        Mat[city][i]=INF;
    for(i=0;i<n;i++)
        Mat[i][ncity]=INF;
    Mat[ncity][InitialVertex]=INF;
}

void initialreduce()
{
    int rowsum,colsum;
    copymat(Mat,cost);
    rowsum=rowred();
    colsum=colred();
    citycost[InitialVertex]=rowsum+colsum;
    copymat(cost,Mat);
}

void tsp(int city)
{
    int i,j,val,rowsum,colsum,ncity,min=INF,flag=0;
    visited[city]=1;
    if(city!=InitialVertex)
        copymat(cost,reduced);
    for(i=0;i<n;i++)
    {
        if(visited[i]!=1)
        {
            flag=1;
            reduce(city,i);
            rowsum=rowred();
            colsum=colred();
            val=rowsum+colsum+citycost[city]+cost[city][i];
            if(val<min)
            {
                min=val;
                ncity=i;
                citycost[i]=min;
                copymat(reduced,Mat);
            }
        }
    }
    if(flag==0)
        return;
    else
    {
        ocost=citycost[ncity];
        printf("%d->",ncity+1);
        tsp(ncity);
    }
}

int main()
{
    getcost();
    initialreduce();
    printf("\n\nOptimal Path: %d->",InitialVertex+1);
    tsp(InitialVertex);
    printf("%d",InitialVertex+1);
    printf("\n\nMinimum Cost: %d",ocost);

    return 0;
}


