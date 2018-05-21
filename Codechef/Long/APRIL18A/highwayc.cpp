#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,s,y,i;
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
		double currTime=0,timeConst,tempDis;
		scanf("%lld %lld %lld",&n,&s,&y);
		long long d[n],c[n],v[n],p[n];
		double pf;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&v[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&d[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&p[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&c[i]);
		}	
		timeConst=(double)y/s;
		double m = 1.0/(1000000);
		//cout<<m<<endl;
		for(i=0;i<n;i++)
		{
			if(d[i]==1)
			{
				pf=(double)p[i]+((double)v[i]*currTime);
				if(pf<(-1)*m)
				{
					tempDis=((-1)*(pf))-m;
					if(tempDis/v[i]>timeConst)
					{
						currTime+=timeConst;
					}
					else
					{
						tempDis=m-(pf-c[i]);
						currTime+=tempDis/v[i];
						currTime+=timeConst;
					}
					continue;
				}
				if(pf>=(-1)*m && (pf-c[i])<=m)
				{
					tempDis=m-(pf-c[i]);
					currTime+=(tempDis/v[i]);
					currTime+=timeConst;
					continue;
				}
				currTime+=timeConst;
			}
			else
			{
				pf=(double)p[i]-((double)v[i]*currTime);
				if(pf>m)
				{
					tempDis=pf-m;
					if(tempDis/v[i]>timeConst)
					{
						currTime+=timeConst;
					}
					else
					{
						tempDis=m+pf+c[i];
						currTime+=tempDis/v[i];
						currTime+=timeConst;
					}
					continue;
				}
				if(pf<=m && (pf+c[i])>=((-1)*m))
				{
					tempDis=m+pf+c[i];
					currTime+=(tempDis/v[i]);
					currTime+=timeConst;
					continue;
				}
				currTime+=timeConst;	
			}
		}
		printf("%lf\n",currTime);
	}	
}