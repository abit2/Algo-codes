#include <iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

struct node
{
	node *ptr;
	int rank;
	int path;
	int flag;
};

node ***initboard(int n){
	int i,j;
	node ***B;
	B = (node ***)malloc(n * sizeof(node **));
	for(i=0;i<n;i++)
	{
		B[i] = (node **)malloc(n * sizeof(node *));
		for(j=0;j<n;j++)
		{
			B[i][j]= (node *)malloc( sizeof(node));
			B[i][j]->rank = 0;
			B[i][j]->ptr = NULL;
			B[i][j]->path = 0;
			B[i][j]->flag = 0;
		}
	}
	return B;
}

node *findset(node *q){
	node *temp = q;
	while(temp->ptr !=NULL)
	{
		temp=temp->ptr;
	}
	return temp;
}

void setunion(node *a, node *b){
	node *i=findset(a);								
	node *j=findset(b);
	if(i->rank > j->rank){
		j->ptr = i;
	}
	else
		i->ptr=j;
	if(i->rank == j->rank){
		j->rank +=1;
	}
}

int neighbour(int i, int j, int ***B,int n)
{
	int p;
	node *u,*d,*e,*w;
	for(int u=0;u<4;u++)
	{	
	p=rand()%100
	p=p%4;
		if(p==1) 
			{
				if(i-1>=0) 
					{
						u=findset(B[i-1][j]);
						if(u->rank == 0)	return 1;
					}
			}
		if(p==2)
		{
			if(i+1<n)	
			{
				d=findset(B[i+1][j]);
				if(d->rank ==0)	return 2;
			}
		}
		if(p==3)
		{
			if(j+1<n) 
				{ 
					e=findset(B[i][j+1]);
					if(e->rank ==0)
					return 3;
				}
		}
		if(p==4)
		{
			if(j-1>n)	
				{
					w=findset(B[i][j-1]);
					if(w->rank ==0)
					return 4;
				}
		}
	}
	return 0;
}

int addpath(node node***A ,int n, int *e)
{
	int c=0 , b=0,r,temp1,temp2;
	int i=rand() % n;
	int j=rand() % n;
	for(i=(i+c)%n,c=0 ; c<n ; c++)
	{
		for(j=(j+b)%n,b=0 ; b<n ;b++)
		{
			if(A[i][j]->rank == 0 && (r=neighbour(i,j,A,n)))
			{
				if(r==1)
				{
					setunion(A[i-1][j] , A[i][j]);
						A[i][j]->flag =e;
						A[i-1][j]->flag =e;
						temp1=i-1; 
						temp2=j;
						return 1;
				}
				if(r==2)
				{
					setunion(A[i+1][j] , A[i][j]);
						A[i][j]->flag =e;
						A[i+1][j]->flag =e;
						temp1=i+1; 
						temp2=j;
						return 1;
				}
				if(r==3)
				{
					setunion(A[i][j+1] , A[i][j]);
						A[i][j]->flag =e;
						A[i][j+1]->flag =e;
						temp1=i; 
						temp2=j+1;
						return 1;
				}
				if(r==4)
				{
					setunion(A[i][j-1] , A[i][j]);
						A[i][j]->flag =e;
						A[i][j-1]->flag =e;
						temp1=i; 
						temp2=j-1;
						return 1;
				}
			}
		}
	}
	return 0;
}



void printboard(int n,node ***d)
{

	//int n=7;
	int l=0,m=0;
	int i,j,k,p;
	
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				cout<<"+---";
			}
				cout<<endl;
				m=0;
			for(p=0;p<n;p++)
			{
				cout<<"| "<<d[l][m]->path<<" ";
				 m++;
				//cout<<p<<endl;
			}
			l++;
			cout<<"|"<<endl;
		}
}

int main()
{
	int n,i=1,t,way=1;
	node ***A;
	cout<<"give n:";
	cin>>n;
	A=initboard(n);
	//cout<<5<<endl;
	while(i>0)
		{//cout<<i<<endl;
		i=addpath(A,n,&way);
		//cout<<5<<endl;
		}
	//addpathnumber(A,n);
	printboard(n,A);
	return 0;
}