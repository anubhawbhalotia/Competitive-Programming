def findPow(base,exp,mod):
	if exp==1:
		return base%mod
	ans=1
	while exp>1:
		tempExp=1
		tempAns=base
		while exp>=(tempExp*2):
			tempExp*=2
			tempAns=(tempAns*tempAns)%mod
		ans=(ans*tempAns)%mod
		exp-=tempExp
	if exp==1:
		ans=(ans*base)%mod
		exp-=1
	return ans
def findGcd(a,b):
	if b==0:
		return a
	return findGcd(b,a%b)
t=int(input())
M=1000000007
for i in range(0,t):
	a,b,n= map(int, raw_input().split())
	if a-b==0:
		a=findPow(a,n,M)
		a+=a
		a=a%M
		print a
	else:
		temp=a-b
		a=findPow(a,n,temp)
		a+=a
		a=a%(temp)
		g=findGcd(a,temp)
		g=g%M
		print g