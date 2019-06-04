#include<bits/stdc++.h>
using namespace std;
// int root(int a,int dsu[])
// {
// 	return a==dsu[a]?a:dsu[a]=root(a,dsu[a]);
// }
int findTreeHeight(int a,int dsu[])
{
	if(a==dsu[a])
	{
		// cout<<"True"<<endl;
		return 1;
	}
	return 1+findTreeHeight(dsu[a],dsu);
}

int unionNode(int a,int b,int dsu[])
{
	if(b==-2)
	{
		return 0;
	}
	dsu[a]=b;
	//root(a,dsu);
}
int main()
{
	int n;
	cin>>n;
	int p[4000],dsu[4000]={},dsuCheck[4000]={};
	for(int i=0;i<n;i++)
	{
		dsu[i]=i;
	}
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
		p[i]--;
		unionNode(i,p[i],dsu);
	}
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<dsu[i]<<" ";
	// }
	// cout<<endl;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans=max(ans,findTreeHeight(i,dsu));
		// cout<<ans<<endl;
	}
	cout<<ans;

}