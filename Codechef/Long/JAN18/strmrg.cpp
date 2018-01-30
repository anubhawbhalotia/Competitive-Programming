#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9 +7;
string a,b,aa,bb;
 
int dp(int d[][5001],int n,int m)
{
	if(n<0 || m<0)
	{
		return 0;
	}
	if(d[n][m])
	{
		return d[n][m];
	}
	if(aa[n]==bb[m])
	{
		d[n][m]=1+dp(d,n-1,m-1);
	}
	else
	{
		d[n][m]=max(dp(d,n-1,m),dp(d,n,m-1));
	}
	return d[n][m];
}
 
 
int main()
{
	int t,n,m,i,ans;
	scanf("%d",&t);
	while(t--)
	{
		aa="";
		bb="";
		scanf("%d %d",&n,&m);
		int d[5001][5001]={};
		cin>>a;
		cin>>b;
		for(i=0;i!=a.length()-1;i++)
		{
			if(a[i]!=a[i+1])
			{
				aa+=a[i];
			}
		}
		aa+=a[a.length()-1];
		for(i=0;i!=b.length()-1;i++)
		{
			if(b[i]!=b[i+1])
			{
				bb+=b[i];
			}
		}
		bb+=b[b.length()-1];
		n=aa.length();
		m=bb.length();
		
		ans=dp(d,n-1,m-1);
		printf("%d\n",n+m-ans);
 
	}
}
