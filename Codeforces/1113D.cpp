#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define fi first
#define	se second
#define f(i,s,n) for(long i=s;i<n;i++)
#define fe(i,s,n) for(long i=s;i<=n;i++)
#define fr(i,s,n) for(long i=s;i>n;i--)
#define fre(i,s,n) for(long i=s;i>=n;i--)
#define mod 998244353
//Anubhaw Bhalotia https://github.com/anubhawbhalotia
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
string s;
int isPalin(int start, int end)
{
	if(start==end)
		return 1;
	int i=(start+end-1)/2;
	while(start<=i)
	{
		if(s[start++]!=s[end--])
			return 0;
	}
	return 1;
}
int main()
{
	cin>>s;
	int start = 0, end = s.length()-1, flag = 1;
	if(s.length()<=3)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	if(isPalin(start,end))
	{
		flag = ((end-start+1) % 2 == 1) ? 2 : flag;
		end = (start+end-1) / 2;
	}
	while(start<end)
	{
		if(isPalin(start, end))
		{
			flag = ((end-start+1) % 2 == 1) ? 2 : flag;
			end = (start+end-1) / 2;
		}
		else
		{
			cout<<flag<<endl;
			return 0;
		}
	}
	end = (s.length() -2)/2;
	while(start<end)
	{
		if(isPalin(start, end))
			end--;
		else
		{
			cout<<flag<<endl;
			return 0;
		}
	}
	cout<<"Impossible\n";
} 