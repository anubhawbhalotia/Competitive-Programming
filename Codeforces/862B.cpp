#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	scanf("%lld",&n);
	int  a[100001]={};
	set <long long> s[100001];
	long long b[3]={},u,v;
	for(long i=0;i<n-1;i++)
	{
		scanf("%lld %lld",&u,&v);
		s[u].insert(v);
		s[v].insert(u);
		//s[min(u,v)].insert(max(u,v)]);	
	}
	queue <long long> q;
	q.push(min(u,v));
	a[min(u,v)]=1;
	b[1]++;
	long temp,val;
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		val=(a[temp]==1)?2:1;
		for(set <long long> :: iterator  it=s[temp].begin();it!=s[temp].end();it++)
		{
			if(a[*it])
				continue;
			a[*it]=val;
			b[val]++;
			q.push(*it);
		}
	}
	cout<<(b[1]*b[2])-(n-1)<<endl;
}