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
typedef struct node
{
	struct node *child[26];
	bool isEnding;
	long countAfterThis;
	long temp;
	node()
	{
		f(i,0,26)
			child[i] = NULL;
		isEnding = false;
		countAfterThis = 0;
		temp = 0;
	}
}node;
void insert(node *head, string word)
{
	node *p = head;
	long index = 0;
	while(index != word.length())
	{
		if(p->child[word[index]-65] == NULL)
			p->child[word[index]-65] = new node;
		p->countAfterThis++;
		p = p->child[word[index]-65];
		index++;
	}
	p->countAfterThis++;
	p->isEnding = true;
}
long ans;
int traversal(node *p, string word, set <string> d)
{
	if(p->countAfterThis == 1)
		return 1;
	if(p->countAfterThis == 2)
	{
		ans += 2;
		d.insert(word);
		return 0;
	}
	f(i,0,26)
	{
		if(p->child[i] == NULL)
			continue;
		char t = i+65;
		p->temp += traversal(p->child[i], word + t,  d);
	}
	if(p->isEnding == true)
		p->temp++;
	if(*(d.lb(word)) != word && (p->temp) >= 2)
	{
		p->temp-=2;
		ans += 2;
		d.insert(word);
	}
	return p->temp;
}
int main()
{
	int t, n;
	string word;
	cin>>t;
	f(j,0,t)
	{
		node *head = new node;
		set <string> d;
		ans = 0;
		cin>>n;
		f(i,0,n)
		{
			cin>>word;
			reverse(word.begin(), word.end());
			insert(head, word);
		}
		f(i,0,26)
		{
			if(head->child[i] != NULL)
			{
				char temp = i+65;
				word = temp;
				traversal(head->child[i], word, d);
			}
		}
		cout<<"Case #"<<j+1<<": "<<ans<<endl;
	}	
} 