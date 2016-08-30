# define MAX_LENGTH 20


#include "myl.h"
int prints(char *str)
{
	int length = 0;
	while(str[length]!='\0')
	{
		++length;	
	}
	__asm__ __volatile__ 
	(
		"movl $1, %%eax \n\t"
		"movq $1, %%rdi \n\t"
		"syscall \n\t"
		:
		:"S"(str), "d"(length)
    	);
	return length;
}

int printi(int n)
{
	int length = 0;
	int start = 0;
	int digit,end;
    	char answer[MAX_LENGTH],temp;
	if(n<0)
	{
		answer[length++] = '-';
		n = -n;
		start = 1;
	}
	else if(n==0)
	{
		answer[length++] = '0';
	}
	while(n>0)
	{
		digit = n%10;
		n = n/10;
		answer[length++] = (char)(digit + '0');
	}
	end = length-1;
	while(start<=end)
	{
		temp = answer[start];
		answer[start] = answer[end];
		answer[end] = temp;
		++start;
		--end;
	}
	__asm__ __volatile__ (
		"movl $1, %%eax \n\t"
		"movq $1, %%rdi \n\t"
		"syscall \n\t"
		:
		:"S"(answer), "d"(length)
    	);
	return length;
}


int readi(int *eP)
{
	char answer[MAX_LENGTH];
	int number=0, length;
	int start = 0;
	__asm__ __volatile__ (
		"movl $0, %%eax \n\t"
		"movq $1, %%rdi \n\t"
		"syscall \n\t"
		:"=rax"(length)
		:"S"(answer), "d"(MAX_LENGTH)
	); 
	length--;
	if(length<=0)
	{
		(*eP) = ERR;
		return 0; 
	}
	if (answer[0]=='-')
	{
		start = 1;
	}
	while(start<length)
	{
		if(answer[start]>='0' && answer[start]<= '9')
		{
			number = number*10 + (answer[start]-'0');	
			++start;
		}
		else
		{
			(*eP) = ERR;
			return 0;
		}
	}
	if(answer[0]=='-')
	{
		number = -number;
	}
	(*eP) = OK;
	return number;
}

int readf(float *fP)
{
	char answer[MAX_LENGTH];
	int i=0,start=0,decimal=0, length,temp,position,divider=10;
	float number = 0.0,extra;
	do
	{
		__asm__ __volatile__(
				"movl $0 ,%%eax \n\t"
				"movq $1 ,%%rdi \n\t"
				"syscall \n\t"
				:
				: "S"(answer+i) , "d"(1)
			);
	}while(answer[i++]!='\n');
	i--;
	length = i;
	if(length<=0)
	{
		(*fP) = ERR;
		return (*fP); 
	}
	if (answer[0]=='-')
	{
		start = 1;
	}
	temp = start;	


	while(temp<length)
	{
		if(answer[temp]=='.')
		{
			++decimal;
			position = temp;
		}
		++temp;
	}
	if(decimal>1)
	{
		(*fP)=ERR;
		return (*fP);
	}
	else if(decimal == 0)
	{

		while(start<length)
		{
			if(answer[start]>='0' && answer[start]<= '9')
			{
				number = number*10 + (answer[start]-'0');	
				++start;

			}
			else
			{

				(*fP) = ERR;
				return (*fP);
			}
		}
	}

		
	else if(decimal == 1)
	{
		while(start<position)
		{
			if(answer[start]>='0' && answer[start]<= '9')
			{
				number = number*10 + (answer[start]-'0');	
				++start;
			}
			else
			{
				(*fP) = ERR;
				return (*fP);
			}
		}
		temp = position+1;
		while(temp<length)
		{
			if(answer[temp]>='0' && answer[temp]<= '9')
			{
				extra = (float)(answer[temp]-'0')/divider;
				number = number + extra;	
				++temp;
				divider = divider*10;
			}
			else
			{
				(*fP) = ERR;
				return (*fP);
			}
		}			
	}

	if(answer[0]=='-')
	{
		number = -number;
	}
	(*fP) = number;
	return OK;
}

int printd(float f)
{
	char answer[MAX_LENGTH],temp;
	int length = 0;
	int start = 0;
	int count = 0;
	int digit,end;
	if(f<0)
	{
		answer[length++] = '-';
		f = -f;
		start = 1;
	}
	int n = (int)(f);
	float decimal = f - n;
	if(n==0)
	{
		answer[length++] = '0';
	}
	while(n>0)
	{
		digit = n%10;
		n = n/10;
		answer[length++] = (char)(digit + '0');
	}
	end = length-1;
	while(start<end)
	{
		temp = answer[start];
		answer[start] = answer[end];
		answer[end] = temp;
		++start;
		--end;
	}
	answer[length++] = '.';
	if(decimal == 0.0)
	{
	answer[length++] = '0';		
	}
	else
	{
		count = 0;
		while(count<5)
		{
			
			digit = (int)(decimal*10);
			decimal = decimal*10;
			decimal = decimal - digit;
			answer[length++] = (char)(digit + '0');
			++count;
		}
	}	
	__asm__ __volatile__ (
		"movl $1, %%eax \n\t"
		"movq $1, %%rdi \n\t"
		"syscall \n\t"
		:
		:"S"(answer), "d"(length)
    	);
	return length;
}


