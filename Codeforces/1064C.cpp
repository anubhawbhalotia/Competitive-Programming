
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n;
	scanf("%ld",&n);
	string s;
	cin>>s;
	long i=0;
	long a[26]={};
	while(i!=n)
	{
		a[s[i]-97]++;
		i++;
	}
	for(int i=0;i<26;i++)
	{
		for(long j=0;j<a[i];j++)
		{
			printf("%c",i+97);
		}
	}
}