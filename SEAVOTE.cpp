//https://www.codechef.com/problems/SEAVOTE

#include<stdio.h>
int main()
{
	int t,n,a[10001],i,sum,zero;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum=0;zero=0;
		for(i=0;i<n;i++) {scanf("%d",&a[i]); sum+=a[i]; if(a[i]==0) zero++;}
		zero=100+n-zero;
		if(sum>=100 && sum<zero)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
} 
