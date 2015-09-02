#include <iostream>
using namespace std;

int main()
{
	int A,B,i,testcases;
	cin>>testcases;
	while(testcases--)
	{
		i=0;
		cin>>A;
		cin>>B;
		while(A!=B)
		{	if(A%2==0)
			{
			if(A>B)
			{
				if(A%2 == 0)
				{A=A/2;
					i++;}
				else
				{A=(A-1)/2;
					i++;
				}
			}
			else
			{
				A=2*A;
				i++;}
			}
			else
			{
				A=(A-1)/2;
					i++;
			}
		}
		cout<<i<<endl;
	}
	return 0;
}
