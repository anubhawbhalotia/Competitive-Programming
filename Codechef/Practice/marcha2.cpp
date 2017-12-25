#include<bits/stdc++.h>
using namespace std;
int main()
{
	long t,k,i,l;
	cin>>t;
	long a[1000011];
	while(t--)
	{
		cin>>k;		
		for(i=0;i<k;i++)
		{
			scanf("%ld",&a[i]);
		}
		l=1;
		for(i=0;i<k-1;i++)
		{
			if(a[i]>l)
			{
				printf("No\n");
				break;
			}
			l=2*(l-a[i]);
		}
		if(i==k-1)
		{
			if(a[i]==l)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
		}
		
	}
}