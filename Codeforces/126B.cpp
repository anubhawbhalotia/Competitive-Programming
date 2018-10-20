// Z algorithm
#include<bits/stdc++.h>
using namespace std;
#define l  long
#define ll long long
#define S string
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
//Anubhaw Bhalotia https://github.com/anubhawbhalotia 
#define fi first
#define	se second
#define f(i,s,n) for(long i=s;i<n;i++)
#define fe(i,s,n) for(long i=s;i<=n;i++)
#define fr(i,s,n) for(long i=s;i>n;i--)
#define fre(i,s,n) for(long i=s;i>=n;i--)
#define mod 10e9 + 7
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef pair<ll,ll> pllll;
S s;
int constructZArray(S s,long z[])
{
	pll lr,temp;
	long k;
	z[0]=s.length();
	lr=mp(0,0);
	long i=1,start,index;
	while(i!=s.length())
	{
		if(i>lr.se)
		{
			start=0;
			index=i;
			pll temp=mp(-1,-1);
			if(s[start]==s[index])
			{
				temp.fi=index;	
				temp.se=index;
				f(i,index+1,s.length())
				{
					if(s[i-(index-start)]==s[i])
						temp.se++;
					else
						break;
				}	
			}	
			if(temp.fi==-1)
				z[i]=0;
			else
			{
				lr=temp;
				z[i]=lr.se-lr.fi+1;
			}
		}
		else
		{
			k=i-lr.fi;
			if(z[k]<lr.se-i+1)
				z[i]=z[k];
			else
			{
				lr.fi=i;
				start=lr.se-i+1;
				index=lr.se+1;
				pll temp=mp(-1,-1);
				if(s[start]==s[index])
				{
					temp.fi=index;	
					temp.se=index;
					f(i,index+1,s.length())
					{
						if(s[i-(index-start)]==s[i])
							temp.se++;
						else
							break;
					}	
				}		
				if(temp.se!=-1)
					lr.se=temp.se;
				z[i]=lr.se-lr.fi+1;
			}
		}
		i++;
	}
	return 1;
}
int main()
{
	cin>>s;
	long z[s.length()];
	constructZArray(s,z);
	long max=0,maxIndex=0;
	f(i,1,s.length()-1)
	{
		if(z[i]>max)
		{
			max=z[i];
			maxIndex=i;
		}
	}
	long val=0,flag=0,last=0;
	fr(i,s.length()-1,maxIndex)
	{
		val++;
		if(z[i]!=val)
		{

		}
		else if(val<=max)
		{
			last=val;
		}
		else
		{
			break;
		}
	}
	if(max==0 || flag==1 ||last==0)
		cout<<"Just a legend"<<endl;
	else
		cout<<s.substr(0,last)<<endl;

	
}