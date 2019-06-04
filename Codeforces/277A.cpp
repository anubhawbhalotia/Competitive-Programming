#include<bits/stdc++.h>
using namespace std;
int root(int k,int dsu[])
{
	return (dsu[k]==k)?k:dsu[k]=root(dsu[k],dsu);
}
int main()
{
	int n,m;
	cin>>n>>m;
	//int f[101][101]={};
	set <int> a[101],b[101];
	int check[101]={};
	int dsuCheck[101]={};
	int dsu[101],inp;
	int z=0;
	for(int i=0;i<n;i++)
	{
		int k;
		dsu[i]=i;
		cin>>k;
		if(k)
		{
			z++;
		}
		for(int j=0;j<k;j++)
		{
			cin>>inp;
			b[inp].insert(i);
			//f[i][inp]=1;
			a[i].insert(inp);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(auto &j:a[i])
		{
			if(check[j])	continue;
			for(auto &k : b[j])
			{
				if(k<=i) continue;
				// int temp=root(k,dsu);
				dsu[root(k,dsu)]=root(i,dsu);
				// root(temp,dsu);
				root(k,dsu); //child nodes are not updated with parent value. Values are updated only from parent to this node
			}
			check[j]=1;
		}
	}
	int count=0;
	for(int i=0;i<n;i++)
	{
		root(i,dsu);//This is done to update all nodes which were left earliew
		// cout<<dsu[i]<<" ";
		if(dsuCheck[dsu[i]]==0)
		{
			count++;
			dsuCheck[dsu[i]]=1;
		}
		
	}
	// cout<<endl;
	if(z==0)
	{
		cout<<count<<endl;
	}
	else
	{
		cout<<count-1<<endl;	
	}



}