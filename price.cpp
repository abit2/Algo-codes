#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t,n,p,b[100001],i,j,k,sum,ans,tt;
    cin>>t;
    tt=t;
    while(t--){
        
        //inputs
        cin>>n>>p;
        for(i=0;i<n;i++)
            cin>>b[i];
        
        //initialization
        sum=0;
        ans=0;
        j=0;
        for(i=0;i<n;i++){
            sum+=b[i];
            if(sum>p){
                sum-=b[i];
                i--;
                break;
            }
        }
        if(i==n)
            i--;
        j=i+1;
        k=i+1;
        ans+=k;
       // cout<<k<<endl;
        
        //computation
        for(i=1;i<n;i++){
            if(j<i)
                j=i;
            if(sum>0) 
                sum-=b[i-1];
            if(k>0) 
                k--;
            while(j<n && (sum+b[j])<=p){
                //cout<<sum<<" "<<i<<" "<<j<<endl;
                sum+=b[j];
                j++;
                k++;
            }
            ans+=k;    
        }
        cout<<"Case #"<<tt-t<<": "<<ans<<endl;
        
    }
    return 0;
}
