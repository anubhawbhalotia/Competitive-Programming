#include<bits/stdc++.h>
using namespace std;
void computeLPSArray(string pat, int M, int lps[])
{
    // length of the previous longest prefix suffix
    int len = 0;
 
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar 
            // to search step.
            if (len != 0)
            {
                len = lps[len-1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
int main()
{
	int n,k;
	string  t;
	cin>>n>>k;
	cin>>t;
	int lps[n];
	computeLPSArray(t,n,lps);
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<lps[i]<<" ";
	// }
	string temp="";
	for(int i=lps[n-1];i<n;i++)
	{
	 	temp+=t[i];
	}
	string ansstr=t;
	int len=n-lps[n-1];
	int ans=(len*k);
	for(int i=0;i<k-1;i++)
	{
		ansstr+=temp;
	}
	
	cout<<ansstr<<endl;


}