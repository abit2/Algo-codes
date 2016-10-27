#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int i,j,k,n;
	string str;
	long long int arr[200001];
	char charr[200001];
	cin>>str;
	
	//initialization
	n= str.length();
	for(i=0;i<n;i++){
		arr[i]=0;
	}
	
	//filling the count array
	j=0;
	for(i=0;i<n-1;i++){
		arr[j]++;
		charr[j]= str[i];
		if(str[i]!=str[i+1]){
			j++;
		}
	}
	if(str[n-2]==str[n-1]){
		arr[j]++;
	}
	if(str[n-2]!=str[n-1]){
		arr[j]++;
		charr[j]= str[n-1];
	}
	j++;
	
	for(i=0;i<j;i++){
		cout<<arr[i]<<" ";
	}
	
	//computataion
	for(i=0;i<j;i++){
		if(arr[i]>=2){
			arr[i]=2;
		}
	}
	for(i=0;i<j-1;i++){
		if(arr[i]==arr[i+1] && arr[i]==2){
			arr[i+1]=1;
		}
	}
	
	for(i=0;i<j;i++){
		for(k=0;k<arr[i];k++){
			cout<<charr[i];
		}
	}
	cout<<endl;
	return 0;
}