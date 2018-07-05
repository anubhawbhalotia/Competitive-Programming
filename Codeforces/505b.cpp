#include<bits/stdc++.h>
using namespace std;
int dsu[100][100];
int findRoot(int v,int c)
{
	return v==dsu[c][v] ? v : dsu[c][v]=findRoot(dsu[c][v],c);
}
int dsuUnion(int a,int b,int c)
{
	int aa=findRoot(a,c);
	int bb=findRoot(b,c);
	dsu[c][aa]=bb;
}
int main()
{
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{
			dsu[i][j]=j;
		}
	}
	int n,m;
	cin>>n>>m;
	int a,b,c;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		a--;
		b--;
		c--;
		dsuUnion(a,b,c);
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			findRoot(j,i);
		}
	}
	int q;
	cin>>q;
	int u,v;
	while(q--)
	{
		cin>>u>>v;
		u--;
		v--;
		int ans=0;
		for(int i=0;i<m;i++)
		{
			if(dsu[i][u]==dsu[i][v])
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}