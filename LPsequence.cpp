#include <iostream>
#include <algorithm>

using namespace std;

int longest_subsequence(char A[],int N)
{
	int arr[N][N];
	int j;
	for (int i = 0; i < N; ++i)
	{
				arr[i][i] = 1;
	}
	for (int cl = 2; cl <= N; ++cl)
	{
		for (int i = 0; i < N-cl+1; ++i)
		{
			j = i+cl-1;
			if(A[i]==A[j] && cl==2)
				{arr[i][j] = 2;}
			else if(A[i]==A[j])
				{arr[i][j] = arr[i+1][j-1] + 2;}
			else 
				{arr[i][j] = max(arr[i][j-1],arr[i+1][j]);
					//cout<<"entered for :"<<arr[i][j]<<"("<<i<<j<<")"<<endl;
				}
			// cout<<arr[i][j]<<"("<<i<<j<<")"<<endl;
		}
	}
	// for (int i = 0; i < N; ++i)
	// {
	// 	for (int j = 0; j < N; ++j)
	// 	{
	// 		cout<<arr[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return arr[0][N-1];
}

int main()
{
	char seq[] = "GEEKS FOR GEEKS";
    int n = 15;
    cout<<"The lnegth of the LPS is "<< longest_subsequence(seq,n)<<endl;
	return 0;
}