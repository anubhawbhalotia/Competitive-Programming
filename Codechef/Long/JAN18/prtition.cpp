#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9 +7;
int main()
{
	long t,x,n,i,last;
	long long sum,s;
	scanf("%ld",&t);
	while(t--)
	{
		char str[1000011];
		
		scanf("%ld %ld",&x,&n);
		str[n]='\0';
		int a[1000011]={};
		sum=(n*(n+1))/2;
		sum-=x;
		a[x]=2;
		if(sum%2==1 || sum<=0)
		{
			//cout<<"case1\n";
			printf("impossible\n");
			continue;
		}
		s=sum/2;
		for(i=n;i>0;)
		{
			//cout<<i<<" "<<s<<endl;
			if(s==0)
			{
				break;
			}
			if(a[i]==0 && s>=i)
			{
				
					a[i]=1;
					s-=i;
					last=i;
					if(s<i)
					{
						i=s;
					}
					else
					{
						i--;
					}
					continue;	
			}
			if(s==2 || s==1)
			{
				s+=last;
				i=last-1;
				a[last]=0;
				continue;
			}
			i--;
 
 
 
		}
		if(s!=0)
		{
			printf("impossible\n");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			str[i-1]=a[i]+48;
		}
		cout<<str<<endl;
	}
}
