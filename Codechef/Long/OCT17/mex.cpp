#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	long n,k,inp,i;
	cin>>t;
	while(t--)
	{
		long a[1000000]={};

		cin>>n>>k;
		for(i=0;i<n;i++)
		{
			cin>>inp;
			a[inp]=1;
		}
		for(i=0;i<1000000;i++)
		{
			if(!a[i])
			{
				if(k)
				{
					k--;
				}
				else
				{
					cout<<i<<"\n";
					break;
				}
			}
		}
	}
}