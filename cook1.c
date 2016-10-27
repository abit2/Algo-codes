#include <stdio.h>

int main(){
	int t,n,count,i,mone,zero,one,flag,a;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		flag=0;
		for(i=mone=one=zero=count=0;i<n;i++){
			scanf("%d",&a);
			if(a==-1)mone++;
			else if(a==0)zero++;
			else if(a==1)one++;
			else count++;
		}
		if(n>1){
			if(mone>0){
				if(mone>1){
					if(one==0)flag=1;
					else{
						if(count!=0)flag=1;
					}
				}
				else{
					if(count!=0)flag=1;
				}
			}
			else{
				if(count>1)flag=1;
			}
		}
		if(flag)printf("no\n");
		else printf("yes\n");
	}
	return 0;
}
