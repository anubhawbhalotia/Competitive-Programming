    #include<bits/stdc++.h>
    using namespace std;
    long lq,rq,x;
    long ans[50],a[110000],pos,val;
    pair  <long,long> p;
    multiset < pair <long,long> > seg[800000];
     
    void build(long node,long l,long r)
    {
        	if(l==r)
        	{
                p.first=a[l];
                p.second=l;
        		seg[node].insert(p);
        		return;
        	}
        	long mid=(l+r)/2;
        	build((node*2)+1,l,mid);
        	build((node*2)+2,mid+1,r);
            //merge(seg[(node*2)+1].begin(),seg[(node*2)+1].end(),seg[(node*2)+2].begin(),seg[(node*2)+2].end(),seg[node].begin());
        	seg[node].insert(seg[(node*2)+1].begin(),seg[(node*2)+1].end());
        	seg[node].insert(seg[(node*2)+2].begin(),seg[(node*2)+2].end());
        }
        void update(long node,long l,long r)
        {
        	if(l==r)
        	{
                p.first=a[pos];
                p.second=pos;
                seg[node].erase(seg[node].lower_bound(p));
                p.first=val;
                seg[node].insert(p);
        		return;
        	}
        	long mid=(l+r)/2;
        	if(pos<=mid)
        	{
        		update((node*2)+1,l,mid);
        	}
        	else
        	{
        		update((node*2)+2,mid+1,r);
        	}
            p.first=a[pos];
            p.second=pos;
        	seg[node].erase(seg[node].lower_bound(p));
            p.first=val;
        	seg[node].insert(p);
            
            
        }
    void query(long node,long l,long r)
    {
    	//cout<<l<<" "<<r<<endl;
    	if(r<lq || l>rq)
    	{
    		return ;
    	}
    	if(l>=lq && r<=rq)
    	{
    		ans[x]=node;
    		x++;
    		return;
    	}
    	long mid=(l+r)/2;
    	query((node*2)+1,l,mid);
    	query((node*2)+2,mid+1,r);
     
    }
    int main()
    {
    	long n,q,i,type,endcount,maxx,flag,count,l1,l2,l3;
    	int maxit;
    	multiset < pair <long,long> >  :: reverse_iterator it[50];
    	scanf("%ld %ld",&n,&q);
    	for(i=1;i<=n;i++)
    	{
    		scanf("%ld",&a[i]);
    	}
    	build(0,1,n);
        while(q--)
        {
        	scanf("%ld",&type);
        	if(type==1)
        	{
        		scanf("%ld %ld",&pos,&val);
        		update(0,1,n);
        		a[pos]=val;
        	}
        	else
        	{
       			scanf("%ld %ld",&lq,&rq);
       			x=0;
       			query(0,1,n);
       			for(i=0;i<x;i++)
       			{
       				
       				it[i]=seg[ans[i]].rbegin();
       			}
       			count=0;
       			flag=0;
       			while(1)
       			{
       				endcount=0;
       				maxx=0;
       				for(i=0;i<x;i++)
       				{	
       					if(it[i]!=seg[ans[i]].rend())
       					{
       						endcount++;
       						if((*(it[i])).first>maxx)
       						{
       							maxx=(*(it[i])).first;
       							maxit=i;
       						}
       					}
       				}
       				if(endcount==0)
       				{
       					break;
       				}
     
       				l1=l2;
       				l2=l3;
       				l3=maxx;
       				it[maxit]++;
       				count++;
       				if(count>=3)
       				{
       					if(l1<(l2+l3))
       					{
       						printf("%ld\n",l1+l2+l3);
       						flag=1;
       						break;	
       					}
       				}
       			}
       			if(!flag)
       			{
       				printf("0\n");
       			}
       		}
       	}
     
    } 