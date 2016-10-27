#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define M 1000000007
#define pii pair<int,int>
#define pll pair<ll,ll>


ll power(ll a, ll b)
{
	if(b==0)
	{
		return 1;
	}
	if(b==1)
	{
		return a%M;
	}
	ll x = power(a,b/2)%M;
	if(b%2 == 0)
	{
		x = (x*x)%M;
		return x;
	}
	else
	{
		x = (x*x)%M;
		x = (x*a)%M;
	}
}
ll inv(ll a)
{
	return power(a, M-2)%M;
}

ll b[100005];
ll dp[100005];

int main()
{
	ll t;
	//cin >> t;
	//while(t--)
	{
		string s;
		cin >> s;
		ll i,j,k,l;
		l = s.length();
		for(i=0; i<l; i++)
		{
			b[i] = (ll)('Z'-s[i]);
		}
		ll sum = 0, temp;
		for(i=l-1; i>=0; i--)
		{
			if(i!=0)temp = b[i]*power(26,i-1);
			else temp = 1;
			temp %= M;
			sum += temp;
			sum %= M;
			dp[i] = sum;
		}
		ll ans=0;
		for(i=0; i<l; i++)
		{
			if(i!=l-1)temp = 1 + dp[i+1]*inv(power(26,i));
			else temp = 1;
			temp %= M;
			temp = temp*b[i];
			temp %= M;
			ans += temp;
			ans %= M;
		}
		cout << ans << endl;
	}
	return 0;
}