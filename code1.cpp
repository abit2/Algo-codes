#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int t,n,i,j,k,l,m,test;
	cin>>t;
	test= t;
	while(t--){
		cin>>n;
		if(n==0){
			cout<<"Case #"<<test-t<<": ";
			cout<<"INSOMNIA"<<endl;
			continue;
		}
		long long int dec[10];
		for(i=0;i<10;i++){
			dec[i]= 0;
		}
		l=2;
		j=n;
		while(1){
			m=j;
			while(j){
				k= j%10;
				if(dec[k]==0){
					dec[k]= 1;
				}
				j/=10;
			}
			k=0;
			for(i=0;i<10;i++){
				if(dec[i]==0){
					k=1;
				}
			}
			if(k==0){
				break;
			}
			j=n*l;
			l++;
			//cout<<j<<" ";
		}
		cout<<"Case #"<<test-t<<": ";
		cout<<m<<endl;
	}
	return 0;
}