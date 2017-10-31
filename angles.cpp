#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	return (b == 0) ? a : gcd(b,a%b);
}

int main()
{
	int n,k,i;
	int temp,input_a;
	int angles[360];
	memset(angles,0,sizeof(angles));
	cin >> n >> k;
	int flag = 0;

	for(i = 0; i < n ; i++)
	{
		cin >> input_a;
		if(flag == 1)
		{
			//flush all the inputs
			continue;
		}
		if(input_a)
		{
			int gcd_with_360 = gcd(input_a,360);
			if(gcd_with_360 == 1)
			{
				flag = 1;
			}
			int c;
			temp = input_a;
			// cout << "gcd  = " << gcd_with_360 << endl;
			for(c = 0 ; c < 360/gcd_with_360; c++)
			{
				angles[temp] = 1;
				temp += input_a;
				temp = temp % 360;
			}
		}
		else
		{
			angles[0] = 1;
		}

	}

	for(i = 0 ; i < k;i++)
	{
		cin >> input_a;
		if(angles[input_a])
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}

}