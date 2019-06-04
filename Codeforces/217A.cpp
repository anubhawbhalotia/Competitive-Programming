#include<bits/stdc++.h>
using namespace std;
int root(int v,int dsu[])
{
	return v==dsu[v]?v:dsu[v]=root(dsu[v],dsu);
}
int unionDsu(int a,int b,int dsu[])
{
	dsu[root(a,dsu)]=root(b,dsu);
	root(a,dsu);
}
int main()
{
	int n;
	cin>>n;
	int x[n],y[n];
	int dsu[200];
	for(int i=0;i<n;i++)
	{
		dsu[i]=i;
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(x[i]==x[j] || y[i]==y[j])
			{
				unionDsu(j,i,dsu);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		root(i,dsu);
	}
	int dsuCheck[200]={};
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(dsuCheck[dsu[i]]==0)
		{
			count++;
			dsuCheck[dsu[i]]=1;
		}
	}
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<dsu[i]<<" ";
	// }
	// cout<<endl;
	cout<<count-1<<endl;


}