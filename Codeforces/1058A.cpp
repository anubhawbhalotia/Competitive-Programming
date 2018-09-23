#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int flag=0;
	int a;
	for(long i=0;i<n;i++)
	{
		cin>>a;
		if(a)
		{
			flag=1;
		}	
	}
	if(flag)
	{
		cout<<"HARD\n";
	}
	else
	{
		cout<<"EASY\n";
	}
}