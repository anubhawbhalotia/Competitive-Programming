#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,e;
	scanf("%d",&n);
	int p[1001];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	int index[1001]={};
	int ans[1001]={};
	for(int i=1;i<=n;i++)
	{
		e=i;
		int temp[1001]={};
		temp[e]=1;
		while(1)
		{	
			e=p[e];
			if(temp[e]==1)
			{
				ans[i]=e;
				break;
			}
			temp[e]=1;
		}
		printf("%d ",ans[i]);	
	}
}