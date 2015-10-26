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

int randnumber(int n){
	int i = rand() % n;
	return i;
}

int disjoint(node ***w,int k,int l,int n,int t)
{
	node *u,*d,*le,*r;
	if(t==1)
	{
		if(k-1>=0)
		{	u=findset(w[k-1][l]);
			if(u!=NULL)
				{if(u == findset(w[k+1][l]));
					return 0;
				}
		}
		if(k+1<n)
			d=findset(w[k+1][l]);

		if(l-1>=0)
		{
				le=findset(w[k][l-1]);
				if(le!=NULL)
				{
					if(le == findset(w[k+1][l]))
						return 0;
				}
		}
		if(l+1<n)
		{
			r=findset(w[k][l+1]);
			if(r!=NULL)
			{
				if(r == findset(w[k+1][l]))
					return 0;
			}
		}
	}
	if(t==2)
	{
		if(k-1>=0)
		{	u=findset(w[k-1][l]);
			
		}
		if(k+1<n)
			d=findset(w[k+1][l]);
			if(d!=NULL)
				{if(d == findset(w[k-1][l]));
					return 0;
				}
		if(l-1>=0)
		{
				le=findset(w[k][l-1]);
				if(le!=NULL)
				{
					if(le == findset(w[k-1][l]))
						return 0;
				}
		}
		if(l+1<n)
		{
			r=findset(w[k][l+1]);
			if(r!=NULL)
			{
				if(r == findset(w[k-1][l]))
					return 0;
			}
		}
	}
	if(t==3)
	{
		if(k-1>=0)
		{	u=findset(w[k-1][l]);
			if(u!=NULL)
				{
					if(u == findset(w[k][l-1]))
						return 0;
				}
		}
		if(k+1<n)
			d=findset(w[k+1][l]);
			if(d!=NULL)
				{if(d == findset(w[k][l-1]));
					return 0;
				}
		if(l-1>=0)
		{
				le=findset(w[k][l-1]);
				
		}
		if(l+1<n)
		{
			r=findset(w[k][l+1]);
			if(r!=NULL)
			{
				if(r == findset(w[k][l-1]))
					return 0;
			}
		}
	}
	if(t==4)
	{
		if(k-1>=0)
		{	u=findset(w[k-1][l]);
			if(u!=NULL)
				{
					if(u == findset(w[k][l+1]))
						return 0;
				}
		}
		if(k+1<n)
			d=findset(w[k+1][l]);
			if(d!=NULL)
				{if(d == findset(w[k][l+1]));
					return 0;
				}
		if(l-1>=0)
		{
				le=findset(w[k][l-1]);
				{if(le == findset(w[k][l+1]));
					return 0;
				}
		}
		if(l+1<n)
		{
			r=findset(w[k][l+1]);
		}
	}
	return 1;
}

int north(int k,int l, node ***p,int size,int d)
{
	int e=1;
	cout<<"in north function"<<endl;
	if(d==0)
	{
		if((p[k][l]->rank == 0)) /*&& (disjoint(p , k , l,size)))*/
		{
			//cout<<"working correctly"<<endl;
			return 1;
		}
	}
	else
		if((p[k][l]->rank ==0 && disjoint(p,k,l,size,e)))
		{
			return 1;
		}
	return 0;
}

int south(int k,int l, node ***p,int size,int d)
{
	int e=2;
	cout<<"in south function"<<endl;
	if(d==0)
	{
		if((p[k][l]->rank == 0)) /*&& (disjoint(p , k , l,size)))*/
		{
			//cout<<"working correctly"<<endl;
			return 1;
		}
	}
	else
		if((p[k][l]->rank ==0 && disjoint(p,k,l,size,e)))
		{
			return 1;
		}
	return 0;
}

int east(int k,int l, node ***p,int size,int d)
{
	int e=3;
	cout<<"in east function"<<endl;
	if(d==0)
	{
		if((p[k][l]->rank == 0)) /*&& (disjoint(p , k , l,size)))*/
		{
			//cout<<"working correctly"<<endl;
			return 1;
		}
	}
	else
		if((p[k][l]->rank ==0 && disjoint(p,k,l,size,e)))
		{
			return 1;
		}
	return 0;
}

int west(int k,int l, node ***p,int size,int d)
{
	int e=4;
	cout<<"in west function"<<endl;
	if(d==0)
	{
		if((p[k][l]->rank == 0)) /*&& (disjoint(p , k , l,size)))*/
		{
			//cout<<"working correctly"<<endl;
			return 1;
		}
	}
	else
		if((p[k][l]->rank ==0 && disjoint(p,k,l,size,e)))
		{
			return 1;
		}
	return 0;
}

