class Solution 
{
public:
   int lengthOfLongestSubstring(string s) 
    {
		int lastIndex[255];
		for(int i=0;i<150;i++)
		{
			lastIndex[i]=-1;
		}
		int i=0;
		int l=s.length();
		int maxx=0;
        int count=0;
        int last=-1;
		while(i!=l)
		{
			//cout<<"count="<<count<<endl;
			if(count>maxx)
				maxx=count;
			if(lastIndex[s[i]]==-1)
			{
				count++;
				lastIndex[s[i]]=i;
				i++;
				continue;
			}
			count=i-max(lastIndex[s[i]],last);
			if(max(lastIndex[s[i]],last)==lastIndex[s[i]])
				last=lastIndex[s[i]];
			lastIndex[s[i]]=i;
            i++;
		}
		if(count>maxx)
			maxx=count;
		//cout<<"count="<<count<<endl;
		return maxx;

    }
};