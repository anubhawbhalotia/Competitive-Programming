#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t; 
	cin>>t;
	while(t--)
	{
		string s;
		long n;
		cin>>s;
		cin>>n;
		int l=s.length();
		int a=0;
		int b=0;
		long ans=0;
		int g=0;
		int p[2000]={};
		for(int i=0;i<l;i++)
		{
			if(s[i]=='a')
			{
				a++;
			}
			else
			{
				b++;
			}
			p[i]=a-b;
			if(p[i]>0)
			{
				g++;
			}
		}
		int last=p[l-1];
		if(last<0)
		{
			for(int i=0;i<l;i++)
			{
				if(p[i]>0)
				{
					int temp=p[i]/abs(last);
					if(p[i]%abs(last)!=0)
					{
						temp++;
					}
					if(temp>n)
					{
						ans+=n;
					}
					else
					{
						ans+=temp;
					}
					//cout<<temp<<" ";
				}
			}
			cout<<ans<<endl;
			continue;
		}
		if(last==0)
		{
			cout<<g*n<<endl;
			continue;
		}
		ans=0;
		for(int i=0;i<l;i++)
		{
			if(p[i]<=0)
			{
				int temp=abs(p[i])/last;
				temp++;
				if(temp<n)
				{
					ans+=n-temp;
				}
			}
			else
			{
				ans+=n;
			}
		}
		cout<<ans<<endl;
		
	}
}