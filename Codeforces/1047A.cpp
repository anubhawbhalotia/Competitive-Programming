#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n,a,b,c;
	scanf("%ld",&n);
	if(n%3==0)
	{
		a=1;
		b=1;
		c=n-2;
	}
	else if(n%3==1)
	{
		a=1;
		b=1;
		c=n-2;
	}
	else if(n%3==2)
	{
		a=1;
		b=2;
		c=n-3;
	}
	printf("%ld %ld %ld\n",a,b,c);
}