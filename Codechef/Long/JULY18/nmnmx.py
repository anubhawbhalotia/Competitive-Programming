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
t=int(input())
while (t>0):
	p=[]
	inp1=list(map(int,raw_input().split()))
	num=inp1[0];
	k=inp1[1];
	ls=list(map(int,raw_input().split()))
	ls.sort();
	#print ls
	s=1
	d1=1
	d2=1
	p.append(0)
	for i in range(1,num):
		s=s*i
		p.append(0)
	#print s
	for i in range (1,k):
		d1=d1*i
	for i in range(1,num-k+1):
		d2=d2*i
	#print d1
	#print d2
	s=s/d1
	s=s/d2
	m=1000000007
	b=1
	for i in range(1,num-1):
		b=b*ls[i]
	#print b
	front=1
	back=num-2
	n=num-1
	r=k-1
	s1=s
	while (front<k-1 and n>k-1):
		s1=(s1*(n-r))/n
		#print s1
		n-=1
		p[front]=s-s1
		p[back]=s-s1
		front+=1
		back-=1
	#print "n="
	# print n
	# print "front bavk"
	# print front
	# print back
	while (n>k-1):
		s1=(s1*(n-r))/n
		#print s1
		n-=1
		if p[front]==0:
			p[front]=s-s1
		else:
			p[front]=p[front]-s1
		if p[back]==0:
			p[back]=s-s1
		else:
			p[back]-=s1
		front+=1
		back-=1
	while (front<(num+1)/2):
		p[front]=s
		p[back]=s
		front+=1
		back-=1
	# print p
	front=1
	back=num-2
	temp=0
	ans=1
	for i in range(1,(num+1)/2):
		#print i
		ans=(ans*findPow(b%m,(p[i]-temp)%(m-1),m))%m
		temp=p[i]
		b/=ls[front]
		b/=ls[back]
		front+=1
		back-=1
	print ans
	t-=1
