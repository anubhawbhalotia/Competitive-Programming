#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	long i,start,end;
	cin>>s;
	long a[s.length()];
	start=0;
	end=s.length()-1;
	for(i=0;i<s.length();i++)
	{
		if(s[i]=='l')
		{
			a[end]=i+1;
			end--;
		}
		else
		{
			a[start]=i+1;
			start++;
		}
	}
	for(i=0;i<s.length();i++)
	{
		printf("%ld\n",a[i]);
	}
}