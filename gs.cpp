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
typedef pair<ll,ll> iil;
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
#define DB(x)              cout<<__LINE__<<" :: "<<#x<< ": "<<x<<endl;
#define DB2(x, y)          cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<endl;
#define DB3(x, y, z)       cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<" | "<<#z<<": "<<z<<endl;
struct scheduler;
struct job
{
	
	long long int id,time,myvar;
	int origsys,instr,imp,dur;//create a hash of the two 
	job(ll Time,ll Id,int Origsys,int Instr,int Imp,int Dur,int Myvar)//<timestamp> <id> <orig> <instr> <importance> <duration>
	{
		id=Id;
		time=Time;
		dur=Dur;
		origsys=Origsys;
		instr=Instr;
		imp = Imp;
		myvar=Myvar;
	}
	bool operator<(const job& a)const
	{
		if(this->imp != a.imp)
		{
			return this->imp > a.imp;
		}
		else if(this->time != a.time)
		{
			return this->time < a.time;
		}
		else return this->dur < a.dur;
	}
	void print(const scheduler& s) const ; 
};
struct scheduler
{
	set<job> pq,queryk; ////to be used for the assign thing 

	priority_queue< ll,vector<ll>,greater<ll> > cur;  //for the cpu 

	priority_queue< iil,vector<iil>,greater<iil> > pqtime;  //for the cpu 

	vector<string> data;///stores origin and function 
	unordered_map<int,priority_queue< iil,vector<iil>,greater<iil> >> pqmapjob;
	unordered_map<int,set<job>> mapjob;
    vector<job> V;
	unordered_map<string,int> M;////////////hash all the strings 
	//unordered_map<int,priority_queue<job,jcmp> >  osearch;  //////////query by search 
	unordered_map<int,ll> intime;

	int ctr=1,cpucount,jobcount=1;
	
};
inline void job::print(const scheduler& s) const 
{
	//job timestamp1 id1 orig instr importance duration
	cout << "job" << ' ' << time << ' ' << id << ' ' << s.data[origsys] << ' ' << s.data[instr] << ' ' << imp << ' ' << dur << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	string s;
	ll n;
	cin>>s>>n;
	scheduler S;
	S.cpucount=n;
	map<job, bool> deb;
	ll prev = -99;
	S.data.pb("");
/// parsing input data for offline processing 

	while(!cin.eof())
	{
		cin>>s;
        if(cin.eof())break;
		if(s=="job")
		{
			ll a,b;
			int c,d;
			string temp,temp2;
			cin>>a>>b>>temp>>temp2>>c>>d;
			auto &id1=S.M[temp];
			auto &id2=S.M[temp2];
			
			if(!id1)
			{
				S.M[temp]=S.ctr++;
				S.data.pb(temp);
			}
			if(!id2)
			{
				S.M[temp2]=S.ctr++;
				S.data.pb(temp2);
			}
			
			const job j1(a,b,id1,id2,c,d,S.jobcount++);	
			S.pq.insert(j1);///*/the queue for the waiting elements
			//S.mapjob[id1].insert(j1);////the queue for the query by object
			S.pqtime.push({j1.time,j1.myvar});
            S.V.pb(j1);
            S.pqmapjob[id1].push({j1.time,j1.myvar});
		}
		else if(s=="assign")
		{
			ll t,k;
			cin>>t>>k;
			while(!S.cur.empty())     ////////optimise later using lower bound and range erase 
			{
				const ll x=S.cur.top();
				if(x > t)break;
				S.cur.pop();
			}
			
			ll ctr=min(S.cpucount-(ll)S.cur.size(),k);
			ctr=min(ctr,(ll)S.pq.size());
			// assert(ctr >=0);
			
			while(ctr)
			{
				job temp=*S.pq.cbegin();
				S.pq.erase(S.pq.cbegin());
				const int id=temp.myvar;
				S.intime[id]=t;
				//cout << "[ans1] ";
				// cout<<temp.time<<" "<<temp.id<<" "<<temp.origsys<<" "<<temp.instr<<" "<<endl;//dur<<" "<<myvar<<endl;
				temp.print(S);
				if(temp.dur + t < 0)S.cur.push(LLONG_MAX);
				else if(temp.dur + t < t  or temp.dur +t <temp.dur)S.cur.push(LLONG_MAX);
				else S.cur.push(temp.dur + t);
				ctr--;
			}

		}
		else if(s=="query")
		{
			ll a;
			string temp;
			
			cin>>a>>temp;
			int n=temp.length();
			bool d=1;
			rep(i,n)
			{
				if(!('0'<=temp[i] and temp[i]<='9')){d=0;break;}
			}
			if(d)
			{
			
                ll x;
                
				 x=stol(temp);
                
				int ctr=0;
				while(!S.pqtime.empty())
				{
					iil temp5=S.pqtime.top();
					if(temp5.first > a)break;
					S.queryk.insert(S.V[temp5.second-1]);
					S.pqtime.pop();
				}
				
				auto it = (S.queryk).cbegin();
				while(it!=(S.queryk).cend() and ctr<x)
				{	
					if(it->time > a ){++it;continue;}
					if(S.intime[it->myvar] <= a and S.intime[it->myvar])
					{
						it++;
					}
					else 
					{
						ctr++;
						(*it).print(S);
						++it;
					}

				}
			}
			else 
			{
				int id=S.M[temp];
				
				while(!S.pqmapjob[id].empty())
				{
					iil temp5=S.pqmapjob[id1].top();
					if(temp5.first > a)break;
					S.mapjob[id].insert(S.V[temp5.second-1]);
					S.pqmapjob[id1].pop();
				}
				auto &it2=S.mapjob[id];
				auto it = it2.begin();
				while(it!=it2.end())
				{
					if(it->time > a ){++it;continue;}
					if(S.intime[it->myvar] <= a and S.intime[it->myvar])
					{
						it++;
					}
					else 
					{
						(*it).print(S);
						it++;
					}
				}
			}
			
		}

		else assert(0);

	}


	return 0;
} 