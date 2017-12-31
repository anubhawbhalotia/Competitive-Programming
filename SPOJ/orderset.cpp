#include<bits/stdc++.h>
using namespace std;
#define A 200005
#define B 200005
int compare (const void * a, const void * b)
{
  return ( *(long*)a - *(long*)b );
}
long a[B]={};
int b[B]={};
long ins[B]={};
long x[B];
char ch[B];
int main()
{
	long q,temp,ans,count=0,found,high,low,mid,c=0,xx,i;
	unordered_map <long,long> g,h;
	scanf("%ld",&q);
	for(i=0;i<q;i++)
	{
		cin>>ch[i];
		scanf("%ld",&x[i]);
		if(ch[i]!='K')
		{
			ins[count++]=x[i];
		}
	}
	qsort(ins,count,sizeof(long),compare);
	for(i=0;i<count;i++)
	{
		g[i+1]=ins[i];  //gives number corresponding to a key
		h[ins[i]]=i+1;  //gives key corresponding to a number
	}
	for(i=0;i<q;i++)
	{
		if(ch[i]=='I')
		{
			xx=h[x[i]];
			if(b[xx]==1)
			{
				continue;
			}
			b[xx]=1;
			c++;
			temp=xx;
			while(temp<B)
			{
				a[temp]++;
				temp+=(temp&-temp);
			}
			continue;
		}
		if(ch[i]=='D')
		{
			xx=h[x[i]];
			if(b[xx]==0)
			{
				continue;
			}
			c--;
			b[xx]=0;
			temp=xx;
			while(temp<B)
			{
				a[temp]--;
				temp+=(temp&-temp);
			}
			continue;
		}
		if(ch[i]=='K')
		{
			xx=x[i];
			if(xx>c)
			{
				printf("invalid\n");
				continue;
			}
			found=0;
			high=B-1;
			low=1;
			while(high>low)
			{
				mid=low+(high-low)/2;
				temp=mid;
				ans=0;
				while(temp>0)
				{
					ans+=a[temp];
					temp-=(temp&-temp);
				}	

				if(ans>xx)
				{
					high=mid;
				}
				else if(ans<xx)
				{
					low=mid+1;
				}
				else
				{
					found=1;
					high=mid;
				}
			}
			
				printf("%ld\n",g[low]);
			
			continue;
		}
		if(ch[i]=='C')
		{
			xx=h[x[i]];
			temp=xx-1;
			ans=0;
			while(temp>0)
			{
				ans+=a[temp];
				temp-=(temp&-temp);
			}
			printf("%ld\n",ans);
			continue;
		}

		

	}
}