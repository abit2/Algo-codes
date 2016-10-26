// https://www.codechef.com/JUNE16/problems/CHEARMY/

#include <iostream>
#include <stack>
using namespace std;
 
int main() {
	// your code goes here
	long long int k,n,ans;
	stack<int> s;
	int t,v;
	cin>>t;
	while(t--){
		cin>>k;
		k--;
		if(k==0){
			cout<<"0\n";
			continue;
		}
		while(k>0){
			v=k%5;
			s.push(2*v);
			k/=5;
		}
		while(!s.empty()){
			ans = s.top();
			s.pop();
			cout<<ans;
		}
		cout<<endl;
	}
	return 0;
} 
