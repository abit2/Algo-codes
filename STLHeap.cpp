#include <iostream>
#include <queue>

using namespace std;

int mincost(int arr[],int s)
{
	priority_queue< int,vector<int>,greater<int> >pq(arr,arr+s);
	int res =0;
	
	while(pq.size()>1)
	{
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();
		res += first + second;
		pq.push(first+second);
	}
	return res;
}

int main()
{
	int arr[] = {4,3,2,6};
	int size = sizeof(arr)/sizeof(arr[0]);
	int mincosft = mincost(arr,size);
	cout<<mincosft<<endl;
	return 0;
}