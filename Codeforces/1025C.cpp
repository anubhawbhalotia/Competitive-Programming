#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	s+=s;
	//cout<<s<<endl;
	char last=s[0];
	long count=1;
	long max=1;
	for(long i=1;i<s.length();i++)
	{
		if(s[i]!=last)
		{
			count++;
		}
		else
		{
			if(count>max)
			{
				max=count;
			}
			count=1;
		}
		last=s[i];
	}
	if(count>max)
	{
		max=count;
	}
	//cout<<max<<endl;
	if(max==(s.length()))
	{
		max=s.length()/2;
	}
	cout<<max<<endl;

}