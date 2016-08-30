#include <iostream>
#include <algorithm>

using namespace std;

int success(int A[],int B[],int N)
{
	int temp[N],count=0;
	temp[0] = A[0];
	int past = A[0];
	for (int i = 1; i < N; ++i)
	{
		temp[i] = A[i] - past;
		past = A[i];
	}
	// for (int i = 0; i < N; ++i)
	// 	{
	// 		cout<<temp[i]<<" number "<<i<<endl;
	// 	}
	for (int i = 0; i < N; ++i)
	{
		if(temp[i] >= B[i])
		{	count++;
			// cout<<count<<"B array "<<B[i]<<endl;
		}
	}
	return count;
}

int main()
{
	int testcases,N,count;
	cin>>testcases;
	while(testcases--)
	{
		cin>>N;
		int A[N],B[N];
		for (int i = 0; i < N; ++i)
		{
			cin>>A[i];
		}
		for (int i = 0; i < N; ++i)
		{
			cin>>B[i];
		}
		cout<<endl;
		count = success(A,B,N);
		cout<<count;
	}

	return 0;
}