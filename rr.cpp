#include<iostream>
#include<string>

using namespace std;

int main()
{
int testcases,i,inputnumber;
string z;
cin>>testcases;
for(i=0;i<testcases;i++)
{
cin>>inputnumber;
z="BOB";
if((inputnumber%2)==0)
{
z="ALICE";
}
cout<<z<<"\n";
}
}
