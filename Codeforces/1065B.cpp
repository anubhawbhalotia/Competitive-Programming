#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m;
	scanf("%lld %lld",&n,&m);
	if(n-(m*2)>=0)
		cout<<n-(m*2)<<" ";
	else
		cout<<"0 ";
	if(m==0)
	{
		cout<<n<<endl;
		return 0;
	}
	long long temp=ceil((1.0+sqrt(8*m))/(2.0));
	if(n-temp>=0)
		cout<<n-temp<<endl;
	else
		cout<<"0"<<endl;

}