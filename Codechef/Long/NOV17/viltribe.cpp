#include <bits/stdc++.h>
using namespace std;
int main()
{
	long a,b,c,t,d,i;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		c=0;
		a=0;
		b=0;
		d=0;
		for(i=0;i!=s.length();i++)
		{
			if(s[i]=='A')
			{
				if(c==1)
				{
					a+=d;
				}
				a++;
				c=1;
				d=0;
			}
			else if(s[i]=='B')
			{
				if(c==2)
				{
					b+=d;
				}
				c=2;
				b++;
				d=0;
			}
			else
			{
				d++;
			}
		}
		cout<<a<<" "<<b<<endl;
	}
}