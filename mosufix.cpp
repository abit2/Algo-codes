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

/// debug //////
#define pr(x,n) {rep(i,n)cout<<x[i]<<" ";cout<<endl;}
#define pr1(x,n) {FOR(i,1,n)cout<<x[i]<<" ";cout<<endl;}

struct SuffixArray {
  const int L;
  string s;
  vector<vector<int> > P;
  vector<pair<pair<int,int>,int> > M;

  SuffixArray(const string &s) : L(s.length()), s(s), P(1, vector<int>(L, 0)), M(L) {
    for (int i = 0; i < L; i++) P[0][i] = int(s[i]);
    for (int skip = 1, level = 1; skip < L; skip *= 2, level++) {
      P.push_back(vector<int>(L, 0));
      for (int i = 0; i < L; i++) 
  M[i] = make_pair(make_pair(P[level-1][i], i + skip < L ? P[level-1][i + skip] : -1000), i);
      sort(M.begin(), M.end());
      for (int i = 0; i < L; i++) 
  P[level][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ? P[level][M[i-1].second] : i;
    }    
  }

  vector<int> GetSuffixArray() { return P.back(); }

  // returns the length of the longest common prefix of s[i...L-1] and s[j...L-1]
  int LongestCommonPrefix(int i, int j) {
    int len = 0;
    if (i == j) return L - i;
    for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--) {
      if (P[k][i] == P[k][j]) {
  i += 1 << k;
  j += 1 << k;
  len += 1 << k;
      }
    }
    return len;
  }

  void prt()
  {
    vi sa=P.back();
    vi temp=sa;
    rep(i,s.size())temp[sa[i]]=i;
    sa=temp;
    FOR(i,0,L-1)
    {
      cout<<LongestCommonPrefix(sa[i],sa[i+1])<<" ";
      FOR(j,sa[i],L-1)cout<<s[j];cout<<endl;
    }
  }

};
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  string s;
  s="aabbab";
  SuffixArray ssa1(s);
  vi sa1=ssa1.GetSuffixArray();
  vi temp(s.size());
  rep(i,s.size())temp[sa1[i]]=i;
  sa1.swap(temp);
  pr(sa1,s.size());
  ssa1.prt();
  
  reverse(all(s));
  SuffixArray ssa2(s);
  vi sa2=ssa2.GetSuffixArray();
  rep(i,s.size())temp[sa2[i]]=i;
  sa2.swap(temp);
  pr(sa2,s.size());
  ssa2.prt();
   return 0;
}
