#include<bits/stdc++.h>
using namespace std;
long int l;
char a[300000],b[300000];
int comparee(long starta,long startb,long length)
{
	long i,j;
	for(i=starta,j=startb;i<starta+length;i++,j++)
	{
		if(a[i]!=b[j])
		{
			return 0;
		}
	}
	return 1;
}
int eq(long starta,long startb,long l)
{
	//cout<<a<<" "<<b<<endl;
	if(comparee(starta,startb,l)==1)
	{
		return 1;
	}
	if(l%2==1)
	{
		return 0;
	}
	//cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;
	if(eq(starta,startb,l/2)==1 && eq(starta+(l/2),startb+(l/2),l/2)==1)
	{
		return 1;
	}
	if(eq(starta,startb+(l/2),l/2)==1 && eq(starta+(l/2),startb,l/2)==1)
	{
		return 1;
	}
	return 0;
}
int main()
{
	
	cin>>a>>b;
	l=strlen(a);
	if(eq(0,0,l))
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
}