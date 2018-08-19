#include<bits/stdc++.h>
using namespace std;
int main()
{
	long t;
	cin>>t;
	while(t--)
	{
		long n;
		cin>>n;
		//multiset <long> s;
		vector <long> s;
		int f[10001]={};
		long inp;
		for(long i=0;i<n;i++)
		{
			scanf("%ld",&inp);
			f[inp]++;
			if(f[inp]==2)
			{
				s.push_back(inp);
				f[inp]=0;
			}	
		}
		sort(s.begin(),s.end());
		long first=-1;
		long second=-2;
		// multiset <long> :: iterator last=s.end();
		// multiset <long> :: iterator temp;
		vector <long> :: reverse_iterator last=s.rend();
		vector <long> :: reverse_iterator temp;
		last--;
		long double ans,min=100000000000000.0;
		long minf,mins,diff=10000000000.0;
		// for(multiset <long> :: iterator i=s.begin();i!=last;i++)
		for(vector <long> :: reverse_iterator i=s.rbegin();i!=last;i++)
		{
			if(first==second && second==*i)
				continue;
			first=*i;
			temp=i;
			temp++;
			second=*temp;
			//	cout<<first<<" "<<second<<endl;
			if(first==second)
			{
				ans=4.0;
				diff=0;
			}
			else
			{
				if(first-second>=diff)
				{
					//cout<<"diff"<<diff<<endl;
					continue;
				}
				long double p=(2*((long double)first+(long double)second))*(2*((long double)first+(long double)second));
				long double s=(long double)first * (long double)second;
				ans=p/s;
			}
			//cout<<ans<<" ";
			if(ans<min)
			{
				min=ans;
				minf=first;
				mins=second;
				diff=first-second;
			}
		}
		printf("%ld %ld %ld %ld\n",minf,minf,mins,mins);
		//cout<<minf<<" "<<minf<<" "<<mins<<" "<<mins<<endl;

	}
}