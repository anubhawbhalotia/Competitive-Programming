#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9 +7;
int compare (const void * a, const void * b)
{
  return ( *(long*)a - *(long*)b);
}
long a[50001],k,n;
long check(int val)
{
	long s=0,i;
	for(i=n-1;i>=0;i--)
	{
		if(a[i]/val)
		{
			s+=a[i]/val;
		}
		else
		{
			return 0;
		}
		if(s>=k)
		{
			return 1;
		}
	}
	return 0;
}
long bs(long start,long end)
{
	long mid;
	if(start==end)
	{
		return start;
	}
	mid=(ceil)((start+end)/2.0);
	if(check(mid))
	{
		return bs(mid,end);
	}
	return bs(start,mid-1);
}


int main()
{
	long t,i;
	cin>>t;
	while(t--)
	{
		long long s=0;
		scanf("%ld %ld",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
			s+=a[i];
		}
		if(s<k)
		{
			printf("0\n");
			continue;
		}
		qsort(a,n,sizeof(long),compare);
		printf("%ld\n",bs(1,s/k));

	}
}

		