#include<bits/stdc++.h>
using namespace std;
long bs(long start,long end,unsigned long long val,unsigned long long arr[])
{
	long mid=(start+end)/2;
	if(val<arr[mid])
		return bs(start,end-1,val,arr);
	else if(val>arr[mid])
		return bs(mid+1,end,val,arr);
	else
		return mid;
}
int main()
{
	int n;
	cin>>n;
	unsigned long long x1[n],x2[n],y1[n],y2[n];
	set <pair <unsigned long long,unsigned long long> > row;
	set <pair <unsigned long long,unsigned long long> > col;
	pair <unsigned long long,unsigned long long> curr;
	char d;
	long x;
	unsigned long long m=1e11+1;
	curr=make_pair(m/2,m/2);
	for(int i=0;i<n;i++)
	{
		pair <unsigned long long,unsigned long long> newCurr;
		cin>>d>>x;
		switch(d)
		{
			case 'U':
				newCurr=make_pair(curr.first+x,curr.second);
				break;
			case 'D':
				newCurr=make_pair(curr.first-x,curr.second);
				break;
			case 'L':
				newCurr=make_pair(curr.first,curr.second-x);
				break;
			case 'R':
				newCurr=make_pair(curr.first,curr.second+x);
				break;
		}
		x1[i]=min(curr.second,newCurr.second);
		x2[i]=max(curr.second,newCurr.second);
		y1[i]=min(curr.first,newCurr.first);
		y2[i]=max(curr.first,newCurr.first);
		curr.first=newCurr.first;
		curr.second=newCurr.second;
	}
		
		row.insert(make_pair(0,0));
		col.insert(make_pair(0,0));
		row.insert(make_pair(1,0));
		row.insert(make_pair(m-1,0));
		col.insert(make_pair(1,0));
		col.insert(make_pair(m-1,0));	
		for(int i=0;i<n;i++)
		{
			if(y1[i]==0 && y2[i]>0)
			{
				row.insert(make_pair(y2[i],1));
			}
			else if(y2[i]==m-1 && y1[i]<(m-1))
			{
				row.insert(make_pair(y1[i],0));
			}
			else
			{
				row.insert(make_pair(y1[i],0));
				row.insert(make_pair(y2[i],1));
			}
			if(x1[i]==0 && x2[i]>0)
			{
				col.insert(make_pair(x2[i],1));
			}	
			else if(x2[i]==m-1 && x1[i]<(m-1))
			{
				col.insert(make_pair(x1[i],0));
			}
			else
			{
				col.insert(make_pair(x1[i],0));
				col.insert(make_pair(x2[i],1));
			}
		}
		long count1=0;
		unsigned long long c[100000]={};
		unsigned long long last=-1;
		for(set <pair <unsigned long long,unsigned long long> > ::iterator i=col.begin();i!=col.end();i++)
		{
			if((*i).second==0)
			{
				if(last==(*i).first)
					continue;
				c[count1]=(*i).first;
				count1++;
				last=(*i).first;
			}
			else
			{
				if((*i).first==m-1)
					continue;
				if(last==(*i).first+1)
					continue;
				c[count1]=(*i).first+1;
				count1++;
				last=(*i).first+1;
			}
		}
		long count2=0;
		unsigned long long r[100000]={};
		last=-1;
		for(set <pair <unsigned long long,unsigned long long> > ::iterator i=row.begin();i!=row.end();i++)
		{
			if((*i).second==0)
			{
				if(last==(*i).first)
					continue;
				r[count2]=(*i).first;
				count2++;
				last=(*i).first;
			}
			else
			{
				if((*i).first==m-1)
					continue;
				if(last==(*i).first+1)
					continue;
				r[count2]=(*i).first+1;
				count2++;
				last=(*i).first+1;
			}
		}
		long cs,rs;
		int grid[3100][3100]={};
		for(int i=0;i<n;i++)
		{
			cs=bs(0,count1-1,x1[i],c);
			rs=bs(0,count2-1,y1[i],r);
			if(y1[i]==y2[i]) //Horizontal line
			{
				for(long j=cs;j<count1;j++)
				{
					if(c[j]<=x2[i])
						grid[rs][j]=1;
					else
						break;
				}
			}
			else
			{
				for(long j=rs;j<count2;j++)
				{
					if(r[j]<=y2[i])
						grid[j][cs]=1;
				}
			}
		}
		unsigned long long csize[100000]={},rsize[100000]={};
		 for(long i=0;i<count1-1;i++)
		{
			csize[i]=c[i+1]-c[i];
		}
		csize[count1-1]=1;
		for(long i=0;i<count2-1;i++)
		{
			rsize[i]=r[i+1]-r[i];
		}
		rsize[count2-1]=1;
		unsigned long long block=0;
		for(long i=0;i<count2;i++)
		{
			for(long j=0;j<count1;j++)
			{
				if(grid[i][j]==1)
				{
					block+=rsize[i]*csize[j];
				}
			}
		}
	unsigned long long ans=0;
	for(long t=0;t<count2;t++)
	{
		for(long u=0;u<count1;u++)
		{
			if((t==0 || t==count2-1)&&(u==0 ||u==count1-1))
			{
				if(!grid[t][u])
				{
					queue < pair <long,long> > q;
					q.push(make_pair(t,u));
					pair <long,long> p;
					p=q.front();
					grid[p.first][p.second]=2;
					int x[]={-1,0,1,0};
					int y[]={0,1,0,-1};
					
					while(!q.empty())
					{
						p=q.front();
						q.pop();
						for(int i=0;i<4;i++)
						{
							if(p.first+x[i]>=0 && p.first+x[i]<count2 && p.second+y[i]>=0 && p.second+y[i]<count1)
							{
								if(!grid[p.first+x[i]][p.second+y[i]])
								{
									q.push(make_pair(p.first+x[i],p.second+y[i]));
									grid[p.first+x[i]][p.second+y[i]]=2;
								}
							}
						}
					}
				}
			}
		}

	}
	for(long i=0;i<count2;i++)
	{
		for(long j=0;j<count1;j++)
		{
			if(grid[i][j]==0 || grid[i][j]==1)
			{
				ans+=csize[j]*rsize[i];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
