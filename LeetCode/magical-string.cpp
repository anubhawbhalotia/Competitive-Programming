class Solution {
public:
    int magicalString(int n) 
    {
    	string a = "122" ;//2
    	long ones=1;
    	if(n==0)
    		return 0;
    	if(n<=3)
			return ones; 
		long lastIndex=2;
		char lastVal='2';
		long i=2;
		n--;
    	while(i<n)
    	{
    		lastVal=(lastVal=='2')?'1':'2';
    		for(int j=0;j<a[lastIndex]-48;j++)
    		{
    			if(lastVal=='1')
    			{
    				ones++;
    			}
    			i++;
    			a+=lastVal;
    			if(i>=n)		break;
    		}
    		lastIndex++;
    	}
    	return ones;
    }	
};