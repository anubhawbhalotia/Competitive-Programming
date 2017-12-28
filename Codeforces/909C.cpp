#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
int main()
{
	long d[5000][5000]={},n,i,s,j;
	cin>>n;
	char a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	d[0][0]=1;
	for(i=1;i<n;i++)
	{
		if(a[i-1]=='f')
		{
			//cout<<"case1\n";
			j=0;
			while(j<=i)
			{
				d[i][j+1]=d[i-1][j];
				j++;
			}
		}
		else
		{
			//cout<<"case2\n";
			j=i;
			s=0;
			while(j>=0)
			{
				s+=d[i-1][j];
				s=s%M;
				d[i][j]=s;
				j--;
			}
		}
	}
	//cout<<s;
	s=0;
	/*for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}*/
	j=0;
	while(j<n)
	{
		s+=d[n-1][j];
		s=s%M;
		j++;
	}
	cout<<s;
}