#include <bits/stdc++.h>
using namespace std;
 
#define INF 1000000007
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;
 
#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define tr(x,it) for(auto it = (x).begin();it!=(x).end();++it)
#define ntr(x,it) for(auto it = (x).rbegin();it!=(x).rend();++it)
#define sz(a) int((a).size()) 
#define pb push_back 
#define PB pop_back
#define pf push_front
#define PF pop_front
#define MP make_pair
#define clr clear
#define rz resize
#define mset(a,b) memset(a,b,sizeof(a))
#define ia(a,n) FOR(i,0,n-1)cin>>a[i]
#define ia1(a,n) FOR(i,1,n)cin>>a[i]
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,n) FOR(i,0,n-1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
inline int norm(int x,int m=INF){if(x>=m)x%=m;if(x<0)x+=m;return x;}
inline int neg(int x,int m=INF){x=-x;return norm(x);}
#define N 110
vi a,b;
vii pts;
vi dp;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    FOR(J,1,T)
    {
    	int n;
        cin>>n;
        a.clr();a.rz(n);
        b.clr();b.rz(n);
        FOR(i,0,n-1)cin>>a[i];
        FOR(i,0,n-1)cin>>b[i];
        pts.clr();
        FOR(i,0,n-1)if(b[i]!=-1)pts.pb({b[i]-a[i]-30,a[i]});
        sort(all(pts));
          
        int x=0;
        int zz=0;
        while((!pts.empty()) and pts[0].F<0)zz++,pts.erase(pts.begin());
        if(pts.empty()){cout<<zz<<"\n";continue;}
        int nn=pts.size();
        FOR(i,0,nn-1)pts[i].F+=pts[i].S;
        sort(all(pts));
        
        dp.clr();
        dp.pb(0);
        dp.pb(pts[0].S);
        FOR(i,1,nn-1)
        {
            NFOR(j,sz(dp)-1,1)
            {
                if(j==sz(dp)-1)
                {
                    if(dp[j]+pts[i].S<=pts[i].F)dp.pb(dp[j]+pts[i].S);
                }
                if(dp[j-1]+pts[i].S<dp[j])dp[j]=dp[j-1]+pts[i].S;
            }
        }
    	cout<<"Case "<<J<<": ";
    	cout<<nn-(dp.size()-1)+ zz<<"\n";
    }
	return 0;
}
