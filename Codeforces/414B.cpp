#include<bits/stdc++.h>
using namespace std;
const long long M=1e+9+7 ;
int main()
{
	int n,k,i,j,sum=0,kk;
	cin>>n>>k;
	int a[2001][2001]={};
	for(i=1;i<=n;i++)
	{
		a[1][i]=1;
	}
	for(i=2;i<=k;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(kk=j;kk<=n;kk+=j)
			{
				a[i][kk]=(a[i][kk]+a[i-1][j])%M;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		sum=(sum+a[k][i])%M;
	}
	cout<<sum<<endl;
}
		