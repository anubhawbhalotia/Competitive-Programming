#include <bits/stdc++.h>
using namespace std;
int main()
{
	long n,cm,hm,i,s,inp1,inp2,t,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>cm>>hm;
		int a[n][n]={};
		for(i=0;i<(2*n);i++)
		{
			cin>>inp1>>inp2;
		}
		s=inp2%n;
		for(i=0;i<n;i++)
		{
			a[s][i]=1;
			a[i][s]=1;	
		}
		a[s][s]=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout<<a[i][j];
			}
			cout<<"\n";
		}
	}
}