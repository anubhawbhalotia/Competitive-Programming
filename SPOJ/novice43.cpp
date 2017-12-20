#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n,a[12][12],s[12]={},i,j,t;
	cin>>t;
	a[1][1]=1;
	s[1]=1;
	for(i=2;i<=11;i++)
	{
		a[i][1]=1;
		a[i][i]=1;
		s[i]+=2;
		for(j=2;j<i;j++)
		{
			a[i][j]=(a[i-1][j]*j)+a[i-1][j-1];
			//cout<<a[i][j]<<" "; 
			s[i]+=a[i][j];
		}
		//cout<<"\n";
	}
	while(t--)
	{
		cin>>n;
		cout<<s[n]<<endl;
	}
}