class Solution {
public:
    void reverseWords(string &s) {
        vector <string> a;
        long i=0;
        while(s[i]==' ')	i++;
        while(s[i]!='\0')
        {
        	string tmp="";
       		while(s[i]!=' ')
        	{
        		tmp+=s[i];
        		i++;
        		if(s[i]=='\0')
        		{
        			break;
        		}
        	}
        	a.push_back(tmp);
        	while(s[i]==' ')	i++;
		}
		s="";
		//vector <string> :: reverse_iterator r=a.rbegin();
		//s+=*r;
		//r++;
		for(vector <string> :: reverse_iterator r=a.rbegin();;r!=a.rend();r++)
		{	if(r!=a.begin)
				s+=" ";
			s+=*r;
		}
    }	
};