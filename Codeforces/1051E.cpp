#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define S string
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
//Anubhaw Bhalotia https://github.com/anubhawbhaloti
#define fi first
#define	se second
#define f(i,s,n) for(long i=s;i<n;i++)
#define fe(i,s,n) for(long i=s;i<=n;i++)
#define fr(i,s,n) for(long i=s;i>=n;i--)
#define mod 998244353
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef pair<ll,ll> pllll;
S a,l,r;
S lZ,RZ;
long lenA,lenL,lenR;
ll dp[1000004]={};
ll suff[1000004]={};
long z1[2000004]={};
long z2[2000004]={};
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
int comp(S &a,S &b,long start,long end,long z[],long len)
{
	long la=end-start,lb=b.length();
	if(la>lb)
		return 0;
	else if(lb>la)
		return 1;
	else
	{
		// f(i,start,end)
		// {
		// 	if(a[i]>b[i-start])
		// 		return 0;
		// 	else if(b[i-start]>a[i])
		// 		return 1;
		// }
		if(z[len+1+start]==len)
			return 3;
		if(a[start+z[len+1+start]]>b[z[len+1+start]])
			return 0;
		else
			return 1;
	}
	return 3;
}
long findMinL(long pos,long start,long end)
{
	ll temp;
	if(start==end)
	{
		temp=comp(a,l,pos,start+1,z1,lenL);
		return ((temp==0 || temp==3) ?  start :  -1);
	}
	long mid=(end+start)/2;
	temp=comp(a,l,pos,mid+1,z1,lenL);
	return ((temp==0 || temp==3) ?findMinL(pos,start,mid) :  findMinL(pos,mid+1,end));
}
long findMaxR(long pos,long start,long end)
{
	ll temp;
	if(start==end)
	{
		temp=comp(a,r,pos,start+1,z2,lenR);
		return ((temp==1 || temp==3) ?start : -1);
	}
	long mid=(end+start+1)/2;
	temp=comp(a,r,pos,mid+1,z2,lenR);
	return ((temp==1 || temp==3) ? findMaxR(pos,mid,end) : findMaxR(pos,start,mid-1));
}
long finddp(long pos)
{
	long L,R;
	if(a[pos]=='0' && l[0]=='0')
	{
		L=pos;
		R=pos;
	}
	else if(a[pos]=='0' && l[0]!='0')
	{
		L=-1;
		R=-1;
	}
	else
	{
		L=findMinL(pos,pos,a.length()-1);
		R=findMaxR(pos,pos,a.length()-1);
	}
	//long temp=comp(a,l,pos,pos+1);
	//cout<<"l="<<L<<" r="<<R<<endl;
	if(L!=-1 && R!=-1)
	{
		//dp[pos]=1;
		dp[pos]=(suff[L+1]-suff[R+2])%mod;
		
	}
	suff[pos]=(suff[pos+1]+dp[pos]);
}
int main()
{
	cin>>a;
	cin>>l;
	cin>>r;
	lenA=a.length();
	lenL=l.length();
	lenR=r.length();
	S lZ=l+'&'+a;
	S rZ=r+'&'+a;
	memset(dp,0,sizeof(dp));
	constructZArray(lZ,z1);
	constructZArray(rZ,z2);
	dp[a.length()]=1;
	suff[a.length()]=1;
	suff[a.length()+1]=0;
	//cout<<"a"<<dp[3]<<endl;
	fr(i,a.length()-1,0)
		finddp(i);
	cout<<dp[0]<<endl;
}