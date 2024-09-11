#include<bits/stdc++.h>
using namespace std ; 

const int N = 1e6+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 

int n; 
int a[N] ; 
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    int n; cin>>n ;
    for(int i=1;i<=n;i++)cin>>a[i] ;
    long long sum = 0 ;
    vector<vector<long long>>dec={{0,0}}; 
    int res = 0 ; 
    for(int i=1;i<=n;i++)
    {
        sum+=a[i] ; 
        int l = 0 ;
        int r = int(dec.size())-1  ;
        int ans = -1 ;
        while(l<=r)
        {
            int mid = (l+r)>>1; 
            if(sum>dec[mid][0])ans=dec[mid][1],r=mid-1;
            else l=mid+1;
        }
        if(ans==-1)
        {
            dec.push_back({sum,i}) ;
        }
        else
        {   
            res=max(res,i-int(ans)) ;
        }
    }
    cout<<res ;
    return 0 ; 
}