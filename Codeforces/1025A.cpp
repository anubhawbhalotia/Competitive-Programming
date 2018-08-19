#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n;
	cin>>n;
	long a[26]={};
	char inp;
	int ans=0;
	for(long i=0;i<n;i++)
	{
		cin>>inp;
		a[inp-97]++;
	}
	for(long i=0;i<26;i++)
	{
		if(a[i]>=2)
		{
			ans=1;
			break;
		}
	}
	if(ans==1 || n==1)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}

}