#include <iostream>
using namespace std;

int main() {
	long long int test,t,i,j,k,n;
	cin>>t;
	test= t;
	while(t--){
		string str;
		cin>>str;
		n= str.length();
		
		if(str[0]=='+'){
			j=1;
		}
		else if(str[0]=='-'){
			j=0;
		}
		
		k=1;
		for(i=0;i<n-1;i++){
			if(str[i]!=str[i+1]){
				k++;
			}
		}
		
		cout<<"Case #"<<test-t<<": ";
		if(j==1){
			if(k%2==1){
				k--;
			}
			else{
				;
			}
			cout<<k<<endl;
		}
		else{
			if(k%2==1){
				;
			}
			else{
				k--;
			}
			cout<<k<<endl;
		}
	}
	return 0;
}