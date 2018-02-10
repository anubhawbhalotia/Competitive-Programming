#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9 +7;
int main()
{
	long i;
	stack <char> s;
	char last;
	string str;
	cin>>str;
	if(str.length()%2==1)
	{
		cout<<"No"<<endl;
		return 0;
	}
	s.push(str[0]);
	last=s.top();
	for(i=1;i!=str.length();i++)
	{
		s.push(str[i]);
		if(s.top()==last)
		{
			s.pop();
			s.pop();
		}
		if(s.empty())
		{
			last='c';
		}
		else
		{
			last=s.top();
		}
	}
	if(s.empty())
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}

}

