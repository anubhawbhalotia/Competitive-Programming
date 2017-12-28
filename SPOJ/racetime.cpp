#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n,q,i,x,p,qq,c;
	char ch;
	cin>>n>>q;
	long a[n+1];
	for(i=1;i<=n;i++)
	{
		scanf("%ld",&a[i]);
	}
	while(q--)
	{
		cin>>ch;
		if(ch=='M')
		{
			scanf("%ld %ld",&i,&x);
			a[i]=x;
		}
		else
		{
			c=0;
			scanf("%ld %ld %ld",&p,&qq,&x);
			for(i=p;i<=qq;i++)
			{
				if(a[i]<=x)
				{
					c++;
				}
			}
			printf("%ld\n",c);
		}
	}
}