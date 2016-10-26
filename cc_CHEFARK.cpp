// https://www.codechef.com/JUNE16/problems/CHEFARK/

#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
 
long long int MOD=1000000007;
using namespace std;
 
ll binPow(ll a, ll q, ll MOD) {
    a %= MOD;
    if (q == 0) return 1;
    return ((q % 2 == 1 ? a : 1) * binPow(a * a, q / 2, MOD)) % MOD;
}
 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long int ans,num, den;
	ll n,t,k,v,flag,i,val;
	cin>>t;
	while(t--){
		flag=0;
		cin>>n>>k;
		for(i=0; i<n; i++){
			cin>>val;
			if(val==0)	flag++;
		}
		if(flag){
			n-=flag;
			if(k>n)	k=n;
			ans=binPow(2,k,MOD);
			cout<<ans<<endl;
		}
		else{
			if(k%2){
				ans=val=n;
				for(i=3; i<=k && i<=n; i+=2){
					num = (((val*(n-i+2))%MOD)*(n-i+1))%MOD;
					den = (i*(i-1));
					val=(num*binPow(den,MOD-2,MOD))%MOD;
					ans+=val;
					if(ans>=MOD)	ans-=MOD;
				}
				cout<<ans<<endl;
			}
			else{
				ans=val=1;
				for(i=2; i<=k && i<=n; i+=2){
					num = (((val*(n-i+2))%MOD)*(n-i+1))%MOD;
					den = (i*(i-1));
					val=(num*binPow(den,MOD-2,MOD))%MOD;
					ans+=val;
					if(ans>=MOD)	ans-=MOD;
				}
				cout<<ans<<endl;
			}
		}
	}
	return 0;
} 