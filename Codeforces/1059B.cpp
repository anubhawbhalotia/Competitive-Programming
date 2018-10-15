#include<bits/stdc++.h>
using namespace std;
#define X 1001
int flag[X][X]={};
char a[X][X];
long n,m;
int checkFlag(long r,long c)
{
	//Check1
	if(c+2<m && r+2<n && c>=0 && r>=0)
	{
		if(a[r][c]=='#' && a[r][c+1]=='#'  && a[r][c+2]=='#' && a[r+1][c]=='#'
			&& a[r+1][c+2]=='#' && a[r+2][c]=='#' && a[r+2][c+1]=='#' && a[r+2][c+2]=='#')
		{
			flag[r][c]=1;
			flag[r][c+1]=1;
			flag[r][c+2]=1;
			flag[r+1][c]=1;
			//flag[r+1][c+1]=0;
			flag[r+1][c+2]=1;
			flag[r+2][c]=1;
			flag[r+2][c+1]=1;
			flag[r+2][c+2]=1;
			return 1;
		}
	}
	if(c+1<m && r+2<n && c>=1 && r>=0)
	{
		if(a[r][c-1]=='#' && a[r][c]=='#'  && a[r][c+1]=='#' && a[r+1][c-1]=='#'  
			&& a[r+1][c+1]=='#' && a[r+2][c-1]=='#' && a[r+2][c]=='#' && a[r+2][c+1]=='#')
		{
			flag[r][c-1]=1;
			flag[r][c]=1;
			flag[r][c+1]=1;
			flag[r+1][c-1]=1;
			//flag[r+1][c]=0;
			flag[r+1][c+1]=1;
			flag[r+2][c-1]=1;
			flag[r+2][c]=1;
			flag[r+2][c+1]=1;
			return 2;
		}
	}
	if(c<m && r+2<n && c>=2 && r>=0)
	{
		if(a[r][c-2]=='#' && a[r][c-1]=='#'  && a[r][c]=='#' && a[r+1][c-2]=='#' 
			&& a[r+1][c]=='#' && a[r+2][c-2]=='#' && a[r+2][c-1]=='#' && a[r+2][c]=='#')
		{
			flag[r][c-2]=1;
			flag[r][c-1]=1;
			flag[r][c]=1;
			flag[r+1][c-2]=1;
			//flag[r+1][c-1]=0;
			flag[r+1][c]=1;
			flag[r+2][c-2]=1;
			flag[r+2][c-1]=1;
			flag[r+2][c]=1;
			return 3;
		}
	}
	if(c+2<m && r+1<n && c>=0 && r>=1)
	{
		if(a[r-1][c]=='#' && a[r-1][c+1]=='#'  && a[r-1][c+2]=='#' && a[r][c]=='#' 
			&& a[r][c+2]=='#' && a[r+1][c]=='#' && a[r+1][c+1]=='#' && a[r+1][c+2]=='#')
		{
			flag[r-1][c]=1;
			flag[r-1][c+1]=1;
			flag[r-1][c+2]=1;
			flag[r][c-2]=1;
			//flag[r][c+1]=0;
			flag[r][c+2]=1;
			flag[r+1][c]=1;
			flag[r+1][c+1]=1;
			flag[r+1][c+2]=1;
			return 4;
		}
	}
	// if(c+1<m && r+1<n && c>=1 && r>=1)
	// {
	// 	if(a[r-1][c-1]=='#' && a[r-1][c]=='#'  && a[r-1][c+1]=='#' && a[r][c-1]=='#' && a[r][c]=='.' 
	// 		&& a[r][c+1]=='#' && a[r+1][c-1]=='#' && a[r+1][c]=='#' && a[r+1][c+1]=='#')
	// 	{
	// 		flag[r-1][c-1]=1;
	// 		flag[r-1][c]=1;
	// 		flag[r-1][c+1]=1;
	// 		flag[r][c-1]=1;
	// 		flag[r][c]=0;
	// 		flag[r][c+1]=1;
	// 		flag[r+1][c-1]=1;
	// 		flag[r+1][c]=1;
	// 		flag[r+1][c+1]=1;
	// 		return 5;
	// 	}
	// }
	if(c<m && r+1<n && c>=2 && r>=1)
	{
		if(a[r-1][c-2]=='#' && a[r-1][c-1]=='#'  && a[r-1][c]=='#' && a[r][c-2]=='#'  
			&& a[r][c]=='#' && a[r+1][c-2]=='#' && a[r+1][c-1]=='#' && a[r+1][c]=='#')
		{
			flag[r-1][c-2]=1;
			flag[r-1][c-1]=1;
			flag[r-1][c]=1;
			flag[r][c-2]=1;
			//flag[r][c-1]=0;
			flag[r][c]=1;
			flag[r+1][c-2]=1;
			flag[r+1][c-1]=1;
			flag[r+1][c]=1;
			return 6;
		}
	}
	if(c+2<m && r<n && c>=0 && r>=2)
	{
		if(a[r-2][c]=='#' && a[r-2][c+1]=='#'  && a[r-2][c+2]=='#' && a[r-1][c]=='#' 
			&& a[r-1][c+2]=='#' && a[r][c]=='#' && a[r][c+1]=='#' && a[r][c+2]=='#')
		{
			flag[r-2][c]=1;
			flag[r-2][c+1]=1;
			flag[r-2][c+2]=1;
			flag[r-1][c]=1;
			//flag[r-1][c+1]=0;
			flag[r-1][c+2]=1;
			flag[r][c]=1;
			flag[r][c+1]=1;
			flag[r][c+2]=1;
			return 7;
		}
	}
	if(c+1<m && r<n && c>=1 && r>=2)
	{
		if(a[r-2][c-1]=='#' && a[r-2][c]=='#'  && a[r-2][c+1]=='#' && a[r-1][c-1]=='#' 
			&& a[r-1][c+1]=='#' && a[r][c-1]=='#' && a[r][c]=='#' && a[r][c+1]=='#')
		{
			flag[r-2][c-1]=1;
			flag[r-2][c]=1;
			flag[r-2][c+1]=1;
			flag[r-1][c-1]=1;
			//flag[r-1][c]=0;
			flag[r-1][c+1]=1;
			flag[r][c-1]=1;
			flag[r][c]=1;
			flag[r][c+1]=1;
			return 8;
		}
	}
	if(c<m && r<n && c>=2 && r>=2)
	{
		if(a[r-2][c-2]=='#' && a[r-2][c-1]=='#'  && a[r-2][c]=='#' && a[r-1][c-2]=='#' 
			&& a[r-1][c]=='#' && a[r][c-2]=='#' && a[r][c-1]=='#' && a[r][c]=='#')
		{
			flag[r-2][c-2]=1;
			flag[r-2][c-1]=1;
			flag[r-2][c]=1;
			flag[r-1][c-2]=1;
		//	flag[r-1][c-1]=0;
			flag[r-1][c]=1;
			flag[r][c-2]=1;
			flag[r][c-1]=1;
			flag[r][c]=1;
			return 9;
		}
	}
	return 0;
}
int main()
{
	string x;
	scanf("%ld %ld",&n,&m);
	for(long i=0;i<n;i++)
	{
		cin>>x;
		for(long j=0;j<m;j++)
		{
			a[i][j]=x[j];
		}
	}
	// printf("\n");
	// for(long i=0;i<n;i++)
	// {
	// 	for(long j=0;j<m;j++)
	// 	{
	// 		printf("%c",a[i][j]);
	// 	}
	// 	printf("\n");
	// }
	
	for(long i=0;i<n;i++)
	{
		for(long j=0;j<m;j++)
		{
			if(a[i][j]=='#' && flag[i][j]==0)
			{
				//cout<<checkFlag(i,j)<<endl;
				if(!checkFlag(i,j))
				{
					cout<<"NO"<<endl;
					return 0;
				}

			}
		}
	}
	cout<<"YES"<<endl;
	return 0;
}