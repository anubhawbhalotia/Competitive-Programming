#include<bits/stdc++.h>
using namespace std;
void build(long long tree[],long long a[],long long node, long long start, long long end)
{
    if(start == end)
    	tree[node] = a[start];
    else
    {
        long long mid = (start + end) / 2;
        build(tree,a,2*node, start, mid);
        build(tree,a,2*node+1, mid+1, end);
        tree[node] = max(tree[2*node],tree[2*node+1]);
    }
}
long long query(long long tree[],long long node,long long start,long long end,long long l,long long r)
{
    if(r < start or end < l)
    	return -110000000;
    if(l <= start and end <= r)
    	return tree[node];
    long long mid = (start + end) / 2;
    long long p1 = query(tree,2*node, start, mid, l, r);
    long long p2 = query(tree,2*node+1, mid+1, end, l, r);
    return max(p1,p2);
}
int main()
{
	long long n,i,m,x1,y1,x2,y2,mc,max,c[4],middlemax,maxans;
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%lld",&n);
		long long a[n+2],pre[n+2],post[n+2],pretree[100000],posttree[100000],l,r;
		pre[0]=0;
		pre[n+1]=0;
		post[0]=0;
		post[n+1]=0;
		a[0]=0;
		a[n+1]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			pre[i]=a[i]+pre[i-1];
		}
		for(i=n;i>0;i--)
			post[i]=post[i+1]+a[i];
		build(pretree,pre,1,1,n);
		build(posttree,post,1,1,n);
		scanf("%lld",&m);
		while(m--)
		{
			scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
			if(y1<x2)
			{
				cout<<query(posttree,1,1,n,x1,y1)-post[y1+1]+query(pretree,1,1,n,x2,y2)-pre[x2-1]+pre[x2-1]-pre[y1]<<endl;
				continue;				
			}
			if(y1==x2)
			{
				l=query(posttree,1,1,n,x1,y1)-post[y1+1];
				if(x2+1 > y2)
					r=0;
				else
					r=query(pretree,1,1,n,x2+1,y2)-pre[x2];
				if(l>l+r)
					maxans=l;
				else
					maxans=l+r;
				cout<<maxans<<endl;
				continue;
			}
			if(x2<y1)
			{
				middlemax=0;
				if(y1-x2>1)
					middlemax=pre[y1-1]-pre[x2];
				c[0]=query(posttree,1,1,n,x1,x2)-post[x2+1]+query(pretree,1,1,n,y1,y2)-pre[y1-1]+middlemax;
				l=query(posttree,1,1,n,x1,x2)-post[x2+1];
				r=query(pretree,1,1,n,x2+1,y1-1)-pre[x2];
				if(l>l+r)
					c[1]=l;
				else
					c[1]=l+r;
				l=query(pretree,1,1,n,y1,y2)-pre[y1-1];
				r=query(posttree,1,1,n,x2+1,y1-1)-post[y1];
				if(l>l+r)
					c[2]=l;
				else
					c[2]=l+r;
				mc=0;
				max=-11000;
				for(i=x2+1;i<y1;i++)
				{
					mc=mc+a[i];
					if(max<mc)
						max=mc;
					if(mc<0)
						mc=0;
				}
				c[3]=max;
				max=-110000000;
				long maxc;
				for(i=0;i<4;i++)
				{
					if(c[i]>max)
					{
						maxc=i;
						max=c[i];
					}
				}
				cout<<max<<endl;
			}
		}
	}
}