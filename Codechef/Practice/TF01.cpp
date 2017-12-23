#include<bits/stdc++.h>
using namespace std;
int compare (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
}
int main()
{
	int n,k,i,t,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		int a[n],b[1000]={};
		b[0]=1;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			for(j=k-a[i];j>=0 && b[k]==0;j--)
			{
				if(b[j]==1)
				{
					b[j+a[i]]=1;
				}
			}
		}
		if(b[k]==1)
		{
			cout<<"1\n";
		}
		else
		{
			cout<<"0\n";
		}

	}
}