    #include<bits/stdc++.h>
    using namespace std;
    //#define MAXTEETH 1000001
    #define N 1000001
    typedef struct name
    {
    	vector <long> vec;
    }node;
     
    long long teeth[N];
    long dsu[N];
    long direction[N*2];
    int invalid[N];
    int hashTable[N*2];
    long n;
    long revPtr[N];
    long nextDir=1;
    long nextNode=0;
    node *nodeAddr[N];
    long long gcd(long long a, long long b)
    {
        if (a == 0)
            return b;
        return gcd(b%a, a);
    }
    long findRoot(long v)
    {
    	return v==dsu[v] ? v : dsu[v]=findRoot(dsu[v]);
    }
    long unionDsu(long a,long b)
    {
    	long aa=findRoot(a);
    	long bb=findRoot(b);
    	dsu[aa]=bb;
    	findRoot(a);
    	findRoot(b);
    }
    void displayDsu()
    {
    	cout<<"DSU ";
    	for(long i=0;i<n;i++)
    	{
    		cout<<dsu[i]<<" ";
    	}
    	cout<<endl;
    }
    void displayInvalid()
    {
    	cout<<"INVALID ";
    	for(long i=0;i<n;i++)
    	{
    		cout<<invalid[i]<<" ";
    	}
    	cout<<endl;
    }
    void displayDirection()
    {
    	cout<<"DIRECTION ";
    	for(long i=0;i<n;i++)
    	{
    		cout<<direction[i]<<" ";
    	}
    	cout<<endl;
    }
    void displayHashTable()
    {
    	cout<<"HASH ";
    	for(long i=0;i<nextDir;i++)
    	{
    		cout<<hashTable[i]<<" ";
    	}
    	cout<<endl;
    }
    int main()
    {
    	long m;
    	cin>>n>>m;
    	for(long i=0;i<N;i++)
    	{
    		dsu[i]=i;
    		invalid[i]=0;
    		direction[i]=0;
    		hashTable[i]=0;
    	}
    	for(long i=0;i<n;i++)
    		scanf("%lld",&teeth[i]);
    	while(m--)
    	{
    		int type;
    		scanf("%d",&type);
    		long x,c,y;
    		long long v;
    		switch(type)
    		{
    			case 1:
    				scanf("%ld %ld",&x,&c);
    				x--;
    				teeth[x]=c;
    				break;
    			case 2:
    				// cout<<"Before case 2\n";
    				// displayDsu();
    				// displayDirection();
    				// displayInvalid();
    				// displayHashTable();
    				scanf("%ld %ld",&x,&y);
    				x--;
    				y--;
    				if(x==y)	
    					break;
    				if(direction[x]!=0 && direction[y]!=0) //x and y both are part of some set of gears
    				{
    					if(findRoot(x)==findRoot(y))//x and y both are part of same set of gears
    					{
    						int temp1=(direction[x]<0)?-1:1;
    						int temp2=(direction[y]<0)?-1:1;
    						int dir1=hashTable[abs(direction[x])]*temp1;
    						int dir2=hashTable[abs(direction[y])]*temp2;
    						if(dir1==dir2)//x and y both move in same direction
    						{
    							invalid[x]=1;
    							invalid[y]=1;
    							invalid[findRoot(x)]=1;
    						}
    					}
    					else //x and y both are part of different set of gears
    					{
    						if(invalid[findRoot(x)]==1 || invalid[findRoot(y)]==1 || invalid[x]==1 || invalid[y]==1) //x or y is blocked
    						{
    							invalid[x]=1;
    							invalid[y]=1;
    							invalid[findRoot(x)]=1;
    							invalid[findRoot(y)]=1;
    							long tempPtr=revPtr[abs(direction[y])];
    							for(vector <long> :: iterator i=nodeAddr[tempPtr]->vec.begin();i!=(nodeAddr[tempPtr]->vec).end();i++)
    							{
    								(nodeAddr[revPtr[abs(direction[x])]]->vec).push_back(*i);
    								revPtr[*i]=revPtr[abs(direction[x])];
    							}
    							delete(nodeAddr[tempPtr]);
    							unionDsu(x,y);
    							invalid[findRoot(x)]=1;
    							invalid[findRoot(y)]=1;
    						}
    						else// both x and y are not blocked
    						{
    							int tempy=(direction[y]<0)?-1:1;
    							int diry=hashTable[abs(direction[y])]*tempy;
    							int tempx=(direction[x]<0)?-1:1;
    							int initHashX=hashTable[abs(direction[x])];
    							int finalHashX=diry*tempx*-1;
    							if(initHashX!=finalHashX)
    							{
    								for(vector <long> :: iterator i=nodeAddr[revPtr[abs(direction[x])]]->vec.begin();i!=(nodeAddr[revPtr[abs(direction[x])]]->vec).end();i++)
    								{
    									hashTable[*i]*=-1;
    								}
    							}
    							long tempPtr=revPtr[abs(direction[y])];
    							for(vector <long> :: iterator i=nodeAddr[tempPtr]->vec.begin();i!=(nodeAddr[tempPtr]->vec).end();i++)
    							{
    								(nodeAddr[revPtr[abs(direction[x])]]->vec).push_back(*i);
    								revPtr[*i]=revPtr[abs(direction[x])];
    							}
    							delete(nodeAddr[tempPtr]);
    							unionDsu(x,y);
    						}
    					}
    				}
    				else if(direction[x]==0 && direction[y]!=0)//x is not a part of any set and y is a part of some set
    				{
    					unionDsu(x,y);
    					//((nodeAddr[revPtr[y]])->vec).push_back(x);
    					//revPtr[x]=revPtr[y];
    					direction[x]=direction[y]*-1;
    				}
    				else if(direction[y]==0 && direction[x]!=0)//y is not a part of any set and x is a part of some set 
    				{
    					unionDsu(y,x);
    					// nodeAddr[revPtr[x]]->vec.push_back(y);
    					// revPtr[y]=revPtr[x];
    					direction[y]=direction[x]*-1;
    				}
    				else
    				{
    					direction[x]=nextDir;
    					direction[y]=direction[x]*-1;
    					hashTable[direction[x]]=1;
    					node *p=new node;
    					// p->vec.push_back(x);
    					// p->vec.push_back(y);
    					p->vec.push_back(direction[x]);
    					nodeAddr[nextNode]=p;
    					// revPtr[x]=nextNode;
    					// revPtr[y]=nextNode;
    					revPtr[direction[x]]=nextNode;
    					nextNode++;
    					nextDir++;
    					unionDsu(x,y);
    				}
    				// cout<<"After case 2"<<endl;
    				// displayDsu();
    				// displayDirection();
    				// displayInvalid();
    				// displayHashTable();
    				break;
    			case 3:
    				scanf("%ld %ld %lld",&x,&y,&v);
    				x--;
    				y--;
    				// for(long i=0;i<n;i++)
    				// {
    				// 	findRoot(i);
    				// }
    				findRoot(x);
    				findRoot(y);
    				if(dsu[x]!=dsu[y] || invalid[dsu[x]]==1 || invalid[dsu[y]]==1 || invalid[x]==1 || invalid[y]==1)
    				{
    					printf("0\n");
    				}
    				else if(x==y)
    				{
    					printf("%lld/1\n",v);
    				}
    				else
    				{
    					long long num=v*teeth[x];
    					long long den=teeth[y];
    					long long Gcd=gcd(num,den);
    					num/=Gcd;
    					den/=Gcd;
    					int temp1=direction[x]<0? -1:1;
    					int temp2=direction[y]<0? -1:1;
    					int dir1=hashTable[abs(direction[x])]*temp1;
    					int dir2=hashTable[abs(direction[y])]*temp2;
    					if((dir1*dir2)<0)
    					{
    						num*=-1;
    					}
    					printf("%lld/%lld\n",num,den);
    				}
    				break;
    		}
    	}
    } 
