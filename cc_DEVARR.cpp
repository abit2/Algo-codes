// https://www.codechef.com/JUNE16/problems/DEVARRAY/


#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	long long int n,q,t,i,max,min,k;
	cin>>n>>q;
	min=10000000000;
	max=-1;
	for(i=0; i<n; i++){
		cin>>k;
		if(k<min)	min=k;
		if(k>max)	max=k;
	}
	for(i=0; i<q;i++){
		cin>>t;
		if(t<min || t>max)	cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
} 
