#include <bits/stdc++.h>
using namespace std;



int min_no_of_coin(int dp[],int coin[],int n,int a)
{
	int i,j,min;
	dp[0] = 0;
	for(i = 1 ; i <= a ; i++)
	{
		min = 1000000;
		for(j = 0 ; j < n ; j++)
		{
			if((i-coin[j]) >= 0)
			{
				if(dp[i-coin[j]] < min)
					min = dp[i-coin[j]];
			}
		}
		dp[i] = 1 + min; 
	}

	cout << endl;
	for(i = 0 ; i <= a ; i++)
	{
		cout << dp[i] << " ";
	}
	cout << endl;

	return dp[a];
}

int main()
{
	int t,a,n;
	cin >> t;
	int *coin;
	int i;
	while(t--)
	{
		cin >> a;
		cin >> n;

		int dp[a+1];	

		coin = new int[n];

		for(i = 0 ; i < n ; i++)
		{
			cin >> coin[i];
		}
		int check = min_no_of_coin(dp,coin,n,a);
		if(check < 1000000)
			cout << check << endl;
		else
			cout << "No solution" << endl;
	}
}