int neighbour(int i,int j,node ***A,int size,int *a,int d)
{
	int count,q =0;
	int f =rand() % 1000;
	//cout<<f<<"working"<<endl;
	f = f % size;
	//cout<<f<<"case no. in neighbour"<<endl;
	while(q<4)
	{
		switch(f=(f+q)%4)
		{
			case 0:
			{
				//cout<<"1st case"<<endl;
				if((i-1) >=0)
				{
				count = north(i-1,j,A,size,d);
				//cout<<count<<endl;
				if(count == 1)
					{	*a = 0;
						return 1;
					}
				}
				q++;
				break;
			}
			case 1:
			{	
				if((j-1) >=0)
				{
				count = east(i,j-1,A,size,d);
				if(count == 1)
					{	*a = 2;	
						return 1;
					}
				}
				q++;
				break;
			}
			case 2:
			{
				if((j+1) <size)
				{
				count = west(i,j+1,A,size,d);
				if(count == 1)
					{	*a = 3;	
						return 1;
					}
				}
				q++;
				break;	
			}
			case 3:
			{	
				if((i+1) <size)
				{
				count = south(i+1,j,A,size,d);
				if(count == 1)
					{	*a = 1;	
						return 1;
					}
				}
				q++;
				break;
			}
			

		}
	}
	return 0;
}


int addpath(node ***k,int n)
{
	int temp1=-1,temp2=-1,a;
	int c,b,r,flag=0;							//a ka value
	node *z;
	int i = randnumber(n);
	int j = randnumber(n);
	cout<<i<<"  "<<j<<endl;
	for(i=(i+c)%n,c=0 ; c<n ; c++)
	{
		for(j=(j+b)%n,b=0 ; b<n ;b++)
		{//cout<<"working"<<endl;
			z=findset(k[i][j]);
			r = neighbour(i,j,k,n,&a,0);
			//cout<<"working"<<endl;
			//cout<<r<<endl;
			if((z->rank == 0) && (r))
			{	
				//flag += 1;
				cout<<"inside loop  "<<a<<endl;
				if(a==0)
				{
						setunion(k[i-1][j] , k[i][j]);
						k[i][j]->flag =1;
						temp1=i-1; 
						temp2=j;
						cout<<"inside case when a=0"<<endl;
						break;
						
				}
				if(a==1) 
				{
						setunion(k[i+1][j] , k[i][j]);
						k[i][j]->flag =1;
						temp1=i+1;
						temp2=j;
						cout<<"inside case when a=1"<<endl;
						break;
				}
				if(a==2)
					{
						setunion(k[i][j-1] , k[i][j]);
						k[i][j]->flag =1;
						temp1=i;
						temp2=j-1;
						cout<<"inside case when a=2"<<endl;
						break;
					}
				if(a==3) 
					{
						setunion(k[i][j+1] , k[i][j]);
						k[i][j]->flag =1;
						temp1=i;
						temp2=j+1;
						cout<<"inside case when a=3"<<endl;
						break;
					}
				}
			}
	}
	//cout<<"flag"<<flag<<endl;
	if(temp1==-1)
		{
		return 0;
		//cout<<"failure"<<endl;
		}
	i=temp1; j=temp2;
	while(neighbour(i,j,k,n,&a,1)!=0)
	{
		cout<<"inside second loop  "<<a<<endl;
		switch( a )
				{
					case 0:
					{
						setunion(k[i-1][j] , k[i][j]);
						temp1=i-1; 
						temp2=j;
						cout<<"inside cakjcase when a=0"<<endl;
						break;
					}
					case 1:
					{
						setunion(k[i+1][j] , k[i][j]);
						temp1=i+1;
						temp2=j;
						cout<<"inside cakjcase when a=0"<<endl;
						break;
					}
					case 2:
					{
						setunion(k[i][j-1] , k[i][j]);
						temp1=i;
						temp2=j-1;
						cout<<"inside cakjcase when a=0"<<endl;
						break;
					}
					case 3:
					{
						setunion(k[i][j+1] , k[i][j]);
						temp1=i;
						temp2=j+1;
						cout<<"inside cakjcase when a=0"<<endl;
						break;
					}
				}
		i=temp1; j=temp2;	
	}
	k[i][j]->flag =1;
	return 1;
	//cout<<"success"<<endl;
}

void addpathnumber(node ***q, int n)
{
	int i,j,k,l,count=1;
	node *a;
	for(i=0;i<n;i++)
	{
		for (j = 0; i < n; ++j)
		{
			a=findset(q[i][j]);
			cout<<q[i][j]->path<<endl;
			//cout<<a->rank<<endl;   		
			if((q[i][j]->path == 0) && (a->rank != 0))
			
				//cout<<"OK"<<endl;
			//if(a->rank != 0)
			{
				cout<<"OK"<<endl;
				q[i][j]->path = count;
				cout<<"OK"<<endl;
				for (k = 0; k < n; ++k)
				{
					for(l=0 ; l<n ; ++l)
					{
						if(findset(q[i][j])!=NULL || findset(q[k][l])!=NULL)
						{
							if(findset(q[i][j]) == findset(q[k][l]))
						{
							//cout<<"OK"<<endl;
							q[k][l]->path = count;
							//cout<<"OK"<<endl;
						}
						}

					}
				}
				count++;
			}
		}
	}
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
	int n,i=1,t;
	node ***A;
	cout<<"give n:";
	cin>>n;
	A=initboard(n);
	//cout<<5<<endl;
	
		//cout<<i<<endl;
		i=addpath(A,n);
		//cout<<5<<endl;
	
	//addpathnumber(A,n);
	printboard(n,A);
	return 0;
}
