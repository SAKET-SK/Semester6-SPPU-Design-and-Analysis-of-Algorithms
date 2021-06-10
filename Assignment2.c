#include<stdio.h>

int n,sum;
int L[10];
float MRT;
void optimal_storage();

int main()
{
	int i;
	printf("Enter number of programs:");
	scanf("%d",&n);
	printf("Enter Length of program:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&L[i]);
	}
	optimal_storage();
	return 0;
}

void optimal_storage()
{
	int i,j,temp,k=0;
	printf("\nProgram length enter by user:");
	for(i=0;i<n;i++)
	{
		printf("\t %d",L[i]);
	}
	for(i=0;i<n-1;i++)//Sorting
	{
		for(j=0;j<n-i-1;j++)
		{
			if(L[j+1]<L[j])
			{
				temp=L[j];
				L[j]=L[j+1];
				L[j+1]=temp;
			}
		}
	}
	printf("\nSorted Program Length:");
	for(i=0;i<n;i++)
	{
		printf("\t %d",L[i]);
	}
	
	for(i=0;i<n;i++)
	{
		sum=0;
		for(j=0;j<=i;j++)
			sum=sum+L[j];
		MRT=MRT+sum;
	} 
	printf("\n\nTotal Retrieval Time:%f",MRT);
	MRT=MRT/n;
	printf("\n\nMean Retrieval Time:%f",MRT);
	
}


