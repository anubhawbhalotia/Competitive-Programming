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
#define f(i,s,n) for(long long i=s;i<n;i++)
#define fe(i,s,n) for(long long i=s;i<=n;i++)
#define fr(i,s,n) for(long long i=s;i>=n;i--)
#define mod 998244353
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef pair<ll,ll> pllll;
int main()
{
	long long a,b;
	cin>>a>>b;
	long long tempa=(-1.0+sqrt(1+(8*a)))/2;
	vll ans1,ans2;
	//cout<<tempa<<endl;
	//cout<<(a-(tempa*(tempa+1))/2)<<endl;
	cout<<tempa<<endl;
	fe(i,1,tempa-(a-(tempa*(tempa+1))/2))
	{
		cout<<i<<"  ";
		//ans1.push_back(i);
	}
	fe(i,tempa-(a-(tempa*(tempa+1))/2)+2,tempa+1)
	{
		cout<<i<<" ";
		//ans1.push_back(i);
	}
	cout<<endl;
	if(b>=tempa-(a-(tempa*(tempa+1)/2))+1)
	{
		ans2.push_back(tempa-(a-(tempa*(tempa+1)/2))+1);
		b-=tempa-(a-(tempa*(tempa+1)/2))+1;
	}
	f(i,tempa+2,1000000)
	{
		if(b>=i)
		{
			ans2.push_back(i);
			b-=i;
		}
		else
			break;
	}
	// cout<<ans1.size()<<endl;
	// f(i,0,ans1.size())
	// 	cout<<ans1[i]<<" ";
	//cout<<endl;
	cout<<ans2.size()<<endl;
	f(i,0,ans2.size())
		cout<<ans2[i]<<" ";
	cout<<endl;


}