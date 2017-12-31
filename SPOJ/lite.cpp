#include<bits/stdc++.h>
using namespace std;
int update(int lazy[],int tree[],int si,int ss,int se,int us,int ue)
{
    if(lazy[si]%2)
    {
        tree[si] = (se-ss+1)-tree[si];
        if (ss != se)
        {
            lazy[si*2 + 1]   += lazy[si];
            lazy[si*2 + 2]   += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss>se || ss>ue || se<us)
        return 0;
    if (ss>=us && se<=ue)
    {
        tree[si] = (se-ss+1)-tree[si];
        if (ss != se)
        {
            lazy[si*2 + 1]   += 1;
            lazy[si*2 + 2]   += 1;
        }
        return 0;
    }
    int mid = (ss+se)/2;
    update(lazy,tree,si*2+1, ss, mid, us, ue);
    update(lazy,tree,si*2+2, mid+1, se, us, ue);
    tree[si] = tree[si*2+1] + tree[si*2+2];
}
int query(int lazy[],int tree[],int ss, int se, int qs, int qe, int si)
{
   	if(lazy[si]%2)
    {
        tree[si] = (se-ss+1)-tree[si];
 		if (ss != se)
        {
            lazy[si*2+1] += lazy[si];
            lazy[si*2+2] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss>se || ss>qe || se<qs)
        return 0;
    if (ss>=qs && se<=qe)
        return tree[si];
    int mid = (ss + se)/2;
    return query(lazy,tree,ss, mid, qs, qe, 2*si+1)+query(lazy,tree,mid+1, se, qs, qe, 2*si+2);
}
int main()
{
	int n,m,q,x,y,tree[1000000],lazy[1000000];
	scanf("%d %d",&n,&m);
	while(m--)
	{
		scanf("%d %d %d",&q,&x,&y);
		if(!q)
		{
			update(lazy,tree,0,0,n-1,x-1,y-1);
		}
		else
		{
			printf("%d\n",query(lazy,tree,0,n-1,x-1,y-1,0));
		}
	}
}