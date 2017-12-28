#include<bits/stdc++.h>
using namespace std;
int main()
{
	long count,i,x,minv,temp,ans=0;
	pair <char,long> p;
	char last;
	string s;
	vector <pair<char,long>> v[1000000];
	cin>>s;
	if(s.length()==1)
	{
		cout<<"0";
		return 0;
	}
	//creating vector
	last=s[0];
	count=1;
	i=1;
	while(i!=s.size()-1)
	{
		if(s[i]==last)
		{
			count++;
		}
		else
		{
			p.first=last;
			p.second=count;
			count=1;
			last=s[i];
			v[0].push_back(p);
		}
		i++;
	}
	if(s[i]==last)
	{
		count++;
		p.first=last;
		p.second=count;
		v[0].push_back(p);
	}
	else
	{
		p.first=last;
		p.second=count;
		v[0].push_back(p);
		p.first=s[i];
		p.second=1;
		v[0].push_back(p);
	}

	x=0;
	while(v[x].size()>1)
	{
		minv=1000001;
		temp=v[x][0].second;
		for(i=1;i!=v[x].size()-1;i++)
		{
			if(v[x][i].second<minv)
			{
				minv=v[x][i].second;
			}
		}
		minv=ceil(minv/2.0);
		if(temp<minv)
		{
			minv=temp;
		}
		if(v[x][i].second<minv)
		{
			minv=v[x][i].second;
		}
		//subtracting min
		//subract until count!=0
		i=0;
		ans+=minv;
		count=0;
		v[x][0].second-=minv;
		if(v[x][0].second)
		{
			last=v[x][0].first;
			count=v[x][0].second;
		}
		i++;
		if(count==0)
		{
			while(count==0 && i<v[x].size()-1)
			{
				v[x][i].second-=min(v[x][i].second,2*minv);
				if(v[x][i].second)
				{
					last=v[x][i].first;
					count=v[x][i].second;
				}
				i++;
			}
		}
		if(count==0 && i==v[x].size()-1)
		{
			v[x][i].second-=minv;
			break;
		}
		for(;i!=v[x].size()-1;i++)
		{
			v[x][i].second-=min(v[x][i].second,2*minv);	
			if(v[x][i].second)
			{
				if(v[x][i].first==last)
				{
					count+=v[x][i].second;
				}
				else
				{
					p.first=last;
					p.second=count;
					last=v[x][i].first;
					count=v[x][i].second;
					v[x+1].push_back(p);
				}
			}
		}
		v[x][i].second-=minv;
		if(v[x][i].second)
		{
			if(v[x][i].first==last)
			{
				count+=v[x][i].second;
				p.first=last;
				p.second=count;
				v[x+1].push_back(p);
			}
			else
			{
				p.first=last;
				p.second=count;
				v[x+1].push_back(p);
				v[x+1].push_back(v[x][i]);
			}
			count=0;
		}
		else if(count)
		{
			p.first=last;
			p.second=count;
			v[x+1].push_back(p);
		}
		x++;
	}
	cout<<ans;
}