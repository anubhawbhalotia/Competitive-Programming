#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    long n;
    string s;
    for(int i = 0; i!=t; i++)
    {
        cin>>n;
        cin>>s;
        for(long j = 0; j!=s.length(); j++)
        {
            if(s[j]=='S')
                s[j]='E';
            else
                s[j]='S';
        }
        printf("Case #%d: ",i+1);
        cout<<s<<endl;
    }
}