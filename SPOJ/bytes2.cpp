#include<bits/stdc++.h>
using namespace std;
//check array c[] only for n*2 indexes
int main()
{
	int t,n;
	long sum,max,i,a,b;
	scanf("%d",&t);
	while(t--)
	{
		char c[10000000]="";
		set <long> s;
		sum=0;
		max=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%ld %ld",&a,&b);
			s.insert(a);
			s.insert(b);
			c[a]=49;
			c[b]=47;
		}
		for(set <long> ::iterator i=s.begin();i!=s.end();i++)
		{
			sum+=c[*i]-48;
			if(sum>max)
			{
				max=sum;
			}
		}
		printf("%ld\n",max);
	}
}