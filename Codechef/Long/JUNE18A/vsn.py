import math
def bs(start,end):
	#print "start=%.8f end=%.8f"%(start,end)
	if end-start<=0.00000001:
		return start
	mid=(start+end)/2.0
	x2=(qx+(mid*dx))-px;
	y2=(qy+(mid*dy))-py;
	z2=(qz+(mid*dz))-pz;
	Hsquare=((x2*x2)+(y2*y2)+(z2*z2));
	H=math.sqrt(Hsquare);
	cos2=((x1*x2)+(y1*y2)+(z1*z2))/(h*H);
	if cos2<=cos1:
		return bs(start,mid)
	else:
		return bs(mid+0.00000001,end)
 
t=int(input())
for i in range(t):
	numbers = map(int, raw_input().split())
	# print numbers
	px=numbers[0]
	py=numbers[1]
	pz=numbers[2]
	qx=numbers[3]
	qy=numbers[4]
	qz=numbers[5]
	dx=numbers[6]
	dy=numbers[7]
	dz=numbers[8]
	cx=numbers[9]
	cy=numbers[10]
	cz=numbers[11]
	r=numbers[12]
	#print r
	hsquare=((px-cx)*(px-cx))+((py-cy)*(py-cy))+((pz-cz)*(pz-cz))
	h=math.sqrt(hsquare)
	#print "h=%.8f"%(h)
	bsquare=(hsquare)-(r*r)
	b=math.sqrt(bsquare)
	x1=cx-px
	y1=cy-py
	z1=cz-pz	
	cos1=b/h
	#print "b=%.8f"%(b)
	#print "cos1=%.8f"%(cos1)
	ans=bs(0,1000000000)
	#print ans
	print "%.7f"%(ans)