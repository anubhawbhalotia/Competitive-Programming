#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n;
	scanf("%ld",&n);
	long a=1;
	while(n>3)
	{
		for(long i=0;i<ceil(n/2.0);i++)
		{
			printf("%ld ",a);
		}
		n=floor(n/2);
		a=a*2;
	}
	switch(n)
	{
		case 1:
			printf("%ld\n",a);
			break;
		case 2:
			printf("%ld %ld\n",a,a*2);
			break;
		case 3:
			printf("%ld %ld %ld\n",a,a,a*3);
			break;
	}
}