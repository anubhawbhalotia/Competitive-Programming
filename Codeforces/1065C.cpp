#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n,k;
	scanf("%ld %ld",&n,&k);
	long h[n];
	for(long i=0;i<n;i++)
		scanf("%ld",&h[i]);
	sort(h,h+n);
	vector <long> v;
	long curr=h[n-1];
	long i=n-1;
	while(i>=0)
	{
		if(h[i]==curr)
		{
			i--;
			continue;
		}
		long t=curr-h[i];
		while(t--)
			v.push_back((n-1)-i);
		curr=h[i];
		i--;
	}
	//cout<<"curr="<<curr<<endl;
	// for(long i=0;i<v.size();i++)
	// 	cout<<v[i]<<" ";
	// cout<<endl;
	long t=curr;
	while(t--)
		v.push_back((n-1)-i);
	// for(long i=0;i<v.size();i++)
	// 	cout<<v[i]<<" ";
	// cout<<endl;
	multiset <long> s;
	//s.insert(-1);
	//long bin_rem[200001]={};
	long res=0;
	curr=v[v.size()-1];
	long ii=v.size()-1;
	while(v[ii]==curr && ii>=0)
		ii--;
	//cout<<"i="<<i<<endl;
	long ans=0;
	for(long i=0;i<=ii;i++)
	{
		//cout<<v[i]<<endl;
		if(ans+v[i]<=k)
		{
			ans+=v[i];
		}
		else
		{
			res++;
			ans=v[i];
		}
		// multiset <long> ::iterator it=s.lower_bound(v[i]);
		// if(it!=s.end())
		// {
		// 	long temp=*it;
		// 	s.erase(it);
		// 	if(temp-v[i]>0)
		// 		s.insert(temp-v[i]);
		// }
		// // for(j=0;j<res;j++)
		// // {
		// // 	if(bin_rem[j]>=v[i])
		// // 	{
		// // 		bin_rem[j]-=v[i];
		// // 		break;
		// // 	}
		// // }
		// else
		// {
		// 	//bin_rem[res]=k- v[i];
		// 	s.insert(k-v[i]);
		// 	res++;
		// }
	}
	if(ans>0)
		res++;
	cout<<res<<endl;




}