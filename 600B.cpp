#include <bits/stdc++.h>

using namespace std;
inline long long int f(long long int y)
{
	return (y*(y-1))/2;
}
inline long long int g(long long int y)
{
	return (y*(y-1)*(y-2))/6;
}
int main()
{
	int t;
	cin>>t;
	for(int idd=1;idd<=t;idd++)
	{
		int n;
		cin>>n;
		vector<int> v(n);
		map<int,int> M;
		for(int i=0;i<n;i++){cin>>v[i],M[v[i]]++;}
		
		vector<pair<long long int,long long int>> w;
		for(auto it=M.begin();it!=M.end();it++)
		{
			w.push_back({it->first,it->second});
		}
		int m = w.size();
		sort(w.begin(),w.end());

		vector<long long int> sum(n+5) , sum2(n+5);

		
		sum[0] = w[0].second;
		sum2[0] = f(w[0].second);
		for(int i=1;i<m;i++)
		{
			sum[i] = w[i].second + sum[i-1];
			sum2[i] = f(w[i].second) + sum2[i-1];
		}

		for(int i=1;i<=m;i++)cout<<sum[i]<<" "<<sum2[i]<<endl;

		long long int ans = 0;
		for(int i=0;i<m;i++)
		{
			int k = i+2;
			for(int j=i+1;j<m-1;j++)
			{
				 while (k < m && w[i].first*2 + w[j].first > w[k].first)
               			++k;
               		k--;
               	ans+=f(w[i].second)*w[k].second*(sum[k] - sum[j-1]);

               	//cout<<i<<" "<<j<<" "<<k<<" gg " <<ans<<endl;
               		cout<<ans<<" fdf "<<i<<" "<<j<<" "<<k<<" "<<sum[k] - sum[j]<<endl;
 					//k++;
			}

		}
		cout<<ans<<" dddddddd "<<endl;
		for(int i=0;i<m;i++)
		{
			int k = i+2;
			for(int j=i+1;j<m-1;j++)
			{
				 while (k < m && w[i].first + w[j].first*2 > w[k].first)
               			++k;
               		k--;
               	ans+=w[i].second*w[k].second*(sum2[k] - sum2[j-1]);
 					
 					//cout<<ans<<" fdf "<<i<<" "<<j<<" "<<k<<" "<<sum2[k] - sum2[j]<<endl;
 					//k++;
			}
			//cout<<ans<<" yo  55 oy "<<w[i].first<<endl;
		}

		for(int i=m-1;i>1;i--)
		{
			ans += f(w[i].second)*(f(sum[i])-sum2[i]);
		}

		for(int i=0;i<m;i++)
		{
			for(int j=i+1;j<m;j++)
			{
				if(w[i].first*3 > w[j].first)
				{
					ans+=g(w[i].second)*w[j].second;
				}
				ans+=w[i].second*g(w[j].second);
			}
		}
		printf("Case #%d: %lld\n",idd,ans);
	}
	return 0;

}
