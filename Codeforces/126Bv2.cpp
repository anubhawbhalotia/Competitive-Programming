#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	long l,len,i;
	cin>>s;
	l=s.length();
	if(l<3)
	{
		cout<<"Just a legend"<<endl;
		return 0;
	}
	long lps[l];
	len=0;
	i=1;
	lps[0]=0;
	while(i<s.length())
	{
		if(s[i]==s[len])
		{
			len++;
			lps[i]=len;
			i++;
			continue;
		}
		if(len==0)
		{
			lps[i]=0;
			i++;
			continue;
		}
		len=lps[len-1];
	}
	// for(i=0;i<l;i++)
	// {
	// 	cout<<s[i]<<" ";
	// }
	// cout<<endl;
	// for(i=0;i<l;i++)
	// {
	// 	cout<<lps[i]<<" ";
	// }
	// cout<<endl;
	if(lps[l-1]==0)
	{
		cout<<"Just a legend"<<endl;
		return 0;
	}
	for(i=0;i<l-1;i++)
	{
		if(lps[i]==lps[l-1])
		{
			cout<<s.substr(0,lps[i])<<endl;
			break;
		}
	}
	if(i!=l-1)
	{
		return 0;
	}
	if(lps[lps[l-1]-1]==0)
	{
		cout<<"Just a legend"<<endl;
		return 0;	
	}
	cout<<s.substr(0,lps[lps[l-1]-1])<<endl;

}