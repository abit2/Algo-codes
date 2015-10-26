#include <iostream>					//not able to debug when running for the while loop to complete a particular path tried alot
#include<math.h>					//else rest are fine
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
	return B;			//initialising the board
}

node *findset(node *q){
	node *temp = q;
	while(temp->ptr !=NULL)
	{
		temp=temp->ptr;
	}
	return temp;				//finding the header
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
	}		//taking union of two squares
}

int randnumber(int n){
	int i = rand() % n;
	return i;				//generating random no.
}

int disjoint(node ***w,int k,int l,int n,int t)		//checking condition if there exist a neighbouring node
{
	node *u,*d,*le,*r;								//such that they are not adjacent to the same paths
	if(t==1)										//made different cases for t's indicating N,E,W,S
	{
		if(k-1>=0)									//1 is N , 2 is S ,3 is E, 4 is W 
		{	u=findset(w[k-1][l]);
			if(u->path!=0)
				{if(u->path == findset(w[k+1][l])->path);
					return 0;
				}
		}
		if(k+1<n)
			d=findset(w[k+1][l]);

		if(l-1>=0)
		{
				le=findset(w[k][l-1]);
				if(le->path != 0)
				{
					if(le->path == findset(w[k+1][l])->path)
						return 0;
				}
		}
		if(l+1<n)
		{
			r=findset(w[k][l+1]);
			if(r->path != 0)
			{
				if(r->path == findset(w[k+1][l])->path)
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
			if(d->path!=0)
				{if(d->path == findset(w[k-1][l])->path);
					//cout<<00000<<endl;
					return 0;
				}
		if(l-1>=0)
		{
				le=findset(w[k][l-1]);
				if(le->path!=0)
				{
					if(le->path == findset(w[k-1][l])->path)
						//cout<<00001<<endl;
						return 0;
				}
		}
		if(l+1<n)
		{
			r=findset(w[k][l+1]);
			if(r->path!=0)
			{
				if(r->path == findset(w[k-1][l])->path)
					//cout<<00002<<endl;
					return 0;
			}
		}
	}
	if(t==3)
	{
		if(k-1>=0)
		{	u=findset(w[k-1][l]);
			if(u->path!=0)
				{
					if(u->path == findset(w[k][l-1])->path)
						return 0;
				}
		}
		if(k+1<n)
			d=findset(w[k+1][l]);
			if(d->path!=0)
				{if(d->path == findset(w[k][l-1])->path);
					return 0;
				}
		if(l-1>=0)
		{
				le=findset(w[k][l-1]);
				
		}
		if(l+1<n)
		{
			r=findset(w[k][l+1]);
			if(r->path!=0)
			{
				if(r->path == findset(w[k][l-1])->path)
					return 0;
			}
		}
	}
	if(t==4)
	{
		if(k-1>=0)
		{	u=findset(w[k-1][l]);
			if(u->path!=0)
				{
					if(u->path == findset(w[k][l+1])->path)
						return 0;
				}
		}
		if(k+1<n)
			d=findset(w[k+1][l]);
			if(d->path!=0)
				{if(d->path == findset(w[k][l+1])->path);
					return 0;
				}
		if(l-1>=0)
		{
				le=findset(w[k][l-1]);
				{if(le->path!=0)
					{
					if(le->path == findset(w[k][l+1])->path);
					return 0;
					}
				}
		}
		if(l+1<n)
		{
			r=findset(w[k][l+1]);
		}
	}
	return 1;
}

int north(int k,int l, node ***p,int size,int d)		//function for going north here if d=0 
{
	int e=1;											//then it doesnot check the disjoint case (adjacent paths)
	if(d==0)
	{
		if((p[k][l]->rank == 0)) 
		{
			return 1;
		}
	}
	else
		{if((p[k][l]->rank ==0 && disjoint(p,k,l,size,e)))		//if d=1 then checks case for adjacent paths
		{
			return 1;
		}
		}
	return 0;
}

int south(int k,int l, node ***p,int size,int d)			//same as north but for going south
{
	int e=2,y;
	if(d==0)
	{
		if((p[k][l]->rank == 0)) 
		{
			
			return 1;
		}
	}
	else{
		//cout<<y<<"asbkajbfabfaf"<<endl;
		y=disjoint(p,k,l,size,e);
		//cout<<y<<"asbkajbfabfaf"<<endl;
		if((p[k][l]->rank ==0 && y))
		{
			return 1;
		}
	}
	return 0;
}

int east(int k,int l, node ***p,int size,int d)				//same as north
{
	int e=3;
	
	if(d==0)
	{
		if((p[k][l]->rank == 0)) 
		{
			//cout<<"working correctly"<<endl;
			return 1;
		}
	}
	else
		{
		if((p[k][l]->rank ==0 && disjoint(p,k,l,size,e)))
		{
			return 1;
		}
		}
	return 0;
}

int west(int k,int l, node ***p,int size,int d)			//same as north
{
	int e=4;
	//cout<<"in west function"<<endl;
	if(d==0)
	{
		if((p[k][l]->rank == 0)) 
		{
			//cout<<"working correctly"<<endl;
			return 1;
		}
	}
	else
		{if((p[k][l]->rank ==0 && disjoint(p,k,l,size,e)))
		{
			return 1;
		}
	}
	return 0;
}

int neighbour(int i,int j,node ***A,int size,int *a,int d) //randomly check for N,E,W,S then goes in some order
{
	int count,q =0,w;
	int f =rand() % 4;
	
	while(q<4)
	{
		w=(f+q)%4;
		cout<<w<<endl;
		//cout<<"enter no."<<endl;
		//cin>>w;
		switch(w)
		{
			
			case 0:
			{	
				//cout<<q<<"abcdef"<<endl;
				if((i-1) >=0)
				{
				count = north(i-1,j,A,size,d);
				//cout<<666666<<endl;
				if(count == 1)
					{
							
						return 1;
					}
				}
				q++;
				break;
			}
			case 1:
			{	
				if((j+1) <size)
				{
				count = east(i,j+1,A,size,d);
				if(count == 1)
					{	
						//q++;	
						return 2;
					}
				}
				q++;
				break;
			}
			case 2:
			{
				if((j-1) >=0)
				{
				count = west(i,j-1,A,size,d);
				if(count == 1)
					{	
						//q++;
						return 3;
					}
				}
				q++;
				break;	
			}
			case 3:
			{	
				if((i+1) <size)
				{
					//cout<<0000000000<<endl;
				count = south(i+1,j,A,size,d);
				if(count == 1)
					{	
						//q++;
						return 4;
					}
				}
				q++;
				break;
			}
			

		}
	}
	//cout<<"aiuabfua"<<endl;
	return 0;
}


int addpath(node ***k,int n)
{
	int temp1,temp2,a;
	int way=1;
	int c,b,r,flag=1;							//taking any i and j index randomly and checking
	node *z;
	int i = randnumber(n);
	int j = randnumber(n);
	cout<<i<<"  "<<j<<endl;
	for(c=0,i=(i+c)%n ; c<n ; c++)
	{
		for(b=0,j=(j+b)%n ; b<n ;b++)
		{
			z=findset(k[i][j]);
			r = neighbour(i,j,k,n,&a,0);
			if((z->rank == 0) && (r))				//in 1st attempt d=0 so disjoint check and it should be both empty
			{											//and neighbour should be present
				
				if(r==1)								//cases for north south east west and given path no. in here itself
				{
					cout<<111<<endl;
						setunion(k[i-1][j] , k[i][j]);
						k[i][j]->flag =1;
						k[i][j]->path = way;
						k[i-1][j]->path = way;
						//cout<<8888888<<endl;
						temp1=i-1; 
						temp2=j;
				}
				if(r==4) 
				{
					cout<<444<<endl;
						setunion(k[i+1][j] , k[i][j]);
						k[i][j]->flag =1;
						k[i][j]->path = way;
						k[i+1][j]->path = way;
						temp1=i+1;
						temp2=j;
				}
				if(r==3)
					{
						cout<<333<<endl;
						setunion(k[i][j-1] , k[i][j]);
						k[i][j]->flag =1;
						k[i][j-1]->path = way;
						k[i][j]->path = way;
						temp1=i;
						temp2=j-1;
					}
				if(r==2) 
					{
						cout<<222<<endl;
						setunion(k[i][j+1] , k[i][j]);
						k[i][j]->flag =1;
						k[i][j]->path = way;
						k[i][j+1]->path = way;
						temp1=i;
						temp2=j+1;
					}
				}
					r=neighbour(temp1,temp2,k,n,&a,1);
					while(r!=0)								//continuing the path until it reaches the end
				{
					//cout<<"ahhkjvkv"<<endl;
					//cout<<"inside second loop  "<<a<<endl;
					
							
								//cout<<r<<endl;
								if(r==1)
								{
									cout<<1111<<endl;
									setunion(k[temp1-1][temp2] , k[temp1][temp2]);
									temp1=temp1-1; 
									temp2=temp2;
									k[temp1][temp2]->path =way;
									
								}
								if(r==4)
								{
									cout<<4444<<endl;
									setunion(k[temp1+1][temp2] , k[temp1][temp2]);
									temp1=temp1+1;
									temp2=temp2;
									k[temp1][temp2]->path = way;
								}
								if(r==3)
								{
									cout<<3333<<endl;
									setunion(k[temp1][temp2-1] , k[temp1][temp2]);
									temp1=temp1;
									temp2=temp2-1;
									k[temp1][temp2]->path =way;
									
								}
								if(r==2)
								{
									cout<<2222<<endl;
									setunion(k[temp1][temp2+1] , k[temp1][j]);
									temp1=temp1;
									temp2=temp2+1;
									k[temp1][temp2]->path =way;
									
								}
							r=neighbour(temp1,temp2,k,n,&a,1);
							
					}
					way++;

			}
			
		}
	k[i][j]->flag =1;
	return 1;
	//cout<<"success"<<endl;
}

/*void addpathnumber(node ***q, int n)
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
}*/
void printboard(int n,node ***d)			//printing board
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
	srand((unsigned int)time(NULL));
	int n,i=1,t;
	node ***A;
	cout<<"give n:";
	cin>>n;
	A=initboard(n);
	
	//cout<<5<<endl;
	
		
		i=addpath(A,n);
		
	//cout<<55555555<<endl;
	//addpathnumber(A,n);
	printboard(n,A);
	return 0;
}