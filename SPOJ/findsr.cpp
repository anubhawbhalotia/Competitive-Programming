#include<bits/stdc++.h>
using namespace std;
int main()
{
	long temp,max,i,count,scount;
	string s;
	cin>>s;
	while(s!="*")
	{
		count=0;
		string a,g;
		if(s.length()==1)
		{
			cout<<"1\n";
			cin>>s;
			continue;
		}
		scount=0;
		g="";
	    for(i=0;i!=s.length();i++)
		{
			if(i==0)
			{
				temp=0;
			}
			else
			{
				temp=i%count;
			}
			if(s[i]!=a[temp])
			{
				a+=g;
				g="";
				count+=scount;
				a+=s[i];
				count++;
			}
			else
			{
				g+=s[i];
				scount++;
			}
		}
		if(s.length()%count==0)
		{
			cout<<s.length()/count<<endl;
		}
		else
		{
			cout<<"1\n";
		}
		cin>>s;

	}
}