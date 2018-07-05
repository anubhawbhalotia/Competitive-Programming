#include<bits/stdc++.h>
using namespace std;
typedef struct link
{
	vector <int> parent;
	vector <int> child;
}node;
node s[26];
int ccount=0;
int flag[26]={};
vector <int> ans;
void displayTree(node s[])
{
	for(int i=0;i<26;i++)
	{
		cout<<(char)(i+97)<<endl;
		cout<<"Parent: ";
		for(vector <int> :: iterator j=s[i].parent.begin();j!=s[i].parent.end();j++)
		{
			cout<<(char)((*j)+97)<<" ";
			//cout<<*j<<" ";
		}
		cout<<endl<<"Child: ";
		for(vector <int> :: iterator j=s[i].child.begin();j!=s[i].child.end();j++)
		{
			cout<<(char)((*j)+97)<<" ";
			//cout<<*j<<" ";
		}
		cout<<endl;
	}
}
int checkValidityForMultipleParents(int i)
{
	for(vector <int> :: iterator j=s[i].parent.begin();j!=s[i].parent.end();j++)
	{
		if(!flag[*j])
		{
			return 0;
		}
	}
	return 1;
}
int findOrder()
{
	
	stack <int> stk;
	for(int i=0;i<26;i++)
	{
		if(s[i].parent.size()==0 && s[i].child.size()!=0)
		{
			stk.push(i);
			ans.push_back(i);
			flag[i]=1;
		}
	}
	while(!stk.empty())
	{
		int temp=stk.top();
		stk.pop();
		for(vector <int> ::iterator i=s[temp].child.begin();i!=s[temp].child.end();i++)
		{	
			if(flag[*i])
			{
				continue;
			}
			if(s[*i].parent.size()>1)
			{
				if(checkValidityForMultipleParents(*i))
				{
					stk.push(*i);
					ans.push_back(*i);
					flag[*i]=1;
				}
			}
			else
			{
				stk.push(*i);
				ans.push_back(*i);
				flag[*i]=1;
			}
		}
	}

}
int cyclePresent()
{
	int tflag[26]={};
	for(int i=0;i<26;i++)
	{
		int lc=0;
		if(tflag[i]==0 && s[i].child.size()>0)
		{
			tflag[i]=1;
			stack <int> tstk;
			tstk.push(i);
			while(!tstk.empty())
			{
				lc++;
				if(lc>1000000)	return 1;
				int temp=tstk.top();
				tstk.pop();
				for(vector <int> :: iterator j=s[temp].child.begin();j!=s[temp].child.end();j++)
				{
					tstk.push(*j);
					tflag[*j]=1;
				}
			}
		}
	}
	return 0;
}
int main()
{
	int n;
	cin>>n;
	string a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		for(int i=0;i<26;i++)
		                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  {
			cout<<(char)(i+97);
		}
		cout<<endl;
		return 0;
	}
	int p=0;
	ccount=0;
	for(int i=1;i<n;i++)
	{
		int con=0;
		int c=0;
		while(a[i-1][c]==a[i][c])
		{
			c++;
			if(c==a[i-1].length())
			{
				con=1;
				break;
			}
			if(c==a[i].length())
			{
				p=1;
				break;
			}
		}
		if(p==1)
		{
			break;
		}
		if(con==1)
		{
			continue;
		}
		if(find(s[a[i-1][c]-97].child.begin(),s[a[i-1][c]-97].child.end(),a[i][c]-97)==s[a[i-1][c]-97].child.end())
		{
			s[a[i-1][c]-97].child.push_back(a[i][c]-97);
			s[a[i][c]-97].parent.push_back(a[i-1][c]-97);	
			ccount++;
		}
	}
	if(p==1)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	if(ccount==0)
	{
		for(int i=0;i<26;i++)
		{
			cout<<(char)(i+97);
		}
		cout<<endl;
		return 0;
	}
	
	//displayTree(s);
	if(cyclePresent())
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	findOrder();	
	for(vector <int> :: iterator i=ans.begin();i!=ans.end();i++)
	{
		cout<<(char)((*i)+97);
	}
	
	for(int i=0;i<26;i++)
	{
		if(!flag[i])
		{
			cout<<(char)(i+97);
		}
	}
	cout<<endl;
}