#include<bits/stdc++.h>
using namespace std;
void displaySetLong(set <long> s)
{
	cout<<"f"<<endl;
	for(set <long> :: iterator it=s.begin();it!=s.end();it++)
	{
		cout<<*it<<" ";
	}
}
int main()
{
	long n;
	scanf("%ld",&n);
	long a[n],b[n];
	long long min=100000000000000;
	long minIndex;
	for(long i=0;i<n;i++)
	{
		scanf("%ld %ld",&a[i],&b[i]);
		if((a[i]+b[i])<min)
		{
			min=a[i]+b[i];
			minIndex=i;
		}
	}
	set <long> f;
	set <long> s;
	for(long i=2;i<=floor(sqrt(a[minIndex]));i++)
	{
		if(a[minIndex]%i==0)
		{
			f.insert(i);
			f.insert(a[minIndex]/i);
		}
	//	displaySetLong(f);
	}	
	f.insert(a[minIndex]);
	//displaySetLong(f);
	for(long i=2;i<=floor(sqrt(b[minIndex]));i++)
	{
		if(b[minIndex]%i==0)
		{
			f.insert(i);
			f.insert(b[minIndex]/i);
		}
		//displaySetLong(f);
	}	
	f.insert(b[minIndex]);
	//displaySetLong(f);
	
	for(long i=0;i<minIndex;i++)
	{
		
		if(f.begin()==f.end())
		{
			printf("-1\n");
			return 0;
		}
		int c=0;
		vector <set <long> ::iterator> v; 
		set <long> ::iterator y,z;
		y=s.lower_bound(a[i]);
		z=s.lower_bound(b[i]);
		if(y!=s.end())
		{
			if(*y!=a[i])
				s.insert(a[i]);
			else
				c++;
		}
		else
			s.insert(a[i]);
		if(z!=s.end())
		{
			if(*z!=b[i])
				s.insert(b[i]);
			else
				c++;
		}
		else
			s.insert(b[i]);
		if(c==2)	continue;

		for(set <long> ::iterator it=f.begin();it!=f.end();it++)
		{
			if(a[i]%*it !=0 && b[i]%*it !=0)
			{
				v.push_back(it);
			}
		}
		for(vector <set <long> ::iterator> ::iterator it=v.begin();it!=v.end();it++)
		{
			f.erase(*it);
		}
	}
	for(long i=minIndex+1;i<n;i++)
	{ 
		if(f.begin()==f.end())
		{
			printf("-1\n");
			return 0;
		}
		int c=0;
		vector <set <long> ::iterator> v; 
		set <long> ::iterator y,z;
		y=s.lower_bound(a[i]);
		z=s.lower_bound(b[i]);
		if(y!=s.end())
		{
			if(*y!=a[i])
				s.insert(a[i]);
			else
				c++;
		}
		else
			s.insert(a[i]);
		if(z!=s.end())
		{
			if(*z!=b[i])
				s.insert(b[i]);
			else
				c++;
		}
		else
			s.insert(b[i]);
		if(c==2)	continue;
		for(set <long> ::iterator it=f.begin();it!=f.end();it++)
		{
			if(a[i]%*it !=0 && b[i]%*it !=0)
			{
				v.push_back(it);
			}
		}
		for(vector <set <long> ::iterator> :: iterator it=v.begin();it!=v.end();it++)
		{
			f.erase(*it);
		}
	}
	if(f.begin()==f.end())
	{
		printf("-1\n");
		return 0;
	}
	// for(set <long> :: iterator it =f.begin();it!=f.end();it++)
	// {
	// 	cout<<*it<<" ";
	// }
	printf("%ld\n",*f.begin());
}