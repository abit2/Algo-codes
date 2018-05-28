#include <bits/stdc++.h>
using namespace std;

int a[101], b[101];
int main()
{
	int t;
	cin>>t;
	for(int I=1;I<=t;I++)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<n;i++)cin>>b[i];
		vector<pair<int,int>> g[n+1];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i != j)
				{
					int x= min(a[i]^b[j],b[i]^a[j]);
					g[j].push_back({i,x});
					g[i].push_back({j,x});
				}
			}
		}
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
		vector<int> vis(n);
		pq.push({0,0});
		long long int ans = 0;
		while(!pq.empty())
		{
			auto pa = pq.top();
			pq.pop();
			if(vis[pa.second])continue;
			vis[pa.second] = 1;
			ans += pa.first*1ll;
			for(auto it:g[pa.second])
			{
				pq.push({it.second,it.first});
			}
		}
		cout<<"Case #"<<I<<": "<<ans<<endl;
	}
}