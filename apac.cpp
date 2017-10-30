#include <bits/stdc++.h>
using namespace std;

long long int f(int a,int b,int mod)
{
	if(b == 0)return 1%mod;
	if(b == 1)return a%mod;
	long long int temp = f(a,b/2,mod);
	if(b & 1)
	{
		return (((temp*temp)%mod)*a)%mod;
	}
	else return (temp*temp)%mod;
}
int f(int i,int j,vector<int> &v)
{
	if(j <= i or j == v.size() or i < 0 )return 0;
	int id = -1, x = INT_MAX;
	for(int k=i;k<=j;k++){
		if(x > v[k])
		{
			x = v[k];
			id = k;
		}
	}
	return f(i,id-1,v) + f(id+1,j,v) + v[id]*(1 + (j-i>1));
}
int main()
{
	int t;
	cin>>t;
	for(int I=1;I<=t;I++)
	{
		int n,m;
		cin>>n>>m;
		vector<int> v(m);
		for(int i=0;i<m;i++)cin>>v[i];
		int ans = 0;
		ans = f(0,m-1,v);
		cout<<"Case #"<<I<<": "<<ans<<endl;
	}
}