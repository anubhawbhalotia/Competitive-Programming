#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k1,k2,inp,i;
	long long x;
	queue <int> q1,q2;
	cin>>n;
	cin>>k1;
	for(i=0;i<k1;i++)
	{
		cin>>inp;
		q1.push(inp);
	}
	cin>>k2;
	for(i=0;i<k2;i++)
	{
		cin>>inp;
		q2.push(inp);
	}
	x=0;
	while(q1.empty()==0 && q2.empty() ==0 && x<1000000)
	{
		x++;
		//cout<<"q1f "<<q1.front()<<" q2f "<<q2.front()<<endl;
		//cout<<"q1f "<<q1.front()<<" q2f "<<q2.front()<<endl;
		if(q1.front()>q2.front())
		{	
			
			q1.push(q2.front());
			q1.push(q1.front());
			q2.pop();
			q1.pop();
		}
		else
		{
			q2.push(q1.front());
			q2.push(q2.front());
			q1.pop();
			q2.pop();
		}
	}
	if(x<1000000)
	{
		cout<<x<<" ";
		if(q1.empty())
		{
			cout<<"2";
		}
		else
		{
			cout<<"1";
		}
	}
	else
	{
		cout<<"-1";
	}
}
