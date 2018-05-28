#include<bits/stdc++.h>
using namespace std;
int segtreeBuild(long node,long start,long end,long tree[],long a[])
{
	//cout<<"segtreeBuild "<<node<<" "<<start<<" "<<end<<endl;
	long mid=(start+end)/2;
	if(start==end)
	{
		tree[node]=a[start];
		//cout<<"tree["<<node<<"]="<<a[start]<<endl;
		return 0;
	}
	int aa=segtreeBuild(node*2+1,start,mid,tree,a);
	segtreeBuild(node*2+2,mid+1,end,tree,a);
	if(aa==0)
	{
		tree[node]=tree[node*2+1]|tree[node*2+2];
		return 1;
	}
	else
	{
		tree[node]=tree[node*2+1]^tree[node*2+2];
		return 0;
	}
}
int segtreeQuery(long node,long start,long end,long tree[],long p,long b)
{
	int a;
	long mid=(start+end)/2;
	if(start==end)
	{
		tree[node]=b;
		return 0;
	}
	if(p<=mid)
	{
		a=segtreeQuery(node*2+1,start,mid,tree,p,b);
	}
	else
	{
		a=segtreeQuery(node*2+2,mid+1,end,tree,p,b);
	}
	if(a==0)
	{
		tree[node]=tree[node*2+1]|tree[node*2+2];
		return 1;
	}
	else
	{
		tree[node]=tree[node*2+1]^tree[node*2+2];
		return 0;
	}

}
int main()
{
	int n;
	long m,p,b,tree[1000000];
	scanf("%d %ld",&n,&m);
	long temp=1;
	for(int i=0;i<n;i++)
	{
		temp=temp*2;
	}
	long a[temp];
	for(long i=0;i<temp;i++)
	{
		scanf("%ld",&a[i]);
	}
	segtreeBuild(0,0,temp-1,tree,a);
	// for(long i=0;i<2*temp;i++)
	// {
	// 	printf("%ld ",tree[i]);
	// }
	// cout<<endl;
	while(m--)
	{
		scanf("%ld %ld",&p,&b);
		p--;
		segtreeQuery(0,0,temp-1,tree,p,b);
		printf("%ld\n",tree[0]);
	}
}
