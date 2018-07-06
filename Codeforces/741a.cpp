#include<bits/stdc++.h>
using namespace std;
long findLcm(int a,int b)
{
	if(a<b)		swap(a,b);
	int aa=a;
	while(a%b!=0)
	{
		a+=aa;
	}
	return a;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	int cycle[n],flag[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		cycle[i]=0;
		flag[i]=0;
		a[i]--;
	}
	int next;
	int c;
	for(int i=0;i<n;i++)
	{
		if(flag[i]==1)	continue;
		next=a[i];
		flag[i]=1;
		flag[next]=1;
		c=0;
		if(next==i)
		{
			cycle[i]=1;
			continue;
		}
		while(next!=i)
		{
			c++;
			if(c>200)	break;
			cycle[i]++;
			next=a[next];
			flag[next]=1;
		}
		if(c>200)	break;
		if(cycle[i])
		{
			cycle[i]++;
		}
		if(cycle[i]%2==0)
		{
			cycle[i]/=2;
		}
	}
	if(c>200)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	int max=-1;
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<cycle[i]<<" ";
	// }
	// cout<<endl;
	sort(cycle,cycle+n);
	int i;
	for(i=0;i<n;i++)
	{
		if(cycle[i]!=0)
		{
			break;
		}
		//cout<<cycle[i]<<" ";
	}
	if(i==n-1)
	{
		cout<<cycle[i]<<endl;
		return 0;
	}
	long lcm=1;
	for(int j=i;j<n;j++)
	{
		lcm=findLcm(lcm,cycle[j]);
	}
	cout<<lcm<<endl;
	

}