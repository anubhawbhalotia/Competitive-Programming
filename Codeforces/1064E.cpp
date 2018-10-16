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
#define mod 10e9 + 7
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef pair<ll,ll> pllll;
int main()
{
	long n;
	scanf("%ld",&n);
	cout<<"0 1"<<endl;
	cout.flush();
	S color;
	cin>>color;
	if(color=="white")
	{
		long w=0,b=1000000001;
		f(i,0,n-1)
		{
			long mid=w+(b-w)/2;
			cout<<mid<<" 1"<<endl;
			cout.flush();
			cin>>color;
			if(color=="white")
				w=mid;
			else
				b=mid;
		}
		cout<<w<<" 0 "<<w+1<<" 2"<<endl;
		cout.flush();
	}
	else
	{
		long b=0,w=1000000001;
		f(i,0,n-1)
		{
			long mid=b+(w-b)/2;
			cout<<mid<<" 1"<<endl;
			cout.flush();
			cin>>color;
			if(color=="black")
				b=mid;
			else
				w=mid;
		}
		cout<<b<<" 0 "<<b+1<<" 2"<<endl;
		cout.flush();
	}
}