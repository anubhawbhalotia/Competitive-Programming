#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,x;
	long t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>n>>a;
		if(a>2)
		{
			string s,g;
			for(i=97;i<97+a;i++)
			{
				s+=i;
			}
			for(i=0;i<n/a;i++)
			{
				g+=s;
			}
			x=97;
			for(i=0;i<n%a;i++)
			{
				g+=x;
				x++;
			}
			cout<<"1 "<<g<<"\n";
		}
		else if(a==1)
		{
			string s;
			for(i=0;i<n;i++)
			{
				s+=97;
			}
			cout<<n<<" "<<s<<"\n";
		}
		else
		{
			string g,s;
			g="aababb";
			if(n==1)
			{
				cout<<"1 a"<<"\n";
			}
			else if(n==2)
			{
				cout<<"1 ab\n";
			}
			else if(n==3)
			{
				cout<<"2 aab\n";
			}
			else if(n==4)
			{
				cout<<"2 aabb\n";
			}
			else if(n==5)
			{
				cout<<"3 aabab\n";
			}
			else if(n==6)
			{
				cout<<"3 aababb\n";
			}
			else if(n==7)
			{
				cout<<"3 aababbb\n";
			}
			else if(n==8)
			{
				cout<<"3 aaababbb\n";
			}
			else
			{
				string s;
				for(i=0;i<n/6;i++)
				{
					s+=g;
				}
				for(i=0;i<n%6;i++)
				{
					s+=g[i];
				}
				cout<<"4 "<<s<<"\n";
			}
		}

	}
}