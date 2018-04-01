#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
	int x=0;
	int flag=0;
	int p;
	string n;
	while(x<20)
	{
		if(flag==1)
		{
			if((a[x]*p)>100)
			{
				cout<<"prime"<<endl;
				fflush(stdout);
				return 0;
			}
			cout<<a[x]*p<<endl;
			fflush(stdout);
			cin>>n;
			if(n=="yes")
			{
				cout<<"composite"<<endl;
				fflush(stdout);
				return 0;
			}
			else
			{
				x++;
			}
		}
		else
		{
			cout<<a[x]<<endl;
			fflush(stdout);
			cin>>n;
			if(n=="yes")
			{	
				flag=1;
				p=a[x];
				x=0;
			}
			else
			{
				x++;
			}
		}
	}
	cout<<"prime"<<endl;
	fflush(stdout);
}