#include<bits/stdc++.h>
using namespace std;
long update(long tree[],long node,long start,long end,long q)
{
	if(q<start||  q>end)
	{
		return 0;
	}
	tree[node]=tree[node]+1;
	if(start!=end)
	{
		long mid=(start+end)/2;
		update(tree,node*2,start,mid,q);
		update(tree,node*2+1,mid+1,end,q);
	}
}
long query(long tree[],long *rv,long b[],long node,long start,long end,long ind,long n)
{
	if(start==end)
	{
		if(*rv==1 && end-start+1-tree[node]==1)
		{
			b[ind]=start;
			update(tree,1,1,n,start);
			return 1;
		}
	}
	if(end-start+1-tree[node]<(*rv))
	{
		*rv-=end-start+1-tree[node];
		return 0;
	}
	if(end-start+1-tree[node]>=(*rv))
	{
		long mid=(start+end)/2;
		if(query(tree,rv,b,node*2,start,mid,ind,n))
		{
			return 1;
		}
		if(query(tree,rv,b,node*2+1,mid+1,end,ind,n))
		{
			return 1;
		}
	}

}
int main()
{
	long t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long a[n+1],b[n+1];
		long tree[1000000]={};
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&a[i]);
		}
		for(i=n;i>0;i--)
		{
			long rv=i-a[i];
			query(tree,&rv,b,1,1,n,i,n);
		}
		for(i=1;i<=n;i++)
		{
			printf("%ld ",b[i]);
		}
		cout<<endl;

	}
}