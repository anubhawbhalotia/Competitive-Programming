#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n;
	scanf("%ld",&n);
	long a[n];
	for(long i=0;i<n;i++)
	{
		scanf("%ld",&a[i]);
	}	
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	int flag=1;
	long last=a[n-1];
	long count=1;
	long max=1;
	for(long i=n-2;i>=0;i--)
	{
		if(flag)
		{
			if(a[i]>=((last+1)/2) && last!=a[i])
			{
				last=a[i];
				count++;
			}
			else
			{
				i++;
				flag=0;
				if(count>max)
				{
					max=count;
				}
				continue;
			}
		}
		else
		{
			last=a[i];
			count=1;
			flag=1;
		}
	}
	if(count>max)
	{
		max=count;
	}
	cout<<max<<endl;
}