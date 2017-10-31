#include <bits/stdc++.h>
using namespace std;

int dp_func(int m,int n,int s[])
{
	bool dp[m+1];
	//memset(dp,sizeof(dp),0);
	int i,j;
	// dp[0] = 0;
	// for(i = 0 ; i < m ; i++)
	// {
	// 	dp[i] = false;
	// }
	fill(dp,dp+m+1,false);

	for(i = 1 ;i <= m ; i++)
	{
		//dp[i] = 0;
		for(j = 0 ; j < n ; j++)
		{
			if(s[j] <= i)
				dp[i] += !dp[i-s[j]];
			else 
				break;
		}
		//dp[i] = !dp[i];
	}

	// for(i = 0 ; i <= m ; i++)
	// {
	// 	cout << dp[i] << " "; 
	// }
	return dp[m];
}

int main()
{
	int t;
	cin >> t;
	// scanf("%d",&t);
	while(t--)
	{
		int m,n,i;
		cin >> m >> n;
		// scanf("%d %d",&m,&n);
		int s[n];
		for(i = 0 ;i < n ; i++)
		{
			cin >> s[i];
			// scanf("%d",&s[i]);
		}
		sort(s,s+n);
		if(dp_func(m,n,s))
			cout << "Little Deepu\n";
		else
			cout << "Kate\n";
	}

}
