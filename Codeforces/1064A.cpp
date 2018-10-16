#include<bits/stdc++.h>
using namespace std;
int main()
{
	long a[3];
	scanf("%ld %ld %ld",&a[0],&a[1],&a[2]);
	sort(a,a+3);
	long temp=a[2]+1-(a[0]+a[1]);
	if(temp>=0)
		cout<<temp<<endl;
	else
		cout<<"0"<<endl;

}
