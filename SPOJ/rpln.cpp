//sqrt decomposition
#include<bits/stdc++.h>
using namespace std;
#define A 1000000000
int main()
{
	int t,segsize,min,i,n,q,aa,b,ss,es;
	cin>>t;
	int d=1;
	while(t--)
	{
		printf("Scenario #%d:\n",d++);
		int a[100001],segres[1000];
		scanf("%d %d",&n,&q);
		//creating segments
		segsize=ceil(sqrt(n));
		//cout<<"segsize="<<segsize<<endl;
		min=A+1;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<min)
			{
				min=a[i];
			}
			if((i+1)%(segsize)==0)
			{
				segres[i/segsize]=min;
				min=A+1;
			}
		}
		segres[segsize+1]=min;
		while(q--)
		{
		//	cout<<"query=<<"<<q<<endl;
			scanf("%d %d",&aa,&b);
			aa--;
			b--;
			//cout<<"a="<<aa<<" b="<<b<<endl;
			ss=(aa/segsize)+1;
			es=(b/segsize)-1;
		//		cout<<ss<<" "<<es<<endl;
			min=A+1;
			if(ss<=es)
			{
				for(i=aa;i<ss*segsize;i++)
				{
					if(a[i]<min)
					{
						min=a[i];
					}
				}
				for(i=ss;i<=es;i++)
				{
					if(segres[i]<min)
					{
						min=segres[i];
					}
				}
				for(i=(es+1)*segsize;i<=b;i++)
				{
					if(a[i]<min)
					{
						min=a[i];
					}
				}
			}
			else
			{
				for(i=aa;i<=b;i++)
				{
					if(a[i]<min)
					{
						min=a[i];
					}
				}
			}
			printf("%d\n",min);
		}
	}
}
		