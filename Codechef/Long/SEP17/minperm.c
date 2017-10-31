#include<stdio.h>
int main()
{
	long i,n;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld",&n);
		if(n%2==0)
		{
			for(i=1;i<=n;i++)
			{
				if(i%2==0)
				{
					printf("%ld ",i-1);
				}
				else
				{
					printf("%ld ",i+1);
				}
			}
		}
		else
		{
			for(i=1;i<=n-3;i++)
			{
				if(i%2==0)
				{
					printf("%ld ",i-1);
				}
				else
				{
					printf("%ld ",i+1);
				}
			}
			printf("%ld %ld %ld",n-1,n,n-2);
		}
		printf("\n");
	}	
}