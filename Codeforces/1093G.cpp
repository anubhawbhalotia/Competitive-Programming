//Hint: use scanf and prinf instead of cin and cout respectively
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
#define f(i,s,n) for(int i=s;i<n;i++)
#define fe(i,s,n) for(int i=s;i<=n;i++)
#define fr(i,s,n) for(int i=s;i>=n;i--)
#define mod 998244353
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef pair<ll,ll> pllll;
int a[200005][6],s[35][200005]={}, tree[35][560000][2],n,l,r;
int c[35][6];
int p, k;
void makeSeg(int index,int start,int end, int node)
{	
	if(start==end)
	{
		tree[index][node][0] = s[index][start];
		tree[index][node][1] = s[index][start];
		return ;
	}
	makeSeg(index, start, (start+end)/2, node*2+1);
	makeSeg(index, (start+end)/2 +1, end, node*2+2);
	tree[index][node][0] = max(tree[index][node*2+1][0], tree[index][node*2+2][0]);
	tree[index][node][1] = min(tree[index][node*2+1][1], tree[index][node*2+2][1]);
}
int queryMax(int index,int start, int end, int node)
{
	if(l>end || r<start)
		return -10000000;
	if(start>=l && end <=r)
		return tree[index][node][0];
	int d = queryMax(index, start, (start+end)/2, node*2+1);
	int e = queryMax(index, (start+end)/2+1, end,  node*2+2);
	return max(d,e);
}
int queryMin(int index, int start, int end, int node)
{
	if(l>end || r<start)
		return 10000000;
	if(start>=l && end <=r)
		return tree[index][node][1];
	int d = queryMin(index,  start, (start+end)/2, node*2+1);
	int e = queryMin(index, (start+end)/2+1, end,  node*2+2);
	return min(d,e);
}
int queryTree()
{
	int maxVal = -1;
	f(i,0,p)
	{
		int M = queryMax(i,0,n-1,0);
		int m = queryMin(i,0,n-1,0);
		maxVal = max(maxVal, M-m);
	}
	return maxVal;
}
void uTree(int index, int start, int end, int val, int node)
{
	if(end<val || start>val)
		return ;
	if(start==end)
	{
		tree[index][node][0]= s[index][start];
		tree[index][node][1]= s[index][start];
		return ;
	}
	uTree(index, start, (start+end)/2, val, node*2+1);
	uTree(index, (start+end)/2+1, end, val, node*2+2);
	tree[index][node][0] = max(tree[index][node*2+1][0], tree[index][node*2+2][0]);
	tree[index][node][1] = min(tree[index][node*2+1][1], tree[index][node*2+2][1]);

}
int updateTree(int index)
{
	f(i,0,p)
	{
		s[i][index]=0; 
		f(j,0,k)
			s[i][index]+=(c[i][j]*a[index][j]);
		uTree(i, 0, n-1, index, 0);
	}
}
int main()
{
	int q, index;
	int power[]={1,2,4,8,16,32};
	int type;
	scanf("%d %d",&n,&k);
	p = power[k];
	f(i,0,p)
	{
		int num=i;
		fr(j,k-1,0)
		{
			c[i][j]=(num&1==1)?1:-1;
			num=num>>1;
		}
	}
	f(i,0,n)
	{
		f(j,0,k)
		{
			scanf("%d",&a[i][j]);
			f(x,0,p)
				s[x][i]+=(c[x][j]*a[i][j]);
		}
	}	
	f(j,0,p)
		makeSeg(j,0,n-1,0);
	cin>>q;
	while(q--)
	{
		cin>>type;
		switch(type)
		{
			case 1:
				scanf("%d",&index);
				index--;
				f(i,0,k)
					scanf("%d",&a[index][i]);
				updateTree(index);
				break;
			case 2:
				scanf("%d %d",&l,&r);
				l--;
				r--;
				printf("%d\n",queryTree());
		}
	}

}