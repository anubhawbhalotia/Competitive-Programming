// Mouse Hunt

#include<bits/stdc++.h>
using namespace std;
long c[200001],a[200001];
long f[200001]={};
long n;
long cycleIndex=1;
long occur[200001]={};
long occurIndex=1;
long cycleFound(long i,vector <long> temp)
{
	int flag=0;
	long min=1000000000;
	for(vector <long> ::iterator it=temp.begin();it!=temp.end();it++)
	{
		if(*it==i)
		{
			flag=1;
		}
		f[*it]=cycleIndex;
		if(flag)
		{
			if(c[*it]<min)
				min=c[*it];
		}
	}
	return min;
}
long initialise(long val,vector <long> temp)
{
	for(vector <long> ::iterator it=temp.begin();it!=temp.end();it++)
	{
		f[*it]=val;
	}
}
int dfs(long i,vector <long> temp)
{
	long long price=0;
	while(1)
	{
		if(occur[i]==occurIndex)
		{
			price+=cycleFound(i,temp);
			cycleIndex++;
			return price;
		}
		if(f[i])
		{
			initialise(f[i],temp);
			return  price;
		}
		temp.push_back(i);
		occur[i]=occurIndex;
		i=a[i];
	}
}
int main()
{
	
	scanf("%ld",&n);
	for(long i=1;i<=n;i++)
		scanf("%ld",&c[i]);
	for(long i=1;i<=n;i++)
		scanf("%ld",&a[i]);
	long long ans=0;
	for(long i=1;i<=n;i++)
	{
		if(f[i])	continue;
		vector <long> temp;
		
		long aa=dfs(i,temp);
		occurIndex++;
		//cout<<aa<<endl;
		ans+=aa;
	}
	cout<<ans<<endl;

}