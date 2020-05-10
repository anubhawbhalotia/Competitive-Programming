#include <bits/stdc++.h>
using namespace std;
void solution()
{
	int n, k;
	cin>>n>>k;
	vector<int> a(n + 1);
	set <int> s, ec;
	for(int i = 1; i < n + 1; i++)
	{
		cin>>a[i];
		if(i != a[i])
			s.insert(i);
	}
	int c = k;
	int i1, i2, i3;
	vector<vector<int>> ans;
	while(c != 0 && s.empty() == 0)
	{
		i1 = *s.begin();
		s.erase(s.find(i1));
		i2 = a[i1];
		s.erase(s.find(i2));
		if(a[i2] == i1)
		{
			if(s.empty() && ec.empty())
			{
				cout<<"-1"<<endl;
				return;
			}
			if(ec.empty() == 0)
			{
				i3 = *ec.begin();
				ec.erase(ec.begin());
				s.insert(*ec.begin());
				ec.erase(ec.begin());
			}
			else
			{
				ec.insert(i1);
				ec.insert(i2);
				continue;
			}
		}
		else
		{
			i3 = a[i2];
			s.erase(s.find(i3));
		}
		int temp = a[i3];
		a[i3] = a[i2];
		a[i2] = a[i1];
		a[i1] = temp;
		ans.push_back({i1, i2, i3});
		if(a[i1] != i1)
			s.insert(i1);
		if(a[i2] != i2)
			s.insert(i2);
		if(a[i3] != i3)
			s.insert(i3);
		c--;
	}
	if(s.empty() == false || ec.empty() == false)
		cout<<"-1"<<endl;
	else
	{
		cout<<ans.size()<<endl;
		for(auto i : ans)
		{
			for(auto j : i)
				cout<<j<<" ";
			cout<<endl;
		}
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solution();
	}
}
