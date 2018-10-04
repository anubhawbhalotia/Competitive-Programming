#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	scanf("%lld",&n);
	long long t=n;
	long long d=0;
	long long ten=1;
	long long s=0;
	long long nine=0;
	if(n<9)
	{
		cout<<n<<endl;
		return 0;
	}
	long long tmp;
	while(t!=0)
	{
		tmp=t%10;
		if(tmp==9)
			nine++;
		d++;
		t=t/10;
		ten=ten*10;
		s+=9;
	}
	if(nine==d)
	{
		cout<<s<<endl;
		return 0;
	}
	s=0;
	ten=ten/10;
	t=n;
	long long digit=d-2,temp=9;
	while(digit>0)
	{
		temp=(temp*10)+9;
		digit--;
	}
	if((n/ten) >1)
		temp+=ten;
	n=n-temp;
	
	while(n!=0)
	{
		tmp=n%10;
		s+=tmp;
		n=n/10;
	}
	while(temp!=0)
	{
		tmp=temp%10;
		s+=tmp;
		temp=temp/10;
	}
	cout<<s<<endl;

	



}