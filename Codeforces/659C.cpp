#include<bits/stdc++.h>
using namespace std;
int main()
{
	set <long long> seta;
	vector <long long> ans;
	long long n,m,i,inp,x,count;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>inp;
		seta.insert(inp);
	}
	i=1;
	count=0;
	while(i<=m)
	{
		if(seta.find(i)==seta.end())
		{
			m-=i;
			count++;
			ans.push_back(i);
		}
		i++;
	}
	cout<<ans.size()<<endl;
	for(i=0;i!=ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
}


