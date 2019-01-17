#include<bits/stdc++.h>
using namespace std;
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
#define fr(i,s,n) for(long i=s;i>n;i--)
#define fre(i,s,n) for(long i=s;i>=n;i--)
#define mod 998244353
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef pair<ll,ll> pllll;
typedef set<int> si;
typedef set<long> sl;
typedef set<ll> sll;
typedef multiset<int> msi;
typedef multiset<long> msl;
typedef multiset<ll> msll;
int main()
{
	int t,n,m,ans;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		if(n==1)
		{
			if(m<=2)
				cout<<"1"<<endl;
			else
				cout<<"2"<<endl;
			f(i,0,m)
				cout<<((i/2)%2)+1<<" ";
			cout<<endl;
		}
		else if(n==2)
		{
			cout<<min(3,m)<<endl;
			f(i,0,n)
			{
				f(j,0,m)
					cout<<(j%3)+1<<" ";
				cout<<endl;
			}
		}
		else if(n==3 && m<=2)
		{
			if(m==1)
				cout<<"2\n1\n1\n2"<<endl;
			else if(m==2)
				cout<<"3\n1 1\n2 2\n3 3"<<endl;
		}
		else if(m==1)
		{
			cout<<"2"<<endl;
			f(i,0,n)
				cout<<((i/2)%2)+1<<endl;
		}
		else if(m==2)
		{
			cout<<"3"<<endl;
			f(i,0,n)
				cout<<(i%3)+1<<" "<<(i%3)+1<<endl;
		}
		else
		{
			cout<<"4"<<endl;
			f(i,0,n)
			{
				int s=(i%4)+1;
				f(j,0,m)
				{
					int d=(s>=3)?s-2:s+2;
					if((j/2)%2==0)
						cout<<s<<" ";
					else
						cout<<d<<" ";
				}
				cout<<endl;
			}
		}
		

	}	
}