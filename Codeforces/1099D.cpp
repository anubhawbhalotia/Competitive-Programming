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
typedef struct link
{
	long index;
	long level;
	long a;
	long s;
	vector <long> child;
}node;
int main()
{
	long n;
	cin>>n;
	long p[n],s[n];
	node* cont[n];
	cont[0] = new node;
	cont[0]->index=0;
	cont[0]->level=1;
	f(i,1,n)
	{
		cin>>p[i];
		p[i]--;
		cont[i]= new node;
		cont[i]->index=i;
		cont[i]->level = (cont[p[i]]->level) + 1;
		(cont[p[i]]->child).pb(i);
	}	
	f(i,0,n)
	{
		cin>>s[i];
		cont[i]->s=s[i];
	}
	cont[0]->a = cont[0]->s;
	queue <long> q;
	q.push(0);
	while(!q.empty())
	{
		node* temp=cont[q.front()];
		q.pop();
		if((temp->level)%2==0)
		{
			if(temp->s!=-1)
			{
				cout<<"-1"<<endl;
				return 0;
			}
			if((temp->child).size())
			{
				long minval = 2000000000;
				f(i,0,(temp->child).size())
				{
					if(cont[(temp->child)[i]]->s < minval)
						minval = cont[(temp->child)[i]]->s;
				}
				long tp = minval - cont[p[temp->index]]->s;
				if(tp<0)
				{
					cout<<"-1"<<endl;
					return 0;
				}
				temp->a = tp;
				temp->s = minval;
			}
			else
			{
				temp->a=0;
				temp->s = cont[p[temp->index]]->s;
			}
		}
		else if((temp->level)!=1)
		{
			if(temp->s == -1)
			{
				cout<<"-1"<<endl;
				return 0;	
			}
			long tp = (temp->s) - cont[p[temp->index]]->s;
			if(tp<0)
			{
				cout<<"-1"<<endl;
				return 0;
			}
			temp->a=tp;
		}
		f(i,0,(temp->child).size())
			q.push((temp->child)[i]);
	}
	q.push(0);
	ll ans=0;
	while(!q.empty())
	{
		node* temp=cont[q.front()];
		q.pop();
		ans+=temp->a;
		f(i,0,(temp->child).size())
			q.push((temp->child)[i]);
	}
	cout<<ans<<endl;
}