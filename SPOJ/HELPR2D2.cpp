#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,k;
	long n,r,v,x,y,sum,max,i;
	string temp;
	cin>>t;
	while(t--)
	{
		max=-1;
		sum=0;
		scanf("%d",&k);
		int a[100001];
		for(i=0;i<=100000;i++)
		{
			a[i]=k;
		}
		scanf("%ld",&n);
		while(n)
		{
			cin>>temp;
			if(temp=="b")
			{
				scanf("%ld %ld",&r,&v);
				n-=r;
				x=-1;
				while(r)
				{
					x++;
					if(a[x]>=v)
					{	
						y=a[x]/v;
						if(y<r)
						{
							r-=y;
							a[x]-=(y*v);
						}	
						else
						{
							a[x]-=(r*v);	
							r=0;
						}
					}
				}
			}
			else
			{
				n--;
				stringstream geek(temp);
				geek>>v;
				x=0;
				while(1)
				{
					if(a[x]>=v)
					{
						a[x]-=v;
						break;
					}
					x++;	
				}
			}
			if(x>max)
			{
				max=x;
			}
		}
		for(i=0;i<=max;i++)
		{
			sum+=a[i];
		}
		printf("%ld %ld\n",max+1,sum);
		
	}

}
