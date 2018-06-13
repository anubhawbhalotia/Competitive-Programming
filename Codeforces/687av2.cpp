#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n,m,u,v;
	cin>>n>>m;
	map < long, pair < long, set <long> > > a;
	queue <long> q;
	set <long> vv[2];	
	for(long i=0;i<m;i++)
	{
		cin>>u>>v;
		a[u].first=0;
		a[u].second.insert(v);
		a[v].first=0;
		a[v].second.insert(u);
	}
	int turn=1;
	for(auto &i:a)
	{
		if(i.second.first!=0)
		{
			continue;
		}
		i.second.first=turn;
		vv[i.second.first-1].insert(i.first);
		q.push(i.first);
		while(!q.empty())
		{
			long temp=q.front();
			q.pop();
			turn=(a[temp].first==1)?2:1;
			for(auto &j: a[temp].second)
			{
				if(a[j].first==0)
				{
					a[j].first=turn;
					//f[a[j].second.first-1]++;
					vv[(a[j].first)-1].insert(j);
					q.push(j);
				}
				else if(a[j].first!=turn)
				{
					cout<<"-1"<<endl;
					return 0;
				}
			}
		}
	}
	cout<<vv[0].size()<<endl;
	for(auto &i: vv[0])
	{
		cout<<i<<" ";
	}
	cout<<endl;
	cout<<vv[1].size()<<endl;
	for(auto &i: vv[1])
	{
		cout<<i<<" ";
	}
	cout<<endl;

}