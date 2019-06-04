#include<bits/stdc++.h>
using namespace std;
typedef struct link
{
	struct link *parent;
	pair <int,int> data;
	struct link *child[3];
}node;
int deleteLeafNodes(node *root,long *d,char (&a)[501][501])
{
	if(!(*d))
	{
		return 0;
	}
	int validChildCOunt=0;
	for(int i=0;i<3;i++)
	{
		if(root->child[i]!=NULL)
		{
			validChildCOunt++;
		}
	}
	if(validChildCOunt==0)
	{
		node *p=root->parent;
		for(int i=0;i<3;i++)
		{
			if(p->child[i]==root)
			{
				p->child[i]=NULL;
				break;
			}
		}
		a[root->data.first][root->data.second]='X';
		delete(root);
		(*d)--;
		return 1;
	}
	for(int i=0;i<3;i++)
	{
		if(root->child[i]!=NULL)
		{
			deleteLeafNodes(root->child[i],d,a);
			if(!(*d))
			{
				break;
			}
		}
	}
	if(!(*d))
	{
		return 1;
	}
	deleteLeafNodes(root,d,a);
}
int main()
{
	int n,m;
	long d;
	char inp;
	int x[]={-1,0,1,0};
	int y[]={0,1,0,-1};
	//pair <long,long> root;
	node *root=new node;
	cin>>n>>m>>d;
	int getStart=0;
	int visited[501][501]={};
	char a[501][501];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='.' && getStart==0)
			{
				root->data=make_pair(i,j);
				root->parent=NULL;
				for(int k=0;k<3;k++)
				{
					root->child[k]=NULL;
				}
				getStart=1;
			}
		}
	}
	queue < node *> q;
	q.push(root);
	visited[root->data.first][root->data.second]=1;
	while(!q.empty())
	{
		node *temp;
		temp=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int newy=((temp->data).first)+y[i];
			int newx=((temp->data).second)+x[i];
			if(newy>=0 && newy<n && newx>=0 && newx<m)
			{
				if(a[newy][newx]=='.' && visited[newy][newx]==0)
				{
					visited[newy][newx]=1;
					node *p=new node;
					p->data=make_pair(newy,newx);
					p->parent=temp;
					for(int k=0;k<3;k++)
					{
						p->child[k]=NULL;
					}
					int k=0;
					while(temp->child[k]!=NULL)	k++;
					temp->child[k]=p;
					q.push(p);
				}
			}
		}
	}
	deleteLeafNodes(root,&d,a);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}

}
	

	

