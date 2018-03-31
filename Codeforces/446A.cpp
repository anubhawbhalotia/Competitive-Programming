#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	long start;
	long end;
	long length;
}listt;
int main()
{
	listt l[200000];
	long n,i,x,flag,max,length;
	cin>>n;
	long a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	x=0;
	flag=0;
	for(i=0;i<n;i++)
	{
		if(flag==0)
		{
			l[x].start=i;
			l[x].end=i;
			l[x].length=l[x].end-l[x].start+1;
			flag=1;
		}
		else
		{
			if(a[i]>a[i-1])
			{
				l[x].end=i;
				l[x].length=l[x].end-l[x].start+1;
			}
			else
			{
				flag=0;
				l[x].length=l[x].end-l[x].start+1;
				x++;
				i--;
				continue;
			}
		}
	}
	x++;
	max=0;
	for(i=0;i<x;i++)
	{
		//cout<<l[i].length<<" ";
		if(l[i].length>max)
		{
			max=l[i].length;
		}
	}
	//cout<<endl;
	if(x==1)
	{
		cout<<l[0].length;
		return 0;
	}
	for(i=0;i<x-1;i++)
	{
		if(l[i].length>1 && l[i+1].length>1)
		{
			if((a[l[i+1].start]-a[l[i].end-1])>1  ||  (a[l[i+1].start+1]-a[l[i].end])>1)
			{
				length=l[i].length+l[i+1].length;
				if(length>max)
				{
					max=length;
				}
				
			}
			else
			{
				
					length=l[i].length+1;
					if(length>max)
					{
						max=length;
					}
				
				
					length=l[i+1].length+1;
					if(length>max)
					{
						max=length;
					}
			}
			continue;
		}
		if(l[i].length==1&& l[i+1].length>1)
		{
			
				length=l[i].length+l[i+1].length;
				if(length>max)
				{
					max=length;
				}
			
			continue;
		}
		if(l[i+1].length==1 && l[i].length>1 )
		{
			
				length=l[i].length+l[i+1].length;
				if(length>max)
				{
					max=length;
				}
			
			continue;
		}

		
			length=2;
			if(length>max)
			{
				max=length;
			}
		
	}
	cout<<max;
}