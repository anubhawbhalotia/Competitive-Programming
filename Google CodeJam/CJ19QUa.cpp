#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    string a,b,n;
    for(int i=0; i<t; i++)
    {
        cin>>n;
        a=n;
        b=n;
        for(int j =0; j!=n.length(); j++)
        {
            if(n[j]=='4')
            {
                a[j]='3';
                b[j]='1';
            }
            else
            {
                a[j]=n[j];
                b[j]='0';
            }
        }
        cout<<"Case #"<<i+1<<": "<<a<<" "<<b<<endl;
    }
}