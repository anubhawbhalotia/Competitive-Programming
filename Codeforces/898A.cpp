#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n;
	cin>>n;
	if(n%10 >5 && (n%10)!=0)
	{
		n=n+10-(n%10);
	}
	else
	{
		n=n-(n%10);
	}
	cout<<n;
}