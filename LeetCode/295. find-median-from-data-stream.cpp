class MedianFinder {
public:
    /** initialize your data structure here. */
   	multiset <long> s;
   	long length;
   	multiset <long> :: iterator high,low;
    MedianFinder() {
        length=0;
        
    }
    
    void addNum(int num) {
    	s.insert(num);
    	if(length==0)
    	{
    		high=s.begin();
    		low=s.begin();
    	}
    	else if(length%2==0)
    	{
    		if(num<*low)
    		{
    			high--;
    		}
    		else if(num>*high)
    		{
    			low++;
    		}
    		else if(*low==*high)
    		{
    			low++;
    		}
    		else if(num==*low)
    		{
    			low++;
    			high--;
    		}
    		else if(num==*high)
    		{
    			low++;	
    		}
    		else
    		{
    			low++;
    			high--;
    		}
    	}
    	else
    	{
    		if(num==*low)
    		{
    			high++;	
    		}
    		else if(num<*low)
    		{
    			low--;
    		}
    		else
    		{
    			high++;
    		}
    	}
    	
    	length++;
    	
    }
    
    double findMedian() {
    	if(length==0)
    		return 0.0;
    	return (double)(*low + *high)/2.0;	
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */