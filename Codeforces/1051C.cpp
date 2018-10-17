#include<bits/stdc++.h>
using namespace std;
#define l  long
#define ll long long
#define S string
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
//Anubhaw Bhalotia https://github.com/anubhawbhalotia 
#define fi first
#define	se second
#define f(i,s,n) for(long i=s;i<n;i++)
#define fe(i,s,n) for(long i=s;i<=n;i++)
#define mod 10e9 + 7
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef pair<ll,ll> pllll;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int freq[101]={};
	f(i,0,n)
	{
		scanf("%d",&a[i]);
		freq[a[i]]++;
	}
	int d[101]={};
	int flag=0;
	fe(i,1,100)
	{
		if(freq[i])
		{
			if(freq[i]!=0 && freq[i]!=1 && freq[i]!=2)
				flag=1;
			d[freq[i]]++;
		}
	}
	if(d[1]==0)
	{
		printf("YES\n");
		f(i,0,n)
			printf("A");
		printf("\n");
	}	
	else if(d[1]%2==0)
	{
		printf("YES\n");
		int temp=d[1]/2;
		f(i,0,n)
		{
			if(freq[a[i]]==1 && temp!=0)
			{
				printf("B");
				temp--;
			}
			else
				printf("A");
		}
	}
	else
	{
		if(flag==0)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
			int temp=d[1]/2;
			f(i,0,n)
			{
				if(freq[a[i]]==1 && temp!=0)
				{
					printf("B");
					temp--;
				}
				else if(freq[a[i]]!=0 && freq[a[i]]!=1 && freq[a[i]]!=2 && flag==1)
				{
					printf("B");
					flag=0;
				}
				else
					printf("A");
			}
		}
	}
}