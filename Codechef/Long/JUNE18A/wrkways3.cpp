#include<bits/stdc++.h>
using namespace std;
long factorise(long fac[],long c)
{
	long x=0;
	for(long i=1;i<=sqrt(c);i++)
	{
		if(c%i==0)
		{
			if(i!=(c/i))
			{
				fac[x]=i;
				x++;
				fac[x]=c/i;
				x++;
			}
			else
			{
				fac[x]=i;
				x++;
			}
		}
	}
	sort(fac,fac+x);
	return x;
}
void displayArray(long fac[],long x)
{
	for(long i=0;i<x;i++)
	{
		cout<<fac[i]<<" ";
	}
	cout<<endl;
}
void initialiseArray(long a[],long n,long val)
{
	for(long i=0;i<n;i++)
	{
		a[i]=val;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long fac[100000];
		long c,n;
		scanf("%ld %ld",&n,&c);
		if(n==1)
		{
			printf("%ld\n",c);
			continue;
		}
		if(c==1)
		{
			for(long i=1;i<=n;i++)
			{
				printf("%ld ",i);
			}
			printf("\n");
			continue;
		}
		long len=factorise(fac,c);
		//displayArray(fac,len);
		long ans[n];
		for(long i=0;i<len;i++)
		{
			long tempi=i;
			//cout<<"i="<<i<<endl;
			long x=n-1;
			initialiseArray(ans,n,1);
			
			ans[x]=fac[tempi];
			x--;
			long prod=c / fac[tempi];
			while(prod!=1 && x!=-1)
			{
				long temp=x;
				if(fac[tempi]!=c && fac[tempi+1]-fac[tempi]==1 && prod%fac[tempi+1]==0)
				{
					
						prod/=fac[tempi+1];
						ans[x]=fac[tempi+1];
						x--;
						
					if(x==-1 && prod!=1)
					{
						break;
					}
					tempi++;
					continue;
				}
				for(long j=tempi;j>0;j--)
				{	
					while(prod%fac[j]==0)
					{
						prod/=fac[j];
						ans[x]=fac[j];
						x--;
						if(x==-1)
						{
							break;
						}
					}
					if(x==-1 || prod==1)
					{
						break;
					}
				}
				if(prod==1 || temp==x)
				{
					break;
				}
			}
			if(prod==1)
			{
				break;
			}
		}
		for(long i=0;i<n;i++)
		{
			ans[i]+=i;
			printf("%ld ",ans[i]);
		}
		printf("\n");
	}
}