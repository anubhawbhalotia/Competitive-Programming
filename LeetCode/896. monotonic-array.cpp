class Solution {
public:
     bool isMonotonic(vector<int>& A) {
    	int last=*(A.begin());
    	int mono=0;
        vector <int> ::iterator it=A.begin()+1;
        for(;it!=A.end();it++)
        {
        	if(mono==0)
        	{
        		if(*it<last)
        			mono=-1;
        		else if(*it>last)
        			mono=1;
        		else
        			mono=0;
                last=*it;
        	}
        	else if(mono==1)
        	{
        		if(*it<last)
        			break;
        		last=*it;
        	}
        	else if(mono==-1)
        	{
        		if(*it>last)
        			break;
        		last=*it;
        	}
        }
        if(it!=A.end())
        	return false;
        else
        	return true;
     }
};