#include<stdio.h>
int main()
{
	int n,x,i,b[150],c,a;
	scanf("%d %d",&n,&x);
	for(i=0;i<110;i++)
	{
		b[i]=0;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		b[a]=1;
	}
	c=0;
	for(i=0;i<x;i++)
	{
		if(b[i]==0)
		{
			c++;
		}
	}
	if(b[x]==1)
	{
		c++;
	}
	printf("%d",c);


}