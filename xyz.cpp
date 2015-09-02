#include<iostream>

using namespace std;

int main()
{
int A,B,diff;
cin>>A;
cin>>B;
diff=A-B;
if( (diff%10==0) || (diff%10==1) )
	diff=diff+1;
else
	diff=diff-1;
cout<<diff;
return 0;
}
