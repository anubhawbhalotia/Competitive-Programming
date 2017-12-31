#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,c,n;
	cin>>t;
	while(t--)
	{

		cin>>n;
		cout<<ceil((sqrt((8*n)+1)-1)/2)<<endl;
	}
}