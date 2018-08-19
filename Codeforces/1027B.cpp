#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,q;
	cin>>n>>q;
	while(q--)
	{
		long long x,y;
		cin>>x>>y;
		long long first,second,count;
		if((x+y) %2==0)
		{
			if(n%2==0)	first=n/2;
			else	first=(n+1)/2;
			second=n/2;
		}
		else
		{
			if(n%2==0)	second=n/2;
			else 	second=(n+1)/2;
			first=n/2;
		}
		// cout<<first<<" "<<second<<endl;
		count=0;
		count+=(first*(x/2));
		// cout<<"c "<<count<<endl;
		//count+=(second*(long long)floor((x-1)/2.0));

		count+=(second*((x-1)/2));
	//	 cout<<"c "<<count<<endl;
		count+=((y+1)/2);
		// cout<<"c "<<count<<endl;
		if((x+y)%2==0)
		{
			cout<<count<<endl;
		}
		else
		{
			cout<<(((n*n)+1)/2)+count<<endl;
		}


	}
}