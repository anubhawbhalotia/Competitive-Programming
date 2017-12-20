#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
int main()
{
	long long i,n;
	cin>>n;
	n--;
	long long a,b,c,d;
	if(n==0)
	{
		cout<<"0";
		return 0;
	}
	a=1;
	d=0;
	for(i=2;i<=n;i++)
	{
		b=((2*a)+d)%M;
		c=(3*a)%M;
		a=b;
		d=c;
		//cout<<a<<" "<<d<<endl;
	}
	cout<<(3*a)%M;

}