#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	string s;
	scanf("%d",&n);
	cin>>s;
	int p1=0;
	int p2=n-1;
	int flag=0;
	int s1=0;
	int s2=0;
	int temp=0;
	int total=0;
	int t=0;
	vector <int> ans;
	s1+=s[p1]-48;
	s2+=s[p2]-48;
	while(p1<p2)
	{
		if(s1<s2)
		{
			p1++;
			if(p1>=p2)
			{
				flag=1;
				temp=s1+s2;
				break;
			}
			s1+=s[p1]-48;
		}
		else if(s1>s2)
		{
			p2--;
			if(p1>=p2)
			{
				flag=1;
				temp=s1+s2;
				break;
			}
			s2+=s[p2]-48;
		}
		else
		{
			if(s1)
				ans.push_back(s1);
			//cout<<s1<<" ";
			total+=s1;
			p1++;
			p2--;
			if(p1==p2)
			{
				flag=1;
				temp=s[p2]-48;
				break;
			}
			s1=s[p1]-48;
			s2=s[p2]-48;
			
			
		}
	}
	
	// cout<<endl;
	// cout<<"\n"<<temp<<endl;
	if(ans.size()==0 && temp!=0)
	{
		cout<<"NO\n";
		return 0;
	}
	if(ans.size()==0 && temp==0)
	{
		cout<<"YES\n";
		return 0;
	}
	if(flag==0)
	{
		cout<<"YES\n";
	}
	else if(temp!=0)
	{
		while(ans.size())
		{
			// for(int i=0;i!=ans.size();i++)
			// {
			// 	cout<<ans[i]<<" ";
			// }
			t=0;
			for(int i=0;i!=ans.size();i++)
			{
				t+=ans[i];
				if(t>temp)
				{
					break;
				}
				if(t==temp)
				{
					t=0;
					continue;
				}
			}
			if(t==0)
			{
				cout<<"YES\n";
				return 0;
			}	
			temp+=2*(*(ans.end()-1));
			ans.erase(ans.end()-1);
		}
		cout<<"NO\n";
	}
	else
	{
		cout<<"YES\n";
	}

}
	

