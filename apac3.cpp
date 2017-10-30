#include <bits/stdc++.h>
using namespace std;

int dp[41][41][41][41];
int mat[41][41][41][41];
int arr[41][41];
int f(int i,int j,int k,int l)
{
  if(j < i or k > l)return 0;
  if(i == j and k == l)return 0;
  if(dp[i][j][k][l]!=-1)return dp[i][j][k][l];
  
  
  int ans= 0;
  for(int ii=i;ii<j;ii++){
    ans =  max(ans, f(i,ii,k,l)+f(ii+1,j,k,l));
  }
  for(int jj=k;jj<l;jj++){
    ans =  max(ans, f(i,j,k,jj)+f(i,j,jj+1,l));
  }
  dp[i][j][k][l] = ans+ mat[i][j][k][l];
  return dp[i][j][k][l];
}
int main()
{
	int t;
	cin>>t;
	for(int I=1;I<=t;I++)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)cin>>arr[i][j];
		}

		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				 int cur = INT_MAX;
				for(int k=1;k<=m;k++)
				{
					cur = INT_MAX;
					for(int l=k;l<=m;l++)
					{
						cur = min(cur, arr[j][l]);
			            mat[i][j][k][l] = cur;
			            if(j > i)mat[i][j][k][l] = min(mat[i][j][k][l], mat[i][j-1][k][l]);
					}
				}
			}
		}
		memset(dp,-1,sizeof(dp));
		cout<<"Case #"<<I<<": "<<f(1,n,1,m)<<endl;
	}
}