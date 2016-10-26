// https://www.codechef.com/JUNE16/problems/BINOP

#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	string s1,s2;
	int i,n0,n1,n01,t,n10,diff,ans;
	cin>>t;
	while(t--){
		cin>>s1>>s2;
		n1=n0=n10=n01=diff=ans=0;
		for(i=0; i<s1.size(); i++){
			if(s1[i]=='1')
			{
				n1++;
				if(s2[i]=='1')	continue;
				else n10++;
			}
			else{
				n0++;
				if(s2[i]=='0')	continue;
				else n01++;
			}
		}
		if(n10 > n01){	ans=n01;	diff=n10-n01; if(n0>0){ans+=diff; } else ans=-1;}
		else{ ans=n10; diff=n01-n10; if(n1>0){	ans += diff; }else ans=-1;}
		
		if(ans==-1)	cout<<"Unlucky Chef\n";
		else{
			cout<<"Lucky Chef\n"<<ans<<endl;
		}
	}
	return 0;
} 