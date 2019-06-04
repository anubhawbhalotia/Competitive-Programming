#include<bits/stdc++.h>
using namespace std;
typedef struct link
{
	long parent;
	vector <long> child;
}node;
node a[100000];
vector <long> ans;
int init[100001],final[100001];
int bfs(long val,int setFlag,int fSet0,int fSet1,int level)
{
	//cout<<val+1<<" "<<setFlag<<" "<<fSet0<<" "<<fSet1<<" "<<level<<endl;
	level=!level;
	if(setFlag)
	{
		if(level==0)
		{
			if(fSet0)
			{
				init[val]=(init[val]==1) ? 0 : 1;
			}
		}
		else
		{
			if(fSet1)
			{
				init[val]=(init[val]==1) ? 0 : 1;
			}
		}
	}
	if(init[val]!=final[val])
	{
		ans.push_back(val+1);
		setFlag=1;
		init[val]=final[val];
		if(level==0)
		{
			fSet0=(fSet0==1) ? 0:1;
		}
		else
		{
			fSet1=(fSet1==1) ? 0:1;
		} 
	}
	queue <long> q;
	for(vector <long> :: iterator i=a[val].child.begin();i!=a[val].child.end();i++)
	{
		q.push(*i);
	}
	while(!q.empty())
	{
		long temp=q.front();
		q.pop();
		bfs(temp,setFlag,fSet0,fSet1,level);
	}

}
int main()
{
	long n;
	cin>>n;
	vector <long> vec[100001];
	long u,v;
	for(long i=0;i<n-1;i++)
	{
		cin>>u>>v;
		u--;
		v--;
		//if(u>v)		swap(u,v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	queue <long> q;
	q.push(0);
	while(!q.empty())
	{
		long temp=q.front();
		q.pop();
		for(vector <long> :: iterator i=vec[temp].begin();i!=vec[temp].end();i++)
		{
			if(*i == a[temp].parent)	continue;
			q.push(*i);
			a[temp].child.push_back(*i);
			a[*i].parent=temp;
		}
	}
	
	for(long i=0;i<n;i++)
	{
		cin>>init[i];
	}
	for(long i=0;i<n;i++)
	{
		cin>>final[i];
	}
	bfs(0,0,0,0,1);
	cout<<ans.size()<<endl;
	for(vector <long> :: iterator i=ans.begin();i!=ans.end();i++)
	{
		cout<<*i<<endl;
	}

}