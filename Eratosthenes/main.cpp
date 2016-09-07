#include <stdio.h>

#define MAX 1000

int main()
{
	int i,j,c=0;
	int prime[MAX+1];
	for(i=2;i<=MAX;i++)
	{
		prime[i]=1;
	}
	for(i=2;i*i<MAX;i++)
	{
		if(prime[i]==1)
		{
			for(j=2*i;j<=MAX;j++)
			{
				if(!prime[j])
				{
					continue;
				}
				if(j%i==0)
				{
					prime[j]=0;
				}
			}
		}
	}
	for(i=2;i<MAX;i++)
	{
		if(prime[i]==1)
		{
			printf("%4d ",i);
			c++;
			if(c%10==0)
			{
				printf("\n");
			}
		}
	}
	printf("\n一共有%d个素数!\n",c);
	return 1;
}
