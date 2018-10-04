#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n;
	scanf("%ld",&n);
	long x,y;
	long long t;
	long long max=0,ans;
	for(long i=0;i<n;i++)
	{
		scanf("%ld %ld",&x,&y);
		t=x+y;
		if(t>max)
		{
			max=t;
		}
		
	}
	printf("%lld\n",max);
}