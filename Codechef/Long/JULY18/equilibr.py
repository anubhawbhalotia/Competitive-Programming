    def findPow(b,s,m):
    	ans=1;
    	while(s>=2):
    		n=1;
    		a=b;
    		while (n*2<s):
    			a=(a*a)%m
    			n=n*2
    		s-=n;
    		ans=(ans*a)%m
    	if s==1:
    		ans=(ans*b)%m
    	return ans
    def modInverse(a, m) :
        return power(a, m - 2, m)
    n=int(input())
    k=int(input())
    m=1000000007
    den=findPow(2,n-1,m)
    num=(den-n)%m
    den=findPow(den,m-2,m)
    print (num*den)%m
     
