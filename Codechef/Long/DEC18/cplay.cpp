#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	long a,b,i,c1,c2,y,z;
	cin>>s;
	while(!cin.eof())
	{
		a=s[0]+s[2]+s[4]+s[6]+s[8]-(48*5);
		b=s[1]+s[3]+s[5]+s[7]+s[9]-(48*5);
		if(a==b)
		{
			for(i=10;i<20;i+=2)
			{
				a+=s[i];
				b+=s[i+1];
				if(a>b)
				{
					cout<<"TEAM-A "<<i+2<<endl;
					break;
				}
				else if(a<b)
				{
					cout<<"TEAM-B "<<i+2<<endl;
					break;
				}
			}
			if(i==20)
			{
				cout<<"TIE"<<endl;
			}		
			cin>>s;
			continue;
		}
		c1=5;
		c2=5;
		y=0;
		z=0;
		for(i=0;i<10;i++)
		{	
			if(i%2==0)
			{
				y+=s[i]-48;
				c1--;
			}
			else
			{
				z+=s[i]-48;
				c2--;
			}
			if(y<z && (z-y)>c1)
			{
				cout<<"TEAM-B "<<i+1<<endl;
				break;
			}
			if(z<y && (y-z)>c2)
			{
				cout<<"TEAM-A "<<i+1<<endl;
				break;
			}
		}
		cin>>s;
	}
}
