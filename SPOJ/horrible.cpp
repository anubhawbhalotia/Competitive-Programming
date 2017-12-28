#include<bits/stdc++.h>
using namespace std;
long long update(long long lazy[],long long tree[],long node,long start,long end,long p,long q,long v)
{
	if(p>end || q<start)
	{
		return 0;
	}
	if(lazy[node])
	{
		tree[node]+=lazy[node]*(end-start+1);
		if(start!=end)
		{
			lazy[node*2]+=lazy[node];
			lazy[(node*2)+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>=p && end<=q)
	{
		tree[node]+=(end-start+1)*v;
		if(start!=end)
		{
			lazy[node*2]+=v;
			lazy[node*2+1]+=v;
		}
		//cout<<"returning "<<(end-start+1)*v<<endl;
		return (end-start+1)*v;
	}
	//cout<<"going for"<<start<<" "<<end<<endl;
	long long f=update(lazy,tree,node*2,start,(start+end)/2,p,q,v);
	long long g=update(lazy,tree,node*2+1,((start+end)/2)+1,end,p,q,v);
	//cout<<"f="<<f<<" g="<<g<<endl;
	tree[node]+=f+g;

	//cout<<"tree "<<node<<"= "<<tree[node]<<endl;
	return f+g;
}
long long query(long long lazy[],long long tree[],long node,long start,long end,long p,long q)
{
//	cout<<start<<" "<<end<<" "<<p<<" "<<q<<endl;
	if(p>end || q<start)
	{
		return 0;
	}
	if(lazy[node])
	{
		tree[node]+=lazy[node]*(end-start+1);
		if(start!=end)
		{
			lazy[node*2]+=lazy[node];
			lazy[(node*2)+1]+=lazy[node];
		}
		lazy[node]=0;		
	}
	if(start>=p && end<=q)
	{
		return tree[node];
	}
	long long f=query(lazy,tree,node*2,start,(start+end)/2,p,q);
	long long g=query(lazy,tree,node*2+1,((start+end)/2)+1,end,p,q);
	//cout<<"f="<<f<<" g="<<g<<endl;
	return f+g;

}
	

int main()
{
	int type;
	long t,n,c,p,q,v,i;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld %ld",&n,&c);
		long long tree[1000000]={},lazy[1000000]={};
		/*for(i=1;i<=16;i++)
				{
					cout<<tree[i]<<" ";
				}
				cout<<endl;
				for(i=1;i<=16;i++)
				{
					cout<<lazy[i]<<" ";
				}
				cout<<endl;*/
		while(c--)
		{
			scanf("%d",&type);
			if(type==0)
			{
				scanf("%ld %ld %ld",&p,&q,&v);
				update(lazy,tree,1,1,n,p,q,v);
			/*	for(i=1;i<=16;i++)
				{
					cout<<tree[i]<<" ";
				}
				cout<<endl;
				for(i=1;i<=16;i++)
				{
					cout<<lazy[i]<<" ";
				}
				cout<<endl;*/
			}
			else
			{
				scanf("%ld %ld",&p,&q);
				printf("%lld\n",query(lazy,tree,1,1,n,p,q));
			}
		}
	}
}