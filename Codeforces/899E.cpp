#include<bits/stdc++.h>
using namespace std;
int main()
{
	set <pair<long long,long long>> seta,setb;
	set <pair<long long,long long>> :: iterator f;
	long long n,i,l=1,start,ans=0,e1,e2;
	cin>>n;
	long long a[n];
	pair <long long, long long> p,q,r;
	cin>>a[0];
	start=0;
	if(n==1)
	{
		cout<<"1";
		return 0;
	}
	for(i=1;i<n;i++)
	{

		cin>>a[i];
		if(a[i]==a[i-1])
		{
			l++;
		}
		else
		{
			p.first=l*-1;
			p.second=start;
			q.first=start;
			q.second=l;
			seta.insert(p);
			setb.insert(q);
			l=1;
			start=i;
		}
	}
	p.first=l*-1;
	p.second=start;
	q.first=start;
	q.second=l;
	seta.insert(p);
	setb.insert(q);

	set <pair<long long,long long>> :: iterator it;
	/*for(it=seta.begin();it!=seta.end();it++)
	{
		cout<<"("<<it->first<<" "<<it->second<<") ";
	}
	cout<<endl;
	for(it=setb.begin();it!=setb.end();it++)
	{
		cout<<"("<<it->first<<" "<<it->second<<") ";
	}*/

	while(seta.size()>1)
	{
		ans++;
		p.first=seta.begin()->second;
		p.second=seta.begin()->first*-1;
		seta.erase(seta.begin());
		f=setb.find(p);
		e1=-1;
		e2=-1;
		if(f!=setb.begin())
		{
			e1=a[prev(f)->first];
		}
		if(f!=prev(setb.end()))
		{
			e2=a[(setb.upper_bound(p)->first)];
		}
		//setb.erase(f);
		if(e1==e2)
		{
			q.first=(prev(f)->second)*-1;
			q.second=prev(f)->first;
			seta.erase(q);
			q.first=(setb.upper_bound(p)->second)*-1;
			q.second=(setb.upper_bound(p)->first);
			seta.erase(q);
			r=p;
			p.first=prev(f)->first;
			p.second=prev(f)->second + (setb.upper_bound(r))->second;
			q.first=(prev(f)->second + (setb.upper_bound(r)->second))*-1;
			q.second=prev(f)->first;
			setb.erase(prev(f));
			setb.erase(setb.upper_bound(r));
			
			setb.insert(p);
			seta.insert(q);
		}
		setb.erase(f);
	}
	cout<<ans+1;
}
