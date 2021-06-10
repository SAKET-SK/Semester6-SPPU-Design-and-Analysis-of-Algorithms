#include<stdio.h>

int distance[10][10],visited_city[10],n,cost=0;
void getdistance();
void mincost(int);
int min(int);

int main()
{

	getdistance();
	
	printf("\n\nPath:->");
	mincost(0);
	printf("\nMinimum cost: %d",cost);
	
	return 0;

}

void getdistance()
{
	int i,j;
	
	printf("\nEnter number of cities:");
	scanf("%d",&n);
	printf("\nEnter distance matrix:\n");
	for(i=0;i<n;i++)
	{
		printf("\nEnter distance of row: %d\n",i+1);
		
		for(j=0;j<n;j++)
		{
			scanf("%d",&distance[i][j]);
		}
	visited_city[i]=0;
	}
	
	printf("\n\nCost Matrix:");
	for(i=0;i<n;i++)
	{
		printf("\n");
		
		for(j=0;j<n;j++)
		{
			printf("\t%d",distance[i][j]);	
		}
	}
}

void mincost(int city)
{
	int i,ncity;
	
	visited_city[city]=1;
	
	printf("%d-->",city+1);
	ncity=min(city);
	
	if(ncity==999)
	{
		ncity=0;
		printf("%d",ncity+1);
		cost=cost+distance[city][ncity];
		
		return;
	}
	mincost(ncity);
}

int min(int c)
{
	int i,nc=999;
	int min=999,kmin;
	
	for(i=0;i<n;i++)
	{
		if((distance[c][i]!=0)&&(visited_city[i]==0))
		
			if(distance[c][i]+distance[i][c]<min)
			{
				min=distance[i][0]+distance[c][i];
				kmin=distance[c][i];
				nc=i;
			}
	}
	
	if(min!=999)
		cost=cost+kmin;
	return nc;
}


